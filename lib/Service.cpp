#include "../headers/Service.h"
#include "../headers/db.h"
#include <sstream>

using namespace std;

void Service::Run()
{
  this->WriteMessage("Select service function:\n\t1 - print report\n\t2 - add coffee\n\t3 - add tea\n\t4 - add water\n\t5 - add sugar\n\t6 - get cash\n\t0 - exit\n>");

  int value = this->ReadInput();

  switch (value)
  {
  case 1:
    this->PrintReport();
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

void Service::AddMaterial(int type)
{
  DB *db = DB::GetInstance();
  this->WriteMessage("Enter amount to add:\n");
  int value = this->ReadInput();
  int result;

  switch (type)
  {
  case 0:
    db->SetCoffeeAmount(value);
    result = db->GetCoffeeAmount();
    break;
  case 1:
    break;
  case 2:
    break;
  case 3:
    break;
  case 4:
    break;
  case 5:
    break;
  }

  stringstream message;
  message << "You add: " << value << ", now at machine are " << result << endl;
  this->WriteMessage(message.str());
  this->Run();
}

void Service::GetCash()
{
}

void Service::PrintReport()
{
  DB *db = DB::GetInstance();
  stringstream report;
  report << "\nREPORT:" << endl;
  report << db->ToString() << endl;
  this->WriteMessage(report.str());
  this->Run();
}

void Service::Stop()
{
  this->WriteMessage("Buy...\nRedirecting to main menu\n");
}
