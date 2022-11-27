// #pragma once
#include "../headers/CoffeeMachine.h"
#include "../headers/Service.h"
#include "../headers/Work.h"

void CoffeeMachine::Run()
{
    this->WriteMessage("Select work type:\n\t1 - Service\n\t2 - Work\n\t0 - Turn off\n>");
    int value = this->ReadInput();

    switch (value)
    {
    case 1:
        this->MakeService();
        break;
    case 2:
        this->MakeWork();
        break;
    case 0:
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