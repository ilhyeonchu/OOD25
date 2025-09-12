#include "util.h"

#include <assert.h>

int Util::Add(int num1, int num2) { return num1 + num2; }

int Util::Sub(int num1, int num2) { return num1 - num2; }

int Util::Mul(int num1, int num2) { return num1 * num2; }

int Util::Div(int num1, int num2) {
  assert(num2 != 0 && "Divide by Zero");
  return num1 / num2;
}
