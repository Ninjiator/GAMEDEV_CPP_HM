#include <iostream>
#include "Vector2d.h"

int Vector2d::CalledVectorConstructors = 0;

Vector2d::Vector2d(float x, float y)
{
	this->m_x = x;
	this->m_y = y;
	CalledVectorConstructors++;
	std::cout << " [C-tor called] " << std::endl;
}