#include <gtest/gtest.h>

#include "H_parts_factory.h"
#include "K_parts_factory.h"
#include "car.h"
#include "car_builder.h"
#include "car_parts_factory.h"
#include "door.h"
#include "part.h"
#include "roof.h"
#include "wheel.h"

class FactoryTest : public ::testing::Test {
 public:
  const KPartsFactory* kFactory = KPartsFactory::GetInstance();
  const HPartsFactory* hFactory = HPartsFactory::GetInstance();
  CarBuilder kBuilder = CarBuilder(kFactory);
  CarBuilder hBuilder = CarBuilder(hFactory);

 protected:
  FactoryTest() {}
  void SetUp() override {}
  void TearDown() override {}
};

TEST_F(FactoryTest, BuildKCar1) {
  Car* kCar = kBuilder.Build();

  EXPECT_EQ(kCar->GetSpec(), "Car(blue)");
  delete kCar;
}

TEST_F(FactoryTest, BuildKCar2) {
  kBuilder.CreateDoor().CreateRoof().SetColor("red");
  Car* kCar = kBuilder.Build();

  EXPECT_EQ(kCar->GetSpec(), "Car([K]Door,[K]Roof,red)");
  delete kCar;
}

TEST_F(FactoryTest, BuildKCar3) {
  kBuilder.CreateDoor().CreateWheel().CreateRoof().SetColor("red");
  ASSERT_DEATH(kBuilder.CreateDoor(), "Duplicated Parts retain:Door");
  Car* kCar = kBuilder.Build();
  delete kCar;
}

TEST_F(FactoryTest, BuildKCar4) {
  kBuilder.CreateDoor().CreateWheel().CreateRoof().SetColor("red");
  Car* kCar = kBuilder.Build();

  EXPECT_EQ(kCar->GetSpec(), "Car([K]Door,[K]Wheel,[K]Roof,red)");
  delete kCar;
}

TEST_F(FactoryTest, BuildKCar5) {
  kBuilder.CreateDoor().CreateWheel().CreateRoof().SetColor("red");
  Car* kCar = kBuilder.Build();
  Car* kCar2 = new Car(*kCar);

  EXPECT_EQ(kCar->GetSpec(), "Car([K]Door,[K]Wheel,[K]Roof,red)");
  EXPECT_EQ(kCar2->GetSpec(), "Car([K]Door,[K]Wheel,[K]Roof,red)");
  delete kCar;
  delete kCar2;
}

TEST_F(FactoryTest, BuildKCar6) {
  Car* kCar1 = kBuilder.Build();
  kBuilder.CreateDoor().CreateWheel().CreateRoof().SetColor("red");
  Car* kCar2 = kBuilder.Build();
  Car car = *kCar2;
  EXPECT_EQ(kCar1->GetSpec(), "Car(blue)");
  EXPECT_EQ(kCar2->GetSpec(), "Car([K]Door,[K]Wheel,[K]Roof,red)");
  EXPECT_EQ(car.GetSpec(), "Car([K]Door,[K]Wheel,[K]Roof,red)");
  car = *kCar1;
  EXPECT_EQ(car.GetSpec(), "Car(blue)");

  delete kCar1;
  delete kCar2;
}

TEST_F(FactoryTest, KHSwap) {
  kBuilder.CreateDoor();
  Car* kCar = kBuilder.Build();
  hBuilder.CreateDoor().CreateWheel().CreateRoof().SetColor("red");
  Car* hCar = hBuilder.Build();
  Car car = *hCar;
  EXPECT_EQ(kCar->GetSpec(), "Car([K]Door,blue)");
  EXPECT_EQ(hCar->GetSpec(), "Car([H]Door,[H]Wheel,[H]Roof,red)");
  EXPECT_EQ(car.GetSpec(), "Car([H]Door,[H]Wheel,[H]Roof,red)");
  car = *kCar;
  EXPECT_EQ(car.GetSpec(), "Car([K]Door,blue)");

  delete kCar;
  delete hCar;
}

TEST_F(FactoryTest, BuildHCar1) {
  Car* hCar = hBuilder.Build();

  EXPECT_EQ(hCar->GetSpec(), "Car(blue)");
  delete hCar;
}

TEST_F(FactoryTest, BuildHCar2) {
  hBuilder.CreateDoor().CreateRoof().SetColor("red");
  Car* hCar = hBuilder.Build();

  EXPECT_EQ(hCar->GetSpec(), "Car([H]Door,[H]Roof,red)");
  delete hCar;
}

TEST_F(FactoryTest, BuildHCar3) {
  hBuilder.CreateDoor().CreateWheel().CreateRoof().SetColor("red");
  ASSERT_DEATH(hBuilder.CreateDoor(), "Duplicated Parts retain:Door");
  Car* hCar = hBuilder.Build();
  delete hCar;
}

TEST_F(FactoryTest, BuildHCar4) {
  hBuilder.CreateDoor().CreateWheel().CreateRoof().SetColor("red");
  Car* hCar = hBuilder.Build();

  EXPECT_EQ(hCar->GetSpec(), "Car([H]Door,[H]Wheel,[H]Roof,red)");
  delete hCar;
}

TEST_F(FactoryTest, BuildHCar5) {
  hBuilder.CreateDoor().CreateWheel().CreateRoof().SetColor("red");
  Car* hCar = hBuilder.Build();
  Car* hCar2 = new Car(*hCar);

  EXPECT_EQ(hCar->GetSpec(), "Car([H]Door,[H]Wheel,[H]Roof,red)");
  EXPECT_EQ(hCar2->GetSpec(), "Car([H]Door,[H]Wheel,[H]Roof,red)");
  delete hCar;
  delete hCar2;
}
