#include <iostream>
#include <string>
#include <algorithm>

#include "StudentGet.h"





int main()
{
    //Task 1
    Student student_1 = { "Jonh", {80, 50, 20, 30} };
    std::cout << "Task 1:" << std::endl;
    std::cout << student_1.name << " average mark is: " << getAverageMark(student_1) << std::endl << std::endl << std::endl;
    
    //Task 2
    Student groupOfStudents[4] =
    {
    { {"Raphael"}, {80, 85, 70, 65} },
    { {"Donatello"}, {98, 100, 95, 95} },
    { {"Leonardo"}, {80, 78, 80, 90} },
    { {"Michelangelo "}, {90, 68, 61, 78} }
    };

    //Task 3
    std::cout << "Task 3:" << std::endl;
    
    const Student* bestStudent = getStudentWithHighScore(groupOfStudents, 4);
    std::cout << "Best student in group is " << bestStudent->name << std::endl;
    for (int i = 0; i < 4; i++)
    {
        printStudentInfo(groupOfStudents, i);
    }
    
    //Task 4
    int predicate = 80;
    std::cout << "\n\nTask 4:" << std::endl;
    std::cout << "Amout of student with  mark >= " << predicate << ", is: " << getStudentsWithMark(groupOfStudents, 4, predicate) << std::endl << std::endl;

    //Task 5
    std::cout << "Task 5:" << std::endl;
    int percent = 34;
    unsigned int outSize = 0;
    const int inSize = 8;
    Student inStudents[inSize] =
    {
    { {"Raphael"}, {80, 85, 70, 65} },
    { {"Donatello"}, {98, 100, 95, 95} },
    { {"Leonardo"}, {80, 78, 80, 90} },
    { {"Michelangelo "}, {90, 68, 61, 78} },
    { {"Splinter "}, {85, 78, 61, 78} },
    { {"April "}, {90, 69, 61, 61} },
    { {"Nikolas"}, {60, 65, 100, 78} },
    { {"Creng "}, {72, 68, 61, 78} },
    };
    getOutSize(outSize, inSize, percent);
    Student* outStudents = new Student[outSize];
    getBestStudents(inStudents, inSize, outStudents, outSize);
    std::cout << "Best student accordingly to percent: " << percent << std::endl;
    for (unsigned int i = 0; i < outSize; i++)
    {
        printStudentInfo(outStudents, i);
    }
    delete[] outStudents;

    //Task 6
    std::cout << "\nTask 6:" << std::endl;
    sortStudentsByMark(inStudents, inSize);
    for (unsigned int i = 0; i < inSize; i++)
    {
        printStudentInfo(inStudents, i);
    }
}   

