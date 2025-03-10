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
    //пропустити string через цикл, створити новий стр≥нг, з л≥тер €ки були до \n,
    //в≥дн€ти в≥д стр1 - стр2, це буде остачч€ сл≥в, стр2 додати в контейнер set
    //повторити поки в стр1 1 елементом не буде \n
    //повернути size set

    
}

