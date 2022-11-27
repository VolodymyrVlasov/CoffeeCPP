// #pragma once
#include <sstream>
#include "../headers/Work.h"
#include "../headers/db.h"

using namespace std;

void Work::Run()
{
    stringstream ss;
    ss << "Select your drink:" << endl;
    ss << "\t1 - Black Tea\t$1" << endl;
    ss << "\t2 - Espresso\t$2" << endl;
    ss << "\t3 - Capuchio\t$3" << endl;
    ss << "\t4 - Machiatto\t$3" << endl;
    ss << "\t5 - Hot Milk\t$2" << endl;
    ss << ">" << endl;
    this->WriteMessage(ss.str());

    int value = this->ReadInput();

    switch (value)
    {
    case 0:
        this->Stop();
        return;
    case 1:
        this->MakeTea();
        break;
    case 2:
        this->MakeEspresso();
        break;
    case 3:
        this->MakeCapuchio();
        break;
    case 4:
        this->MakeMachiatto();
        break;
    case 5:
        this->MakeHotMilk();
        break;
    default:
        this->WriteMessage("Please, make correct choice!");
        this->Run();
    }
}

void Work::MakeTea()
{
    DB *db = DB::GetInstance();
    int price = 1;
    int waterAmount = 300;
    int teaAmount = 1;
    int sugarAmount = this->AddSugar();
    this->WriteMessage("Please wait a few moment...");
    if (db->GetWaterAmount() >= waterAmount && db->GetTeaAmount() >= teaAmount && db->GetSugarAmount() >= sugarAmount)
    {
        db->SetSugarAmount(db->GetSugarAmount() - sugarAmount);
        db->SetWaterAmount(db->GetWaterAmount() - waterAmount);
        db->SetTeaAmount(db->GetTeaAmount() - teaAmount);
        db->SetCashAmount(db->GetCashAmount() + price);
        this->WriteMessage("Your tea are ready. Thank you!");
    }
    else
    {
        this->WriteMessage("Sorry, not enought ingridients");
    }
    this->Run();
}

void Work::MakeEspresso()
{
    DB *db = DB::GetInstance();
    int price = 2;
    int waterAmount = 50;
    int coffeeAmount = 1;
    int sugarAmount = this->AddSugar();
    this->WriteMessage("Please wait a few moment...");
    if (db->GetWaterAmount() >= waterAmount && db->GetCoffeeAmount() >= coffeeAmount && db->GetSugarAmount() >= sugarAmount)
    {
        db->SetSugarAmount(db->GetSugarAmount() - sugarAmount);
        db->SetWaterAmount(db->GetWaterAmount() - waterAmount);
        db->SetCoffeeAmount(db->GetCoffeeAmount() - coffeeAmount);
        db->SetCashAmount(db->GetCashAmount() + price);
        this->WriteMessage("Your espresso are ready. Thank you!");
    }
    else
    {
        this->WriteMessage("Sorry, not enought ingridients");
    }
    this->Run();
}

void Work::MakeCapuchio()
{
    DB *db = DB::GetInstance();
    int price = 3;
    int waterAmount = 50;
    int coffeeAmount = 1;
    int milkAmount = 150;
    int sugarAmount = this->AddSugar();
    this->WriteMessage("Please wait a few moment...");
    if (db->GetWaterAmount() >= waterAmount && db->GetCoffeeAmount() >= coffeeAmount && db->GetSugarAmount() >= sugarAmount && db->GetMilkAmount() >= milkAmount)
    {
        db->SetSugarAmount(db->GetSugarAmount() - sugarAmount);
        db->SetWaterAmount(db->GetWaterAmount() - waterAmount);
        db->SetCoffeeAmount(db->GetCoffeeAmount() - coffeeAmount);
        db->SetMilkAmount(db->GetCoffeeAmount() - milkAmount);
        db->SetCashAmount(db->GetCashAmount() + price);
        this->WriteMessage("Your capuchio are ready. Thank you!");
    }
    else
    {
        this->WriteMessage("Sorry, not enought ingridients");
    }
    this->Run();
}

void Work::MakeMachiatto()
{
    DB *db = DB::GetInstance();
    int price = 3;
    int waterAmount = 50;
    int coffeeAmount = 1;
    int milkAmount = 250;
    int sugarAmount = this->AddSugar();
    this->WriteMessage("Please wait a few moment...");
    if (db->GetWaterAmount() >= waterAmount && db->GetCoffeeAmount() >= coffeeAmount && db->GetSugarAmount() >= sugarAmount && db->GetMilkAmount() >= milkAmount)
    {
        db->SetSugarAmount(db->GetSugarAmount() - sugarAmount);
        db->SetWaterAmount(db->GetWaterAmount() - waterAmount);
        db->SetCoffeeAmount(db->GetCoffeeAmount() - coffeeAmount);
        db->SetMilkAmount(db->GetCoffeeAmount() - milkAmount);
        db->SetCashAmount(db->GetCashAmount() + price);
        this->WriteMessage("Your machiatto are ready. Thank you!");
    }
    else
    {
        this->WriteMessage("Sorry, not enought ingridients");
    }
    this->Run();
}

void Work::MakeHotMilk()
{
    DB *db = DB::GetInstance();
    int price = 2;
    int milkAmount = 250;
    int sugarAmount = this->AddSugar();
    this->WriteMessage("Please wait a few moment...");
    if (db->GetSugarAmount() >= sugarAmount && db->GetMilkAmount() >= milkAmount)
    {
        db->SetSugarAmount(db->GetSugarAmount() - sugarAmount);
        db->SetMilkAmount(db->GetCoffeeAmount() - milkAmount);
        db->SetCashAmount(db->GetCashAmount() + price);
        this->WriteMessage("Your milk are ready. Thank you!");
    }
    else
    {
        this->WriteMessage("Sorry, not enought ingridients");
    }
    this->Run();
}

int Work::AddSugar()
{
    DB *db = DB::GetInstance();
    this->WriteMessage("Add sugar? (min 0 max 5)");
    int sugarAmount = this->ReadInput();
    if (sugarAmount >= 0 && sugarAmount <= 5 && db->GetSugarAmount() >= sugarAmount)
    {
        return sugarAmount;
    }
    else
    {
        this->WriteMessage("Input error, make yor choice");
        this->AddSugar();
    }
}

void Work::Stop()
{
    this->WriteMessage("Redirecting to main menu\n");
}