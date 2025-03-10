#pragma once
#include <cstdlib>

template<typename T>
class DynamicArray
{
public:
    DynamicArray<T>();

    DynamicArray<T>(std::size_t size);
    DynamicArray<T>(const DynamicArray<T>& other);

    ~DynamicArray<T>();

	T& operator[](std::size_t index);

    void clear();

    bool operator==(const DynamicArray& other);
    bool operator!=(const DynamicArray& other);

    std::size_t getSize() const;

    
    DynamicArray& operator=(const DynamicArray& other);
    void setSize(std::size_t newSize);

    void push_back(T element);
	void reserve(std::size_t reservedSpace);
	std::size_t getCapacity() const { return m_capacity; }
	void shrinkToFit();
	void pop_back();
	T back() const;
	bool operator==(const DynamicArray<T>& other) const;

private:
    T* m_data = nullptr;
    int m_size = 0;
	std::size_t m_capacity = 0;
};



template<typename T>
DynamicArray<T>::DynamicArray() : m_size(0)
{
	m_data = new T[m_size];
}

template<typename T>
DynamicArray<T>::DynamicArray(std::size_t size) : m_size(static_cast<int>(size))
{
	if (m_size > 0)
	{
		m_data = new T[m_size]();
	}
	else
	{
		m_data = nullptr;
	}
}

template<typename T>
DynamicArray<T>::DynamicArray(const DynamicArray<T>& other)
{
	m_data = new T[other.m_size];
	this->m_size = other.m_size;
	for (int i = 0; i < other.m_size; i++)
	{
		m_data[i] = other.m_data[i];
	}
}
template<typename T>
DynamicArray<T>& DynamicArray<T>::operator=(const DynamicArray<T>& other)
{
	if (this == &other)
		return *this;

	delete[] m_data;

	m_data = new T[other.m_size];

	m_size = other.m_size;
	for (int i = 0; i < other.m_size; i++)
	{
		m_data[i] = other.m_data[i];
	}

	return *this;
}

template<typename T>
void DynamicArray<T>::setSize(std::size_t newSize)
{
	if (newSize > m_capacity) {
		reserve(newSize);
	}
	m_size = newSize;
}

template<typename T>
void DynamicArray<T>::push_back(T element)
{
	int newSize = m_size + 1;
	this->setSize(newSize);
	m_data[m_size - 1] = element;
}

template<typename T>
DynamicArray<T>::~DynamicArray()
{
	delete[] m_data;
}

template<typename T>
T& DynamicArray<T>::operator[](std::size_t index)
{
	return m_data[index];
}

template<typename T>
void DynamicArray<T>::clear()
{
	delete[] m_data;
	m_size = 0;
	m_data = new int[m_size];
}

template<typename T>
bool DynamicArray<T>::operator==(const DynamicArray<T>& other)
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

template<typename T>
bool DynamicArray<T>::operator!=(const DynamicArray<T>& other)
{
	return !(*this == other);
}

template<typename T>
std::size_t DynamicArray<T>::getSize() const
{
	return m_size;
}

template<typename T>
void DynamicArray<T>::reserve(std::size_t reservedSpace)
{
	if (reservedSpace <= m_capacity) {
		return;  
	}

	T* newData = new T[reservedSpace];  
	if (m_data) {
		std::copy(m_data, m_data + m_size, newData); 
		delete[] m_data;  
	}
	m_data = newData;
	m_capacity = reservedSpace;  
}

template<typename T>
void DynamicArray<T>::shrinkToFit()
{
	if (m_capacity > m_size)
	{
		T* newData = new T[m_size]; 
		std::copy(m_data, m_data + m_size, newData); 
		delete[] m_data; 
		m_data = newData;
		m_capacity = m_size; 
	}
}

template<typename T>
void DynamicArray<T>::pop_back()
{
	if (m_size > 0)
	{
		--m_size; 
	}
}

template<typename T>
T DynamicArray<T>::back() const
{
	if (m_size == 0)
	{
		std::cerr << "size 0";
	}
	return m_data[m_size - 1]; 
}

template<typename T>
bool DynamicArray<T>::operator==(const DynamicArray& other) const
{
	if (m_size != other.m_size)
	{
		return false;
	}
	for (std::size_t i = 0; i < m_size; ++i)
	{
		if (m_data[i] != other.m_data[i])
		{
			return false;
		}
	}
	return true;
}