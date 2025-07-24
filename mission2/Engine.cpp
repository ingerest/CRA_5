#include "Engine.h"

class GmEngine : public Engine {
private:
	std::string engineType = "GM";
public:
	std::string getEngineTypeName() override
	{
		return engineType;
	}
	void printEngineType() override
	{
		std::cout << "Engine : GM\n";
	}
	bool isCarInvalidCheck(std::string car) override
	{
		return true;
	}
};

class ToyotaEngine : public Engine {
private:
	std::string engineType = "TOYOTA";
public:
	std::string getEngineTypeName() override
	{
		return engineType;
	}
	void printEngineType() override
	{
		std::cout << "Engine : TOYOTA\n";
	}
	bool isCarInvalidCheck(std::string car) override
	{
		if (car == "SUV")
		{
			return false;
		}

		return true;
	}
};

class WiaEngine : public Engine {
private:
	std::string engineType = "WIA";
public:
	std::string getEngineTypeName() override
	{
		return engineType;
	}
	void printEngineType() override
	{
		std::cout << "Engine : WIA\n";
	}
	bool isCarInvalidCheck(std::string car) override
	{
		if (car == "Truck")
		{
			return false;
		}

		return true;
	}
};