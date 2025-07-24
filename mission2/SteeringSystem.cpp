#include "SteeringSystem.h"

class BoschSteeringSystem : public SteeringSystem {
private:
	std::string steeringSystemType = "BOSCH";
public:
	std::string getSteeringSystemTypeName() override
	{
		return steeringSystemType;
	}
	void printSteeringSystemType() override
	{
		std::cout << "SteeringSystem : Bosch\n";
	}
};

class MobisSteeringSystem : public SteeringSystem {
private:
	std::string steeringSystemType = "MOBIS";
public:
	std::string getSteeringSystemTypeName() override
	{
		return steeringSystemType;
	}
	void printSteeringSystemType() override
	{
		std::cout << "SteeringSystem : Mobis\n";
	}
};