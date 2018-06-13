/**
 * @file node_48 header
 * @author Rafael Kallis <rk@rafaelkallis.com>
 */

#ifndef ART_NODE_48_HPP
#define ART_NODE_48_HPP

#include "node.hpp"
#include "node_256.hpp"

// TODO(rafaelkallis): rule of five

template <class T> class node_48 : public node<T> {
public:
  node_48();
  node_48(key_type prefix, T *value);
  ~node_48() override = default;

  node<T> *find_child(const partial_key_type &partial_key) const override;
  void set_child(const partial_key_type &partial_key, node<T> *child) override;
  node<T> *grow() override;
  bool is_full() const override;
  bool is_leaf() const override;

private:
  static const partial_key_type EMPTY;

  unsigned char n_children_;
  array<partial_key_type, 256> indexes_;
  array<node<T> *, 48> children_;
};

template <class T> node_48<T>::node_48() : node_48<T>(key_type(0), nullptr) {}

template <class T>
node_48<T>::node_48(key_type prefix, T *value)
    : node<T>(prefix, value), n_children_(0), indexes_() {
  for (int i = 0; i < 256; i += 1) {
    this->indexes_[i] = node_48::EMPTY;
    if (i < 48) {
      this->children_[i] = nullptr;
    }
  }
}

template <class T>
node<T> *node_48<T>::find_child(const partial_key_type &partial_key) const {
  unsigned char index = this->indexes_[partial_key];
  return node_48::EMPTY != index ? this->children_[index] : nullptr;
}

template <class T>
void node_48<T>::set_child(const partial_key_type &partial_key,
                           node<T> *child) {

  // TODO(rafaelkallis): pick random starting entry in order to increase
  // performance? i.e. for (int i = random([0,48)); i != (i-1) % 48; i = (i+1) %
  // 48){}

  /* find empty child entry */
  for (int i = 0; i < 48; i += 1) {
    if (nullptr == this->children_[i]) {
      this->indexes_[partial_key] = i;
      this->children_[i] = child;
      break;
    }
  }
  this->n_children_ += 1;
}

template <class T> node<T> *node_48<T>::grow() {
  auto new_node = new node_256<T>(this->get_prefix(), this->get_value());
  for (int partial_key = 0; partial_key < 256; partial_key += 1) {
    unsigned char index = this->indexes_[partial_key];
    if (index != node_48::EMPTY) {
      new_node->set_child(partial_key, this->children_[index]);
    }
  }
  delete this;
  return new_node;
}

template <class T> bool node_48<T>::is_full() const {
  return this->n_children_ == 48;
}

template <class T> bool node_48<T>::is_leaf() const {
  return this->n_children_ == 0;
}

template <class T> const unsigned char node_48<T>::EMPTY = 48;

#endif