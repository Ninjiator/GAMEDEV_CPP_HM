#include "Weapon.h"
#include <iostream>
#include "SoundManager.h"

Weapon::Weapon(sf::RenderWindow* window, Player* player)
	: GameObject(window)
	, m_player(player)
{
	if (m_player)
	{
		m_position = m_player->getPosition();
	}
	else
	{
		m_position = sf::Vector2f{ 0.f, 0.f };
	}
}

void Weapon::update(float dt)
{
	shoot(dt);
	deleteProjectile(dt);
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
	float SPEED_X = 1000.f;
	float delta_X = 0.f;
	sf::Vector2f spawnPosition;
	const float shootTimerMax = 0.1f; 
	m_shootTimer += dt;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space) && m_shootTimer > shootTimerMax)
	{
		m_shootTimer = 0.f;
		if (m_player->getPlayerOrientation() == PlayerOrientation::Left)
		{
			delta_X = -SPEED_X;

			spawnPosition = m_player->getPosition() - sf::Vector2f{ m_player->getSpriteWidth() * 1.5f, 0.f };
		}
		if (m_player->getPlayerOrientation() == PlayerOrientation::Right)
		{
			delta_X = SPEED_X;

			spawnPosition = m_player->getPosition() + sf::Vector2f{ 0.f, 0.f };
		}
		
		m_projectiles.push_back(new Projectile{ m_window, "resources/Sprites/CupHead/cuphead_projectile_basic.png", 1.f, spawnPosition, delta_X, 0.f});
		SoundManager::getInstance().playPlayerShoot();
	}
}

void Weapon::deleteProjectile(float dt)
{
	for (auto it = m_projectiles.begin(); it != m_projectiles.end(); )
	{
		(*it)->update(dt); 
		if ((*it)->getPosition().x > m_window->getSize().x || (*it)->getPosition().x < 0.f || (*it)->getIsDestroyed())
		{
			delete* it; 
			std::cout << "PROJECTILE DELETED\n";  
			it = m_projectiles.erase(it); 

		}
		else
		{
			++it; 
		}
	}
}
