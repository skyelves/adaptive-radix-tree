/**
 * @file leaf_node header
 * @author Rafael Kallis <rk@rafaelkallis.com>
 */

#ifndef ART_LEAF_NODE_HPP
#define ART_LEAF_NODE_HPP

#include "node.hpp"

namespace art {

    template<class T>
    class art;

    template<class T>
    class leaf_node : public node<T> {
    public:
        explicit leaf_node(T *value);

        T *set_value(T *value);

        bool is_leaf() const override;

        T *value_ = NULL;
    };

    template<class T>
    leaf_node<T>::leaf_node(T *value) {
        value_ = (T *) malloc(sizeof(T));
        *value_ = *value;
    }

    template<class T>
    T *leaf_node<T>::set_value(T *value) {
        if (value_ == NULL)
            value_ = (T *) malloc(sizeof(T));
        *value_ = *value;
        return value_;
    }

    template<class T>
    bool leaf_node<T>::is_leaf() const { return true; }

} // namespace art

#endif
