#pragma once
#include <iostream>

class Vector2d
{
public:
	Vector2d(float x, float y);
	//Vector2d() { std::cout << " [C-tor called] " << std::endl; }

	static void printCalledVectors() { std::cout << "Vector2d was called: " << CalledVectorConstructors << " times" << std::endl; }

	float getX() const { return m_x; }
	float getY() const { return m_y; }


	Vector2d operator+(const Vector2d& secondVector) const {return Vector2d(this->m_x + secondVector.m_x, this->m_y + secondVector.m_y);}
	Vector2d operator-(const Vector2d& secondVector) const {return Vector2d(this->m_x - secondVector.m_x, this->m_y - secondVector.m_y);}
	Vector2d operator=(const Vector2d& secondVector) { return Vector2d(this->m_x = secondVector.m_x, this->m_y = secondVector.m_y); }
	float& operator[](std::size_t idx) { if (idx == 0) return this->m_x; else return this->m_y; }
	

private:
	float m_x = 0.0f;
	float m_y = 0.0f;
	static int CalledVectorConstructors;
}; 