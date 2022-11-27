
#pragma once
#include "HumanInterface.h"

class Service : public HumanInterface
{
public:
    void Run();
    void AddMaterial(int type);
    void CollectCash();
    void PrintReport();
    void Stop();
};
