#include "vector.h"

#include <cassert>
#include <cstddef>

Vector::Vector(std::size_t capacity) : capacity_(capacity), size_(0) {
  this->elements_ = new int[this->capacity_];
}

Vector::Vector(const Vector& vector)
    : capacity_(vector.capacity()), size_(vector.size()) {
  this->elements_ = new int[this->capacity_];
  for (int i = 0; i < vector.size(); i++) {
    this->elements_[i] = vector.elements_[i];
  }
}

Vector::~Vector() { delete[] this->elements_; }

void Vector::operator=(const Vector& vector) {
  if (this == &vector) {
    return;
  }

  delete[] this->elements_;
  this->size_ = vector.size();
  this->capacity_ = vector.capacity();
  this->elements_ = new int[this->capacity_];

  for (int i = 0; i < vector.size(); i++) {
    this->elements_[i] = vector.elements_[i];
  }
}

int& Vector::operator[](const int index) {
  assert(index < this->size_ && "Out of Bound");

  return this->elements_[index];
}

std::size_t Vector::size() const { return this->size_; }

std::size_t Vector::capacity() const { return this->capacity_; }

void Vector::PushBack(int elem) {
  if (this->capacity_ <= this->size_) {
    this->capacity_ += 4;
    int* newElems = new int[this->capacity_];

    for (int i = 0; i < this->size_; i++) {
      newElems[i] = this->elements_[i];
    }

    delete[] elements_;
    this->elements_ = newElems;
  }

  this->elements_[this->size_] = elem;
  this->size_ += 1;
}

void Vector::PopBack() {
  assert(this->size_ != 0 && "Out of Bound");
  this->size_ -= 1;
  // this->elements_[size] = nullptr; 쓰레기값? 아니면 초기화?
}

bool Vector::IsEmpty() const { return !this->size_; }
