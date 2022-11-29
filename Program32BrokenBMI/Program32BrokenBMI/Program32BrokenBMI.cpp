#include <iostream>
#include <string>
using namespace std;

float height();
float weight();
void output_bmi(float weight, float height);

int total_inches, total_weight;


int main()
{
	double bmi;
	const string message = "Welcome to your BMI Calculator.";
	string name;
	
	cout << message << endl;
	cout << "Firstly what is your full name?" << endl;
	getline(cin,name);
	cout << "Hi " << name << " lets get started." << endl;
	
	weight();
	height();

	output_bmi(total_weight, total_inches);
}

float height()
{
	int inches = 0, feet = 0;
	while(true)
	{
		cout << "Please enter your height in feet:" << endl;
		cin >> feet;
		if(feet < 2 || feet > 7)
		{
			cout << "You must be between 2 and 7 feet" << endl;
		}
		else
		{
			cout << "Thank you!" << endl;
			break;
		}
	}

	while(true)
	{
		cout << "\nPlease enter the inches:" << endl;
		cin >> inches;

		if(inches < 0 || inches > 11)
		{
			cout << "\nInches must be between 0 and 11" << endl;
		}
		else
		{
			cout << "Thank you!" << endl;
			break;
		}

	}

	total_inches = feet * 12 + inches;
	cout << "Your total height in inches is: " << total_inches << endl;
	return total_inches;
}

float weight()
{
	int stone, pounds;
	while (true)
	{
		cout << "\nPlease enter your weight in stone:" << endl;
		cin >> stone;
		if (stone < 3 || stone > 30)
		{
			cout << "\nYou must be between 3 and 30 stone" << endl;
		}
		else
		{
			cout << "Thank you!" << endl;
			break;
		}
	}

	while (true)
	{
		cout << "Please enter the pounds:" << endl;
		cin >> pounds;

		if (pounds < 0 || pounds > 13)
		{
			cout << "Pounds must be between 0 and 13" << endl;
		}
		else
		{
			cout << "Thank you!" << endl;
			break;
		}

	}

	total_weight = stone * 12 + pounds;
	cout << "Your total weight in pounds is: " << total_weight << endl;
	return total_weight;
}

void output_bmi(float weight, float height)
{
	float bmi;
	bmi = weight * 703 / (height * height);
	cout << "Your BMI is: " << bmi << endl;
}