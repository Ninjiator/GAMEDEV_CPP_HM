#include "Boss.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "SoundManager.h"
#include "GameConfig.h"

Boss::Boss(sf::RenderWindow* window)
	: GameObject(window)
	, m_texture("resources/Sprites/Boss/snowflake_spritesheet_10frames.png")
	, m_sprite(m_texture)
	, m_orientation(BossOrientation::Left)
	, m_newOrientationRequest(BossOrientation::Left)
	, m_defaultAnimation(m_texture, { 566, 890 }, 8, 0.6f)
	, m_finalStageTexture("resources/Sprites/Boss/last_stage.png")
	, m_finalStageAnimation(m_finalStageTexture, {581, 935}, 10, 0.8)
	, m_deathTexture("resources/Sprites/Boss/death_final.png")
	, m_deathAnimation(m_deathTexture, { 557,834 }, 20, 3.0f)
{
	//boss setup
	m_deathAnimation.setLoopFalse();
	m_defaultAnimation.applyToSprite(m_sprite);

	m_sprite.setScale({ 0.5f, 0.5f });
	sf::FloatRect spriteLocalBounds = m_sprite.getLocalBounds();
	m_sprite.setOrigin({ spriteLocalBounds.size.x / 2.0f, spriteLocalBounds.size.y / 2.0f });
	const sf::Vector2u windowSize = m_window->getSize(); 
	const sf::FloatRect spriteSize = m_sprite.getGlobalBounds(); 
	sf::Vector2f newPosition = sf::Vector2f{ static_cast<float>(windowSize.x) - spriteSize.size.x / 2.0f,
								static_cast<float>(windowSize.y) - spriteSize.size.y / 2.0f };
	m_sprite.setPosition(newPosition);
	
	//waipoint's setup for movement
	sf::Vector2u winSize = m_window->getSize();
	float halfWidth = m_sprite.getGlobalBounds().size.x / 2.0f;
	float halfHeight = m_sprite.getGlobalBounds().size.y / 2.0f;

	sf::Vector2f bottomRight(winSize.x - halfWidth, winSize.y - halfHeight);
	sf::Vector2f topRight(winSize.x - halfWidth, halfHeight);
	sf::Vector2f centerOfScreen(winSize.x / 2.f, winSize.y / 2.f);
	//sf::Vector2f centerBottom(winSize.x / 2.f, winSize.y - halfHeight);
	sf::Vector2f topLeft(halfWidth, halfHeight);
	sf::Vector2f bottomLeft(halfWidth, winSize.y - halfHeight);

	m_waypoints.push_back(bottomRight); // index 0
	m_waypoints.push_back(topRight);
	m_waypoints.push_back(centerOfScreen);
	//m_waypoints.push_back(centerBottom);
	m_waypoints.push_back(topLeft);
	m_waypoints.push_back(bottomLeft);
}

void Boss::update(float dt)
{
	move(dt);
	handleBossOrientation();
	updateStage();
	chooseAnimation(dt);
}

void Boss::chooseAnimation(float dt)
{
	if (isEntityAlive() == true)
	{
		if (m_bossPhase == BossPhase::Phase_1)
		{
			m_defaultAnimation.update(dt);
			m_defaultAnimation.applyToSprite(m_sprite);
		}
		else
		{
			m_sprite.setTexture(m_finalStageTexture);
			m_finalStageAnimation.update(dt);
			m_finalStageAnimation.applyToSprite(m_sprite);
		}	
	}
	else
	{
		m_sprite.setTexture(m_deathTexture);
		m_deathAnimation.update(dt);
		m_deathAnimation.applyToSprite(m_sprite);
	}
}

void Boss::giveDamage()
{
	if (m_damageCooldown.getElapsedTime().asSeconds() > m_invincibilityDuration)
	{
		m_hp--;
		m_damageCooldown.restart();
		SoundManager::getInstance().playBossHittedSound();
		std::cout << "[BOSS] HIT — HP = " << m_hp << std::endl;
	}
}

bool Boss::isEntityAlive()
{
	if (m_hp > 0)
	{
		return true;
	}
	else
	{
		return false;
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
	if (GameConfig::BossHPThreshold_1 < m_hp || isEntityAlive() == false)
	{
		return;
	}
	else if (m_hp < GameConfig::BossHPThreshold_2 && m_hp > GameConfig::BossHPThreshold_3)
	{
		m_reverse = true;
	}
	else if (m_hp < GameConfig::BossHPThreshold_3)
	{
		m_reverse = false;
	}

	if (m_waypoints.empty())
	{
		 
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
		giveDamage();
		std::cout << "[BOSS HP] " << m_hp <<std::endl;
	}
	if (colidable->getType() == Type::Player)
	{
	}
	if (colidable->getType() == Type::Unknown)
	{
		std::cerr << "UNKOWN TYPE!!!" << std::endl;
	}
}

void Boss::updateStage()
{
	if (m_hp > GameConfig::BossHPThreshold_1)
	{
		m_bossPhase = BossPhase::Phase_1;														// 200-150
	}
	else if (m_hp < GameConfig::BossHPThreshold_2 && m_hp > GameConfig::BossHPThreshold_3)
	{
		m_bossPhase = BossPhase::Phase_2;														// 100-50
	}
	else if (m_hp < GameConfig::BossHPThreshold_3)
	{
		m_bossPhase = BossPhase::Phase_3;														// 50-1
	}
	
}
