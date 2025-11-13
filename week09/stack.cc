#include "stack.h"

#include <cassert>
#include <cstddef>

#include "vector.h"

Stack::Stack(std::size_t capacity) : Vector(capacity) {}

Stack::Stack(const Stack& stack) : Vector(stack) {}

void Stack::operator=(const Stack& stack) { Vector::operator=(stack); }

std::size_t Stack::size() const { return Vector::size(); }

std::size_t Stack::capacity() const { return Vector::capacity(); }

void Stack::Push(int elem) { PushBack(elem); }

int Stack::Pop() {
  assert(!IsEmpty() && "Out of Bound");
  int popInt = operator[](size() - 1);
  PopBack();
  return popInt;
}

bool Stack::IsEmpty() const { return !this->size(); }
