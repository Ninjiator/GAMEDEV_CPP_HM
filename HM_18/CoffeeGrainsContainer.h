#pragma once
#include <iostream>

class CoffeGrainsContainer
{
public:
	void showOperations();
	void receiveInput();
	void update();

	float getGrainsVolume() const { return m_grainsCoffeeVolume; }
	float getGroundedVolume() const { return m_groundedCoffeeVolume; }
	float getUsedVolume() const { return m_usedCoffeeVolume; }
	float getUsedLimit() const { return MaxUsedCoffe; }

	void useGroundedCoffee(float Volume) { m_groundedCoffeeVolume -= Volume; }
	void fillUsedCoffeeContainer(float Volume) { m_usedCoffeeVolume += Volume; }

	void clean() { m_usedCoffeeVolume = 0; }
	void fill(float newGrainsCoffeeVolume) { m_grainsCoffeeVolume = std::min(newGrainsCoffeeVolume, MaxGrainsCoffee); }
	void groundCoffee(float newGroundVolume); 

private:
	int m_operation = -1;

	float m_grainsCoffeeVolume = 0;
	float m_groundedCoffeeVolume = 0;
	float m_usedCoffeeVolume = 0;

	const float MaxGrainsCoffee = 0.5f;
	const float MaxGroundedCoffee = 0.5f;
	const float MaxUsedCoffe = 0.3f;

	

};