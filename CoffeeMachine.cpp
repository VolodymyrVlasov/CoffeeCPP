#include "CoffeeMachine.h"

class CoffeeMachine
{
private:
    int currentSelection;

public:
    void run()
    {
        int input;
        cout << "Hello!\nSelect work type: 1 - Service, 2 - Work, 3 - Turn off >" << endl;
        cin >> input;

        switch (input)
        {
        case 1:
           // create instance of Service
           // 
            
            break;
        case 2:

            break;
        case 3:

            break;
        }
    }



    ~CoffeeMachine()
    {
    }
};