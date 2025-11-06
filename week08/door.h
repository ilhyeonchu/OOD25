#ifndef _DOOR_H
#define _DOOR_H

#include "part.h"

class Door : public Part {
 public:
  explicit Door(std::string factory_name);
  std::string GetInfo() const override;
};

#endif  // _DOOR_H
