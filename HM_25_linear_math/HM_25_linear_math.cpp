#include <iostream>
#include "Vector2d.h"



void operator<<(std::ostream& out, const Vector2d& vector)
{ 
	out << "{" << vector.getX() << " ; " << vector.getY() << "}";
}

int main()
{
	//Tasks from HM17
	Vector2d vector1 = { 5.1f , 2.0f };
	Vector2d vector2 = { 3.5f , 1.2f};
	Vector2d vector3;

	std::cout << "Vector 1: " << vector1 ;

	std::cout << "\n\nVector 2: " << vector2;

	std::cout << "\n\nVector 3: " << vector3;

	
	std::cout << "\n\nVector1 + Vector2 = Vector3";
	vector3 = vector1 + vector2;
	std::cout << vector3;
	
	std::cout << "\n\nVector1 - Vector2 = Vector3";
	vector3 = vector1 - vector2;
	std::cout << vector3;

	
	float x = vector1[0];
	std::cout << "\n\nX of Vector1 = " << x << std::endl;
	float y = vector1[1];
	std::cout << "Y of Vector1 = " << y << std::endl << std::endl;

	//Task's from HM25
	Vector2d vec_1 = { 0.0f, 0.0f, 3.1f, 5.6f };
	std::cout << "\nVec_1 created from tail & head coordinates: " << vec_1;
	Vector2d vec_2 = { 3.0f, -1.5f, 5.0f, 1.0f };
	std::cout << "\nVec_2 created from tail & head coordinates: " << vec_2;
	float dotProd = vec_1.dotProduct(vec_2);
	std::cout << "\nDot Product of vec_1 & vec_2: " << dotProd << std::endl;
	Vector2d vec_3 = vec_1.negate();
	std::cout << "Vec_3 is negate of Vec_1: " << vec_3;
	
	vec_3.scale(2.0, 1.0);
	std::cout << "\nVec_3 x2 scale by x: " << vec_3;

	std::cout << std::endl;
	Vector2d::printCalledVectors();
	
	vec_3 = vec_1;

	vec_1.getRelativeState(vec_3);
}
