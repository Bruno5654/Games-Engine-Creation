#include <iostream>
using namespace std;

int main()
{
    const int MAX_ITEMS = 4;
    int numItems = 0;
    string inventory[MAX_ITEMS];
    inventory[numItems++] = "sword";
    inventory[numItems++] = "battle axe";
    inventory[numItems++] = "healing potion";
    inventory[numItems++] = "dagger";

    char userInput;
    bool isUserInputCorrect = false;

    cout << "Huzzah! The wizard is finaly dead and your adventure complete. As you turn to leave the dungeon you notice his ornate staff, it looks to be worth a pretty penny.\n";
    do
    {
        cout << "Would you like to swap the dagger in your inventory for your staff? (y/n)\n";
        cin >> userInput;
        cout << "\n";
        
        if (tolower(userInput) == 'y')
        {
            
            inventory[3] = "wizard's staff";

            cout << "This staff will make a fine addition to your collection. Putting it in your bag you begin your long journey home.\n";
            cout << "\n";
            cout << "=-=-=-=-=-INVENTORY-=-=-=-=-=\n";
            for (int i = 0; i < 4; i++)
            {
                cout << inventory[i] << "\n";
            }
            cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";

            isUserInputCorrect = true;

        }
        else if (tolower(userInput) == 'n')
        {
            cout << "Deciding it best to leave the thing behind your begin your long journey home.\n";
            cout << "\n";
            cout << "=-=-=-=-=-INVENTORY-=-=-=-=-=\n";
            for (int i = 0; i < 4; i++)
            {
                cout << inventory[i] << "\n";
            }
            cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";

            isUserInputCorrect = true;
        }
        else
        {
            cout << "Please enter either y or n.\n";
        }

    } while (!isUserInputCorrect);
    
    return 0;
}

