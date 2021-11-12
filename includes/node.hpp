#ifndef NODE_HPP
#define NODE_HPP

#include <set>

template <typename T>
struct Node {
  T data;
  std::set<T> actions;
};

#endif