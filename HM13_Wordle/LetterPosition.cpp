#include <iostream>

void correctPos(std::string& playerInput, const std::string& mysteryWord, std::string& mysteryPlaceholder, bool* used)
{
	//STEP:1 processing correct position & adding to placeholder on correct pos, flag used - true
	for (int i = 0; i < playerInput.length(); i++)
	{
		if (playerInput[i] == mysteryWord[i])
		{
			mysteryPlaceholder[i] = std::toupper(playerInput[i]);
			used[i] = true;
		}
	}
}
void incorrectPos(std::string& playerInput, const std::string& mysteryWord, std::string& mysteryPlaceholder, bool* used)
{
	for (int i = 0; i < playerInput.length(); i++)
	{
		if (mysteryPlaceholder[i] != '*')	// skip != empty positions
			continue;

		//STEP:2.2 processing inccorect position but correct letters
		for (int j = 0; j < playerInput.length(); j++)
		{
			if (playerInput[i] == mysteryWord[j] && !used[j])
			{
				mysteryPlaceholder[i] = playerInput[i];
				used[j] = true;
				break;
			}
		}
	}
}