#include <art.hpp>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

int main() {
  cout << "ART project" << endl;
  /* cout << sizeof(vector<char>) << endl; */
  /* cout << sizeof(string) << endl; */
  /* cout << "Sizes of nodes:" << endl; */
  /* cout << (sizeof(node<int>)) << endl; */

  /* Node n; */
  /* cout << sizeof(n) << endl; */
  /* cout << "Node4" << endl; */
  /* cout << (sizeof(node_4<int>)) << endl; */
  /* Node4 n4; */
  /* cout << sizeof(n4) << endl; */

  /* cout << (sizeof(node_16<int>)) << endl; */
  /* cout << (sizeof(node_48<int>)) << endl; */
  /* cout << (sizeof(node_256<int>)) << endl; */

  /* auto n0 = new node_0<int>(); */
  node_0<int> n0;
  n0.check_prefix(key_type(), 0);
}