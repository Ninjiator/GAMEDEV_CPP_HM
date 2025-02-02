#include <iostream>
#include <string>

struct Student
{
    std::string name;
    int marks[4] = {0};
};

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
 
int markPredicate(const Student* studentPtr, int size, int& mark)
{
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        int markAmount = sizeof(studentPtr[i].marks) / sizeof(studentPtr[i].marks[0]);
        int total = 0;
        for (int j = 0; j < markAmount; j++)
        {
            total += studentPtr[i].marks[j];
        }
        int avrMark = total / markAmount;
        if (avrMark > mark)
        {
            count++;
        }
    }
    return count;
};

const Student* GetBestStudent(const Student* studentPtr, int size)
{
    if (size == 0)
    {
        return nullptr;
    }

    const Student* best = &studentPtr[0];
    
    int* total = new int[size](); 

    for (int i = 0; i < size; i++)
    {
        int markAmount = sizeof(studentPtr[i].marks) / sizeof(studentPtr[i].marks[0]);
        for (int j = 0; j < markAmount; j++)
        {
            total[i] += studentPtr[i].marks[j];
        }
    }
    int bestIndex = 0;
    for (int i = 0; i < size; i++)
    {
        if (total[i] > total[bestIndex])
        {
            bestIndex = i;
        }
    }
    delete[] total;
    best = &studentPtr[bestIndex];
    return best;
};

int main()
{
    Student student_1 = { "Jonh", {80, 50, 20, 30} };

    std::cout << student_1.name << " average mark is: " << AverageMark(student_1) << std::endl;
    Student groupA[4] = 
    { 
    { {"Leonard"}, {80, 85, 70, 65} },
    { {"Rafael"}, {98, 100, 95, 95} },
    { {"Mikelangelo"}, {80, 78, 80, 90} },
    { {"Donatello"}, {90, 68, 61, 78} }
    };
    int predicate = 80;
    std::cout << "Amout of student with average mark > " << predicate << " is: " << markPredicate(groupA, 4, predicate) << std::endl;

    std::cout << GetBestStudent(groupA, 4) << std::endl;
    std::cout << &groupA[0] << std::endl;
    std::cout << &groupA[1] << std::endl;
    std::cout << &groupA[2] << std::endl;
    std::cout << &groupA[3] << std::endl;
}

