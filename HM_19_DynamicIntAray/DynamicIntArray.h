#pragma once
#include <cstdlib>

class DynamicIntArray
{
public:
    //MAIN HW PART
        //default c-tor
    DynamicIntArray();

    //c-tor with size
    DynamicIntArray(std::size_t size);

    //free allocated memory
    ~DynamicIntArray();

    int& operator[](std::size_t index);

    //Clear internal memory, set size to 0
    void clear();

    //Comparison operators
    bool operator==(const DynamicIntArray& other);
    bool operator!=(const DynamicIntArray& other);


    std::size_t getSize() const;





  
    DynamicIntArray(const DynamicIntArray& other);
    DynamicIntArray& operator=(const DynamicIntArray& other);
    void setSize(std::size_t newSize);

    //ADDITIONAL HW
    //delete previous memory, create new inner array with updated size saving old content if possible
    

    // Allocate new memory (old memory + 1 new element)
    // Copy old content to new inner array
    // insert new element at the last index
    // update size
    void push_back(int element);

private:
    int* m_data = nullptr;
    int m_size = 0;
};