#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


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
	std::vector<std::string> stringContainer = { "gfdsmg", "abc", "oewmnfgone"};
	std::cout << "Vector before sorting:\n";

	printVec(stringContainer);

	std::sort(stringContainer.begin(), stringContainer.end(), compareByLength);
	std::cout << "Vector after sorting:\n";
	printVec(stringContainer);
	//Task 2
	std::vector<std::string> stringContainer2 = { "ggggg", "abc", "xxxl"};
	std::cout << "Vector before sorting:\n";

	printVec(stringContainer2);

	std::sort(stringContainer2.begin(), stringContainer2.end(), [](const std::string& str1, const std::string& str2)
	{
			return str1.length() < str2.length();
	}
	);
	std::cout << "Vector after sorting:\n";
	printVec(stringContainer2);
}

