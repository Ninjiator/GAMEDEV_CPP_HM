#include "Weapon.h"
#include <iostream>
#include "SoundManager.h"
#include "GameConfig.h"

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
	float delta_X = 0.f;
	sf::Vector2f spawnPosition;
	const float shootTimerMax = 0.1f; 
	m_shootTimer += dt;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter) && m_shootTimer > shootTimerMax)
	{
		m_shootTimer = 0.f;
		if (m_player->getPlayerOrientation() == PlayerOrientation::Left)
		{
			delta_X = -GameConfig::PlayerProjectileSPEED;

			spawnPosition = m_player->getPosition() - sf::Vector2f{ m_player->getSpriteWidth(), 0.f };
		}
		if (m_player->getPlayerOrientation() == PlayerOrientation::Right)
		{
			delta_X = GameConfig::PlayerProjectileSPEED;

			spawnPosition = m_player->getPosition() + sf::Vector2f{ m_player->getSpriteWidth()/2.0f, 0.f };
		}
		
		auto* projectile = new Projectile(m_window, "resources/Sprites/CupHead/beam_spritesheet_centered_spacing_updated.png", 1.f, spawnPosition, delta_X, 0.f);
		projectile->initAnimation(AttackType::PlayerAttack);
		m_projectiles.push_back(projectile);
		SoundManager::getInstance().playPlayerShoot();
	}
}

void Weapon::deleteProjectile(float dt)
{
	for (auto it = m_projectiles.begin(); it != m_projectiles.end(); )
	{
		(*it)->update(dt); 
		if ((*it)->getPosition().x > m_window->getSize().x || 
			(*it)->getPosition().x < 0.f || 
			(*it)->getIsDestroyed() ||
			(*it)->getPosition().y >= m_window->getSize().y ||
			(*it)->getPosition().y < 0.f)
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
