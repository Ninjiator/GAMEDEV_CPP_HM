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
};

void printStudentInfo(const Student* student, int studentGroupIndex)
{
    std::cout << student[studentGroupIndex].name << " average mark - " << getAverageMark(student[studentGroupIndex]) << std::endl;
};

//Task 3
const Student* getStudentWithHighScore(const Student* studentPtr, unsigned size)
{
    int* total = new int[size]();

    for (unsigned int i = 0; i < size; i++)
    {
        int markAmount = sizeof(studentPtr[i].marks) / sizeof(studentPtr[i].marks[0]);
        for (int j = 0; j < markAmount; j++)
        {
            total[i] += studentPtr[i].marks[j];
        }
        total[i] = total[i] / markAmount;
    }
    int bestIndex = 0;
    for (unsigned int i = 0; i < size; i++)
    {
        if (total[i] > total[bestIndex])
        {
            bestIndex = i;
        }
    }
    delete[] total;
    return &studentPtr[bestIndex];
};

//Task 4
int getStudentsWithMark(const Student* studentsPtr, unsigned size, int& markPredicate)
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
    if (outSize != 0)
    {
        double* averages = new double[inSize];
        int* stud_index = new int[inSize];
        for (unsigned int i = 0; i < inSize; i++)
        {
            averages[i] = getAverageMark(inStudents[i]);
            stud_index[i] = i;
        }

        for (unsigned int i = 0; i < inSize; i++)
        {
            for (unsigned int j = 0; j < inSize - 1; j++)
            {
                if (averages[stud_index[j]] < averages[stud_index[j + 1]])
                {
                    std::swap(stud_index[j], stud_index[j + 1]);
                }
            }
        }

        for (unsigned int i = 0; i < outSize; i++)
        {
            outStudents[i] = inStudents[stud_index[i]];
        }

        delete[] averages;
        delete[] stud_index;
    }
}

//Task 6
void sortStudentsByMark(Student* students, unsigned groupSize)
{
    int* avrMarks = new int[groupSize];

    for (unsigned int i = 0; i < groupSize; i++)
    {
        int markAmount = sizeof(students[i].marks) / sizeof(students[i].marks[0]);
        int sum = 0;
        for (int j = 0; j < markAmount; j++)
        {
            sum += students[i].marks[j];
        }
        avrMarks[i] = sum / markAmount;
    }

    for (unsigned int i = 0; i < groupSize - 1; i++)
    {
        unsigned int maxIndex = i;
        for (unsigned int j = i + 1; j < groupSize; j++)
        {
            if (avrMarks[j] > avrMarks[maxIndex])
            {
                maxIndex = j;
            }
        }
        if (maxIndex != i)
        {
            std::swap(students[i], students[maxIndex]);
            std::swap(avrMarks[i], avrMarks[maxIndex]);
        }
    }

    delete[] avrMarks;
}