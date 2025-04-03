#include "Boss.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "SoundManager.h"

Boss::Boss(sf::RenderWindow* window)
	: GameObject(window)
	, m_texture("resources/Sprites/Boss/snowflake_spritesheet_10frames.png")
	, m_sprite(m_texture)
	, m_orientation(BossOrientation::Left)
	, m_newOrientationRequest(BossOrientation::Left)
{
	m_spriteIntRect = sf::IntRect({ 0, 0 }, { 566, 890 }); 
	m_sprite.setScale({ 0.5f, 0.5f });
	m_sprite.setTextureRect(m_spriteIntRect);
	
	sf::FloatRect spriteLocalBounds = m_sprite.getLocalBounds();
	m_sprite.setOrigin({ spriteLocalBounds.size.x / 2.0f, spriteLocalBounds.size.y / 2.0f });

	const sf::Vector2u windowSize = m_window->getSize(); 
	const sf::FloatRect spriteSize = m_sprite.getGlobalBounds(); 

	sf::Vector2f newPosition = sf::Vector2f{ static_cast<float>(windowSize.x) - spriteSize.size.x / 2.0f,
								static_cast<float>(windowSize.y) - spriteSize.size.y / 2.0f };
	m_sprite.setPosition(newPosition);
}

void Boss::update(float dt)
{
	move(dt);
	handleBossOrientation();
	animation(dt);
}

void Boss::animation(float dt)
{
	m_timer += 0.1f + dt;
	if (m_timer >= m_timerMax)
	{
		const float spriteLocalWidth = m_sprite.getLocalBounds().size.x;
		m_spriteIntRect.position.x += spriteLocalWidth;
		if (m_spriteIntRect.position.x >= m_texture.getSize().x)
		{
			m_spriteIntRect.position.x = 0;
		}
		if (m_spriteIntRect.position.x < m_texture.getSize().x)
		{
			m_sprite.setTextureRect(m_spriteIntRect);
		}
		m_timer = 0.0f;
	}
}

void Boss::handleBossOrientation()
{
	if (m_newOrientationRequest != m_orientation)
	{
		m_sprite.setScale({ m_sprite.getScale().x * -1.0f, m_sprite.getScale().y });
		m_orientation = m_newOrientationRequest;
	}
}

void Boss::move(float dt)
{
	constexpr unsigned int phase_1 = 400;
	constexpr unsigned int phase_2 = 250;
	constexpr unsigned int phase_3 = 100;
	if (phase_1 < m_hp)
		return;
	else if (m_hp < phase_2 && m_hp > phase_3)
	{
		m_reverse = true;
	}
	else if (m_hp < phase_3)
	{
		m_reverse = false;
	}

	if (m_waypoints.empty())
	{
		sf::Vector2u winSize = m_window->getSize();
		float halfWidth = m_sprite.getGlobalBounds().size.x / 2.0f;
		float halfHeight = m_sprite.getGlobalBounds().size.y / 2.0f;
		
		
		sf::Vector2f bottomRight(winSize.x - halfWidth, winSize.y - halfHeight); // 0 – start
		sf::Vector2f topRight(winSize.x - halfWidth, halfHeight);                // 1
		sf::Vector2f topLeft(halfWidth, halfHeight);                             // 2
		sf::Vector2f bottomLeft(halfWidth, winSize.y - halfHeight);              // 3

		m_waypoints.push_back(bottomRight); // index 0
		m_waypoints.push_back(topRight);    // index 1
		m_waypoints.push_back(topLeft);     // index 2
		m_waypoints.push_back(bottomLeft);  // index 3
	}
	
	sf::Vector2f target = m_waypoints[m_currentWaypoint];
	sf::Vector2f currentPos = m_sprite.getPosition();
	sf::Vector2f direction = target - currentPos;
	float distance = std::sqrt(direction.x * direction.x + direction.y * direction.y);
	if (distance > 0.001f)
	{
		direction /= distance;
	}

	float speed = 180.f;
	if (currentPos.x > m_window->getSize().x / 2.f)
	{
		m_newOrientationRequest = BossOrientation::Left;
	}
	else 
	{
		m_newOrientationRequest = BossOrientation::Right;
	}

	sf::Vector2f movement = direction * speed * dt;
	if (std::sqrt(movement.x * movement.x + movement.y * movement.y) > distance)
	{
		currentPos = target;
	}
	else
	{
		currentPos += movement;
	}

	m_sprite.setPosition(currentPos);
	m_position = currentPos;

	if (distance < 5.f)
	{
		if (!m_reverse)
		{
			if (m_currentWaypoint < m_waypoints.size() - 1)
				m_currentWaypoint++;
		}
		else 
		{
			if (m_currentWaypoint > 0)
				m_currentWaypoint--;
		}
	}
}




void Boss::draw()
{
	m_window->draw(m_sprite);
}

void Boss::onCollision(GameObject* colidable)
{
	if (colidable->getType() == Type::Projectile)
	{
		m_hp--;
		SoundManager::getInstance().playBossHittedSound();
		std::cout << "[BOSS HP] " << m_hp <<std::endl;
	}
	if (colidable->getType() == Type::Player)
	{
//TODO: add some effect/SFX
	}
	if (colidable->getType() == Type::Unknown)
	{
		std::cerr << "UNKOWN TYPE!!!" << std::endl;
	}
}
