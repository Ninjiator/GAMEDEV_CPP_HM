#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>	
#include <string>
#include <ctime>

#include "LetterPosition.h"
#include "MysteryWordGen.h"
#include "Time.h"

using std::cout;
using std::cin;
using std::endl;

void playerGuess(std::string& playerInput, const std::string& mysteryWord, std::string& mysteryPlaceholder, int& playerAttempts)
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
void attemptsCalculation(int playerAttempts)
{
	cout << "\nCongratulations, YOU WIN !\nAttempts was needed [" << playerAttempts << "]\n" << endl;
}

int main()
{
	std::time_t t = std::time(nullptr);
	std::tm* now = std::localtime(&t);
	std::string playerInput;
	std::string mysteryWord;
	int gameMode = -1;
	while (gameMode != 0)
	{
		cout << "1 - Word of the day" << endl;
		cout << "2 - Random Word" << endl;
		cout << "0 - Exit" << endl;
		cout << "Choose GAMEMODE: ";
		cin >> gameMode;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
		
		int playerAttempts = 0;
		std::string mysteryPlaceholder = "*****";
		bool flagIsUsed[usedSize] = { false }; 

		if (gameMode == 1) //"Word of a day"
		{
			int day = getDay(now);
			int month = getMonth(now);
			int year = getYear(now);
			const char* crossStart = "CrossStart.txt";
			const char* dataBase_1 = "WordOfDay.txt";
			if (IsWordGuessToday(crossStart, day, month, year))
			{
				wordOfDay(mysteryWord, dataBase_1);
				while (mysteryWord != playerInput)
				{
					playerAttempts++;
					playerGuess(playerInput, mysteryWord, mysteryPlaceholder, playerAttempts);
					correctPos(playerInput, mysteryWord, mysteryPlaceholder, flagIsUsed);
					incorrectPos(playerInput, mysteryWord, mysteryPlaceholder, flagIsUsed);
				}
				attemptsCalculation(playerAttempts);
			}
		}
		else if (gameMode == 2)
		{
			const char* dataBase_2 = "RandomWordDataBase.txt";
			randomWord(mysteryWord, dataBase_2);
			while (mysteryWord != playerInput)
			{
				playerAttempts++;
				playerGuess(playerInput, mysteryWord, mysteryPlaceholder, playerAttempts);
				correctPos(playerInput,  mysteryWord, mysteryPlaceholder, flagIsUsed);
				incorrectPos(playerInput, mysteryWord, mysteryPlaceholder, flagIsUsed);
			}
			attemptsCalculation(playerAttempts);
		}
		else
		{
			continue;
		}
	}
}
