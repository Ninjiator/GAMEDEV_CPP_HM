#include "Boss.h"
#include <SFML/Graphics.hpp>


Boss::Boss(sf::RenderWindow* window)
	: m_window(window)
	, m_texture("resources/snowflake_spritesheet.png")
	, m_sprite(m_texture)
	
{
	m_spriteIntRect = sf::IntRect({ 0, 0 }, { 558, 882 }); // õ + 558
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
	if (true)
	{
		if (m_spriteIntRect.position.x == 3348)
		{
			m_spriteIntRect.position.x = 0;
		}
		else
		{
			m_spriteIntRect.position.x += 558;
		}
		m_sprite.setTextureRect(m_spriteIntRect);
	}
	
	/*if (m_spriteIntRect.position.x == 0)
	{
		m_spriteIntRect.position.x += 558;
		m_sprite.setTextureRect(m_spriteIntRect);
		return;
	}
	if (m_spriteIntRect.position.x == 3348)
	{
		m_spriteIntRect.position.x -= 558;
		m_sprite.setTextureRect(m_spriteIntRect);
		return;
	}*/
	
}

void Boss::draw()
{
	m_window->draw(m_sprite);
}
