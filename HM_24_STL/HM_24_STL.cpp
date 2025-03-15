#include <iostream>
#include <vector>
#include <set>
#include <iostream>
#include <sstream>
#include <unordered_map>
#include <stack>

#include "Node.h"

unsigned int uniqueWordsCount(const std::string& line)
{
    std::string word;
    std::istringstream lineStream(line);
    std::set<std::string> wordsFromLine;
    while (lineStream >> word)
    {
        wordsFromLine.insert(word);
    }
    return wordsFromLine.size();
}

std::string mostOccuredWord(const std::string& line)
{
    std::string mostOccured;
    std::istringstream wordsFromLine(line);
    std::unordered_map<std::string, int> wordCount;
    while (wordsFromLine >> mostOccured)
    {
        wordCount[mostOccured]++;
    } 
    int max = 0;
    for (const auto&pair : wordCount )
    {
        if (pair.second > max)
        {
            max = pair.second;
            mostOccured = pair.first;
        }
    }
    return mostOccured;
}

bool isClosed(const std::string& line)
{
    std::stack<char> charStack;
 
    for (char c : line)
    {
        if (c == '(' || c == '{' || c == '[')
        {
            charStack.push(c);
        }
        else if (c == ')' || c == '}' || c == ']')
        {
            if (charStack.empty())
            {
                return false;
            }
            char top = charStack.top();
            charStack.pop();

            if ((c == ')' && top != '(') || (c == '}' && top != '{') || (c == ']' && top != '['))
            {
                return false;
            }
        }
    }
    return charStack.empty();
}



bool has_cycle(Node* head)
{
    if (!head || !head->next)
    {
        return false;
    }
    Node* slow = head;
    Node* fast = head;
    
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow==fast)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    std::string line1 = "hi, man, how, are, you";
    std::cout << uniqueWordsCount(line1) << std::endl;


    std::string line2 = "apple tree banana apple juice";
    std::cout << uniqueWordsCount(line2) << std::endl;
    std::cout << "\nMost occured word is: " << mostOccuredWord(line2) << std::endl;


    std::string brackets1 = "(){}{}{}";             //true
    std::cout << isClosed(brackets1);

    std::string brackets2 = "((    ( ))){ }[ ]";    //true
    std::cout << isClosed(brackets2);

    std::string brackets3 = "()}{";                 //false
    std::cout << isClosed(brackets3);

    //without cycle
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    std::cout << "\nList 1 without cycle: " << (has_cycle(head) ? "Cycle is present" : "no Cycle") << std::endl;


    //with cycle
    Node* head1 = new Node(10);
    head1->next = new Node(20);
    head1->next->next = head1;
    std::cout << "\nList 2 with cycle: " << (has_cycle(head1) ? "Cycle is present" : "no Cycle") << std::endl;
}

