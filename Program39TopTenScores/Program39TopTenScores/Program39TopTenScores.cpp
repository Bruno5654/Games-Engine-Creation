#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void inputScore(int* scores, string* names);
void printScores(int* scores, string* names);

string loadScores(int* scores, string* names);

int main()
{
	int scores[10];
	int userInput;
	string names[10];
	bool done = false;

	do
	{
		cout << "What would you like to do?\n(1) Input score and name.\n(2) Ouput top ten scores.\n(3) Close program.\n";
		cin >> userInput;

		switch (userInput)
		{
		case 1:
			inputScore(scores,names);
			break;
		case 2:
			printScores(scores,names);
			break;
		case 3:
			done = true;
			break;
		default:
			cout << "Invalid input. Please enter either 1, 2 or 3.\n";
			break;
		}
	} while (!done);

	exit(1);
}

void inputScore(int* scores, string* names)
{
	string userName;
	int score;
	int newScorePos;
	bool valid = false;

	loadScores(scores,names);

	//Get user Input.
	cout << "Please enter the name you'd like to save the score under. (Spaces are not allowed.)\n";
	cin >> userName;

	do
	{
		cout << "Please enter your score. (0-100)\n";
		cin >> score;

		if (score >= 0 && score <= 100)
		{
			valid = true;
		}
		else
		{
			cout << "Invalid score. Please enter a number between 0-100,\n";
		}

	} while (!valid);

	//See if new score is higher.
	for (int i = 0; i < 10; i++)
	{
		if (score <= scores[i])
		{
			newScorePos = i - 1;
		}

		if (i == 9 && score > scores[i])
		{
			newScorePos = 9;
		}
	}

	if (newScorePos >= 0)
	{
		names[newScorePos] = userName;
		scores[newScorePos] = score;
	}

	fstream outFile("Scores.txt");
	
	//Check file is open.
	if (!outFile.is_open())
	{
		cout << "Critical Error, file Scores.txt, could not be opened.";
		exit(1);
	}

	//Write to file
	for (int i = 0; i < 10; i++)
	{
		outFile << names[i] << " " << scores[i] << "\n";
	}
	
	outFile.close();
}

void printScores(int* scores, string* names)
{
	loadScores(scores,names);
	
	cout << "=-=-=-=-=-=Scores=-=-=-=-=-=\n";
	for (int i = 0; i < 10; i++)
	{
		cout << i + 1 << ". " << names[i] << " " << scores[i] << "\n";
	}
}


string loadScores(int* scores, string* names)
{
	string scoreData;

	//Open file
	ifstream inFile("Scores.txt");

	//Check file is open.
	if (!inFile.is_open())
	{
		cout << "Critical Error, file Scores.txt, could not be opened.";
		exit(1);
	}
	
	//Load scores from file.
	int j = 0;
	while (getline(inFile, scoreData))
	{
		for (int i = 0; i < scoreData.size(); i++)
		{
			if (scoreData[i] == ' ')
			{
				names[j] = scoreData.substr(0, i);
				scores[j] = stoi(scoreData.substr(i + 1));
				j++;
				break;
			}
		}
		
	}

	inFile.close();
}
