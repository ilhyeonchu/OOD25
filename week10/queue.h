#ifndef _QUEUE_H_
#define _QUEUE_H_

#include <cstddef>

#include "list.h"

template <typename T>
class Queue : private List<T> {
 public:
  Queue() {};
  Queue(const Queue& queue) : List<T>(queue) {};
  void operator=(const Queue& queue) { List<T>::operator=(queue); };
  std::size_t size() const { return List<T>::size(); };
  void Add(T elem) { List<T>::PushBack(elem); };
  T Poll() {
    T returnInt = List<T>::At(0);
    List<T>::PopFront();
    return returnInt;
  };
  bool IsEmpty() const { return this->size() == 0; };
};

#endif  // _QUEUE_H_
