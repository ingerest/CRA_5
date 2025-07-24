#include "Car.h"

class Sedan : public Car {
private:
	std::string carType = "Sedan";
public:
	std::string getCarTypeName() override
	{
		return carType;
	}
	void printCarType() override
	{
		std::cout << "Car Type : " << carType << "\n";
	}
};

class Suv : public Car {
private:
	std::string carType = "SUV";
public:
	std::string getCarTypeName() override
	{
		return carType;
	}
	void printCarType() override
	{
		std::cout << "Car Type : " << carType << "\n";
	}
};

class Truck : public Car {
private:
	std::string carType = "Truck";
public:
	std::string getCarTypeName() override
	{
		return carType;
	}
	void printCarType() override
	{
		std::cout << "Car Type : " << carType << "\n";
	}
};