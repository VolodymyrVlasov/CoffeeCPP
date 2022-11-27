#include <string>

class DB
{
private:
    static DB *instance;
    DB();
    int teaAmount = 20,
        coffeeAmount = 80,
        waterAmount = 1000,
        sugarAmount = 100,
        cashAmount = 0;

public:
    static DB *GetInstance();
    int SetTeaAmount(int amount);
    int GetTeaAmount();
    int SetCoffeeAmount(int amount);
    int GetCoffeeAmount();
    int SetWaterAmount(int amount);
    int GetWaterAmount();
    int SetSugarAmount(int amount);
    int GetSugarAmount();
    int SetCashAmount(int amount);
    int GetCashAmount();
    std::string ToString();
};

