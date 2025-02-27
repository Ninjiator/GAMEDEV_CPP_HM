#include "DynamicIntArray.h"
#include <iostream>
//Implementations go here

DynamicIntArray::DynamicIntArray() : m_size(0)
{
	m_data = new int[m_size];
}

DynamicIntArray::DynamicIntArray(std::size_t size) : m_size(static_cast<int>(size))
{
	if (m_size > 0)
	{
		m_data = new int[m_size];
		for (int i = 0; i < m_size; i++)
		{
			m_data[i] = 0;
		}
	}
	else
	{
		m_data = nullptr;
	}
}

DynamicIntArray::DynamicIntArray(const DynamicIntArray& other)
{
	m_data = new int[other.m_size];
	this->m_size = other.m_size;
	for (int i = 0; i < other.m_size; i++)
	{
		m_data[i] = other.m_data[i];
	}
}

DynamicIntArray& DynamicIntArray::operator=(const DynamicIntArray& other)
{
	if (this == &other)
		return *this;

	delete[] m_data;

	m_data = new int[other.m_size];

	// Копіюємо дані
	m_size = other.m_size;
	for (int i = 0; i < other.m_size; i++) 
	{
		m_data[i] = other.m_data[i];
	}

	return *this;
}

void DynamicIntArray::setSize(std::size_t newSize)
{
	if (newSize == m_size)
	{
		return;
	}

	int* copy = new int[newSize];
	int copySize = std::min(static_cast<int>(m_size), static_cast<int>(newSize));

	for (int i = 0; i < copySize; i++) 
	{
		copy[i] = m_data[i];  
	}

	for (int j = copySize; j < newSize; j++) 
	{
		copy[j] = 0;  
	}

	delete[] m_data;
	m_size = newSize;
	m_data = copy;
}

void DynamicIntArray::push_back(int element)
{
	int newSize = m_size + 1;
	this->setSize(newSize);
	m_data[m_size - 1] = element;
}

DynamicIntArray::~DynamicIntArray()
{
	delete[] m_data;
}

int& DynamicIntArray::operator[](std::size_t index)
{
	return m_data[index];
}

void DynamicIntArray::clear()
{
	delete[] m_data;	
	m_size = 0;
	m_data = new int[m_size];
}

bool DynamicIntArray::operator==(const DynamicIntArray& other)
{
	if (this->m_size != other.m_size)
		return false;

	for (int i = 0; i < m_size; i++)
	{
		if (this->m_data[i] != other.m_data[i])
		{
			return false;
		}
	}

	return true;
}

bool DynamicIntArray::operator!=(const DynamicIntArray& other)
{
	if (this->m_size == other.m_size)
	{
		for (int i = 0; i < m_size; i++)
		{
			if (this->m_data[i] != other.m_data[i])
			{
				return true;
			}
		}
		return false;
	}
	return true;
}

std::size_t DynamicIntArray::getSize() const
{
	return m_size;
}


