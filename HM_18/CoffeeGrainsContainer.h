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

	void clean() { m_usedCoffeeVolume = 0; }
	void fill(float newGrainsCoffeeVolume) { m_grainsCoffeeVolume = std::min(newGrainsCoffeeVolume, MaxGrainsCoffee); }

private:
	float m_grainsCoffeeVolume = 0;
	float m_groundedCoffeeVolume = 0;
	float m_usedCoffeeVolume = 0;

	const float MaxGrainsCoffee = 1.0f;
	const float MaxGroundedCoffee = 1.0f;
	const float MaxUsedCoffe = 0.5f;

};