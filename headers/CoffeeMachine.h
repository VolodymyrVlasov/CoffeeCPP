#pragma once
#include <iostream>
#include "HumanInterface.h"

using namespace std;

class CoffeeMachine : public HumanInterface
{

private:
    int state;

public:
    void Run();
    void MakeWork();
    void MakeService();
    void Stop();
    void SetState(int newState);
    int GetState();
};
