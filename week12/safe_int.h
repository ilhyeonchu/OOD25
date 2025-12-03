#ifndef _SAFE_INT_H_
#define _SAFE_INT_H_

class SafeInt {
 public:
  explicit SafeInt(int val);
  SafeInt operator+(const SafeInt& operand) const;
  SafeInt operator-(const SafeInt& operand) const;
  SafeInt operator*(const SafeInt& operand) const;
  SafeInt operator/(const SafeInt& operand) const;
  SafeInt operator%(const SafeInt& operand) const;
  int value() const;

 private:
  int value_;
};

#endif  // _SAFE_INT_H_
