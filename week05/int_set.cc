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
  assert((index >= 0 && index < size_) && "Out of bound");
  return elements_[index];
}

// 중복, 크기 확인 후 추가
// ForAll에 not_equal을 인자로 넘겨서 value 포함 확인
// 포함이면 끝 아니면 size_와 capacity_ 비교
// grow()는 필요하면 하고 아니면 elements_에 value 추가
void IntSet::Add(int value) {
  bool is_not_duplicate_ = false;
  bool is_full = false;

  // value와 index 값을 비교 다르면 true 반환
  std::function<bool(int)> not_equal = [value](int index) {
    return value != index;
  };

  // capacity_가 4 큰 배열을 만들어 데이터를 옮긴 후 주소 바꾸기
  std::function<void()> grow = [this]() {
    capacity_ = capacity_ + 4;
    int* arr = new int[capacity_];
    for (int i = 0; i < size_; i++) {
      arr[i] = this->elements_[i];
    }
    delete[] elements_;
    this->elements_ = arr;
  };

  is_not_duplicate_ = this->ForAll(not_equal);
  if (is_not_duplicate_) {
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

// func 적용 후 compress()로 압축
void IntSet::Map(std::function<int(int)> func) {
  // 0부터 순회하면서 다시 new_size_ 위치에 옮겨 압축
  std::function<void()> compress = [this]() {
    bool is_duplicate_ = false;
    int new_size_ = 0;
    for (int i = 0; i < this->size_; i++) {
      for (int j = 0; j < new_size_; j++) {
        if (this->elements_[j] == this->elements_[i]) {
          is_duplicate_ = true;
          break;
        }
      }
      if (is_duplicate_) {
        is_duplicate_ = false;
      } else {
        this->elements_[new_size_] = this->elements_[i];
        new_size_++;
      }
    }
    this->size_ = new_size_;
  };
  for (int i = 0; i < this->size_; i++) {
    elements_[i] = func(elements_[i]);
  }
  compress();
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
