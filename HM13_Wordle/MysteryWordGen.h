#pragma once

void randomWord(std::string& mysteryWord, const char* fileName);
void wordOfDay(std::string& mysteryWord, const char* dataBase_1);
bool IsWordGuessToday(const char* fileName, const int& day, const int& month, const int& year);