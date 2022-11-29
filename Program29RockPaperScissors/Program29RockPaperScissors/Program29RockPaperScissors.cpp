#include <iostream>
using namespace std;

void stringToLower(string& data)
{
    for (int i = 0; i < data.length(); i++)
    {
        data[i] = tolower(data[i]);
    }
}

void userLoss(int& ps, int& cs)
{
    cout << "You lose...\n";
    cs++;
    cout << "Current scores:\n";
    cout << "You - " << ps << "\n";
    cout << "Computer - " << cs << "\n";
}

void userWin(int& ps, int& cs)
{
    cout << "You win!\n";
    ps++;
    cout << "Current scores:\n";
    cout << "You - " << ps << "\n";
    cout << "Computer - " << cs << "\n";
}


int main()
{
    bool isPlaying = true, valid = false, playerWon = false;
    string userInput, computerMove;
    int computerRand, round = 1, playerScore = 0, computerScore = 0;

    srand(time(NULL));

    cout << "Welcome to ultimate Rock Paper Scissors! First to three wins.\n";
    do
    {
        computerRand = rand() % 2;
        switch (computerRand)
        {
        case 0:
            computerMove = "rock";
            break;
        case 1:
            computerMove = "paper";
            break;
        case 2:
            computerMove = "scissors";
            break;
        default:
            computerMove = "rock";
            break;
        }
        cout << "=-=-=-=-=ROUND " << round << "=-=-=-=-=\n";
        cout << "Please enter your move!:\n";
        do
        {
            cin >> userInput;
            stringToLower(userInput);

            
            if (userInput == computerMove)
            {
                //draw
                valid = true;
                cout << "Computer plays " << computerMove << ".\n";
                cout << "It's a draw! Nobody wins.\n";
            }
            else if (userInput == "rock")
            {
                valid = true;
                cout << "Computer plays " << computerMove << ".\n";
                if (computerMove == "paper")
                {
                    userLoss(playerScore, computerScore);
                }
                else if (computerMove == "scissors")
                {
                    userWin(playerScore, computerScore);
                }

            }
            else if (userInput == "paper")
            {
                valid = true;
                cout << "Computer plays " << computerMove << ".\n";
                if (computerMove == "scissors")
                {
                    userLoss(playerScore, computerScore);
                }
                else if (computerMove == "rock")
                {
                    userWin(playerScore, computerScore);
                }
            }
            else if (userInput == "scissors")
            {
                valid = true;
                cout << "Computer plays " << computerMove << ".\n";
                if (computerMove == "rock")
                {
                    userLoss(playerScore, computerScore);
                }
                else if (computerMove == "paper")
                {
                    userWin(playerScore, computerScore);
                }
            }
            else
            {
                //invalid input.
                cout << "Input not valid. Try rock, paper or scissors.\n";
            }
        } while (!valid);

        valid = false;
        round++;
        cout << "=-=-=-=-=-=-=-=-=-=-=-=-=\n";
        cout << "\n";
        //Should game continue?
        if (playerScore >= 3)
        {
            playerWon = true;
            isPlaying = false;
        }
        else if (computerScore >= 3)
        {
            playerWon = true;
            isPlaying = false;
        }

    } while (isPlaying);

    cout << "** Final Scores! **\n";
    cout << "Player - " << playerScore << ".\n";
    cout << "Computer - " << computerScore << ".\n";
    cout << "\n";
    if (playerWon)
    {
        cout << "Player wins the game!\n";
    }
    else
    {
        cout << "Computer wins the game!\n";
    }
}


