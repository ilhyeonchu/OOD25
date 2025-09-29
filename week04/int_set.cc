#include "int_set.h"

#include <cassert>
#include <functional>

IntSet::IntSet(int capacity)
    : capacity_(capacity), size_(0), elements_(new int[capacity]) {}

IntSet::IntSet(const IntSet& int_set)
    : capacity_(int_set.capacity_),
      size_(int_set.size_),
      elements_(new int[int_set.capacity_]) {
  for (int i = 0; i < this->capacity_; i++) {
    elements_[i] = int_set.elements_[i];
  }
}

int IntSet::capacity() const { return this->capacity_; }

int IntSet::size() const { return this->size_; }

int* IntSet::elements() const { return this->elements_; }

void IntSet::Add(int value) {
  bool is_duplicate_ = false;
  for (int i = 0; i < this->size_; i++) {
    if (elements_[i] == value) {
      is_duplicate_ = true;
      break;
    }
  }
  if (!is_duplicate_) {
    assert(size_ < capacity_ && "Exceeded capacity");
    elements_[this->size_] = value;
    this->size_ = this->size_ + 1;
  }
}

void IntSet::Add(const IntSet& int_set) {
  for (int i = 0; i < int_set.size_; i++) {
    this->Add(int_set.elements_[i]);
  }
}

void IntSet::Map(std::function<int(int)> func) {
  for (int i = 0; i < this->size_; i++) {
    elements_[i] = func(elements_[i]);
  }
}

bool IntSet::ForAll(std::function<bool(int)> func) {
  bool check = true;
  for (int i = 0; i < this->size_; i++) {
    check = func(elements_[i]);
    if (!check) {
      return check;
    }
  }
  return check;
}
