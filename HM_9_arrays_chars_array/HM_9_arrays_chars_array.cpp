#include <iostream>
#include <cctype>
using std::cout;
using std::endl;
using std::cin;

void translateArray(int numbers[], int size)
{
    for (int j = 0; j < size; j++)
    {
        if (numbers[j] > 0)
        {
            numbers[j] = numbers[j] * 2;
        }
        else
        {
            numbers[j] = numbers[j] * 0;
        }
    }
}

void toUppercase(char str[])
{
    int length = 0;
    const int ASCIIshift = 32;
    while ((str[length]) != '\0')
    {
        if (std::isalpha(str[length]))
        {
            if (static_cast<int>(str[length]) >= 90)
            {
                int CharFromStr = static_cast<int>(str[length]);
                str[length] = static_cast<char>(CharFromStr - ASCIIshift);
                cout << static_cast<char>(str[length]) << "";
            }
            else
            {
                cout << str[length] << "";
            }
        }
        else
        {
            cout << str[length] << "";
        }
        length++;
    }
}

bool isPalindrom(const char str[])
{
    int length = 0;
    while ((str[length]) != '\0')
    {
        length++;
    }
    for (int j = 0; j < length / 2; j++)
    {
        if ((str[j]) != (str[length - j - 1]))
        {
            return false;
        }
    }
    return true;
}

void parseStringLetters(const char str[], int& vowelsCount, int& constonantsCount)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        char c = tolower(str[i]);
        if (c >= 'a' && c <= 'z')
        {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y')
            {
                vowelsCount++;
            }
            else
            {
                constonantsCount++;
            }
        }
    }

}

bool isEqual(const char str1[], const char str2[])
{
    int lenghtStr1 = 0;
    int lenghtStr2 = 0;

    while ((str1[lenghtStr1]) != '\0')
    {
        lenghtStr1++;
    }

    while ((str2[lenghtStr2]) != '\0')
    {
        lenghtStr2++;
    }

    if (lenghtStr1 != lenghtStr2)
    {
        return false;
    }

    for (int i = 0; str1[i] != '\0'; i++)
    {
        if ((str1[i]) != (str2[i]))
        {
            return false;
        }
    }
    return true;

}

int main()
{

    //Task 1 
    const int arraySizeUserInput = 10;
    cout << "Task 1\nEnter a nums for array[10] \n";
    int arrayTask_1[arraySizeUserInput];
    for (int i = 0; i < arraySizeUserInput; i++) 
    {
        cout << "Num-[" << i << "] is: ";
        cin >> arrayTask_1[i];
    }
    translateArray(arrayTask_1, arraySizeUserInput);
    cout << "\n\nUsing a func translateArray: \n\n";

    for (int j = 0; j < arraySizeUserInput; j++)
    {
        cout << "Num-[" << j << "] is: " << arrayTask_1[j] << endl;
    }


    //Task 2 
    cout << "Task 2\nEnter a string using letters to uppercase low letters : \n";
    char stringUserInput[100];
    cin >> stringUserInput;
    toUppercase(stringUserInput);

    //Task 3 
    cout << "\n\n\nTask 3\nWrite a word to analyse on :\n";
    cin >> stringUserInput;
    cout << "->" << std::boolalpha << isPalindrom(stringUserInput);

    //Task 4
    int vowelsCount = 0;
    int constonantsCount = 0;
    cout << "\n\n\nnTask 4\nWrite a word for count Vowels & Constonant :\n";
    cin >> stringUserInput;
    parseStringLetters(stringUserInput, vowelsCount, constonantsCount);
    cout << "\nVowels count : " << vowelsCount << endl;
    cout << "Constonants count : " << constonantsCount << endl;

    //Task 5 bool isEqual(const char str1[], const char str2[]);
    char array_1[100];
    char array_2[100];
    cout << "\n\n\nTask 5\nEnter two char arrays to compare them: " << endl;
    cout << "Array 1 is ";
    cin >> array_1;
    cout << "Array 2 is ";
    cin >> array_2;
    cout << "Is Array 1 == Array 2 -> " << std::boolalpha << isEqual(array_1, array_2);



}
