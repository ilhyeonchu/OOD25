#include "int_accumulator.h"

#include <assert.h>

namespace int_accumulator {
Accumulator::Accumulator(int acc) : acc_(acc) {}

void Accumulator::Add(int num) { acc_ = acc_ + num; }

void Accumulator::Sub(int num) { acc_ = acc_ - num; }

void Accumulator::Mul(int num) { acc_ = acc_ * num; }

void Accumulator::Div(int num) {
  assert(num != 0 && "Divide by Zero");
  acc_ = acc_ / num;
}

int Accumulator::acc() const { return acc_; }

}  // namespace int_accumulator
