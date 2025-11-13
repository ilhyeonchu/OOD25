#include "queue.h"

#include <cstddef>

#include "list.h"

Queue::Queue() {}

Queue::Queue(const Queue& queue) : List(queue) {}

void Queue::operator=(const Queue& queue) { List::operator=(queue); }

std::size_t Queue::size() const { return List::size(); }

void Queue::Add(int elem) { PushBack(elem); }

int Queue::Poll() {
  int returnInt = List::At(0);
  List::PopFront();
  return returnInt;
}

bool Queue::IsEmpty() const { return this->size() == 0; }
