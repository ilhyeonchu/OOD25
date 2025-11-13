#ifndef _VECTOR_H_
#define _VECTOR_H_

#include <cstddef>
#include <iostream>

class Vector {
 public:
  explicit Vector(std::size_t capacity);
  Vector(const Vector& vector);
  virtual ~Vector();
  void operator=(const Vector& vector);
  int& operator[](const int index);
  std::size_t size() const;
  std::size_t capacity() const;
  void PushBack(int elem);
  void PopBack();
  bool IsEmpty() const;

 private:
  int* elements_;
  std::size_t capacity_;
  std::size_t size_;
};

#endif  // _VECTOR_H_
