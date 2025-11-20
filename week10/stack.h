#ifndef _STACK_H_
#define _STACK_H_

#include <cstddef>

#include "vector.h"

template <typename T>
class Stack : private Vector<T> {
 public:
  explicit Stack(std::size_t capacity) : Vector<T>(capacity) {};
  Stack(const Stack& stack) : Vector<T>(stack) {};
  void operator=(const Stack& stack) { Vector<T>::operator=(stack); };
  std::size_t size() const { return Vector<T>::size(); };
  std::size_t capacity() const { return Vector<T>::capacity(); };
  void Push(T elem) { Vector<T>::PushBack(elem); };
  T Pop() {
    T popInt = Vector<T>::operator[]((int)this->size() - 1);
    Vector<T>::PopBack();
    return popInt;
  };
  bool IsEmpty() const { return this->size() == 0; };
};

#endif  // _STACK_H_
