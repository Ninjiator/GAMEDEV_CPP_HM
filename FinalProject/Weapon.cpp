#include "Weapon.h"
#include <iostream>

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

			spawnPosition = m_player->getPosition() + sf::Vector2f{ -(m_player->getPlayerWidth())/2.f, 0.f };
		}
		if (m_player->getPlayerOrientation() == PlayerOrientation::Right)
		{
			delta_X = SPEED_X;

			spawnPosition = m_player->getPosition() + sf::Vector2f{ m_player->getPlayerWidth()/2.f, 0.f };
		}
		
		m_projectiles.push_back(new Projectile{ m_window, spawnPosition, delta_X });
	}
}

void Weapon::deleteProjectile(float dt)
{
	for (auto it = m_projectiles.begin(); it != m_projectiles.end(); )
	{
		(*it)->update(dt); 
		// check for out of bounds
		if ((*it)->getPosition().x > m_window->getSize().x || (*it)->getPosition().x < 0.f)
		{
			delete* it; 
			//DEBUG TO DO: Delete 
			std::cout << "PROJECTILE DELETED\n";  
			it = m_projectiles.erase(it); 
		}
		else
		{
			++it; 
		}
	}
	//DEBUG TO DO: Delete 
	//std::cout << "Number of projectiles: " << m_projectiles.size() << std::endl;
}
