#include "divide_by_zero_exception.h"

#include <stdexcept>
#include <string>

DivideByZeroException::DivideByZeroException(const char* operation)
    : std::runtime_error("Divide-by-zero exception occurs in " +
                         std::string(operation)) {}
