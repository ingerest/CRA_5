#ifndef _DEBUG
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <map>
#include <string>
#include <iostream>
#include <stdexcept>
#include <cctype>
#include <Windows.h>
#include <cstdlib>

enum QuestionType
{
    CarType_Q,
    Engine_Q,
    BrakeSystem_Q,
    SteeringSystem_Q,
    Run_Test,
};

void cleanScreen();
void showMenu();
void showCarTypeMenu();
void showEngineMenu();
void showBreakSystemMenu();
void showSteeringSystemMenu();
void showRunTestMenu();

bool selectMenu(int answer);
bool selectCarType(int answer);
bool selectEngine(int answer);
bool selectbrakeSystem(int answer);
bool selectSteeringSystem(int answer);
bool selectRunTest(int answer);

void initalize();
void initSelect();
void initCarType();
void initEngine();
void initBreakSystem();
void initSteeringSystem();

bool isValidCheck();
bool isCarAndBrakeValidCheck();
bool isCarAndEngineValidCheck();
bool isBrakeAndSteeringValidCheck();

void runProducedCar();
void testProducedCar();

QuestionType getPrevStep();
void delay(int ms);

QuestionType currentStep;
std::map<int, std::string> selectMap = {};
std::map<int, std::string> carTypeMap = {};
std::map<int, std::string> engineMap = {};
std::map<int, std::string> brakeSystemMap = {};
std::map<int, std::string> steeringSystemMap = {};

template<typename K, typename V>
std::pair<K, V> getMaximumKey(const std::map<K, V>& map) {
    return *std::max_element(map.begin(), map.end(), [](std::pair<K, V> const& x, std::pair<K, V> const& y) {
        return x.first < y.first;
        });
}
template<typename K, typename V>
std::pair<K, V> getMinimumKey(const std::map<K, V>& map) {
    return *std::min_element(map.begin(), map.end(), [](std::pair<K, V> const& x, std::pair<K, V> const& y) {
        return x.first < y.first;
        });
}



void delay(int ms)
{
    Sleep(ms);
}

void initalize()
{
    initSelect();
    initCarType();
    initEngine();
    initBreakSystem();
    initSteeringSystem();

    currentStep = CarType_Q;
}

void initSelect()
{
    selectMap.insert({ CarType_Q, "" });
    selectMap.insert({ Engine_Q, "" });
    selectMap.insert({ BrakeSystem_Q, "" });
    selectMap.insert({ SteeringSystem_Q, "" });
}

void initCarType()
{
    carTypeMap.insert({ 1, "SEDAN" });
    carTypeMap.insert({ 2, "SUV" });
    carTypeMap.insert({ 3, "TRUCK" });
}

void initEngine()
{
    engineMap.insert({ 1, "GM" });
    engineMap.insert({ 2, "TOYOTA" });
    engineMap.insert({ 3, "WIA" });
}

void initBreakSystem()
{
    brakeSystemMap.insert({ 1, "MANDO" });
    brakeSystemMap.insert({ 2, "CONTINENTAL" });
    brakeSystemMap.insert({ 3, "BOSCH" });
}

void initSteeringSystem()
{
    steeringSystemMap.insert({ 1, "BOSCH" });
    steeringSystemMap.insert({ 2, "MOBIS" });
}

int main()
{
    std::string input;
    initalize();
    QuestionType prevStep;
    bool selectRet;
    int answer;
    while (1)
    {
        showMenu();

        std::cout << "INPUT > ";
        std::cin >> input;

        if (input == "exit")
        {
            printf("바이바이\n");
            break;
        }

        // 숫자로 된 대답인지 확인
        try
        {
            answer = std::stoi(input);
        }
        catch (const std::invalid_argument&)
        {
            printf("ERROR :: 숫자만 입력 가능\n");
            delay(800);
            continue;
        }

        // 처음 or 이전으로 돌아가기
        if (answer == 0)
        {
            prevStep = getPrevStep();

            if (currentStep != prevStep)
            {
                currentStep = prevStep;
                continue;
            }
        }

        selectRet = selectMenu(answer);

        if (selectRet == false)
        {
            delay(800);
        }
    }
}

QuestionType getPrevStep()
{
    switch (currentStep)
    {
    case CarType_Q:
        return CarType_Q;
    case Engine_Q:
        return CarType_Q;
    case BrakeSystem_Q:
        return Engine_Q;
    case SteeringSystem_Q:
        return BrakeSystem_Q;
    case Run_Test:
        return CarType_Q;
    default:
        break;
    }

    return CarType_Q;
}

void cleanScreen()
{
    std::system("cls");
}

void showMenu()
{
    if (currentStep == CarType_Q)
    {
        showCarTypeMenu();
    }
    else if (currentStep == Engine_Q)
    {
        showEngineMenu();
    }
    else if (currentStep == BrakeSystem_Q)
    {
        showBreakSystemMenu();
    }
    else if (currentStep == SteeringSystem_Q)
    {
        showSteeringSystemMenu();
    }
    else if (currentStep == Run_Test)
    {
        showRunTestMenu();
    }
    printf("===============================\n");
}

void showCarTypeMenu()
{
    cleanScreen();
    std::cout <<  "        ______________\n";
    std::cout << "       /|            | \n";
    std::cout << "  ____/_|_____________|____\n";
    std::cout << " |                      O  |\n";
    std::cout << " '-(@)----------------(@)--'\n";
    std::cout << "===============================\n";
    std::cout << "어떤 차량 타입을 선택할까요?\n";
    
    for (auto car : carTypeMap) {
        std::cout << car.first << ". " << car.second << "\n";
    }
}

void showEngineMenu()
{
    cleanScreen();
    std::cout << "어떤 엔진을 탑재할까요?\n";
    std::cout << "0. 뒤로가기\n";
    for (auto engine : engineMap) {
        std::cout << engine.first << ". " << engine.second << "\n";
    }
}

void showBreakSystemMenu()
{
    cleanScreen();
    std::cout << "어떤 제동장치를 선택할까요?\n";
    std::cout << "0. 뒤로가기\n";
    for (auto breakSystem : brakeSystemMap) {
        std::cout << breakSystem.first << ". " << breakSystem.second << "\n";
    }
}

void showSteeringSystemMenu()
{
    cleanScreen();
    std::cout << "어떤 조향장치를 선택할까요?\n";
    std::cout << "0. 뒤로가기\n";
    for (auto steeringSystem : steeringSystemMap) {
        std::cout << steeringSystem.first << ". " << steeringSystem.second << "\n";
    }
}

void showRunTestMenu()
{
    cleanScreen();
    std::cout << "멋진 차량이 완성되었습니다.\n";
    std::cout << "어떤 동작을 할까요?\n";
    std::cout << "0. 처음 화면으로 돌아가기\n";
    std::cout << "1. RUN\n";
    std::cout << "2. Test\n";
}

bool selectMenu(int answer)
{
    if (currentStep == CarType_Q)
    {
        return selectCarType(answer);
    }
    else if (currentStep == Engine_Q)
    {
        return selectEngine(answer);
    }
    else if (currentStep == BrakeSystem_Q)
    {
        return selectbrakeSystem(answer);
    }
    else if (currentStep == SteeringSystem_Q)
    {
        return selectSteeringSystem(answer);
    }
    else if (currentStep == Run_Test)
    {
        return selectRunTest(answer);
    }
}

bool selectCarType(int answer)
{
    int minRange = getMinimumKey(carTypeMap).first;
    int maxRange = getMaximumKey(carTypeMap).first;
    if (answer < minRange || answer > maxRange)
    {
        std::cout << "ERROR :: 차량 타입은 " << minRange << " ~ " << maxRange << " 범위만 선택 가능\n";
        return false;
    }

    selectMap[CarType_Q] = carTypeMap[answer];
    std::cout << "차량 타입으로 "<< selectMap[CarType_Q] << " 을 선택하셨습니다.\n";
    currentStep = Engine_Q;
    delay(800);
    return true;
}

bool selectEngine(int answer)
{
    int minRange = getMinimumKey(engineMap).first;
    int maxRange = getMaximumKey(engineMap).first;

    if (answer < minRange || answer > maxRange)
    {
        std::cout << "ERROR :: 엔진은 " << minRange << " ~ " << maxRange << " 범위만 선택 가능\n";
        return false;
    }

    selectMap[Engine_Q] = engineMap[answer];
    std::cout << selectMap[Engine_Q] << " 엔진을 선택하셨습니다.\n";
    currentStep = BrakeSystem_Q;
    delay(800);
    return true;
}

bool selectbrakeSystem(int answer)
{
    int minRange = getMinimumKey(brakeSystemMap).first;
    int maxRange = getMaximumKey(brakeSystemMap).first;

    if (answer < minRange || answer > maxRange)
    {
        std::cout << "ERROR :: 제동장치는 " << minRange << " ~ " << maxRange << " 범위만 선택 가능\n";
        return false;
    }

    selectMap[BrakeSystem_Q] = brakeSystemMap[answer];
    std::cout << selectMap[BrakeSystem_Q] << " 제동장치를 선택하셨습니다.\n";
    currentStep = SteeringSystem_Q;
    delay(800);
    return true;
}

bool selectSteeringSystem(int answer)
{
    int minRange = getMinimumKey(steeringSystemMap).first;
    int maxRange = getMaximumKey(steeringSystemMap).first;

    if (answer < minRange || answer > maxRange)
    {
        std::cout << "ERROR :: 조향장치는 " << minRange << " ~ " << maxRange << " 범위만 선택 가능\n";
        return false;
    }

    selectMap[SteeringSystem_Q] = steeringSystemMap[answer];
    std::cout << selectMap[SteeringSystem_Q] << " 조향장치를 선택하셨습니다.\n";
    currentStep = Run_Test;
    delay(800);
    return true;
}

bool selectRunTest(int answer)
{
    if (answer < 1 || answer > 2)
    {
        std::cout << "ERROR :: Run 또는 Test 중 하나를 선택 필요\n";
        return false;
    }

    if (answer == 1)
    {
        runProducedCar();
        delay(2000);
    }
    else if (answer == 2)
    {
        std::cout << "Test...\n";
        delay(1500);
        testProducedCar();
        delay(2000);
    }

    return true;
}

bool isValidCheck()
{
    if (isCarAndBrakeValidCheck() == false)
    {
        return false;
    }

    if (isCarAndEngineValidCheck() == false)
    {
        return false;
    }

    if (isBrakeAndSteeringValidCheck() == false)
    {
        return false;
    }

    return true;
}

bool isCarAndBrakeValidCheck()
{
    if (selectMap[CarType_Q] == "SEDAN" && selectMap[BrakeSystem_Q] == "CONTINENTAL")
    {
        return false;
    }
    else if (selectMap[CarType_Q] == "TRUCK" && selectMap[BrakeSystem_Q] == "MANDO")
    {
        return false;
    }

    return true;
}

bool isCarAndEngineValidCheck()
{
    if (selectMap[CarType_Q] == "SUV" && selectMap[Engine_Q] == "TOYOTA")
    {
        return false;
    }
    else if (selectMap[CarType_Q] == "TRUCK" && selectMap[Engine_Q] == "WIA")
    {
        return false;
    }
    
    return true;
}

bool isBrakeAndSteeringValidCheck()
{
    if (selectMap[BrakeSystem_Q] == "BOSCH" && selectMap[SteeringSystem_Q] != "BOSCH")
    {
        return false;
    }

    return true;
}

void runProducedCar()
{
    if (isValidCheck() == false)
    {
        std::cout << "자동차가 동작되지 않습니다\n";
        return;
    }
    
    std::cout << "Car Type : " << selectMap[CarType_Q] << "\n";
    std::cout << "Engine : " << selectMap[Engine_Q] << "\n";
    std::cout << "Brake System : " << selectMap[BrakeSystem_Q] << "\n";
    std::cout << "Steering System : " << selectMap[SteeringSystem_Q] << "\n";
    std::cout << "자동차가 동작됩니다.\n";
}

void testProducedCar()
{
    if (isCarAndBrakeValidCheck() == false)
    {
        std::cout << "자동차 부품 조합 테스트 결과 : FAIL\n";
        std::cout << selectMap[CarType_Q]  << "에는 " << selectMap[BrakeSystem_Q] << "제동장치 사용 불가\n";
        return;
    }

    if (isCarAndEngineValidCheck() == false)
    {
        std::cout << "자동차 부품 조합 테스트 결과 : FAIL\n";
        std::cout << selectMap[CarType_Q] << "에는 " << selectMap[Engine_Q] << "엔진 사용 불가\n";
        return;
    }

    if (isBrakeAndSteeringValidCheck() == false)
    {
        std::cout << "자동차 부품 조합 테스트 결과 : FAIL\n";
        std::cout << "Bosch제동장치에는 Bosch조향장치 이외 사용 불가\n";
        return;
    }

    std::cout << "자동차 부품 조합 테스트 결과 : PASS\n";
}
#endif