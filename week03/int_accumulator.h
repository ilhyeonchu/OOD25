#ifndef _INT_ACCUMULATOR_H_
#define _INT_ACCUMULATOR_H_

#include <assert.h>

namespace int_accumulator {
class Accumulator {
 public:
  explicit Accumulator(int acc);
  void Add(int num);
  void Sub(int num);
  void Mul(int num);
  void Div(int num);
  int acc() const;

 private:
  int acc_;
};
}  // namespace int_accumulator

#endif  //  _INT_ACCUMULATOR_H_
