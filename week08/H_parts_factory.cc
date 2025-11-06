#include "H_parts_factory.h"

#include "door.h"
#include "part.h"
#include "roof.h"
#include "wheel.h"

HPartsFactory::HPartsFactory() {}

HPartsFactory* HPartsFactory::GetInstance() {
  static HPartsFactory instance_;
  return &instance_;
}

Part* HPartsFactory::CreateDoor() const { return new Door("H"); }

Part* HPartsFactory::CreateWheel() const { return new Wheel("H"); }

Part* HPartsFactory::CreateRoof() const { return new Roof("H"); }
