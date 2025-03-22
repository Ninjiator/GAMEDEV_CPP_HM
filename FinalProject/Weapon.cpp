#include "Weapon.h"

Weapon::Weapon(sf::RenderWindow* window, Player* player)
	: m_window(window)
	, m_player(player)
	, m_position(player->getPosition())
{
	m_projectiles.push_back(new Projectile{ m_window, m_position });
}

void Weapon::update(float dt)
{
	shoot(dt);
	for (Projectile* projectile : m_projectiles)
	{
		projectile->update(dt);
	}
}

void Weapon::draw()
{
	for (Projectile* projectile : m_projectiles)
	{
		projectile->draw();
	}
}

void Weapon::shoot(float dt)
{
	float SPEED_X = 1000.f * dt;
	float delta_X = 0.f;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
	{
		delta_X += SPEED_X;
		
		m_position = m_player->getPosition() + sf::Vector2f{ delta_X, 0.0f };
		m_projectiles[0]->setPosition(m_position);
	}
	
}
