#include "empty_container_exception.h"

#include <stdexcept>
#include <string>

EmptyContainerException::EmptyContainerException(const char* what)
    : std::runtime_error("This " + std::string(what) + " is empty") {}
