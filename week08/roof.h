#ifndef _ROOF_H
#define _ROOF_H

#include "part.h"

class Roof : public Part {
 public:
  explicit Roof(std::string factory_name);
  std::string GetInfo() const override;
};

#endif  // _ROOF_H
