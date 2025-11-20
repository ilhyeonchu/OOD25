#ifndef _VECTOR_H_
#define _VECTOR_H_

#include <cassert>
#include <cstddef>
#include <iostream>

template <typename T>
class Vector {
 public:
  explicit Vector(std::size_t capacity) : capacity_(capacity) {
    this->elements_ = new T[this->capacity()];
  }

  Vector(const Vector& vector)
      : capacity_(vector.capacity()), size_(vector.size()) {
    this->elements_ = new T[this->capacity_];
    for (int i = 0; i < vector.size(); i++) {
      this->elements_[i] = vector.elements_[i];
    }
  }
  virtual ~Vector() { delete[] this->elements_; };

  void operator=(const Vector& vector) {
    if (this == &vector) {
      return;
    }

    delete[] this->elements_;
    this->size_ = vector.size();
    this->capacity_ = vector.capacity();
    this->elements_ = new T[this->capacity_];

    for (int i = 0; i < vector.size(); i++) {
      this->elements_[i] = vector.elements_[i];
    }
  };

  T& operator[](const int index) {
    assert((0 <= index && index < this->size_) && "Out of Bound");
    return this->elements_[index];
  };

  std::size_t size() const { return this->size_; };

  std::size_t capacity() const { return this->capacity_; };

  void PushBack(T elem) {
    if (this->capacity_ <= this->size_) {
      this->capacity_ += 4;
      T* newElems = new T[this->capacity_];

      for (int i = 0; i < this->size_; i++) {
        newElems[i] = this->elements_[i];
      }

      delete[] elements_;
      this->elements_ = newElems;
    }

    this->elements_[this->size_] = elem;
    this->size_ += 1;
  };

  void PopBack() {
    assert(this->size_ != 0 && "Out of Bound");
    this->size_ -= 1;
  };

  bool IsEmpty() const { return this->size_ == 0; };

 private:
  T* elements_;
  std::size_t capacity_;
  std::size_t size_ = 0;
};

#endif  // _VECTOR_H_
