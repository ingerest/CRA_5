#include <memory>
#include "Car.cpp"

class CarFactory {
public:
	CarFactory() { }

	std::unique_ptr<Car> createCar(int answer) {

		switch (answer)
		{
		case 1:
			return std::make_unique<Sedan>();
		case 2:
			return std::make_unique<Suv>();
		case 3:
			return std::make_unique<Truck>();
		default:
			break;
		}
		
		return nullptr;
	}
};