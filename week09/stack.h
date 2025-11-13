#ifndef _STACK_H_
#define _STACK_H_

#include <cstddef>

#include "vector.h"

class Stack : private Vector {
 public:
  explicit Stack(std::size_t capacity);
  Stack(const Stack& stack);
  void operator=(const Stack& stack);
  std::size_t size() const;
  std::size_t capacity() const;
  void Push(int elem);
  int Pop();
  bool IsEmpty() const;
};

#endif  // _STACK_H_
