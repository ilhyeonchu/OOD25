#ifndef _LIST_H_
#define _LIST_H_

#include <cassert>
#include <cstddef>
#include <iostream>
#include <iterator>

template <typename T>
class List {
 public:
  List() : head(nullptr) {};

  List(const List& list) : size_(list.size_), head(nullptr) {
    if (list.IsEmpty()) {
      return;
    }
    head = new Elem{list.head->value, nullptr};
    Elem* currentElem = this->head;
    Elem* nextElem = list.head->next;

    while (nextElem != nullptr) {
      currentElem->next = new Elem{nextElem->value, nullptr};
      currentElem = nextElem;
      nextElem = nextElem->next;
    }
  };

  virtual ~List() {
    while (this->size() != 0) {
      this->PopFront();
    }
  };

  void operator=(const List& list) {
    if (this == &list) {
      return;
    }
    Elem* currentElem = nullptr;
    Elem* nextElem = nullptr;
    while (this->head != nullptr) {
      this->PopFront();
    }

    if (list.IsEmpty()) {
      return;
    }

    this->head = new Elem{list.head->value, nullptr};
    currentElem = this->head;
    nextElem = list.head->next;

    while (nextElem != nullptr) {
      currentElem->next = new Elem{nextElem->value, nullptr};
      currentElem = nextElem;
      nextElem = nextElem->next;
    }
  };

  std::size_t size() const { return this->size_; };

  void PushBack(T elem) {
    Elem* newElem = new Elem{elem, nullptr};
    if (this->head == nullptr) {
      this->head = newElem;
      this->size_++;
      return;
    }

    Elem* currentElem = this->head;

    while (currentElem->next != nullptr) {
      currentElem = currentElem->next;
    }

    currentElem->next = newElem;
    this->size_++;
  };

  void PushFront(T elem) {
    Elem* newElem = new Elem{elem, this->head};
    this->head = newElem;
    this->size_++;
  };

  void PopBack() {
    assert(!this->IsEmpty() && "Out of Bound");
    Elem* previousElem = this->head;
    Elem* currentElem = this->head;

    while (currentElem->next != nullptr) {
      previousElem = currentElem;
      currentElem = currentElem->next;
    }

    delete currentElem;
    this->size_--;
  };

  void PopFront() {
    assert(!this->IsEmpty() && "Out of Bound");
    Elem* nextElem = this->head->next;
    delete this->head;
    this->head = nextElem;
    this->size_--;
  };

  T& At(int index) {
    assert((0 <= index && index < this->size_) && "Out of Bound");
    Elem* indexElem = this->head;

    for (int i = 0; i < index; i++) {
      indexElem = indexElem->next;
    }
    return indexElem->value;
  };

  bool IsEmpty() const { return this->size() == 0; };

 private:
  struct Elem {
    T value;
    Elem* next;
  };
  Elem* head;
  std::size_t size_ = 0;
};

#endif  // _LIST_H_
