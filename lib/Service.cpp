// #pragma once
#include "Service.h"

void Service::Run()
{
  this->WriteMessage("Select service function:\n\t1 - print report\n\t2 - add coffee\n\t3 - add tea\n\t4 - add water\n\t5 - add sugar\n\t6 - get cash>");

  int value = this->ReadInput();

  switch (value)
  {
  case 1:
    this->WriteMessage("You select: print report");
    break;
  case 2:
    this->WriteMessage("You select: add coffee");
    break;
  case 3:
    this->WriteMessage("You select: add tea");
    break;
  case 4:
    this->WriteMessage("You select: add water");
    break;
  case 5:
    this->WriteMessage("You select: add sugar");
    break;
  case 6:
    this->WriteMessage("You select: get cash");
    break;
  default:
    this->WriteMessage("Please, make correct choice!");
    this->Run();
  }
}

void Service::Stop()
{
}