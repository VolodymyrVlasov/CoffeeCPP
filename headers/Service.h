
#pragma once
#include "HumanInterface.h"

class Service : public HumanInterface
{
public:
    void Run();
    void AddCoffee(int amount);
    void AddTea(int amount);
    void AddWater(int amount);
    void AddSugar(int amount);
    void GetCash(int amount);
    void PrintReport();
    void Stop();
};
