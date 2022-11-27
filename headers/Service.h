
#pragma once
#include "HumanInterface.h"

class Service : public HumanInterface
{
public:
    void Run();
    void AddMaterial(int type);
    void CollectCash(int amount);
    void PrintReport();
    void Stop();
};
