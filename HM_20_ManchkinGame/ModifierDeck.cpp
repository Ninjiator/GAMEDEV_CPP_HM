#include "ModifierDeck.h"

#include "Modifier.h"
#include <algorithm>  
#include <random>

ModifierDeck::ModifierDeck()
{
	m_modifiersDatabase =
	{
		{new SimpleModifier{3}},
		{new SimpleModifier{3}},
		{new SimpleModifier{2}},
		{new SimpleModifier{2}},
		{new SimpleModifier{2}},
		{new SimpleModifier{4}},
		{new SimpleModifier{1}},
		{new SimpleModifier{1}},
		{new SimpleModifier{1}},
		{new DoubleMunchkinLevel{}},
		{new DoubleMunchkinLevel{}},
		{new HalvesMonsterLevel{Tribe::Undead}},
		{new HalvesMonsterLevel{Tribe::God}},
		{new RaceModifier{PlayerRace::Elph}},
		{new RaceModifier{PlayerRace::Human}},
		{new RaceModifier{PlayerRace::Ork}},
		};
	m_avaliableModifies = m_modifiersDatabase;
	shuffleModifier();
}

ModifierDeck::~ModifierDeck()
{
	//TODO: FREE MEMORY
	for (Modifier* modifier : m_modifiersDatabase)
	{
		delete modifier;
	}
}

void ModifierDeck::shuffleModifier()
{
	static std::random_device rd;
	static std::mt19937 g(rd());
	std::shuffle(m_avaliableModifies.begin(), m_avaliableModifies.end(), g);
}

Modifier* ModifierDeck::generateModifier() 
{
	//#TODO: this call should return unique modifier every time
	//either for as long as the same game is being played
	//or unless ALL cards were generated from database to the game - in this case 
	//make ALL cards available again

	if (m_avaliableModifies.empty())
	{
		m_avaliableModifies = m_modifiersDatabase;
		shuffleModifier();
	}
	Modifier* choosenModifier = m_avaliableModifies.back();
	m_avaliableModifies.pop_back();

	return choosenModifier;
}

std::vector<Modifier*> ModifierDeck::generateModifiers()
{
	std::vector<Modifier*> selectedModifiers; 

	if (m_avaliableModifies.empty())
	{
		m_avaliableModifies = m_modifiersDatabase; 
		shuffleModifier(); 
	}

	for (size_t i = 0; i < m_modifiersAmount; i++)
	{
		Modifier* chosenModifier = m_avaliableModifies.back();
		m_avaliableModifies.pop_back();
		selectedModifiers.push_back(chosenModifier);
	}

	return selectedModifiers;
}