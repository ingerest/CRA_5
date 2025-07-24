#include "Engine.cpp"


class EngineFactory {
public:
	EngineFactory() {}

	std::unique_ptr<Engine> createEngine(int answer) {

		switch (answer)
		{
		case 1:
			return std::make_unique<GmEngine>();
		case 2:
			return std::make_unique<ToyotaEngine>();
		case 3:
			return std::make_unique<WiaEngine>();
		default:
			break;
		}

		return nullptr;
	}
};