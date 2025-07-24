#pragma once
#include <string>
#include <iostream>
#include "BrakeSystem.h"

class SteeringSystem {
public:
	virtual std::string getSteeringSystemTypeName() = 0;
	virtual void printSteeringSystemType() = 0;
	virtual ~SteeringSystem() = default;
};