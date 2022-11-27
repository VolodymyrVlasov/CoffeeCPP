
#pragma once
#include "HumanInterface.h"

class Work : public HumanInterface
{
public:
    void Run();
    void MakeTea();
    void MakeCoffee();
    void AddSugar();
    void Stop();
};