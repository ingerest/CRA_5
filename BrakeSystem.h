#pragma once
#include <string>
#include <iostream>
#include "Car.h"
#include "SteeringSystem.h"

class BrakeSystem {
public:
	virtual std::string getBrakeSystemTypeName() = 0;
	virtual void printBrakeSystemType() = 0;
	virtual bool isCarInvalidCheck(std::string car) = 0;
	virtual bool isSteeringInvalidCheck(std::string steeringSystem) = 0;
	virtual ~BrakeSystem() = default;
};