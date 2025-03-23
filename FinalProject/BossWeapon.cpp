#include "BossWeapon.h"
#include "Boss.h"

BossWeapon::BossWeapon(sf::RenderWindow* window, Boss* boss)
	: Weapon(window, nullptr) //using base c-tor from Weapon, nullptr for player
	, m_boss(boss)
{

}

void BossWeapon::update(float dt)
{
	shoot(dt);
	Weapon::deleteProjectile(dt);
}

void BossWeapon::shoot(float dt)
{
	float SPEED_X = -1000.f;
	float delta_X = 0.f;
	sf::Vector2f spawnPosition;
	const float shootTimerMax = 0.1f;
	m_shootTimer += dt;

	if ( m_shootTimer > shootTimerMax)
	{
		m_shootTimer = 0.f;
		
		spawnPosition = m_boss->getPosition() + sf::Vector2f{ m_boss->getBossWidth() / 2.f, 0.f };
		
		m_projectiles.push_back(new Projectile{ m_window, spawnPosition, delta_X });
	}
}
