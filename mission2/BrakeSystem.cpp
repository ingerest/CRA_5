#include "BrakeSystem.h"

class MandoBrakeSystem : public BrakeSystem {
private:
	std::string brakeType = "MANDO";
public:
	std::string getBrakeSystemTypeName() override
	{
		return brakeType;
	}
	void printBrakeSystemType() override
	{
		std::cout << "Brake System : Mando\n";
	}
	bool isCarInvalidCheck(std::string car) override
	{
		if (car == "Truck")
		{
			return false;
		}
		return true;
	}
	bool isSteeringInvalidCheck(std::string steeringSystem) override
	{
		return true;
	}
};

class ContinentalBrakeSystem :public BrakeSystem {
private:
	std::string brakeType = "CONTINENTAL";
public:
	std::string getBrakeSystemTypeName() override
	{
		return brakeType;
	}
	void printBrakeSystemType() override
	{
		std::cout << "Brake System : Continental\n";
	}
	bool isCarInvalidCheck(std::string car) override
	{
		if (car == "Sedan")
		{
			return false;
		}
		return true;
	}
	bool isSteeringInvalidCheck(std::string steeringSystem) override
	{
		return true;
	}
};

class BoschBrakeSystem : public BrakeSystem {
private:
	std::string brakeType = "BOSCH";
public:
	std::string getBrakeSystemTypeName() override
	{
		return brakeType;
	}
	void printBrakeSystemType() override
	{
		std::cout << "Brake System : Bosch\n";
	}
	bool isCarInvalidCheck(std::string car) override
	{
		return true;
	}
	bool isSteeringInvalidCheck(std::string steeringSystem) override
	{
		if (steeringSystem != "BOSCH")
		{
			return false;
		}
		return true;
	}
};