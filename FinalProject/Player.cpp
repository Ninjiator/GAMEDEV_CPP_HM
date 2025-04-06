#include "Player.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "SoundManager.h"
#include "Animation.h"
#include "GameConfig.h"

Player::Player(sf::RenderWindow* window)
	: GameObject(window)
	, m_texture("resources/Sprites/CupHead/cuphead_spritesheet.png")
	, m_sprite(m_texture)
	, m_orientation(PlayerOrientation::Right)
	, m_newOrientationRequest(PlayerOrientation::Right)
	, m_animation(m_texture, { 100, 150 }, 5, 0.45f)
	, m_deathTexture("resources/Sprites/CupHead/cuphead_death.png")
	, m_deathAnimation(m_deathTexture, {152,90}, 16, 2.f)
{
	m_deathAnimation.setLoopFalse();
	m_sprite.scale({ 1.0f, 1.0f });

	sf::FloatRect spriteLocalBounds = m_sprite.getLocalBounds();
	m_sprite.setOrigin({ spriteLocalBounds.size.x / 2.0f, spriteLocalBounds.size.y / 2.0f });

	const sf::Vector2u windowSize = m_window->getSize(); 
	const sf::FloatRect spriteSize = m_sprite.getGlobalBounds(); 
	
	sf::Vector2f newPosition = sf::Vector2f{ static_cast<float>(windowSize.x) / 3.0f, static_cast<float>(windowSize.y) - spriteSize.size.y / 2.0f};
	m_sprite.setPosition(newPosition);
}

void Player::update(float dt)
{
	if (isEntityAlive() == true)
	{
		handleInput(dt);
		updateJumpInput(dt);
		updateGravity(dt);
		applyVelocity(dt);
		handleArenaBounds();
		handlePlayerOrientation();
		m_animation.update(dt);
		m_animation.applyToSprite(m_sprite);
	}
	else
	{
		m_sprite.setTexture(m_deathTexture);
		m_deathAnimation.update(dt);
		m_deathAnimation.applyToSprite(m_sprite);
	}

}

void Player::handleArenaBounds()
{
	const float spriteHeight = m_sprite.getGlobalBounds().size.y;
	const float spriteWidth = m_sprite.getGlobalBounds().size.x;
	//Handling floor colision
	if (m_position.y + spriteHeight/ 2.0f >= m_window->getSize().y)
	{
		m_onGround = true;
		m_velocity.y = 0.0f;
		m_position.y = m_window->getSize().y - spriteHeight / 2.0f;
	}

	//Handling wall's colision and updating X coordinate, if collision present
	if (m_position.x + spriteWidth / 2.0f > m_window->getSize().x)
	{
		m_position.x = m_window->getSize().x - spriteWidth / 2.0f;
	}
	else if (m_position.x - spriteWidth / 2.0f < 0.0f)
	{
		m_position.x = spriteWidth / 2.0f;
	}
	m_sprite.setPosition(m_position);
}

void Player::updateGravity(float dt)
{
	m_velocity.y += GameConfig::acceleration * dt;
}

void Player::applyVelocity(float dt)
{
	const sf::Vector2f displacement{ m_velocity.x * dt, m_velocity.y * dt }; //zmishenia
	if (!m_onGround)
	{
		m_position += displacement;
	}
}

void Player::updateJumpInput(float dt)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) && m_jumpCoolDownTimer.getElapsedTime().asSeconds() > m_jumpCoolDownSec && m_onGround == true)
	{
		jumpImpulse(dt);
		m_onGround = false;
		m_jumpCoolDownTimer.restart();
		SoundManager::getInstance().playJumpSound();
	}
}

void Player::jumpImpulse(float dt)
{
	m_velocity.y = GameConfig::jumpImpulse * dt;
}

void Player::handlePlayerOrientation()
{
	if (m_newOrientationRequest != m_orientation)
	{
		m_sprite.setScale({ m_sprite.getScale().x * -1.0f, m_sprite.getScale().y });
		m_orientation = m_newOrientationRequest;
	}
}

void Player::draw()
{
	m_window->draw(m_sprite);
}

void Player::onCollision(GameObject* colidable)
{
	if (colidable->getType() == Type::Projectile)
	{
		giveDamage();
		SoundManager::getInstance().playPlayerHittedSound();
		std::cout << "[PLAYER] HITTED by Projectile" << std::endl;
	}
	if (colidable->getType() == Type::Boss)
	{
		giveDamage();
		SoundManager::getInstance().playPlayerHittedSound();
		std::cout << "--[BOSS HIT'S THE PLAYER by colision]--" << std::endl;

		float spriteHeight = m_sprite.getGlobalBounds().size.y;
		float spriteWidth = m_sprite.getGlobalBounds().size.x;
		float playerLeft = m_position.x - spriteWidth / 2.0f;
		float playerRight = m_position.x + spriteWidth / 2.0f;
		float playerTop = m_position.y - spriteHeight / 2.0f;

		float bossHeight = colidable->getSpriteHeight();
		float bossBottom = colidable->getPosition().y + bossHeight / 2.0f;
		float bossLeft = colidable->getPosition().x - colidable->getSpriteWidth() / 2.0f;
		float bossRight = colidable->getPosition().x + colidable->getSpriteWidth() / 2.0f;

		//Right side
		if (playerLeft < bossRight && m_position.x > colidable->getPosition().x)
		{
			m_position.x = bossRight + spriteWidth / 2.0f;
		}

		//Left side
		if (playerRight > bossLeft && m_position.x < colidable->getPosition().x)
		{
			m_position.x = bossLeft - spriteWidth / 2.0f;
		}
		m_sprite.setPosition(m_position);

		//Bottom TODO: doesn't work
		if (m_position.y > colidable->getPosition().y && playerTop < bossBottom)
		{
			m_position.y = bossBottom + spriteHeight / 2.0f;
		}
	}
	else if (colidable->getType() == Type::Unknown)
	{
		std::cerr << "Unknown type detected, check the code!" << std::endl;
	}
	
}

void Player::giveDamage()
{
	if (m_damageCooldown.getElapsedTime().asSeconds() > m_invincibilityDuration)
	{
		m_hp--;
		m_damageCooldown.restart();
		SoundManager::getInstance().playPlayerHittedSound();
		std::cout << "[PLAYER] HIT � HP = " << m_hp << std::endl;
	}
}

bool Player::isEntityAlive()
{
	if (m_hp > 0 )
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Player::handleInput(float dt)
{
	const float SPEED_X = 800.0f * dt;
	float deltaAir = 0.f;

	//Reducing deltaX during jump action
	if (!m_onGround) 				
	{
		deltaAir = 450.0f * dt;
	}

	float deltaX = 0.0f;
	float deltaY = 0.0f;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
	{
		deltaX = -(SPEED_X - deltaAir);
		m_newOrientationRequest = PlayerOrientation::Left;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
	{
		deltaX = +(SPEED_X - deltaAir);
		m_newOrientationRequest = PlayerOrientation::Right;
	}

	//TO DO:
	//sprite manipulation's for duck, jump, dash
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
	{
	}
	m_position = m_sprite.getPosition() + sf::Vector2f{ deltaX, deltaY };
}
