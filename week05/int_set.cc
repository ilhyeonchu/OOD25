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

IntSet::~IntSet() { delete[] elements_; }

int IntSet::capacity() const { return this->capacity_; }

int IntSet::size() const { return this->size_; }

int* IntSet::elements() const { return this->elements_; }

int IntSet::operator[](int index) const {
  assert(index < size_ && "Out of bound");
  return this->elements_[index];
}

void IntSet::Add(int value) {
  bool is_duplicate_ = false;
  bool is_full = false;
  std::function<bool(int)> contain = [this, value](int index) {
    return value == this->elements_[index];
  };
  std::function<void()> grow = [this]() {
    capacity_ = capacity_ + 4;
    int* arr = new int[capacity_];
    for (int i = 0; i < size_; i++) {
      arr[i] = this->elements_[i];
    }
    delete[] elements_;
    this->elements_ = arr;
  };
  // for (int i = 0; i < this->size_; i++) {
  //   if (elements_[i] == value) {
  //     is_duplicate_ = true;
  //     break;
  //   }
  // }
  is_duplicate_ = this->ForAll(contain);
  if (!is_duplicate_) {
    // assert(size_ < capacity_ && "Exceeded capacity");
    if (size_ == capacity_) {
      grow();
    }
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
