#include "CoffeeMachine.h"
#include "./services/service.h"
#include "./services/work.h"

void CoffeeMachine::Run()
{
    this->WriteMessage("Select work type:\n\t1 - Service\n\t2 - Work\n\t3 - Turn off >");
    int value = this->ReadInput();

    switch (value)
    {
    case 1:
        this->MakeService();
        break;
    case 2:
        this->MakeWork();
        break;
    case 3:
        this->Stop();
        break;
    default:
        cout << "Please, make correct choice!" << endl;
        this->Run();
    }
}

void CoffeeMachine::MakeService()
{
    Service service;
    service.Run();
}

void CoffeeMachine::MakeWork()
{
    Work work;
    work.Run();
}

void CoffeeMachine::Stop()
{
   this->WriteMessage("Bye bye");
}