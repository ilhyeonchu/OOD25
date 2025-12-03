#include "safe_int.h"

#include <limits>
#include <stdexcept>
#include <string>

#include "divide_by_zero_exception.h"

SafeInt::SafeInt(int val) : value_(val) {}

SafeInt SafeInt::operator+(const SafeInt& operand) const {
  long long result =
      static_cast<long long>(this->value_) + static_cast<long long>(operand.value_);
  if (result > std::numeric_limits<int>::max() ||
      result < std::numeric_limits<int>::min()) {
    throw std::overflow_error(
        "Integer overflow occurs in " + std::to_string(this->value_) + " + " +
        std::to_string(operand.value_));
  }
  return SafeInt(static_cast<int>(result));
}

SafeInt SafeInt::operator-(const SafeInt& operand) const {
  long long result =
      static_cast<long long>(this->value_) - static_cast<long long>(operand.value_);
  if (result > std::numeric_limits<int>::max() ||
      result < std::numeric_limits<int>::min()) {
    throw std::overflow_error(
        "Integer overflow occurs in " + std::to_string(this->value_) + " - " +
        std::to_string(operand.value_));
  }
  return SafeInt(static_cast<int>(result));
}

SafeInt SafeInt::operator*(const SafeInt& operand) const {
  long long result =
      static_cast<long long>(this->value_) * static_cast<long long>(operand.value_);
  if (result > std::numeric_limits<int>::max() ||
      result < std::numeric_limits<int>::min()) {
    throw std::overflow_error(
        "Integer overflow occurs in " + std::to_string(this->value_) + " * " +
        std::to_string(operand.value_));
  }
  return SafeInt(static_cast<int>(result));
}

SafeInt SafeInt::operator/(const SafeInt& operand) const {
  if (operand.value_ == 0) {
    std::string message = std::to_string(this->value_) + " / " +
                          std::to_string(operand.value_);
    throw DivideByZeroException(message.c_str());
  }
  return SafeInt(this->value_ / operand.value_);
}

SafeInt SafeInt::operator%(const SafeInt& operand) const {
  if (operand.value_ == 0) {
    std::string message = std::to_string(this->value_) + " % " +
                          std::to_string(operand.value_);
    throw DivideByZeroException(message.c_str());
  }
  return SafeInt(this->value_ % operand.value_);
}

int SafeInt::value() const { return this->value_; }
