#include <iostream>
using namespace std;

char cardsOnBoard[10] =
{
    'E','A','C','B','D','A','B','D','E','C'
};

bool isCardsFound[10] =
{
    false,false,false,false,false,false,false,false,false,false
};

int attemptCount = 0;

void drawGameBoard();
void checkTwoCards(int guess1, int guess2);

int main()
{
    bool isPlaying = true;
    int score = 0, guess1,guess2;

    do
    {
        drawGameBoard();
        cout << "\n";
        cout << "Guess two cards (1-10) which you think are pairs.\n";
        cout << "Guess 1: ";
        cin >> guess1;

        checkTwoCards(guess1, 11);
        cout << "\n";
        cout << "Guess 2: ";
        cin >> guess2;

        checkTwoCards(guess1, guess2);

        //Check Results
        if (cardsOnBoard[guess1-1] == cardsOnBoard[guess2-1])
        {
            score++;
            isCardsFound[guess1-1] = true;
            isCardsFound[guess2-1] = true;

            cout << "A match!\n";
            system("pause");
        }
        else
        {
            cout << "No match...\n";
            system("pause");
        }

        //Player wins game.
        if (score == 5)
        {
            cout << "Congratulations! You've won the game in " << attemptCount << " guesses!\n";
            isPlaying = false;
        }
        else
        {
            attemptCount++;
        }

    } while (isPlaying);
   
    return 0;
}

void drawGameBoard()
{
    system("cls");
    cout << "\n";
    cout << "Attempt count: " << attemptCount << "\n";
    cout << "\n";

    for (int i = 0; i < 10; i++)
    {
        if (isCardsFound[i])
            cout << "[" << cardsOnBoard[i] << "]";
        else
            cout << "[" << i+1 << "]";
        
        if (i == 4)
            cout << "\n";
    }
    cout << "\n";
}

void checkTwoCards(int guess1, int guess2)
{
    system("cls");
    cout << "\n";
    cout << "Attempt count: " << attemptCount << "\n";
    cout << "\n";
    
    for (int i = 0; i < 10; i++)
    {
        if (isCardsFound[i] || i + 1 == guess1 || i + 1 == guess2)
            cout << "[" << cardsOnBoard[i] << "]";
        else
            cout << "[" << i + 1 << "]";
        if (i == 4)
            cout << "\n";
    }
    cout << "\n";
   
}
