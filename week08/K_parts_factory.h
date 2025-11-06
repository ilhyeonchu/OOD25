#ifndef _K_PARTS_FACTORY_H
#define _K_PARTS_FACTORY_H

#include "car_parts_factory.h"
#include "part.h"

class KPartsFactory : public CarPartsFactory {
 public:
  static KPartsFactory* GetInstance();
  Part* CreateDoor() const override;
  Part* CreateWheel() const override;
  Part* CreateRoof() const override;

 private:
  KPartsFactory();
  static KPartsFactory* instance_;
};

#endif  // _K_PARTS_FACTORY_H
