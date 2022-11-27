#include "../headers/HumanInterface.h"

int HumanInterface::ReadInput()
{
    int value;
    cin >> value;
    return value;
}

void HumanInterface::WriteMessage(string message)
{
    cout << message << endl;
}

bool HumanInterface::ConfirmDrink (string &drink)
{
    this->WriteMessage("Your drink is");
}
