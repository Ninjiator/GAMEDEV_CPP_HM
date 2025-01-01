#include <iostream>
#include <ctime>
#include <cstdlib>

using std::cout;
using std::cin;
using std::endl;

int main()
{
    int rounds = 0;
    enum class GameSkills 
    {
        Rock = 'r',
        Paper = 'p',
        Scissors = 's',
    };
    GameSkills playerChoice = GameSkills::Rock;
    GameSkills pcChoice = GameSkills::Rock;
    char playerChar;

    cout << "Hello! Welcome to 'Rock paper scissors' game for 2 players.\n";
    while (true)
    {
        int won = 0;
        int lose = 0;
        int draw = 0;

        cout << "Enter round number: (-1 to quite): ";
        cin >> rounds;
        cout << endl;

        if (rounds == -1)
        {
            cout << "Thnx for a game\n\n\n";
            return 0;
        }
        for (int i = 0; i < rounds; i++)
        {
            cout << "To make your turn enter one of possible symbol\n";
            cout << "[r] - Rock\n";
            cout << "[p] - Paper\n";
            cout << "[s] - Scissors\n";
            
            //Player logic
            cin >> playerChar;
            
            switch (playerChar)
            {
            case 'r':
                playerChoice = GameSkills::Rock;
                cout << "Player choise is : [r]\n";
                break;
            case 'p':
                playerChoice = GameSkills::Paper;
                cout << "Player choise is : [p]\n";
                break;
            case 's':
                playerChoice = GameSkills::Scissors;
                cout << "Player choise is : [s]\n";
                break;
            default:
                cout << "Invalid input, pls use only discribied chars\n";
                break;
            }

            //PC logic
            std::srand(std::time(nullptr)); // Use current time as a seed for random generator
            int pcRandom = std::rand() % 3; //0-3
            
            if (pcRandom == 0)
            {
                pcChoice = GameSkills::Rock;
                cout << "PC choise is : [r]\n";
            }
            else if (pcRandom == 1)
            {
                pcChoice = GameSkills::Paper;
                cout << "PC choise is : [p]\n";
            }
            else
            {
                pcChoice = GameSkills::Scissors;
                cout << "PC choise is : [s]\n";
            }

            //Results calculation
            if (playerChoice == GameSkills::Paper && pcChoice == GameSkills::Rock ||
                playerChoice == GameSkills::Rock && pcChoice == GameSkills::Scissors ||
                playerChoice == GameSkills::Scissors && pcChoice == GameSkills::Paper)
            {
                won++;
                cout << "Human WIN\n\n\n";
            }
            else if (playerChoice == pcChoice)
            {
                draw++;
                cout << "It's a DRAW\n\n\n";
            }
            else
            {
                lose++;
                cout << "PC on one step closer to SKYNET\n\n\n";
            }
        }

        cout << "Game results: " << endl;
        cout << "Wins: " << won << endl;
        cout << "Losses: " << lose << endl;
        cout << "Draws: " << draw << endl;
    }
}