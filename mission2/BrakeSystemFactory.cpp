#include "BrakeSystem.cpp"


class BrakeSystemFactory {
public:
	BrakeSystemFactory() {}

	std::unique_ptr<BrakeSystem> createBrakeSystem(int answer) {

		switch (answer)
		{
		case 1:
			return std::make_unique<MandoBrakeSystem>();
		case 2:
			return std::make_unique<ContinentalBrakeSystem>();
		case 3:
			return std::make_unique<BoschBrakeSystem>();
		default:
			break;
		}

		return nullptr;
	}
};