#include "car.h"

#include "door.h"
#include "part.h"
#include "roof.h"
#include "wheel.h"

Car::Car(const Car& car) : color_(car.color_) {
  if (car.door_ != nullptr) {
    this->door_ = new Door(car.door_->factory_name());
  } else {
    this->door_ = nullptr;
  }
  if (car.wheel_ != nullptr) {
    this->wheel_ = new Wheel(car.wheel_->factory_name());
  } else {
    this->wheel_ = nullptr;
  }
  if (car.roof_ != nullptr) {
    this->roof_ = new Roof(car.roof_->factory_name());
  } else {
    this->roof_ = nullptr;
  }
}

Car::Car(Part* door, Part* wheel, Part* roof, std::string color)
    : door_(door), wheel_(wheel), roof_(roof), color_(color) {}

Car& Car::operator=(const Car& car) {
  if (this == &car) {
    return *this;
  }
  delete door_;
  delete wheel_;
  delete roof_;
  if (car.door_ != nullptr) {
    this->door_ = new Door(car.door_->factory_name());
  } else {
    this->door_ = nullptr;
  }
  if (car.wheel_ != nullptr) {
    this->wheel_ = new Wheel(car.wheel_->factory_name());
  } else {
    this->wheel_ = nullptr;
  }
  if (car.roof_ != nullptr) {
    this->roof_ = new Roof(car.roof_->factory_name());
  } else {
    this->roof_ = nullptr;
  }
  this->color_ = car.color_;
  return *this;
}

Car::~Car() {
  delete door_;
  delete wheel_;
  delete roof_;
}

std::string Car::GetSpec() const {
  std::string spec = "Car(";
  if (door_ != nullptr) {
    spec += door_->GetInfo() + ",";
  }

  if (wheel_ != nullptr) {
    spec += wheel_->GetInfo() + ",";
  }

  if (roof_ != nullptr) {
    spec += roof_->GetInfo() + ",";
  }
  spec += color_ + ")";
  return spec;
}
