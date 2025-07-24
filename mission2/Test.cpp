#include "gmock/gmock.h"
#include "CarFactory.cpp"
#include "BrakeSystemFactory.cpp"
#include "EngineFactory.cpp"
#include "SteeringSystemFactory.cpp"

TEST(Group, CarFactoryInputUnknown)
{
	CarFactory carFactory;

	auto ret = carFactory.createCar(0);

	EXPECT_EQ(nullptr, ret);
}

TEST(Group, CarFactoryInputSedanTypeName)
{
	CarFactory carFactory;

	auto ret = carFactory.createCar(1);
	std::string carName = ret->getCarTypeName();
	ret->printCarType();

	EXPECT_EQ("Sedan", carName);
}

TEST(Group, CarFactoryInputSuvTypeName)
{
	CarFactory carFactory;

	auto ret = carFactory.createCar(2);
	std::string carName = ret->getCarTypeName();
	ret->printCarType();

	EXPECT_EQ("SUV", carName);
}

TEST(Group, CarFactoryInputTruckTypeName)
{
	CarFactory carFactory;

	auto ret = carFactory.createCar(3);
	std::string carName = ret->getCarTypeName();
	ret->printCarType();

	EXPECT_EQ("Truck", carName);
}

TEST(Group, EngineFactoryInputUnknown)
{
	EngineFactory engineFactory;

	auto ret = engineFactory.createEngine(0);

	EXPECT_EQ(nullptr, ret);
}

TEST(Group, EngineFactoryInputGMTypeName)
{
	EngineFactory engineFactory;

	auto ret = engineFactory.createEngine(1);
	std::string name = ret->getEngineTypeName();
	ret->printEngineType();

	EXPECT_EQ("GM", name);
}

TEST(Group, EngineFactoryInputToyotaTypeName)
{
	EngineFactory engineFactory;

	auto ret = engineFactory.createEngine(2);
	std::string name = ret->getEngineTypeName();
	ret->printEngineType();

	EXPECT_EQ("TOYOTA", name);
}

TEST(Group, EngineFactoryInputWiaTypeName)
{
	EngineFactory engineFactory;

	auto ret = engineFactory.createEngine(3);
	std::string name = ret->getEngineTypeName();
	ret->printEngineType();

	EXPECT_EQ("WIA", name);
}


TEST(Group, EngineFactoryInputGMInvalidCarCheck)
{
	EngineFactory engineFactory;

	auto engine = engineFactory.createEngine(1);
	std::string car = "Sedan";
	bool ret = engine->isCarInvalidCheck(car);
	EXPECT_EQ(true, ret);
}

TEST(Group, EngineFactoryInputToyotaInvalidCarCheck1)
{
	EngineFactory engineFactory;

	auto engine = engineFactory.createEngine(2);
	std::string car = "SUV";
	bool ret = engine->isCarInvalidCheck(car);
	EXPECT_EQ(false, ret);
}
TEST(Group, EngineFactoryInputToyotaInvalidCarCheck2)
{
	EngineFactory engineFactory;

	auto engine = engineFactory.createEngine(2);
	std::string car = "Sedan";
	bool ret = engine->isCarInvalidCheck(car);
	EXPECT_EQ(true, ret);
}

TEST(Group, EngineFactoryInputWiaInvalidCarCheck1)
{
	EngineFactory engineFactory;

	auto engine = engineFactory.createEngine(3);
	std::string car = "Truck";
	bool ret = engine->isCarInvalidCheck(car);
	EXPECT_EQ(false, ret);
}

TEST(Group, EngineFactoryInputWiaInvalidCarCheck2)
{
	EngineFactory engineFactory;

	auto engine = engineFactory.createEngine(3);
	std::string car = "Sedan";
	bool ret = engine->isCarInvalidCheck(car);
	EXPECT_EQ(true, ret);
}

TEST(Group, BrakeFactoryInputUnknown)
{
	BrakeSystemFactory brakeFactory;

	auto ret = brakeFactory.createBrakeSystem(0);

	EXPECT_EQ(nullptr, ret);
}

TEST(Group, BrakeFactoryInputMandoTypeName)
{
	BrakeSystemFactory brakeFactory;

	auto ret = brakeFactory.createBrakeSystem(1);
	std::string name = ret->getBrakeSystemTypeName();
	ret->printBrakeSystemType();

	EXPECT_EQ("MANDO", name);
}

TEST(Group, BrakeFactoryInputContinentalTypeName)
{
	BrakeSystemFactory brakeFactory;

	auto ret = brakeFactory.createBrakeSystem(2);
	std::string name = ret->getBrakeSystemTypeName();
	ret->printBrakeSystemType();

	EXPECT_EQ("CONTINENTAL", name);
}

TEST(Group, BrakeFactoryInputBoschTypeName)
{
	BrakeSystemFactory brakeFactory;

	auto ret = brakeFactory.createBrakeSystem(3);
	std::string name = ret->getBrakeSystemTypeName();
	ret->printBrakeSystemType();

	EXPECT_EQ("BOSCH", name);
}

TEST(Group, BrakeFactoryInputMandoInvalidCheck1)
{
	BrakeSystemFactory brakeFactory;

	auto brake = brakeFactory.createBrakeSystem(1);
	bool ret = brake->isCarInvalidCheck("Truck");

	EXPECT_EQ(false, ret);
}

TEST(Group, BrakeFactoryInputMandoInvalidCheck2)
{
	BrakeSystemFactory brakeFactory;

	auto brake = brakeFactory.createBrakeSystem(1);
	bool ret = brake->isCarInvalidCheck("Sedan");

	EXPECT_EQ(true, ret);
}

TEST(Group, BrakeFactoryInputMandoInvalidCheck3)
{
	BrakeSystemFactory brakeFactory;

	auto brake = brakeFactory.createBrakeSystem(1);
	bool ret = brake->isSteeringInvalidCheck("BOSCH");

	EXPECT_EQ(true, ret);
}

TEST(Group, BrakeFactoryInputContinentalInvalidCheck1)
{
	BrakeSystemFactory brakeFactory;

	auto brake = brakeFactory.createBrakeSystem(2);
	bool ret = brake->isCarInvalidCheck("Sedan");

	EXPECT_EQ(false, ret);
}

TEST(Group, BrakeFactoryInputContinentalInvalidCheck2)
{
	BrakeSystemFactory brakeFactory;

	auto brake = brakeFactory.createBrakeSystem(2);
	bool ret = brake->isCarInvalidCheck("Truck");

	EXPECT_EQ(true, ret);
}

TEST(Group, BrakeFactoryInputContinentalInvalidCheck3)
{
	BrakeSystemFactory brakeFactory;

	auto brake = brakeFactory.createBrakeSystem(2);
	bool ret = brake->isSteeringInvalidCheck("BOSCH");

	EXPECT_EQ(true, ret);
}



TEST(Group, BrakeFactoryInputBoschInvalidCheck1)
{
	BrakeSystemFactory brakeFactory;

	auto brake = brakeFactory.createBrakeSystem(3);
	bool ret = brake->isCarInvalidCheck("Sedan");

	EXPECT_EQ(true, ret);
}

TEST(Group, BrakeFactoryInputBoschInvalidCheck2)
{
	BrakeSystemFactory brakeFactory;

	auto brake = brakeFactory.createBrakeSystem(3);
	bool ret = brake->isSteeringInvalidCheck("BOSCH");

	EXPECT_EQ(true, ret);
}

TEST(Group, BrakeFactoryInputBoschInvalidCheck3s)
{
	BrakeSystemFactory brakeFactory;

	auto brake = brakeFactory.createBrakeSystem(3);
	bool ret = brake->isSteeringInvalidCheck("MOBIS");

	EXPECT_EQ(false, ret);
}

TEST(Group, SteeringFactoryInputUnknown)
{
	SteeringSystemFactory steeringFactory;

	auto ret = steeringFactory.createSteeringSystem(0);

	EXPECT_EQ(nullptr, ret);
}


TEST(Group, SteeringFactoryInputBoschTypeName)
{
	SteeringSystemFactory steeringFactory;

	auto ret = steeringFactory.createSteeringSystem(1);
	std::string name = ret->getSteeringSystemTypeName();
	ret->printSteeringSystemType();

	EXPECT_EQ("BOSCH", name);
}

TEST(Group, SteeringFactoryInputMobisTypeName)
{
	SteeringSystemFactory steeringFactory;

	auto ret = steeringFactory.createSteeringSystem(2);
	std::string name = ret->getSteeringSystemTypeName();
	ret->printSteeringSystemType();

	EXPECT_EQ("MOBIS", name);
}
