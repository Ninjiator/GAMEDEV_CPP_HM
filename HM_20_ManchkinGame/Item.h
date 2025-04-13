#pragma once
#include "Tribe.h"
#include <string>


class Item
{
public:
	virtual int getPower(Tribe monsterTribeModifier) const { return 0; }
	virtual int getBasePower() const { return 0; }

	void setName(const std::string& name) { m_name = name; }
	const std::string getName() const { return m_name; }
	virtual std::string getFullInfo() const = 0;

	virtual Tribe getAdvantage() const { return Tribe::Count; }

protected:
	std::string m_name;
	//other fields like description, image, category

private:
};

class Weapon : public Item
{
public:
	Weapon(const std::string& name, int power) : m_power(power)
	{
		setName(name);
	}

	int getBasePower() const override
	{
		return m_power;
	}

	virtual std::string getFullInfo() const override
	{
		return "\"" + getName() + "\"" + ", power:" + std::to_string(getBasePower()) + ", skills: None\n";
	}

protected:
	int m_power = 0;
};

class UndeadWeapon : public Weapon
{
public:
	UndeadWeapon(const std::string& name, int power) : Weapon(name, power) {}

	virtual int getPower(Tribe monsterTribeModifier) const override
	{
		switch (monsterTribeModifier)
		{
		case Tribe::Undead:
			return m_power * 2;
		case Tribe::Human:
		case Tribe::Zombie:
		default:
			return m_power;
		}
	}

	virtual std::string getFullInfo() const override
	{
		return "\"" + getName() + "\"" + ", power:" + std::to_string(getBasePower()) + ", skills: x2 vs UNDEADS!\n";
	}
};

class MagicWeapon : public Weapon
{
public:
	MagicWeapon(const std::string& name, int power) : Weapon(name, power) {}

	virtual int getPower(Tribe monsterTribeModifier) const override
	{
		switch (monsterTribeModifier)
		{
		case Tribe::Human:
			return m_power * 0.8;
		case Tribe::Undead:
		case Tribe::Zombie:
		case Tribe::God:
			return m_power * 2;
		default:
			return m_power;
		}
	}

	virtual std::string getFullInfo() const override
	{
		return "\"" + getName() + "\"" + ", power:" + std::to_string(getBasePower()) + ", skills: x2 vs GODS BUT x0.8 vs HUMANS!\n";
	}
};


//TODO: Add new Item type with unique properties
class HollyWeapon : public Weapon
{
public:
	HollyWeapon(const std::string& name, int power, Tribe advantage) : Weapon(name, power), m_advantage(advantage){}

	Tribe getAdvantage() const override { return m_advantage; }

	virtual std::string getFullInfo() const override
	{
		return "\"" + getName() + "\"" + ", power:" + std::to_string(getBasePower()) + ", skills: Instantly destroy a Zombie !\n";
	}

private:
	Tribe m_advantage;
};

class BrutalWeapon : public Weapon
{
public:
	BrutalWeapon(const std::string& name, int power) : Weapon(name, power) {}

	virtual int getPower(Tribe monsterTribeModifier) const override
	{
		switch (monsterTribeModifier)
		{
		case Tribe::Human:
			return m_power * 0.3;
		case Tribe::Undead:
			return m_power * 0.3;
		case Tribe::Zombie:
			return m_power * 0.3;
		case Tribe::God:
			return m_power * 2;
		default:
			return m_power;
		}
	}

	virtual std::string getFullInfo() const override
	{
		return "\"" + getName() + "\"" + ", power:" + std::to_string(getBasePower()) + ", skills: x2 vs GODS and x0.3 vs OTHERS!\n";
	}
};


