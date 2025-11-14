#include "list.h"

#include <cassert>
#include <cstddef>

List::List() : size_(0), head(nullptr) {}

List::List(const List& list) : size_(list.size_), head(nullptr) {
  if (list.IsEmpty()) {
    return;
  }
  Elem* currentElem = this->head;
  Elem* nextElem = list.head->next;

  while (nextElem != nullptr) {
    currentElem->next = new Elem{nextElem->value, nullptr};
    currentElem = nextElem;
    nextElem = nextElem->next;
  }
}

List::~List() {
  // if (this->head == nullptr) {
  //   return;
  // }
  // Elem* currentElem = this->head;
  // Elem* nextElem = currentElem->next;
  // while (nextElem != nullptr) {
  //   delete currentElem;
  //   currentElem = nextElem;
  //   nextElem = nextElem->next;
  // }
  // delete currentElem;
  while (this->size() != 0) {
    this->PopFront();
  }
}

void List::operator=(const List& list) {
  Elem* currentElem = nullptr;
  Elem* nextElem = nullptr;
  while (this->head != nullptr) {
    this->PopFront();
  }

  if (list.IsEmpty()) {
    return;
  }

  this->head = list.head;
  currentElem = this->head;
  nextElem = list.head->next;

  while (nextElem != nullptr) {
    currentElem->next = new Elem{nextElem->value, nullptr};
    currentElem = nextElem;
    nextElem = nextElem->next;
  }
}

std::size_t List::size() const { return this->size_; }

void List::PushBack(int elem) {
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
}

void List::PushFront(int elem) {
  Elem* newElem = new Elem{elem, this->head};
  this->head = newElem;
  this->size_++;
}

void List::PopBack() {
  assert(!this->IsEmpty() && "Out of Bound");
  Elem* previousElem = this->head;
  Elem* currentElem = previousElem->next;

  while (currentElem != nullptr) {
    previousElem = currentElem;
    currentElem = currentElem->next;
  }

  delete previousElem;
  this->size_--;
}

void List::PopFront() {
  assert(!this->IsEmpty() && "Out of Bound");
  Elem* nextElem = this->head->next;
  delete this->head;
  this->head = nextElem;
  this->size_--;
}

int& List::At(int index) {
  assert((0 <= index && index < this->size_) && "Out of Bound");
  Elem* indexElem = this->head;

  for (int i = 0; i < index; i++) {
    indexElem = indexElem->next;
  }
  return indexElem->value;
}

bool List::IsEmpty() const { return this->size() == 0; }
