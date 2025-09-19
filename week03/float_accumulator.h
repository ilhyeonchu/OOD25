#ifndef _FLOAT_ACCUMULATOR_H_
#define _FLOAT_ACCUMULATOR_H_

#include <assert.h>

namespace float_accumulator {
class Accumulator {
 public:
  explicit Accumulator(float acc);
  void Add(float num);
  void Sub(float num);
  void Mul(float num);
  void Div(float num);
  float acc() const;

 private:
  float acc_;
};
}  // namespace float_accumulator

#endif  //  _FLOAT_ACCUMULATOR_H_
