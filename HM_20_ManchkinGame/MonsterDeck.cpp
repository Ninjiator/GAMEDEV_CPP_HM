#include "MonsterDeck.h"

#include "Monster.h"
#include "Runaway.h"

MonsterDeck::MonsterDeck()
{
	m_monstersDatabase =
	{
		//#TODO: Think of new monsters, feel free to use official Munchkin games as a reference
		//new Monster{"Crazy Joe", 4}, /*"Just a poor guy who looks some drunk-fights"*/
		//new Monster{"Shiva destructor", 20, Tribe::God, new Runaway_LevelDowngradeIf{2, 5}},
		//new Monster{"Vampire", 15, Tribe::Zombie, new Runaway_LevelDowngrade{1}},
		new Monster{ "Holly Bible", 20, Tribe::God, new Runaway_ModifierFromHandRemoval{3} },
		new Monster{ "Jaden a Clerk", 60, Tribe::Human, new Runaway_ItemEquipedRemoval{1} },
		/*new Monster{"Mad dog", 10, Tribe::Undead, new Runaway_ModifierFromHandRemoval{2}}*/
	};
}

MonsterDeck::~MonsterDeck()
{
	//TODO: Clear memory
}

Monster* MonsterDeck::generateMonster() const
{
	//#TODO: this call should return monster every time
	//either for as long as the same game is being played
	//or unless ALL cards were generated from database to the game - in this case 
	//make ALL cards available again

	const int choice = std::rand() % m_monstersDatabase.size();
	return m_monstersDatabase[choice];
}