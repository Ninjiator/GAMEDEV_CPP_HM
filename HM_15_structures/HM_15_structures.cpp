#include <iostream>
#include <string>
#include <algorithm>


struct Student
{
    std::string name;
    int marks[4] = {0};
};


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
    int* avrMarks = new int[groupSize]();
    for (unsigned int i = 0; i < groupSize; i++)
    {
        int markAmount = sizeof(students[i].marks[i]) / sizeof(students[i].marks[0]);
        for (int j = 0; j < markAmount; j++)
        {
            avrMarks[i] += students[i].marks[j];
        }
        avrMarks[i] = avrMarks[i] / markAmount;
    }

    for (unsigned int k = 0; k < groupSize; k++) // sorting DOEST NOT WORK  !!!
    {
        int highest = 0;
        if (avrMarks[k] > avrMarks[highest])
        {
            std::swap(students[k], students[highest]);
            highest = k;
        }
    }
    delete[] avrMarks;
};

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
    for (unsigned int i = 0; i < outSize; i++)
    {
        printStudentInfo(outStudents, i);
    }
    delete[] outStudents;

    //Task 6
    std::cout << "Task 6:" << std::endl;
 /*   for (unsigned int i = 0; i < inSize; i++)
    {
        PrintStudentInfo(inStudents, i);
    }*/
}   

