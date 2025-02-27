#include <iostream>
#include "DynamicIntArray.h"

int main()
{
	DynamicIntArray array1;
	DynamicIntArray array2(5);
	std::cout << "Array 1 size: " << array1.getSize() << std::endl;
	std::cout << "Array 2 size: " << array2.getSize() << std::endl;
	for (int i = 0; i < array2.getSize(); i++)
	{
		array2[i] = 13;
	}
	array1 = array2;
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
	DynamicIntArray array3(5);
	DynamicIntArray array4(4);
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
}
