#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    vector<string> inventory;
    int invMax = 3;

    while (inventory.size() < invMax)
    {

    }


    inventory.clear();
}

void printInventory(vector<string> inventory)
{
    cout << " =-=-=-=-=-=INVENTORY=-=-=-=-=-=\n";
    for (auto i : inventory)
    {
        cout << i << "\n";
    }
    cout << " =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
}
   
    
    

   
    
    
  
  
