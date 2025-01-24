#include <iostream>
#include <algorithm>
#include <string>
using std::cout;
using std::cin;
using std::endl;

//init game params
	//Player input
	//"Random word" from database
		//func for random
	//"Word of a day"
		//TO DO
constexpr int SIZE = 5;

void randomWord(std::string database[SIZE], std::string mysteryWord[SIZE])
{
	//TO DO
}

void playerGuess(std::string playerInput[SIZE], std::string mysteryWord[SIZE])
{
	//TO DO
}
int main()
{
	std::string database[10] = { "apple", "bread", "chair", "dream", "flute", "grape", "heart", "jelly", "knife", "plant" };
	std::string playerInput;
	//Intro "Hi it is my super game...." & Selection of game mode 
			//"Random word" +-
			//"Word of a day"
			//Close Game +
			// 
	//Game Loop after GameMode Selected
			//User trying to guess a Word
			//Search for common letters in a generated Word
			//Higlight a right letters
				//small copy if letter present in a Word
				//big letter if letter is located on a right position
				
	//std::getline(std::cin, playerInput);
	int gameMode = -1;
	while (gameMode != 0)
	{
		cout << "1 - Word of the day" << endl;
		cout << "2 - Random Word" << endl;
		cout << "0 - Exit" << endl;
		cout << "Enter: ";
		cin >> gameMode;

		if (gameMode == 1)
		{
			//"Word of a day"
		}
		else
		{
			//"Random word" 
			//TO DO in a future
		}
	}





}
