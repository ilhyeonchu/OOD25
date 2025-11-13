#ifndef _LIST_H_
#define _LIST_H_

#include <cstddef>
#include <iostream>

class List {
 public:
  List();
  List(const List& list);
  virtual ~List();
  void operator=(const List& list);
  std::size_t size() const;
  void PushBack(int elem);
  void PushFront(int elem);
  void PopBack();
  void PopFront();
  int& At(int index);
  bool IsEmpty() const;

 private:
  struct Elem {
    int value;
    Elem* next;
  };
  Elem* head;
  std::size_t size_;
};

#endif  // _LIST_H_
