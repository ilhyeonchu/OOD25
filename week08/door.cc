#include "door.h"

#include <string>

#include "part.h"

Door::Door(std::string factory_name) : Part(factory_name) {}
std::string Door::GetInfo() const {
  return "[" + factory_name() + "]" + "Door";
}
