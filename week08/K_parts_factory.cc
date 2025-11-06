#include "K_parts_factory.h"

#include "door.h"
#include "part.h"
#include "roof.h"
#include "wheel.h"

KPartsFactory::KPartsFactory() {}

KPartsFactory* KPartsFactory::GetInstance() {
  static KPartsFactory instance_;
  return &instance_;
}

Part* KPartsFactory::CreateDoor() const { return new Door("K"); }

Part* KPartsFactory::CreateWheel() const { return new Wheel("K"); }

Part* KPartsFactory::CreateRoof() const { return new Roof("K"); }
