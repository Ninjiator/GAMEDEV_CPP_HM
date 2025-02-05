#pragma 

struct Student
{
    std::string name;
    int marks[4] = { 0 };
};

double getAverageMark(const Student& student);
void printStudentInfo(const Student* student, int studentGroupIndex);
const Student* getStudentWithHighScore(const Student* studentPtr, unsigned size);
int getStudentsWithMark(const Student* studentsPtr, unsigned size, int& markPredicate);
void getOutSize(unsigned int& outSize, const unsigned inSize, unsigned int percent);
void getBestStudents(Student* inStudents, unsigned inSize, Student* outStudents, unsigned& outSize);
void sortStudentsByMark(Student* students, unsigned groupSize);