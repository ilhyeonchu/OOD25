#include <stdio.h>

#include <iostream>

#include "list.h"
#include "queue.h"
#include "stack.h"
#include "vector.h"

template <typename T>
void pp_v(T struc, int num) {
  std::cout << "capacity : " << struc.capacity() << std::endl;
  std::cout << "size : " << struc.size() << std::endl;
  std::cout << "elements : " << std::endl;
  for (int i = 0; i < struc.size(); i++) {
    std::cout << struc[i] << ", ";
  }
}

void vectorTest1() {
  Vector<float> vector1 = Vector<float>(3);
  pp_v(vector1, 0);
}

int main() { vectorTest1(); }
