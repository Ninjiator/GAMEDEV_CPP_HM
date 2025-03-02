#pragma once
#include <cstdlib>

class DynamicIntArray
{
public:
    DynamicIntArray();

    DynamicIntArray(std::size_t size);

    ~DynamicIntArray();

    int& operator[](std::size_t index);

    void clear();

    bool operator==(const DynamicIntArray& other);
    bool operator!=(const DynamicIntArray& other);

    std::size_t getSize() const;

    DynamicIntArray(const DynamicIntArray& other);
    DynamicIntArray& operator=(const DynamicIntArray& other);
    void setSize(std::size_t newSize);

    void push_back(int element);

private:
    int* m_data = nullptr;
    int m_size = 0;
};