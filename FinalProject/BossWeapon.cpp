#include "BossWeapon.h"
#include <iostream>
#include <random>

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
	fallingBombsAbility(dt);
	deleteProjectile(dt);
}

void BossWeapon::draw()
{
	Weapon::draw();
}

void BossWeapon::shoot(float dt)
{
	float SPEED = 800.f;
	float delta_X = 0.f;
	float delta_Y = 0.f;
	m_shootTimer += dt;

	if (m_shootTimer > m_shootTimerMax)
	{
		m_shootTimer = 0.f;
		if (m_boss->getBossOrientation() == BossOrientation::Left)
		{
			delta_X -= SPEED;
		}
		if (m_boss->getBossOrientation() == BossOrientation::Right)
		{
			delta_X = SPEED;
		}
		float projectileSpawnY[2] = { 0.f, m_window->getSize().y / 5.f };
		sf::Vector2f spawnPosition = m_boss->getPosition() + sf::Vector2f{ -(m_boss->getSpriteWidth() / 4.f), generateRandomFromArray(projectileSpawnY) };
		
		if (m_boss->getPosition().y <  m_window->getSize().y / 2.f)
		{
			delta_Y = 250.f;
		}
			m_projectiles.push_back(new Projectile{ m_window, "resources/Sprites/Boss/boss_projectile_temp.png", 4.f, spawnPosition, delta_X, delta_Y });
			std::cout << "drawing boss projectiles" << std::endl;
	}
}

void BossWeapon::deleteProjectile(float dt)
{
	Weapon::deleteProjectile(dt);
}

void BossWeapon::fallingBombsAbility(float dt)
{
	float delta_Y = 500.f;
	
	m_bombTimer += dt;
	if (m_boss->getHealthPoints() < 15 && m_bombTimer > m_boombTimerMax)
	{
		m_bombTimer = 0.f;
		sf::Vector2f part = sf::Vector2f{ m_window->getSize().x / 5.f, 0.f };
		//if Boss located on a left side of arena - bombs will spawn on a right side 
		if (m_boss->getPosition().x < m_window->getSize().x / 2.f)
		{
			float leftSideX[3] = { m_window->getSize().x - part.x / 2.f, m_window->getSize().x - part.x * 2.f, m_window->getSize().x - part.x * 3.5f };
			sf::Vector2f spawnPosition = sf::Vector2f{ generateRandomFromArray(leftSideX), 0.f };

			m_projectiles.push_back(new Projectile{ m_window, "resources/Sprites/Boss/ph3_icecream_cone_0018.png", 0.7f, spawnPosition, 0.f, delta_Y });
			m_projectiles.push_back(new Projectile{ m_window, "resources/Sprites/Boss/ph3_icecream_cone_0018.png", 0.7f, spawnPosition, 0.f, delta_Y });
			m_projectiles.push_back(new Projectile{ m_window, "resources/Sprites/Boss/ph3_icecream_cone_0018.png", 0.7f, spawnPosition, 0.f, delta_Y });
		}
		//if Boss located on a right side of arena - bombs will spawn on a left side 
		if (m_boss->getPosition().x > m_window->getSize().x / 2.f)
		{
			float rigthSideX[3] = { part.x / 2.f, part.x * 2.f, part.x * 3.5f };
			sf::Vector2f spawnPosition = sf::Vector2f{ generateRandomFromArray(rigthSideX), 0.f };

			m_projectiles.push_back(new Projectile{ m_window, "resources/Sprites/Boss/ph3_icecream_cone_0018.png", 0.7f, spawnPosition, 0.f, delta_Y });
			m_projectiles.push_back(new Projectile{ m_window, "resources/Sprites/Boss/ph3_icecream_cone_0018.png", 0.7f, spawnPosition, 0.f, delta_Y });
			m_projectiles.push_back(new Projectile{ m_window, "resources/Sprites/Boss/ph3_icecream_cone_0018.png", 0.7f, spawnPosition, 0.f, delta_Y });
		}
	}
}

float BossWeapon::generateRandomFromArray(float arr[])
{
	int size = sizeof(arr) / sizeof(arr[0]);
	std::srand(std::time(nullptr));
	int index = std::rand() % size;
	return arr[index];
}
