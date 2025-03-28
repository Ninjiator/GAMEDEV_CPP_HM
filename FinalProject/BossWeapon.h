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

	void shoot(float dt) override; //add boss logic
	void deleteProjectile(float dt);
	

private:
	Boss* m_boss = nullptr;
	
	sf::Vector2f m_position;
	
};