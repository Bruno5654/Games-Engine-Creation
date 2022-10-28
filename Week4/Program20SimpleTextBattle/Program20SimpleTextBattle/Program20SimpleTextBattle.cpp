#include <iostream>
using namespace std;

int playerHP = 1000, enemyHP = 2000;
bool isPlaying = true;

void AttackChoice(int choice);
bool PlayState();

int main()
{
	int playerChoice = 0;
	
	cout << "When traveling the dangerous path home you encounter a troll, as it snarles you realise you have no choice but to fight." << endl;
	cout << endl;

	while (isPlaying)
	{
		cout << "What will you do? Use your sword (1), use your magic (2) or use your axe (3):" << endl;
		cin >> playerChoice;
		AttackChoice(playerChoice);
		PlayState();
	}

	return 0;
}

void AttackChoice(int choice)
{
	const int swordDamage = 300, magicDamage = 650, axeDamage = 450, trollSword = 350, trollMagic = 50, trollAxe = 100;
	
	switch (choice)
	{
		case 1:
			enemyHP -= swordDamage;
			playerHP -= trollSword;
			
			cout << endl;
			cout << "You strike true with your valiant blade however the troll quickly retorts, clobbering you back." << endl;
			
			if (playerHP < 0)
				playerHP = 0;

			if (enemyHP < 0)
				enemyHP = 0;

			cout << "=-=-=-=-=-=-=-=-=-=-=" << endl;
			cout << "Troll HP = " << enemyHP << endl;
			cout << "Your HP = " << playerHP << endl;
			cout << "=-=-=-=-=-=-=-=-=-=-=" << endl;
			cout << endl;

		break;
		case 2:
			enemyHP -= magicDamage;
			playerHP -= trollMagic;

			cout << endl;
			cout << "Putting some distance between yourself and your foe you fire off a mighty blast of ice, the troll barely able to scratch you in return." << endl;

			if (playerHP < 0)
				playerHP = 0;

			if (enemyHP < 0)
				enemyHP = 0;

			cout << "=-=-=-=-=-=-=-=-=-=-=" << endl;
			cout << "Troll HP = " << enemyHP << endl;
			cout << "Your HP = " << playerHP << endl;
			cout << "=-=-=-=-=-=-=-=-=-=-=" << endl;
			cout << endl;

		break;
		case 3:
			enemyHP -= axeDamage;
			playerHP -= trollAxe;

			cout << endl;
			cout << "You bring your mighty axe down upon the troll, a wicked howl of pain leaving its mouth and damaging your mind." << endl;

			if (playerHP < 0)
				playerHP = 0;
			
			if (enemyHP < 0)
				enemyHP = 0;

			cout << "=-=-=-=-=-=-=-=-=-=-=" << endl;
			cout << "Troll HP = " << enemyHP << endl;
			cout << "Your HP = " << playerHP << endl;
			cout << "=-=-=-=-=-=-=-=-=-=-=" << endl;
			cout << endl;

		break;
		default:
			cout << "Please enter either 1, 2 or 3." << endl;
			cout << endl;
		break;
	}

}

bool PlayState()
{
	char playerInput = 'n';
	bool choiceMade = false;
	if (enemyHP <= 0)
	{
		cout << "After a tough battle you have bested the troll and can finnaly continue the long journey home." << endl;

		do
		{
			cout << "Play again? (y/n):" << endl;
			cin >> playerInput;

			if (tolower(playerInput) == 'y')
			{
				enemyHP = 2000;
				playerHP = 1000;
				cout << "When traveling the dangerous path home you encounter a troll, as it snarles you realise you have no choice but to fight." << endl;

				choiceMade = true;
				isPlaying = true;
			}
			else if (tolower(playerInput) == 'n')
			{
				choiceMade = true;
				isPlaying = false;
			}
			else
			{
				cout << "Please enter either y or n." << endl;
			}

		} while (choiceMade == false);
	}
	else if (playerHP <= 0)
	{
		cout << "Succumbing to your wounds you fall back in the snow, drawing you last breath you think of the home you will never return to." << endl; 
		cout << "You have been defeated." << endl;
		
		do
		{
			cout << "Play again? (y/n):" << endl;
			cin >> playerInput;

			if (tolower(playerInput) == 'y')
			{
				enemyHP = 2000;
				playerHP = 1000;
				cout << "When traveling the dangerous path home you encounter a troll, as it snarles you realise you have no choice but to fight." << endl;

				choiceMade = true;
				isPlaying = true;
			}
			else if (tolower(playerInput) == 'n')
			{
				choiceMade = true;
				isPlaying = false;
			}
			else
			{
				cout << "Please enter either y or n." << endl;
			}

		} while (choiceMade == false);
	}

	return(false);
}

