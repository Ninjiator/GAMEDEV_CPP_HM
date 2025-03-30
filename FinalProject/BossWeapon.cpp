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
	float SPEED = 1000.f;
	float delta_X = 0.f;
	float delta_Y = 0.f;
	//const float m_shootTimerMax = 0.5f;
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

		sf::Vector2f spawnPosition = m_boss->getPosition() + sf::Vector2f{ -(m_boss->getSpriteWidth() / 4.f), generateRandomYForProjectile() };
		
		if (m_boss->getPosition().y <  m_window->getSize().y / 2.f)
		{
			delta_Y = 250.f;
		}

		m_projectiles.push_back(new Projectile{ m_window, "resources/Sprites/Boss/boss_projectile_temp.png", 4.f, spawnPosition, delta_X, delta_Y});
		std::cout << "drawing boss projectiles" << std::endl;
	}
}

void BossWeapon::deleteProjectile(float dt)
{
	Weapon::deleteProjectile(dt);
}

void BossWeapon::fallingBombsAbility(float dt)
{
	float delta_Y = 300.f;
	
	m_bombTimer += dt;
	if (m_boss->getHealthPoints() < 15 && m_bombTimer > m_boombTimerMax)
	{
		m_bombTimer = 0.f;

		sf::Vector2f spawnPosition_1 = sf::Vector2f{ 1150.f, 0.f };
		sf::Vector2f spawnPosition_2 = sf::Vector2f{ 1000.f, 0.f };
		sf::Vector2f spawnPosition_3 = sf::Vector2f{ 700.f, 0.f };

		m_projectiles.push_back(new Projectile{ m_window, "resources/Sprites/Boss/ph3_icecream_cone_0018.png", 1.f, spawnPosition_1, 0.f, delta_Y });
		m_projectiles.push_back(new Projectile{ m_window, "resources/Sprites/Boss/ph3_icecream_cone_0018.png", 1.f, spawnPosition_2, 0.f, delta_Y });
		m_projectiles.push_back(new Projectile{ m_window, "resources/Sprites/Boss/ph3_icecream_cone_0018.png", 1.f, spawnPosition_3, 0.f, delta_Y });
	}
}

float BossWeapon::generateRandomYForProjectile()
{
	float projectileSpawnY[2] = { 0.f, m_window->getSize().y / 6.f };
	int size = sizeof(projectileSpawnY) / sizeof(projectileSpawnY[0]);
	std::srand(std::time(nullptr));
	int index = std::rand() % size;
	return projectileSpawnY[index];
}
