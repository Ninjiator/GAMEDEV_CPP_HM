#pragma once
#include <vector>

class Monster;

class MonsterDeck
{
public:
	MonsterDeck();
	~MonsterDeck();

	Monster* generateMonster();
	void shuffleMonsters();
private:
	std::vector<Monster*> m_monstersDatabase;
	std::vector<Monster*> m_availableMonsters;
}; 