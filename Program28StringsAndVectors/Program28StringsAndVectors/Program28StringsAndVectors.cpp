#include <iostream>
#include <string>
#include <vector>
using namespace std;

void printInventory(vector<string> inventory)
{
    cout << " =-=-=-=-=-=INVENTORY=-=-=-=-=-=\n";
    for (auto i : inventory)
    {
        cout << i << "\n";
    }
    cout << " =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
}

int main()
{
    vector<string> inventory;
    int invMax = 3;
    bool valid = false;
    string userInput;
    int userInput2;

    while (inventory.size() < invMax)
    {
        do
        {
            if (inventory.size() == 0)
            {
                cout << "Type which item you wish to keep: sword or mace\n";
                getline(cin, userInput);
                if (userInput == "sword")
                {
                    inventory.push_back("sword");
                    valid = true;
                }
                else if (userInput == "mace")
                {
                    inventory.push_back("mace");
                    valid = true;
                }
                else
                {
                    cout << "Invalid input.\n";
                }
            }
            else if (inventory.size() == 1)
            {
                cout << "Type which item you wish to keep: staff or knife\n";
                getline(cin, userInput);
                if (userInput == "staff")
                {
                    inventory.push_back("staff");
                    valid = true;
                }
                else if (userInput == "knife")
                {
                    inventory.push_back("knife");
                    valid = true;
                }
                else
                {
                    cout << "Invalid input.\n";
                }
            }
            else if (inventory.size() == 2)
            {
                cout << "Type which item you wish to keep: healing potion or fire spell\n";
                getline(cin, userInput);
                if (userInput == "healing potion")
                {
                    inventory.push_back("healing potion");
                    valid = true;
                }
                else if (userInput == "fire spell")
                {
                    inventory.push_back("fire spell");
                    valid = true;
                }
                else
                {
                    cout << "Invalid input.\n";
                }
            }

        } while (!valid);
        
        cout << "\n";
        printInventory(inventory);
        cout << "\n";
        valid = false;
    }
    
    cout << "Your inventory is full!\n";
    cout << "\n";

    cout << "You have found a magic ring, what would you like to replace in your inventory?\n";
    cout << "Choices:\n1: " << inventory[0]<<"\n2: " << inventory[1] << "\n3: "<< inventory[2]<<"\n";
    do
    {
        cin >> userInput2;
        switch (userInput2)
        {
        case 1:
            inventory[0] = "magic ring";
            valid = true;
            break;
        case 2:
            inventory[1] = "magic ring";
            valid = true;
            break;
        case 3:
            inventory[2] = "magic ring";
            valid = true;
            break;
        default:
            cout << "Invalid input.\n";
            break;
        }
    } while (!valid);
   
    printInventory(inventory);
    
    cout << "\n";
    cout << "You have been robbed!!\n";
    inventory.clear();
    inventory.push_back("Empty!");
    printInventory(inventory);
}


   
    
    

   
    
    
  
  
