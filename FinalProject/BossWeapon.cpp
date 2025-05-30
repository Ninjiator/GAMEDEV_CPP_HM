#include "BossWeapon.h"
#include <iostream>
#include <random>
#include "SoundManager.h"
#include "GameConfig.h"

BossWeapon::BossWeapon(sf::RenderWindow* window, Boss* boss)
	: Weapon(window, nullptr)
	, m_boss(boss)
{
	m_position = boss->getPosition();
	std::cout << "\n" << m_position.x << " " << m_position.y << std::endl;
}


void BossWeapon::update(float dt)
{
	if (m_boss->isEntityAlive() != false)
	{
		shoot(dt);
		fallingBombsAbility(dt);
	}
	deleteProjectile(dt);
}

void BossWeapon::draw()
{
	Weapon::draw();
}

void BossWeapon::shoot(float dt)
{
	float delta_X = 0.f;
	float delta_Y = 0.f;
	m_shootTimer += dt;

	if (m_shootTimer > m_shootTimerMax)
	{
		m_shootTimer = 0.f;
		if (m_boss->getBossOrientation() == BossOrientation::Left)
		{
			delta_X -= GameConfig::BossProjectileSPEED;
		}
		if (m_boss->getBossOrientation() == BossOrientation::Right)
		{
			delta_X = GameConfig::BossProjectileSPEED;;
		}
		float projectileSpawnY[2] = { 0.f, m_window->getSize().y / 5.f };
		sf::Vector2f spawnPosition = m_boss->getPosition() + sf::Vector2f{ -(m_boss->getSpriteWidth() / 4.f), generateRandomFromArray(projectileSpawnY) };
		
		if (m_boss->getPosition().y <  m_window->getSize().y / 2.f && m_boss->getBossPhase() == BossPhase::Phase_3)
		{
			delta_Y = 250.f;
		}

		initProjectileForShooting(spawnPosition, delta_X, delta_Y);

		SoundManager::getInstance().playBossShootSound();
		std::cout << "drawing boss projectiles" << std::endl;
	}
}

void BossWeapon::initProjectileForShooting(sf::Vector2f spawnPos, float delta_x, float delta_y)
{
	if (m_boss->getBossPhase() == BossPhase::Phase_1)
	{
		auto* projectile = new Projectile(m_window, "resources/Sprites/Boss/moon_spritesheet.png", 0.8f, spawnPos, delta_x, delta_y, EffectType::BossIceCreamEffect);
		projectile->initAnimation(AttackType::BossAttackMoon);
		m_projectiles.push_back(projectile);
	}
	else
	{
		auto* projectile = new Projectile(m_window, "resources/Sprites/Boss/last_stage_projectile.png", 0.6f, spawnPos, delta_x, delta_y, EffectType::BossIceCubsEffect);
		projectile->initAnimation(AttackType::BossCubesAttack);
		m_projectiles.push_back(projectile);
	}
}

void BossWeapon::deleteProjectile(float dt)
{
	Weapon::deleteProjectile(dt);
}

void BossWeapon::fallingBombsAbility(float dt)
{
	m_bombTimer += dt;
	if (m_boss->getHealthPoints() < GameConfig::BossHPThreshold_1 && m_bombTimer > m_boombTimerMax)
	{
		m_bombTimer = 0.f;
		sf::Vector2f part = sf::Vector2f{ m_window->getSize().x / 5.f, 0.f };
		//if Boss located on a left side of arena - bombs will spawn on a right side 
		if (m_boss->getPosition().x < m_window->getSize().x / 2.f)
		{
			float bombSpawnPositionXLeft[3] = { m_window->getSize().x - part.x / 2.f, m_window->getSize().x - part.x * 2.f, m_window->getSize().x - part.x * 3.5f };
			sf::Vector2f spawnPosition = sf::Vector2f{ generateRandomFromArray(bombSpawnPositionXLeft), 0.f };
			initBombForBombAbility(spawnPosition);
		}
		//if Boss located on a right side of arena - bombs will spawn on a left side 
		if (m_boss->getPosition().x > m_window->getSize().x / 2.f)
		{
			float bombSpawnPositionXRight[3] = { part.x / 2.f, part.x * 2.f, part.x * 3.5f };
			sf::Vector2f spawnPosition = sf::Vector2f{ generateRandomFromArray(bombSpawnPositionXRight), 0.f };
			initBombForBombAbility(spawnPosition);
		}
	}
}

void BossWeapon::initBombForBombAbility(sf::Vector2f spawnPos)
{
	auto* projectile = new Projectile(m_window, "resources/Sprites/Boss/icecream_cone_spritesheet_aligned.png", 0.8f, spawnPos, 0.f, GameConfig::BossBombsSPEED, EffectType::BossIceCreamEffect);
	projectile->initAnimation(AttackType::BossBombAttack);
	m_projectiles.push_back(projectile);
}

float BossWeapon::generateRandomFromArray(float arr[])
{
	int size = sizeof(arr) / sizeof(arr[0]);
	int index = std::rand() % size;
	return arr[index];
}
