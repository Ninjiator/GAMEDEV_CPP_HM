#pragma once
#include <string>
#include "Monster.h"
#include "Munchkin.h"

class Modifier
{
public:
	virtual void apply(Munchkin* munchkin, Monster* monster) = 0;
	virtual int getMunchkinModifier() const { return m_munchkinPowerChange; }
	virtual int getMonsterModifier() const { return m_monsterPowerChange; }
	virtual std::string getFullInfo() const { return ""; }

protected:
	int m_munchkinPowerChange = 0;
	int m_monsterPowerChange = 0;
};

class SimpleModifier : public Modifier
{
public:
	SimpleModifier(int powerBoost) : m_powerBoost(powerBoost) {}

	virtual void apply(Munchkin*, Monster*) override
	{
		m_munchkinPowerChange = m_powerBoost;
	}

	virtual std::string getFullInfo() const
	{
		return "Munchkin power + " + std::to_string(m_powerBoost);
	}

private:
	int m_powerBoost;
};

class DoubleMunchkinLevel : public Modifier
{
public:
	virtual void apply(Munchkin* munchkin, Monster*) override
	{
		m_munchkinPowerChange = munchkin->getLevel();
	}

	virtual std::string getFullInfo() const override
	{
		return "Double Munchkin level!";
	}
};

class HalvesMonsterLevel : public Modifier
{
public:
	//#DONE: cut monster's power in 2 if he is of type tribe

	HalvesMonsterLevel(Tribe tribe) { m_tribeLevelHalfDowngrade = tribe; } //implement
	Tribe getTribe() const { return m_tribeLevelHalfDowngrade; }
	virtual void apply(Munchkin*, Monster* monster) override 
	{
		if (monster->getTribe() == m_tribeLevelHalfDowngrade)
		{
			m_monsterPowerChange = monster->getLevel();
			m_monsterPowerChange = -m_monsterPowerChange / 2;
		}
	} 
	std::string tribeToString(Tribe tribe) const
	{
		switch (tribe)
		{
		case Tribe::Human:
			return "Human";
		case Tribe::Undead:
			return "Undead";
		case Tribe::Zombie:
			return "Zombie";
		case Tribe::God:
			return "God";
		}
	}
	virtual std::string getFullInfo() const override 
	{ return "Monster level is downgraded by half if he is: " + tribeToString(m_tribeLevelHalfDowngrade);  } //implement
private:
	Tribe m_tribeLevelHalfDowngrade;
};

//#DONE: Add unique modifier munchkin/monster specific

class RaceModifier : public Modifier
{
public:
	RaceModifier(PlayerRace race) {m_raceModifier = race; }

	std::string raceToString(PlayerRace race) const
	{
		switch (race)
		{
		case PlayerRace::Elph:
			return "Elph";
		case PlayerRace::Human:
			return "Human";
		case PlayerRace::Ork:
			return "Ork";
		}
	}

	virtual void apply(Munchkin* munchkin, Monster* monster) override
	{
		if (munchkin->getRace() == m_raceModifier )
		{
			m_munchkinPowerChange = munchkin->getLevel();
		}
	}
	virtual std::string getFullInfo() const override
	{
		return "If player class is " + raceToString(m_raceModifier) + " double Munchkin level!";
	}
private:
	PlayerRace m_raceModifier;
};

//Absolutely unique (for example add Munckin class: gnome, elph, human, sex: man, woman, non-binary