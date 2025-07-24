#pragma once
#include <string>
#include <iostream>

class Car {
public:
	virtual std::string getCarTypeName() = 0;
	virtual void printCarType() = 0;
	virtual ~Car() = default;
};