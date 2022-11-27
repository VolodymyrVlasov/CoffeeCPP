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
    this->AddMaterial(2);
    break;
  case 3:
    this->AddMaterial(3);
    break;
  case 4:
    this->AddMaterial(4);
    break;
  case 5:
    this->AddMaterial(5);
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
  int value;
  int result;

  switch (type)
  {
  case 2:
    value = this->ReadInput();
    db->SetCoffeeAmount(value);
    result = db->GetCoffeeAmount();
    break;
  case 3:
    value = this->ReadInput();
    db->SetTeaAmount(value);
    result = db->GetTeaAmount();
    break;
  case 4:
    value = this->ReadInput();
    db->SetWaterAmount(value);
    result = db->GetWaterAmount();
    break;
  case 5:
    value = this->ReadInput();
    db->SetSugarAmount(value);
    result = db->GetSugarAmount();
    break;
  default:
    this->WriteMessage("Invalid choice");
    this->Run();
  }

  stringstream message;
  message << "You add: " << value << ", now at machine are " << result << endl;
  this->WriteMessage(message.str());
  this->Run();
}

void Service::CollectCash(int amount)
{
  DB *db = DB::GetInstance();
  int remainingCash;
  if (db->GetCashAmount() - amount >= 0)
  {
    remainingCash = db->GetCashAmount() - amount;
    db->SetCashAmount(remainingCash);
    stringstream report;
    report << "You take: " << amount << " Remaining: " << db->GetCashAmount() << endl;
    this->WriteMessage(report.str());
  }
  else
  {
    this->WriteMessage("Error! Enter smaller value");
  }
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
