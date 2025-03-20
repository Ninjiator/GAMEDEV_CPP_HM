#include <iostream>
#include "Vector2d.h"



void operator<<(std::ostream& out, const Vector2d& vector)
{ 
	out << "{" << vector.getX() << " ; " << vector.getY() << "}";
}

void printRelativeStateResults(VectorRelativeState result)
{
	switch (result)
	{
	case VectorRelativeState::Identical:
		std::cout << "\nVectors are: Identical" << std::endl;
		break;
	case VectorRelativeState::coDirected:
		std::cout << "\nVectors are: coDirected" << std::endl;
		break;
	case VectorRelativeState::OppositeDirected:
		std::cout << "\nVectors are: OppositeDirected" << std::endl;
		break;
	case VectorRelativeState::AcuteAngle:
		std::cout << "\nVectors are: AcuteAngle" << std::endl;
		break;
	case VectorRelativeState::ObtuseAngle:
		std::cout << "\nVectors are: ObtuseAngle" << std::endl;
		break;
	case VectorRelativeState::RightAngle:
		std::cout << "\nVectors are: RightAngle" << std::endl;
		break;
	default:
		break;
	}
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
	
	std::cout << "\n\nVector 1: " << vector1;
	std::cout << "\nVector 2: " << vector2;
	printRelativeStateResults(vector1.getRelativeState(vector2));

	std::cout << "\nVector 3: " << vector3;
	Vector2d vector4 = vector3.negate();
	std::cout << "\nVector 4: " << vector4;
	printRelativeStateResults(vector3.getRelativeState(vector4));


	Vector2d vector5 = { 1.5f, 3.0f, 7.6f, 0.5f };
	Vector2d vector6 = vector5;
	vector6.scale(2, 2);
	std::cout << "\n\nVector 5: " << vector5;
	std::cout << "\nVector 6: " << vector6;
	printRelativeStateResults(vector5.getRelativeState(vector6));

	Vector2d vector7 = { 0.f, 1.0f };
	std::cout << "\n\nVector 7: " << vector7;
	Vector2d vector8 = { 1.0f, 0.f };
	std::cout << "\nVector 8: " << vector8;
	printRelativeStateResults(vector7.getRelativeState(vector8));

	Vector2d vector9 = { -4.0f, 16.0f };
	std::cout << "\n\nVector 9: " << vector9;
	Vector2d vector10 = { 0.0f, 12.0f };
	std::cout << "\nVector 10: " << vector10;
	printRelativeStateResults(vector9.getRelativeState(vector10));

	vector1 = vector2;
	std::cout << "\nVector 1 == Vector 2: " << vector2;
	printRelativeStateResults(vector2.getRelativeState(vector1));

	Vector2d vector11 = { -10.0f, 0.0f };
	Vector2d vector12 = { 6.0f, 6.0f };
	std::cout << "\nVector 11 : " << vector11;
	std::cout << "\nVector 12 : " << vector12;
	printRelativeStateResults(vector11.getRelativeState(vector12));
}
