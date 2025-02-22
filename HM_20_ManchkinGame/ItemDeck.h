#pragma once
#include <vector>

class Item;

class ItemDeck
{
public:
	ItemDeck();
	~ItemDeck();

	Item* generateItem();

	std::vector<Item*> generateItems();
	void shuffleItems();
private:
	const int m_itemsAmount = 3;
	std::vector<Item*> m_itemsDataBase;
	std::vector<Item*> m_avaliableItemsDataBase;
};