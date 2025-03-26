#include "Boss.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "SoundManager.h"

Boss::Boss(sf::RenderWindow* window)
	: GameObject(window)
	, m_texture("resources/Sprites/Boss/snowflake_spritesheet_10frames.png")
	, m_sprite(m_texture)
{
	m_spriteIntRect = sf::IntRect({ 0, 0 }, { 566, 890 }); // õ + 558
	m_sprite.setScale({ 0.6f, 0.6f });
	m_sprite.setTextureRect(m_spriteIntRect);
	
	sf::FloatRect spriteLocalBounds = m_sprite.getLocalBounds();
	m_sprite.setOrigin({ spriteLocalBounds.size.x / 2.0f, spriteLocalBounds.size.y / 2.0f });

	const sf::Vector2u windowSize = m_window->getSize(); // Vector2u - save wight and height in unsigned type
	const sf::FloatRect spriteSize = m_sprite.getGlobalBounds(); //returns a resctangle 

	sf::Vector2f newPosition = sf::Vector2f{ static_cast<float>(windowSize.x) - static_cast<float>(windowSize.x) / 7.0f,
								static_cast<float>(windowSize.y) - spriteSize.size.y / 2.0f };
	m_sprite.setPosition(newPosition);
}

void Boss::update(float dt)
{
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
		std::cout << "[BOSS HITTED BY PLAYER]" << std::endl;
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
