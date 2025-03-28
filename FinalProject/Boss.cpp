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

	sf::Vector2f newPosition = sf::Vector2f{ static_cast<float>(windowSize.x) - static_cast<float>(windowSize.x) / 7.0f,
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
    if (m_hp > 10)
    {
        return;
    }
    //TODO: need to be moved down
    sf::Vector2u winSize = m_window->getSize();
    sf::Vector2f currentPos = m_sprite.getPosition();
    float bottomLimit = static_cast<float>(winSize.y) - m_sprite.getGlobalBounds().size.y / 2.0f;
    float leftCornerX = static_cast<float>(winSize.x) / 7.f;
    float rightCornerX = static_cast<float>(winSize.x) - leftCornerX;
    if (m_hp < 5)
    {
        m_reverse = true;
        if (currentPos.y == bottomLimit && rightCornerX == currentPos.x)
        {
            m_reverse = false;
        }
    }

    const float SPEED = 200.f * dt;
    
    

    float targetY = static_cast<float>(winSize.y) / 3.f;  
    
    

    switch (m_state)
    {
    case BossMovementState::MovingUp:
    {
        if (currentPos.y > targetY + 1.f)
        {
            currentPos.y -= SPEED;
            if (currentPos.y < targetY)
            {
                currentPos.y = targetY;
            }
        }
        else
        {
            currentPos.y = targetY;
            m_state = BossMovementState::MovingLeft;
            if (m_reverse)
            {
                m_state = BossMovementState::MovingRight;
            }
        }
        break;
    }
    case BossMovementState::MovingLeft:
    {
        // –ух вл≥во, поки pos.x > targetX
        if (currentPos.x > leftCornerX + 1.f)
        {
            currentPos.x -= SPEED;
            if (currentPos.x < leftCornerX)
            {
                currentPos.x = leftCornerX;
            }
        }
        else
        {
            currentPos.x = leftCornerX;
            m_state = BossMovementState::MovingDown;
            m_newOrientationRequest = BossOrientation::Right;
        }
        break;
    }
    case BossMovementState::MovingRight:
    {
        if (currentPos.x < rightCornerX)
        {
            currentPos.x += SPEED;
            if (currentPos.x > rightCornerX)
            {
                currentPos.x = rightCornerX;
            }
        }
        else
        {
            currentPos.x = rightCornerX;
            m_newOrientationRequest = BossOrientation::Left;
            if (m_reverse)
            {
                m_state = BossMovementState::MovingDown;
                m_newOrientationRequest = BossOrientation::Left;
            }
        }
    }
    break;
    case BossMovementState::MovingDown:
    {
        float bottomLimit = static_cast<float>(winSize.y) - m_sprite.getGlobalBounds().size.y / 2.0f;
        if (currentPos.y < bottomLimit - 1.f)
        {
            currentPos.y += SPEED;
            if (currentPos.y > bottomLimit)
                currentPos.y = bottomLimit;
        }
        else
        {
            currentPos.y = bottomLimit;
            if (m_reverse)
            {
                m_state = BossMovementState::MovingUp;
            }
 
        }
        break;
    }
    }
    m_sprite.setPosition(currentPos);
    m_position = currentPos;
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
