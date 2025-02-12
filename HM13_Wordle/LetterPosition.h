#pragma once
constexpr int usedSize = 5;
void correctPos(std::string& playerInput, const std::string& mysteryWord, std::string& mysteryPlaceholder, bool* used);
void incorrectPos(std::string& playerInput, const std::string& mysteryWord, std::string& mysteryPlaceholder, bool* used);