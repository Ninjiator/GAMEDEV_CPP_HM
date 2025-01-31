#include <iostream>
#include <fstream>
#include <algorithm>
#include <random>

using std::cout;
using std::cerr;
using std::endl;

void randomWord(std::string& mysteryWord, const char* fileName)
{
	std::fstream file;
	file.open(fileName, std::ios_base::in);
	if (file.is_open())
	{
		int SIZE = 0;
		file >> SIZE;
		if (SIZE != 0 && SIZE > 0)
		{
			std::string* database = new std::string[SIZE];
			for (int i = 0; i < SIZE; i++)
			{
				file >> database[i];
			}
			std::random_device rd;
			std::mt19937 g(rd());
			std::shuffle(database, database + SIZE, g);
			mysteryWord = database[0];
			delete[] database;
		}
		file.close();
	}
	else
	{
		cerr << "[ERROR] can not read from file: [RandomWordDataBase.txt]\nPlease re-import it" << endl;
	}
}

void wordOfDay(std::string& mysteryWord, const char* dataBase_1)
{
	std::fstream file;
	file.open(dataBase_1, std::ios_base::in);
	if (!file.is_open())
	{
		cerr << "[ERROR] Cannot read from file: [" << dataBase_1 << "]\nPlease re-import it." << std::endl;
		return;
	}

	int SIZE = 0;
	file >> SIZE;

	if (SIZE <= 0)
	{
		cerr << "[ERROR] The database is empty or corrupted in [" << dataBase_1 << "]" << std::endl;
		file.close();
		return;
	}

	std::string* database = new std::string[SIZE]; 
	for (int i = 0; i < SIZE; i++)
	{
		file >> database[i];
	}
	file.close();

	std::random_device rd;
	std::mt19937 g(rd());
	std::shuffle(database, database + SIZE, g);

	mysteryWord = database[SIZE - 1];
	SIZE--;
	std::ofstream outFile(dataBase_1, std::ios::trunc);
	if (outFile.is_open())
	{
		outFile << SIZE << std::endl; 
		for (int i = 0; i < SIZE; i++)
		{
			outFile << database[i] << std::endl;
		}
		outFile.close();
	}
	else
	{
		cerr << "[ERROR] Cannot write to file: [" << dataBase_1 << "]" << std::endl;
	}

	delete[] database; 
}

bool IsWordGuessToday(const char* fileName, const int& day, const int& month, const int& year)
{
	std::fstream file;
	file.open(fileName, (std::ios::in));
	if (file.is_open())
	{
		int day_file;
		int month_file;
		int year_file;

		file >> day_file;
		file >> month_file;
		file >> year_file;

		if (day_file == day && month_file == month && year_file == year)
		{
			file.close();
			cout << "Already found! Come back tomorrow!" << std::endl;
			return false;
		}
		file.close();

		std::ofstream outFile(fileName, std::ios::trunc); 
		if (outFile.is_open())
		{
			outFile << day << "\n" << month << "\n" << year << std::endl;
			outFile.close();
			return true;
		}
		else
		{
			cerr << "[ERROR] Cannot write to file: [" << fileName << "]" << std::endl;
			return false;
		}
	}
	else
	{
		cerr << "[ERROR] can not write in file: [RandomWordDataBase.txt]\nPlease re-import it" << endl;
		return false;
	}
}