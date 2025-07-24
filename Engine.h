#pragma once
#include <string>
#include <iostream>
#include "Car.h"

class Engine {
public:
	virtual std::string getEngineTypeName() = 0;
	virtual void printEngineType() = 0;
	virtual bool isCarInvalidCheck(std::string car) = 0;
	virtual ~Engine() = default;
};