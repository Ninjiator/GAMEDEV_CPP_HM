#pragma once
#include <vector>
#include <string>

class Item;
class Modifier;
enum class PlayerRace
{
	Elph,
	Human,
	Ork
};
using uint = unsigned int;

class Munchkin
{
public:
	Munchkin() = default;
	Munchkin(const std::string& name, const PlayerRace& race) : m_name(name), m_race(race) {}

	void setRace(int choise) 
	{
		switch (choise)
		{
		case 1:
			m_race = PlayerRace::Elph;
			break;
		case 2:
			m_race = PlayerRace::Human;
			break;
		case 3:
			m_race = PlayerRace::Ork;
			break;
		default:
			break;
		}
	}
	void setName(const std::string& name) { m_name = name; }
	const std::string& getName() const { return m_name; }

	PlayerRace getRace() const { return m_race; }
	int getLevel() const { return m_level; } // used by FIGHT
	void updateLevelBy(int levels);	//used by VICTORY FLOW

	void addItem(Item* item);
	void addItems(const std::vector<Item*>& items);
	const std::vector<Item*>& getItems() const;

	Modifier* popModifier(int idx);
	Item* popItem(int idx);
	const std::vector<Modifier*>& getModifiers() const { return m_modifiers; }	//FOR UI ONLY
	void addModifiers(const std::vector<Modifier*>& modifiers) { m_modifiers = modifiers; }

	//TODO: Implement, by index or by pointer or at random
	void removeModifierFromHand() {}
	void removeItemEquipped() {}

private:
	uint m_level = 1;
	std::string m_name;
	PlayerRace m_race;

	std::vector<Item*> m_items;
	std::vector<Modifier*> m_modifiers;
};