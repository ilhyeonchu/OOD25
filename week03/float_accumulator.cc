#include "float_accumulator.h"

#include <assert.h>

namespace float_accumulator {
Accumulator::Accumulator(float acc) : acc_(acc) {}

void Accumulator::Add(float num) { acc_ = acc_ + num; }

void Accumulator::Sub(float num) { acc_ = acc_ - num; }

void Accumulator::Mul(float num) { acc_ = acc_ * num; }

void Accumulator::Div(float num) {
  assert(num != 0 && "Divide by Zero");
  acc_ = acc_ / num;
}

float Accumulator::acc() const { return acc_; }
}  // namespace float_accumulator
