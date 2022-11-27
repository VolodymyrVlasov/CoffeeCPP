#pragma once
#include <iostream>

using namespace std;

class HumanInterface
{
public:
    int ReadInput();
    void WriteMessage(string message);
    bool ConfirmDrink(string &drink);
};