#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>	
#include <string>
#include <ctime>
#include <fstream>

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
	std::string playerInput = "aaaaa";
	std::string mysteryWord;
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
		std::string mysteryPlaceholder = "*****";
		bool flagIsUsed[usedSize] = { false }; 

		if (gameMode == 1) //"Word of a day"
		{
			if (true/* if date in "CrossStart.txt" < today date*/)
			{
				while (mysteryWord != playerInput)
				{
					//wordOfDay(mysteryWord);
					playerAttempts++;
					playerGuess(playerInput, mysteryWord, mysteryPlaceholder, playerAttempts);
					correctPos(playerInput, mysteryWord, mysteryPlaceholder, flagIsUsed);
					incorrectPos(playerInput, mysteryWord, mysteryPlaceholder, flagIsUsed);
				}
				attemptsCalculation(playerAttempts);
			}
			else
			{
				cout << "Already found! Come back tommorow!" << endl;
			}
		}
		else if (gameMode == 2)
		{
			//randomWord(mysteryWord);
			mysteryWord = "hello";
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
