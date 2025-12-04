#include <stdio.h>

#include <iostream>
#include <limits>
#include <stdexcept>

#include "divide_by_zero_exception.h"
#include "empty_container_exception.h"
#include "list.h"
#include "safe_int.h"
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

  vector1.PopBack();
}
/*
void SafeIntExample() {
  const int kMax = std::numeric_limits<int>::max();
  const int kMin = std::numeric_limits<int>::min();

  SafeInt add_op1(100);
  SafeInt add_op2(50);
  SafeInt result = add_op1 + add_op2;
  std::cout << result.value() << std::endl;

  SafeInt sub_op1(kMin);
  SafeInt sub_op2(100);
  try {
    result = sub_op1 - sub_op2;
  } catch (std::overflow_error& e) {
    std::cout << e.what() << std::endl;
  }

  SafeInt div_op1(200);
  SafeInt div_op2(0);
  try {
    result = div_op1 / div_op2;
  } catch (DivideByZeroException& e) {
    std::cout << e.what() << std::endl;
  }
}
*/

int main() {
  // vectorTest1();
  // SafeIntExample();
}
