#include "ItemDeck.h"

#include "Item.h"

#include <algorithm>  
#include <random>

ItemDeck::ItemDeck()
{
	//TODO: Move item's database to file in format:
	// type;name; params for the type
	//For example:
	//UndeadWeapon;"Holy Grenade";4		//should call UndeadWeapon("Holy Grenade", 4);

	//TODO: Setup more items of diferent types
	m_itemsDataBase =
	{ new Weapon{"The Sword of DOOM", 5},
	new UndeadWeapon{"Stinky knife", 4},
	new UndeadWeapon{"Holy grenade", 6},
	new MagicWeapon{"HOLLY MOLLY", 7},
	new HollyWeapon{"Angel Sword", 4, Tribe::Zombie},
	new BrutalWeapon{"Ronin's Fear", 8} };

	m_avaliableItemsDataBase = m_itemsDataBase;
}

ItemDeck::~ItemDeck()
{
	//TODO: FREE MEMORY
	for (Item* item : m_itemsDataBase)
	{
		delete item;
	}
}
void ItemDeck::shuffleItems()
{
	static std::random_device rd;
	static std::mt19937 g(rd());
	std::shuffle(m_avaliableItemsDataBase.begin(), m_avaliableItemsDataBase.end(), g);
}

Item* ItemDeck::generateItem() 
{
	//DONE: PICK AT RANDOM SEVERAL ITEMS FROM DATABASE AS A PLAYER HAND
	if (m_avaliableItemsDataBase.empty())
	{
		m_avaliableItemsDataBase = m_itemsDataBase;
		shuffleItems();
	}
	Item* choosenItem = m_avaliableItemsDataBase.back();
	m_avaliableItemsDataBase.pop_back();

	return choosenItem;
}
std::vector<Item*> ItemDeck::generateItems()
{
	std::vector<Item*> selectedModifiers;

	if (m_avaliableItemsDataBase.empty())
	{
		m_avaliableItemsDataBase = m_itemsDataBase;
		shuffleItems();
	}

	for (size_t i = 0; i < m_itemsAmount; i++)
	{
		Item* chosenModifier = m_avaliableItemsDataBase.back();
		m_avaliableItemsDataBase.pop_back();
		selectedModifiers.push_back(chosenModifier);
	}

	return selectedModifiers;
}