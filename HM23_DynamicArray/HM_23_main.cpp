#include <iostream>
#include "DynamicIntArray.h"

int main()
{
	DynamicArray<int> array1;
	DynamicArray<int> array2(5);

	std::cout << "Array 1 size: " << array1.getSize() << std::endl;
	std::cout << "Array 2 size: " << array2.getSize() << std::endl;
	for (int i = 0; i < array2.getSize(); i++)
	{
		array2[i] = 13;
	}
	array2 = array1;
	std::cout << "Second element of array 2 is : " << array2[2] << std::endl;
	array2.clear();
	std::cout << "Array 2 size after .clear() : " << array2.getSize() << std::endl;

	if (array1 == array2)
	{
		std::cout << "true\n";
	}
	else
	{
		std::cout << "false\n";
	}
	DynamicArray<int> array3(5);
	DynamicArray<int> array4(4);
	array3[2] = 13;
	array4[2] = 13;
	if (array3 == array4)
	{
		std::cout << "Is array 3 == array 4 :\ntrue\n";
	}
	else
	{
		std::cout << "Is array 3 == array 4 :\nfalse\n";
	}

	array2 = array4;
	if (array2 == array4)
	{
		std::cout << "Is array 3 == array 4 :\ntrue\n";
	}
	else
	{
		std::cout << "Is array 3 == array 4 :\nfalse\n";
	}

	array2.setSize(7);
	array4.setSize(6);
	std::cout << "Array 2 size after .setSize(7) : " << array2.getSize() << std::endl;
	std::cout << "Array 4 size after .setSize(3) : " << array4.getSize() << std::endl;
	array4.push_back(6);
	std::cout << "Array 4 size after .push_back(5) : [" << array4.getSize() << "] 5th element is: [" << array4[6] << "]" << std::endl;
	std::cout << "\nLast element of Array 4" << array4.back();
	// HM23
	DynamicArray<std::string> str1;
	DynamicArray<std::string> str2(5);

	std::cout << "\n\n\nstring array 1 size: " << str1.getSize() << std::endl;
	std::cout << "string array 2 size: " << str2.getSize() << std::endl;
	str1.push_back("abc");
	std::cout << "zero element of str1 after push_back: " << str1[0];
	str1 = str2;

	bool isEqual = str1 == str2;
	std::cout << "\n" << isEqual;

	
	str1.reserve(100);
	std::cout << "\nCapacity of str1 after increasing : " << str1.getCapacity();
	str1.shrinkToFit();
	std::cout << "\nCapacity of str1 after shrinkToFit " << str1.getCapacity();
	str1.back();
	
}

