#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include "LenghtComparator.h"


bool compareByLength(const std::string& str1, const std::string & str2)
{
	return str1.length() < str2.length();
}

void printVec(std::vector<std::string> vec)
{
	for (int i = 0; i < vec.size(); i++)
	{
		std::cout << vec[i] << std::endl;
	}
}

unsigned int countDivisibleBy(const std::vector<int>& vec, int number)
{
	unsigned int amount = 0;
	amount = static_cast<unsigned int>(std::count_if(vec.begin(), vec.end(), [number](const int& a) 
	{
		return a % number == 0;
	}
	));
	return amount;
}

int main()
{
	//Task 1
	std::vector<std::string> stringContainer = {"", "gfdsmg", "abc", "oewmnfgone"};
	std::cout << "\nVector before sorting:\n";

	printVec(stringContainer);

	std::sort(stringContainer.begin(), stringContainer.end(), compareByLength);
	std::cout << "\nVector after sorting str1 > str2 via func:\n";

	printVec(stringContainer);


	//Task 2
	std::sort(stringContainer.begin(), stringContainer.end(), [](const std::string& str1, const std::string& str2)
	{
			return str1.length() > str2.length();
	}
	);
	std::cout << "\nVector after sorting str1 < str2 via lamda:\n";
	printVec(stringContainer);

	//Task 3
	std::cout << "\nVector after sorting str1 > str2 via func obj:\n";
	std::sort(stringContainer.begin(), stringContainer.end(), LengthComparator());
	printVec(stringContainer);

	//Task 4
	std::vector<int> intVec = {10, 26, 30, 41, 75, 100 };
	std::cout << "\n" << countDivisibleBy(intVec, 1);
}

