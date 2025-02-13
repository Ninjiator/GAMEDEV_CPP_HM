#include <iostream>
#include <string>
#include <algorithm>

#include "StudentGet.h"

//task 1
double getAverageMark(const Student& student)
{
    int size = sizeof(student.marks) / sizeof(student.marks[0]);
    int total = 0;
    for (int i = 0; i < size; i++)
    {
        total += student.marks[i];
    }
    return total / size;
}

void printStudentInfo(const Student* student, int studentGroupIndex)
{
    std::cout << student[studentGroupIndex].name << " average mark - " << getAverageMark(student[studentGroupIndex]) << std::endl;
};

//Task 3
const Student* getStudentWithHighScore(const Student* studentPtr, unsigned size)
{
    if (size == 0) return nullptr;  

    const Student* bestStudent = &studentPtr[0];
    int highestAverage = getAverageMark(studentPtr[0]);

    for (unsigned int i = 1; i < size; i++)  
    {
        double currentAverage = getAverageMark(studentPtr[i]);
        if (currentAverage > highestAverage)
        {
            highestAverage = currentAverage;
            bestStudent = &studentPtr[i];
        }
    }

    return bestStudent;
}

//Task 4
int getStudentsWithMark(const Student* studentsPtr, unsigned size, int markPredicate)
{
    int count = 0;
    for (unsigned int i = 0; i < size; i++)
    {
        int markAmount = sizeof(studentsPtr[i].marks) / sizeof(studentsPtr[i].marks[0]);
        int total = 0;
        for (int j = 0; j < markAmount; j++)
        {
            total += studentsPtr[i].marks[j];
        }
        int avrMark = total / markAmount;
        if (avrMark > markPredicate)
        {
            count++;
        }
    }
    return count;
};

//Task 5 
void getOutSize(unsigned int& outSize, const unsigned inSize, unsigned int percent)
{
    outSize = (percent * inSize) / 100;
    if (outSize < 1)
    {
        outSize = 1;
    }
};

void getBestStudents(Student* inStudents, unsigned inSize, Student* outStudents, unsigned& outSize)
{
    for (unsigned int i = 0; i < inSize - 1; i++)
    {
        for (unsigned int j = 0; j < inSize - i - 1; j++)
        {
            if (getAverageMark(inStudents[j]) < getAverageMark(inStudents[j + 1]))
            {
                std::swap(inStudents[j], inStudents[j + 1]);
            }
        }
    }
    for (unsigned int i = 0; i < outSize && i < inSize; i++)
    {
        outStudents[i] = inStudents[i];
    }
}

//Task 6
void sortStudentsByMark(Student* students, unsigned groupSize)
{
    for (unsigned int i = 0; i < groupSize - 1; i++)
    {
        unsigned int maxIndex = i;
        for (unsigned int j = i + 1; j < groupSize; j++)
        {
            if (getAverageMark(students[j]) > getAverageMark(students[maxIndex]))
            {
                maxIndex = j;
            }
        }
        if (maxIndex != i)
        {
            std::swap(students[i], students[maxIndex]);
        }
    }
}