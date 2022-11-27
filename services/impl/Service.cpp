#pragma once
#include "../Service.h"

void Service::Run()
{
  this->WriteMessage("Select function:\n\t1 - print report\n\t2 - add coffee\n\t3 - add tea\n\t4 - add AddWater\n\t5 - add AddSugar\n\t6 - get cash>");

  int value = this->ReadInput();

  switch (value)
  {
  case 1:

    break;
  case 2:

    break;
  case 3:

    break;
  default:
    this->WriteMessage("Please, make correct choice!");
    this->Run();
  }
}

void Service::Stop()
{
}
