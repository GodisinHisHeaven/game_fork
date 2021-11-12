#ifndef NODE_HPP
#define NODE_HPP

#include <vector>

template <typename T>
struct Node {
  T data;
  std::vector<T> actions;
};

#endif