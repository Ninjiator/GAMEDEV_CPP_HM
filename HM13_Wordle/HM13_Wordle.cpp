#include <iostream>
#include <algorithm>
#include <string>
#include <ctime>

using std::cout;
using std::cin;
using std::endl;

constexpr int dataBaseSIZE = 10;
constexpr int usedSize = 5;

void randomWord(std::string database[], int SIZE, std::string& mysteryWord)
{
	std::srand(static_cast<unsigned int>(std::time(nullptr)));
	std::random_shuffle(database, database + SIZE);
	mysteryWord = database[0];
}

void playerGuess(std::string& playerInput, std::string mysteryWord, std::string& mysteryPlaceholder, int& playerAttempts)
{
		cout << "RESULT : " << mysteryPlaceholder << endl;
		cout << "ENTER  : ";
		std::getline(std::cin, playerInput);

		if (playerInput.length() != mysteryWord.length())
		{
			cout << "\nPlease input Word with length = [" << mysteryWord.length() << "]" << endl << endl;
			playerAttempts--;

		}
}
void correctPos(std::string& playerInput, std::string mysteryWord, std::string& mysteryPlaceholder, bool* used)
{
	//STEP:1 processing correct position & adding to placeholder on correct pos, flag used - true
	for (int i = 0; i < playerInput.length(); i++)
	{
		if (playerInput[i] == mysteryWord[i])
		{
			mysteryPlaceholder[i] = std::toupper(playerInput[i]);
			used[i] = true;
		}
	}
}
void incorrectPos(std::string& playerInput, std::string mysteryWord, std::string& mysteryPlaceholder, bool* used)
{
	for (int i = 0; i < playerInput.length(); i++)
	{
		if (mysteryPlaceholder[i] != '*')	// skip != empty positions
			continue;

		//STEP:2.2 processing inccorect position but correct letters
		for (int j = 0; j < playerInput.length(); j++)
		{
			if (playerInput[i] == mysteryWord[j] && !used[j]) 
			{
				mysteryPlaceholder[i] = playerInput[i];
				used[j] = true;
				break;
			}
		}
	}
}

void attemptsCalculation(int playerAttempts)
{
	cout << "\nCongratulations, YOU WIN !\nAttempts was needed [" << playerAttempts << "]\n" << endl;
}

int main()
{
	std::string database[dataBaseSIZE] = { "apple", "bread", "chair", "dream", "flute", "grape", "heart", "jelly", "knife", "plant" };
	std::string playerInput = "tests";
	std::string mysteryWord = "hello";
	int turnCount = 0;
	int gameMode = -1;
	while (gameMode != 0)
	{
		cout << "1 - Word of the day [WIP]" << endl;
		cout << "2 - Random Word" << endl;
		cout << "0 - Exit" << endl;
		cout << "Choose GAMEMODE: ";
		cin >> gameMode;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //Fix for double output "Enter : " from .getline
		int playerAttempts = 0;

		if (gameMode == 1) //"Word of a day"
		{
			//TO DO
		}
		else if (gameMode == 2)  //Random word
		{
			std::string mysteryPlaceholder = "*****";
			bool used[usedSize] = { false }; // flag

			//randomWord(database, dataBaseSIZE, mysteryWord);
			cout << "DEBUG:TEST WORD : " << mysteryWord << endl;

			//Random Word game loop
			while (mysteryWord != playerInput)
			{
				playerAttempts++;
				playerGuess(playerInput, mysteryWord, mysteryPlaceholder, playerAttempts);
				correctPos(playerInput,  mysteryWord, mysteryPlaceholder, used);
				incorrectPos(playerInput, mysteryWord, mysteryPlaceholder, used);
			}
			attemptsCalculation(playerAttempts);
		}
	}
}
