#include <cstdint>
#include <iostream>
#include <ostream>

#include "int_set.h"

void print_size(const IntSet& intset) {
  std::cout << "size : " << intset.size() << std::endl;
}
void print_capacity(const IntSet& intset) {
  std::cout << "capacity : " << intset.capacity() << std::endl;
}
void print_elements(const IntSet& intset) {
  std::cout << "elements : {";
  for (int i = 0; i < intset.size(); i++) {
    if (i == 0) {
      std::cout << intset.elements()[i];
    } else {
      std::cout << ", " << intset.elements()[i];
    }
  }
  std::cout << " }" << std::endl;
}
void print_set(std::string msg, const IntSet& intset) {
  if (!msg.empty()) {
    std::cout << "== " << msg << " ==" << std::endl;
  }
  print_capacity(intset);
  print_size(intset);
  print_elements(intset);
}

int main() {
  IntSet int_set1 = IntSet(3);
  int_set1.Add(1);
  int_set1.Add(2);
  print_set("1) Make set(expect size = 2)", int_set1);

  return 0;
}
