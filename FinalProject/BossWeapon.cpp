#include "BossWeapon.h"
#include <iostream>

BossWeapon::BossWeapon(sf::RenderWindow* window, Boss* boss)
	: Weapon(window, nullptr) //using base c-tor from Weapon, nullptr for player
	, m_boss(boss)
{
	m_position = boss->getPosition();
	std::cout << "\n" << m_position.x << " " << m_position.y << std::endl;
}

void BossWeapon::update(float dt)
{
	shoot(dt);
	deleteProjectile(dt);
}

void BossWeapon::draw()
{
	Weapon::draw();
}

void BossWeapon::shoot(float dt)
{
	float SPEED_X = 1000.f;
	float delta_X = 0.f;
	
	const float shootTimerMax = 0.6f;
	m_shootTimer += dt;

	if (m_shootTimer > shootTimerMax)
	{
		m_shootTimer = 0.f;
		delta_X -= SPEED_X;
		
		sf::Vector2f spawnPosition = m_boss->getPosition() + sf::Vector2f{ -(m_boss->getSpriteWidth() / 4.f), 0.f };
		
		m_projectiles.push_back(new Projectile{ m_window, "resources/Sprites/Boss/boss_projectile_temp.png", 4.f, spawnPosition, delta_X });
		std::cout << "drawing boss projectiles" << std::endl;
	}
}

void BossWeapon::deleteProjectile(float dt)
{
	Weapon::deleteProjectile(dt);
}
