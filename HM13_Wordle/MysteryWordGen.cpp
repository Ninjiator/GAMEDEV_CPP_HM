#include <iostream>
#include <fstream>
#include <algorithm>

using std::cout;
using std::endl;

void randomWord(std::string& mysteryWord)
{
	std::fstream file("RandomWordDataBase.txt", std::ios_base::in);
	if (file.is_open())
	{
		int SIZE = 0;
		file >> SIZE;

		if (SIZE != 0 && SIZE > 0)
		{
			std::string* database = new std::string[SIZE];
			int i = 0;
			while (i < SIZE)
			{
				file >> database[i];
				i++;
			}
			std::srand(static_cast<unsigned int>(std::time(nullptr)));
			std::random_shuffle(database, database + SIZE);									//TO DO ----------------------------->>>>> change to C++ 17 std::shuffle
			mysteryWord = database[0];
			delete[] database;
		}
		file.close();
	}
	else
	{
		cout << "[ERROR] can not read from file: [RandomWordDataBase.txt]\nPlease re-import it" << endl;
	}
}
void wordOfDay(std::string& mysteryWord)
{
	// transform date -> day
	// select word accordingly to the day
		//TO DO 
	// -> mysteryWord from file "WordOfDay.txt"
	// re-write today date in "WordOfDay.txt"
	//close file "WordOfDay.txt"
}