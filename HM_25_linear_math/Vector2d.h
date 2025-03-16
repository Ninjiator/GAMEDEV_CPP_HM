#pragma once
#include <iostream>

enum class VectorRelativeState
{
	Identical, // ==, angle == 0
	coDirected, // one direction but != Identical
	OppositeDirected, // pararell, angle == 180 
	AcuteAngle, // angle < 90
	ObtuseAngle, // angle > 90
	RightAngle // angle = 90
};

class Vector2d
{
public:
	Vector2d(float x, float y);
	Vector2d() { CalledVectorConstructors++; /*std::cout << "\n[C-tor called]" << std::endl;*/ }

	Vector2d(float x0, float y0, float x1, float y1);

	float dotProduct(const Vector2d& other) const;

	Vector2d negate() const;

	bool equal(const Vector2d& other) const;

	void scale(float factorX, float factorY);

	VectorRelativeState getRelativeState(const Vector2d& other) const;

	float getLength() const;
	float getAngle(const Vector2d& other) const;

	//static void printCalledVectors() { std::cout << "Vector2d was called: " << CalledVectorConstructors << " times" << std::endl; }

	float getX() const { return m_x; }
	float getY() const { return m_y; }


	Vector2d operator+(const Vector2d& secondVector) const {return Vector2d(this->m_x + secondVector.m_x, this->m_y + secondVector.m_y);}
	Vector2d operator-(const Vector2d& secondVector) const {return Vector2d(this->m_x - secondVector.m_x, this->m_y - secondVector.m_y);}
	Vector2d operator=(const Vector2d secondVector);
	float& operator[](std::size_t idx) { if (idx == 0) return this->m_x; else return this->m_y; }
	

private:
	float m_x = 0.0f;
	float m_y = 0.0f;
	static int CalledVectorConstructors;
}; 