#include "Runaway.h"
#include "Munchkin.h"
#include "Item.h"
#include "Monster.h"

void Runaway_LevelDowngrade::apply(Munchkin* munchkin)
{
	munchkin->updateLevelBy(-m_levelToDowngrade);
}

void Runaway_LevelDowngradeIf::apply(Munchkin* munchkin)
{
	if (munchkin->getLevel() >= m_minimalMunchkinLevelToApply)
	{
		Runaway_LevelDowngrade::apply(munchkin);
	}
}

void Runaway_ModifierFromHandRemoval::apply(Munchkin* munchkin)
{
	for (int i = 1; i <= m_cardRemove; i++)
	{
		unsigned int idx = std::rand() % munchkin->getModifiers().size();
		munchkin->popModifier(idx);
	}
	
}

void Runaway_ItemEquipedRemoval::apply(Munchkin* munchkin)
{
    for (int i = 0; i < m_removeAmount; i++)  
    {
        if (munchkin->getItems().empty()) return;  

        int bestItemPower = 0;
        Item* bestItem = nullptr;
        int bestItemIndex = -1; 

        std::vector<Item*> items = munchkin->getItems(); 
        for (size_t j = 0; j < items.size(); j++)
        {
            if (items[j] && items[j]->getBasePower() > bestItemPower)
            {
                bestItemPower = items[j]->getBasePower();
                bestItem = items[j];
                bestItemIndex = j;
            }
        }
        if (bestItem != nullptr && bestItemIndex != -1)
        {
            Item* removedItem = munchkin->popItem(bestItemIndex);
            delete removedItem; 
        }
    }
}
