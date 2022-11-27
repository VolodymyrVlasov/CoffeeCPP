#include "../headers/db.h"

DB *DB::instance = 0;

DB::DB(){};

DB *DB::GetInstance()
{
    if (!instance)
    {
        instance = new DB();
    }
    return instance;
}

int DB::SetTeaAmount(int amount)
{
    return this->teaAmount = amount;
}

int DB::GetTeaAmount()
{
    return this->teaAmount;
}

int DB::SetCoffeeAmount(int amount)
{
    return this->coffeeAmount = amount;
}

int DB::GetCoffeeAmount()
{
    return this->coffeeAmount;
}

int DB::SetWaterAmount(int amount)
{
    return this->waterAmount = amount;
}

int DB::GetWaterAmount()
{
    return this->waterAmount;
}

int DB::SetSugarAmount(int amount)
{
    return this->sugarAmount = amount;
}

int DB::GetSugarAmount()
{
    return this->sugarAmount;
}

int DB::SetCashAmount(int amount)
{
    return this->cashAmount = amount;
}

int DB::GetCashAmount()
{
    return this->cashAmount;
}