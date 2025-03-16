#include <iostream>
#include "Vector2d.h"



void operator<<(std::ostream& out, const Vector2d& vector)
{ 
	out << "{" << vector.getX() << " ; " << vector.getY() << "}";
}

int main()
{
	Vector2d vector1 = { 5.1f , 2.0f };
	Vector2d vector2 = { 3.5f , 1.2f};
	Vector2d vector3;

	std::cout << "Vector 1: " << vector1 ;

	std::cout << "\n\nVector 2: " << vector2;

	std::cout << "\n\nVector 3: " << vector3;

	
	std::cout << "\n\nVec1 + Vec2 = Vec3";
	vector3 = vector1 + vector2;
	std::cout << vector3;
	
	std::cout << "\n\nVec1 - Vec2 = Vec3";
	vector3 = vector1 - vector2;
	std::cout << vector3;

	
	float x = vector1[0];
	std::cout << "\n\nX of Vec1 = " << x << std::endl;
	float y = vector1[1];
	std::cout << "Y of Vec1 = " << y << std::endl << std::endl;

	Vector2d::printCalledVectors();
	
}
