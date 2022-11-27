class DB
{
private:
    static DB *instance;
    DB();
    int teaAmount = 0,
        coffeeAmount = 0,
        waterAmount = 0,
        sugarAmount = 0,
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
};

