#include "PhysicsEngine.h"
#include "Player.h"
#include "Boss.h"
#include "Projectile.h"
#include <iostream>


PhysicsEngine::PhysicsEngine(Player* player, std::vector<Projectile*>& playerProjectiles, 
							Boss* boss, std::vector<Projectile*>& bossProjectiles, 
							IEffectSpawner* effectSpawner)
	: m_player(player)
	, m_playerProjectiles(playerProjectiles)
	, m_boss(boss)
	, m_bossProjectiles(bossProjectiles)
	, m_effectSpawner(effectSpawner)
{
}

void PhysicsEngine::update(float dt)
{
	//Boss reaction on Player bullet's & -m_bossHP
	//bullet's distract's if they are hit the boss
	for (Projectile* playerProjectile : m_playerProjectiles)
	{
		sf::FloatRect bossBox = m_boss->getBoundingBox();
		sf::FloatRect playerProjectileBox = playerProjectile->getBoundingBox();

		if (std::optional intersectedBox = bossBox.findIntersection(playerProjectileBox))
		{
			playerProjectile->onCollision(m_boss);
			m_boss->onCollision(playerProjectile);

			if (m_effectSpawner)
			{
				m_effectSpawner->spawnEffect(playerProjectile->getPosition(), EffectType::PlayerHitSparkEffect);
			}
		}
	}

	//Player reaction on Boss bullet's & -m_playerHP
	//bullet's distract's if they are hit the Player
	for (Projectile* bossProjectile : m_bossProjectiles)
	{
		sf::FloatRect playerBox = m_player->getBoundingBox();
		sf::FloatRect bossProjectileBox = bossProjectile->getBoundingBox();

		if (std::optional intersectedBox = playerBox.findIntersection(bossProjectileBox))
		{
			bossProjectile->onCollision(m_player);
			m_player->onCollision(bossProjectile);

			if (m_effectSpawner)
			{
				if (bossProjectile->getEffectType() == EffectType::BossIceCreamEffect)
				{
					m_effectSpawner->spawnEffect(bossProjectile->getPosition(), EffectType::BossIceCreamEffect);
				}
				if (bossProjectile->getEffectType() == EffectType::BossIceCubsEffect)
				{
					m_effectSpawner->spawnEffect(bossProjectile->getPosition(), EffectType::BossIceCubsEffect);
				}
				
			}
		}
	}

	//Player reaction on colision with Boss -m_playerHP
	sf::FloatRect playerBox = m_player->getBoundingBox();
	sf::FloatRect bossBox = m_boss->getBoundingBox();
	if (std::optional intersectedBox = playerBox.findIntersection(bossBox))
	{
		m_player->onCollision(m_boss);
		m_boss->onCollision(m_player);
	}
}
