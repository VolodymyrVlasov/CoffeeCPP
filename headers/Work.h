
#pragma once
#include "HumanInterface.h"

class Work : public HumanInterface
{
public:
    void Run();
    void MakeTea();
    void MakeEspresso();
    void MakeCapuchio();
    void MakeMachiatto();
    void MakeHotMilk();
    int AddSugar();
    void Stop();
};