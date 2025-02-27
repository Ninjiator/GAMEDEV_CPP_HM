#pragma once
#include <string>

//forwad declaration
class Munchkin;

class Runaway
{
public:
	virtual void apply(Munchkin* munchkin) = 0;

	//#TODO: Implement in all children classes, see class Item for reference
	
	virtual std::string getFullInfo() const = 0;
};

class Runaway_LevelDowngrade : public Runaway
{
public:
	Runaway_LevelDowngrade(int level = 1) : m_levelToDowngrade(level) {}
	void apply(Munchkin* munchkin) override;
	virtual std::string getFullInfo() const override
	{
		return std::string("\"") + "[RUNAWAY]: Player level is downgraded on " + std::to_string(m_levelToDowngrade) + " levels/'s";
		
	}

protected:
	int m_levelToDowngrade = 0;
};


class Runaway_LevelDowngradeIf : public Runaway_LevelDowngrade
{
public:
	Runaway_LevelDowngradeIf(int level, int minimalMunchkinLevel)
		: Runaway_LevelDowngrade(level), m_minimalMunchkinLevelToApply(minimalMunchkinLevel) {}

	void apply(Munchkin* munchkin) override;
	virtual std::string getFullInfo() const override
	{
		return "[RUNAWAY]: If player's level bigger than -> " + std::to_string(m_minimalMunchkinLevelToApply)
			+ "\nPlayer's level is downgraded on " + std::to_string(m_levelToDowngrade) + " levels.";
	}
private:
	int m_minimalMunchkinLevelToApply;
};


//Remove a card from hand(modifier) at random
class Runaway_ModifierFromHandRemoval : public Runaway
{
public:
	//#TODO
	Runaway_ModifierFromHandRemoval(int cardAmount) : m_cardRemove(cardAmount) {}

	void apply(Munchkin* munchkin) override;

	virtual std::string getFullInfo() const override
	{
		return "[RUNAWAY]: Monster discard " + std::to_string(m_cardRemove) +" random modifier from player hand \n";
	}
private:
	int m_cardRemove;
};


//Item 
// MUNCHKIN
// ACTIVE DECK
// DEACTIVED DECK

//Random item removal
class Runaway_ItemEquipedRemoval : public Runaway
{
public:
	//#TODO
	Runaway_ItemEquipedRemoval(int remove) : m_itemRemove(remove) {}
	void apply(Munchkin* munchkin) override;
	virtual std::string getFullInfo() const override
	{
		return "[RUNAWAY]: Monster discard " + std::to_string(m_itemRemove) + " random equiped items \n";
	}
private:
	int m_itemRemove;
};

//DONE Remove equiped item from Outfit with biggest base power
class Runaway_BiggestBonusCardRemoval : public Runaway
{
public:
	Runaway_BiggestBonusCardRemoval(int remove) : m_removeAmount(remove) {}
	void apply(Munchkin* munchkin) override;
	virtual std::string getFullInfo() const override
	{
		return "[RUNAWAY]: Monster discard " + std::to_string(m_removeAmount) + " a most powerfull items from hand\n";
	}
private:
	int m_removeAmount = 0;
};