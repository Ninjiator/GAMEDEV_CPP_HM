#include <iostream>
#include "Vector2d.h"
#include <cmath>

int Vector2d::CalledVectorConstructors = 0;

Vector2d::Vector2d(float x, float y)
{
	this->m_x = x;
	this->m_y = y;
	CalledVectorConstructors++;
	std::cout << "\n[C-tor called]" << std::endl;
}

float Vector2d::getLength() const
{
	return static_cast<float>(std::sqrt(std::pow(this->m_x, 2) + std::pow(this->m_y, 2)));
}

float Vector2d::getAngle(const Vector2d& other) const
{
	return static_cast<float>(std::pow(std::cos((this->dotProduct(other)) / (this->getLength() * other.getLength())), -1));
}

bool Vector2d::equal(const Vector2d& other) const
{
	if (this->m_x == other.m_x && this->m_y == other.m_y)
	{
		return true;
	}
	return false;
}

VectorRelativeState Vector2d::getRelativeState(const Vector2d& other) const
{
	float angleBeetween = this->getAngle(other);

	if (angleBeetween == 0.0f && this->equal(other))
	{
		return VectorRelativeState::Identical;
	}
	if (angleBeetween == 0.0f && !(this->equal(other)))
	{
		return VectorRelativeState::coDirected;
	}
	if (angleBeetween == 180.0f)
	{
		return VectorRelativeState::OppositeDirected;
	}
	if (angleBeetween < 90.0f)
	{
		return VectorRelativeState::AcuteAngle;
	}
	if (angleBeetween > 90.0f && angleBeetween < 180.0f)
	{
		return VectorRelativeState::ObtuseAngle;
	}
	if (this->dotProduct(other) == 0.0f)
	{
		return VectorRelativeState::RightAngle;
	}
	return VectorRelativeState::Error;
}

Vector2d::Vector2d(float x0, float y0, float x1, float y1)
{
	this->m_x = x1 - x0;
	this->m_y = y1 - y0;
	CalledVectorConstructors++;
	std::cout << "\n[C-tor called]" << std::endl;
}

float Vector2d::dotProduct(const Vector2d& other) const
{
	return (this->m_x * other.m_x + this->m_y * other.m_y);
}

Vector2d Vector2d::negate() const
{
	return Vector2d(-this->m_x, -this->m_y);
}

void Vector2d::scale(float factorX, float factorY)
{
	m_x = m_x * factorX;
	m_y = m_y * factorY;
}
