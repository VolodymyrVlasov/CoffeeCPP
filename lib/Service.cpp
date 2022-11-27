#include "../headers/Service.h"
#include "../headers/db.h"
#include <sstream>

using namespace std;

void Service::Run()
{
  stringstream ss;
  ss << "Select service function:" << endl;
  ss << "\t1 - print report" << endl;
  ss << "\t2 - add coffee" << endl;
  ss << "\t3 - add tea" << endl;
  ss << "\t4 - add water" << endl;
  ss << "\t5 - add sugar" << endl;
  ss << "\t6 - add milk" << endl;
  ss << "\t7 - get cash" << endl;
  ss << "\t0 - exit" << endl;
  ss << ">" << endl;
  this->WriteMessage(ss.str());

  int value = this->ReadInput();

  switch (value)
  {
  case 0:
    this->Stop();
    return;
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
    this->AddMaterial(6);
    break;
  case 7:
    this->CollectCash();
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
    db->SetCoffeeAmount(db->GetCoffeeAmount() + value);
    result = db->GetCoffeeAmount();
    break;
  case 3:
    value = this->ReadInput();
    db->SetTeaAmount(db->GetTeaAmount() + value);
    result = db->GetTeaAmount();
    break;
  case 4:
    value = this->ReadInput();
    db->SetWaterAmount(db->GetWaterAmount() + value);
    result = db->GetWaterAmount();
    break;
  case 5:
    value = this->ReadInput();
    db->SetSugarAmount(db->GetSugarAmount() + value);
    result = db->GetSugarAmount();
    break;
  case 6:
    value = this->ReadInput();
    db->SetMilkAmount(db->GetMilkAmount() + value);
    result = db->GetMilkAmount();
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

void Service::CollectCash()
{
  DB *db = DB::GetInstance();
  int remainingCash;
  this->WriteMessage("Enter amount to take:");
  int amount = this->ReadInput();
  if (amount && db->GetCashAmount() - amount >= 0)
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
  this->Run();
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
