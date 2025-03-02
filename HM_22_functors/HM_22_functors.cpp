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

int main()
{
	//Task 1
	std::vector<std::string> stringContainer = {"", "gfdsmg", "abc", "oewmnfgone"};
	std::cout << "\nVector before sorting:\n";

	printVec(stringContainer);

	std::sort(stringContainer.begin(), stringContainer.end(), compareByLength);
	std::cout << "\nVector after sorting str1 > str2:\n";

	printVec(stringContainer);


	//Task 2
	std::sort(stringContainer.begin(), stringContainer.end(), [](const std::string& str1, const std::string& str2)
	{
			return str1.length() > str2.length();
	}
	);
	std::cout << "\nVector after sorting str1 < str2:\n";
	printVec(stringContainer);
	std::cout << "\nVector after sorting str1 > str2:\n";
	std::sort(stringContainer.begin(), stringContainer.end(), LengthComparator());
	printVec(stringContainer);
}

