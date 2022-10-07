#include <iostream>
using namespace std;
typedef int health;

int main()
{
	enum Weapons
	{
		SWORD,
		DAGGER,
		MACE,
		TWIN_SWORDS,
		SAMURAI,
		WIZARD_STAFF,
		FIRE_POTION,
		ICE_BLADE,
		SMALL_KNIFE

	};

	health CurrentHealth = 13000;
	Weapons CurrentWeapon = SAMURAI;

	cout << "My current health is: " << CurrentHealth << endl;
	cout << "And the ID of my weapon of choice is: " << CurrentWeapon << endl;

}


