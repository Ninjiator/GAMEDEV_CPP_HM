#pragma once
#include "Weapon.h"
#include "Projectile.h"
#include <vector>
#include "SFML/Graphics.hpp"
#include "Boss.h"
#include <iostream>

class BossWeapon : public Weapon
{
public:
	BossWeapon(sf::RenderWindow* window, Boss* boss);

	void update(float dt) override;
	void draw();

	void shoot(float dt) override;
	float generateRandomFromArray(float arr[]);
	void deleteProjectile(float dt);
	
	void fallingBombsAbility(float dt);


private:
	Boss* m_boss = nullptr;
	
	sf::Vector2f m_position;
	
	const float m_shootTimerMax = 0.45f;
	const float m_boombTimerMax = 2.0f;
	float m_bombTimer = 0.f;
};