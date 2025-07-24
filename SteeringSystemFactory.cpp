#include "SteeringSystem.cpp"


class SteeringSystemFactory {
public:
	SteeringSystemFactory() {}

	std::unique_ptr<SteeringSystem> createSteeringSystem(int answer) {

		switch (answer)
		{
		case 1:
			return std::make_unique<BoschSteeringSystem>();
		case 2:
			return std::make_unique<MobisSteeringSystem>();
		default:
			break;
		}

		return nullptr;
	}
};