#include "MonsterDeck.h"

#include "Monster.h"
#include "Runaway.h"
#include <algorithm>  
#include <random>

MonsterDeck::MonsterDeck()
{
	m_monstersDatabase =
	{
		//#TODO: Think of new monsters, feel free to use official Munchkin games as a reference
		new Monster{"Crazy Joe", 4, Tribe::Human, new Runaway_LevelDowngradeIf{1, 2}},
		new Monster{"Shiva destructor", 20, Tribe::God, new Runaway_LevelDowngradeIf{2, 5}},
		new Monster{"Vampire", 15, Tribe::Zombie, new Runaway_LevelDowngrade{1}},
		new Monster{"Holly Bible", 50, Tribe::God, new Runaway_ModifierFromHandRemoval{3} },
		new Monster{"Jaden a Clerk", 60, Tribe::Human, new Runaway_BiggestBonusCardRemoval{1} },
		new Monster{"Mad dog", 80, Tribe::Undead, new Runaway_ModifierFromHandRemoval{2}},
		new Monster{"Gunslinger Jack", 15, Tribe::Human, new Runaway_ItemEquipedRemoval{1}}
	};
	m_availableMonsters = m_monstersDatabase;
}

MonsterDeck::~MonsterDeck()
{
	//TODO: Clear memory
	for (Monster* monster : m_monstersDatabase)
	{
		delete monster;
	}
}
void MonsterDeck::shuffleMonsters()
{
	static std::random_device rd;
	static std::mt19937 g(rd());
	std::shuffle(m_availableMonsters.begin(), m_availableMonsters.end(), g);
}

Monster* MonsterDeck::generateMonster() 
{
	//#TODO: this call should return monster every time
	//either for as long as the same game is being played
	//or unless ALL cards were generated from database to the game - in this case 
	//make ALL cards available again

	if (m_availableMonsters.empty())  
	{
		m_availableMonsters = m_monstersDatabase; 
		shuffleMonsters(); 
	}

	Monster* chosenMonster = m_availableMonsters.back(); 
	m_availableMonsters.pop_back(); 

	return chosenMonster;
}

