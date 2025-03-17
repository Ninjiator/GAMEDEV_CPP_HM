#include <iostream>
#include "Vector2d.h"
#include <cmath>


int Vector2d::CalledVectorConstructors = 0;

Vector2d::Vector2d(float x, float y)
{
	this->m_x = x;
	this->m_y = y;
	CalledVectorConstructors++;
	//std::cout << "\n[C-tor called]" << std::endl;
}

Vector2d::Vector2d(float x0, float y0, float x1, float y1)
{
	this->m_x = x1 - x0;
	this->m_y = y1 - y0;
	CalledVectorConstructors++;
	//std::cout << "\n[C-tor called]" << std::endl;
}

float Vector2d::getLength() const
{
	return static_cast<float>(std::sqrt(std::pow(this->m_x, 2) + std::pow(this->m_y, 2)));
}

float Vector2d::getAngle(const Vector2d& other) const
{
	return ((this->dotProduct(other)) / (this->getLength() * other.getLength()));
}

Vector2d Vector2d::operator=(const Vector2d secondVector)
{
	this->m_x = secondVector.m_x;
	this->m_y = secondVector.m_y; 

	return *this;
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
    float dotProduct = this->dotProduct(other);
    float length1 = this->getLength();
    float length2 = other.getLength();

    const float epsilon = 1e-5;

    if (this->equal(other)) {
        return VectorRelativeState::Identical;
    }
    if (dotProduct > 0 && std::abs(dotProduct - (length1 * length2)) < epsilon) {
        return VectorRelativeState::coDirected;
    }
    if (dotProduct < 0 && std::abs(dotProduct + (length1 * length2)) < epsilon) {
        return VectorRelativeState::OppositeDirected;
    }
    if (std::abs(dotProduct) < epsilon) {
        return VectorRelativeState::RightAngle;
    }
    if (dotProduct > 0) {
        return VectorRelativeState::AcuteAngle;
    }

    return VectorRelativeState::ObtuseAngle;
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
