#include <iostream>
#include <vector>
#include <set>

unsigned int uniqueWordsCount(const std::string& line)
{
    std::vector<std::string> word;
    std::string lineCopy = line;
    std::set<std::string> searched;
    while (lineCopy != '\n')
    {

    }
    for (int i = 0; line[i] != '\n'; i++)
    {
        word[i] = line[i];
    }
    searched.insert(word);
    word.clear();

}
int main()
{
    //���������� string ����� ����, �������� ����� �����, � ���� ��� ���� �� \n,
    //������ �� ���1 - ���2, �� ���� ������� ���, ���2 ������ � ��������� set
    //��������� ���� � ���1 1 ��������� �� ���� \n
    //��������� size set

    
}

