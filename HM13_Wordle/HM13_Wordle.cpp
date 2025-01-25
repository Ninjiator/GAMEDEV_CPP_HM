#include <iostream>
#include <algorithm>
#include <string>
#include <ctime>

using std::cout;
using std::cin;
using std::endl;

//init game params
	//Player input +
	//"Random word" from database +
		//func for random +
	//"Word of a day"
		//TO DO
constexpr int dataBaseSIZE = 10;

void randomWord(std::string database[], int SIZE, std::string& mysteryWord)
{
	std::srand(static_cast<unsigned int>(std::time(nullptr)));
	std::random_shuffle(database, database + SIZE);
	mysteryWord = database[0];
}

void playerGuess(std::string& playerInput, std::string mysteryWord, std::string& mysteryPlaceholder)
{
	while (mysteryWord != playerInput)
	{
		cout << "RESULT : " << mysteryPlaceholder << endl;
		cout << "ENTER  : ";
		std::getline(std::cin, playerInput);

		if (playerInput.length() != mysteryWord.length()) 
		{
			cout << "\n[ERROR] input length.\nPlease input Word with length [5]\n\n";
			continue;
		}

		for (int i = 0; playerInput[i] != '\0'; i++)
		{
			char curentChar = playerInput[i];
			for (int j = 0; mysteryWord[j] != '\0'; j++) // char search in mysteryWord
			{
				if (curentChar == mysteryWord[j])
				{
					mysteryPlaceholder[i] = curentChar; // if char present -> add to placeholder on match position 
				}
				else
				{
					break;
				}
			}
			if (playerInput[i] == mysteryWord[i]) // correct position of Letter = add to placeholder on correct pos
			{
				mysteryPlaceholder[i] = std::toupper(playerInput[i]);
			}
		}

	}
}

void gameResults(int turnCount)
{
	//TODO
}

int main()
{
	std::string database[dataBaseSIZE] = { "apple", "bread", "chair", "dream", "flute", "grape", "heart", "jelly", "knife", "plant" };
	std::string playerInput = "tests";
	std::string mysteryWord = "cocon";
	int turnCount = 0;
	//Intro 
			//"Random word" +-
			//"Word of a day"
			//Close Game +
			// 
	//Game Loop after GameMode Selected
			//User trying to guess a Word +
			//Search for common letters in a generated Word 
			//Higlight a right letters
				//small copy if letter present in a Word
				//big letter if letter is located on a right position +

	;
	int gameMode = -1;
	while (gameMode != 0)
	{
		cout << "1 - Word of the day" << endl;
		cout << "2 - Random Word" << endl;
		cout << "0 - Exit" << endl;
		cout << "Choose GAMEMODE: ";
		cin >> gameMode;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //Fix for double "Enter : " with .getline

		if (gameMode == 1)
		{
			//"Word of a day"
			//TO DO in a future
		}
		else if (gameMode == 2)
		{
			//Random word preparation
			std::string mysteryPlaceholder = "*****";
			//randomWord(database, dataBaseSIZE, mysteryWord);
			cout << "DEBUG:TEST WORD : " << mysteryWord << endl;

			//Random Word game loop
			playerGuess(playerInput, mysteryWord, mysteryPlaceholder);
		}
	}
}
