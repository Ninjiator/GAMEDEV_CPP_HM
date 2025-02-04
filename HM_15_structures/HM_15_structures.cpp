#include <iostream>
#include <string>
#include <algorithm>


struct Student
{
    std::string name;
    int marks[4] = {0};
};


//task 1
int AverageMark(const Student& student) 
{
    int size = sizeof(student.marks) / sizeof(student.marks[0]);
    int total = 0;
    for (int i = 0; i < size; i++)
    {
        total += student.marks[i];
    }
    return total / size;
};

void PrintStudentInfo(const Student* student, int studentIndex)
{
    std::cout << student[studentIndex].name << " average mark - " << AverageMark(student[studentIndex]) << std::endl;
};

//Task 3
const Student* GetStudentWithHighScore(const Student* studentPtr, unsigned size)
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
int MarkPredicate(const Student* studentsPtr, unsigned size, int& markPredicate)
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
void GetBestStudents(Student* inStudents, unsigned inSize, Student* outStudents, unsigned& outSize, unsigned percent) 
{

};

//Task 6
void SortStudentsByMark(Student* students, unsigned groupSize)
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

    for (unsigned int k = 0 ; k < groupSize; k++) // sorting DOEST NOT WORK  !!!
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
    std::cout << student_1.name << " average mark is: " << AverageMark(student_1) << std::endl << std::endl << std::endl;
    
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
    
    const Student* bestStudent = GetStudentWithHighScore(groupOfStudents, 4);
    std::cout << "Best student in group is " << bestStudent->name << std::endl;
    PrintStudentInfo(groupOfStudents, 0);
    PrintStudentInfo(groupOfStudents, 1);
    PrintStudentInfo(groupOfStudents, 2);
    PrintStudentInfo(groupOfStudents, 3);
    
    //Task 4
    int predicate = 80;
    std::cout << "\n\nTask 4:" << std::endl;
    std::cout << "Amout of student with  mark >= " << predicate << ", is: " << MarkPredicate(groupOfStudents, 4, predicate) << std::endl;

    //Task 5
    std::cout << "Task 5:" << std::endl;
    Student perspectiveStudents[4];

    //Task 6
    std::cout << "Task 6:" << std::endl;
    SortStudentsByMark(groupOfStudents, 4);
    PrintStudentInfo(groupOfStudents, 0);
    PrintStudentInfo(groupOfStudents, 1);
    PrintStudentInfo(groupOfStudents, 2);
    PrintStudentInfo(groupOfStudents, 3);
}   

