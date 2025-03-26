#include "Player.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "SoundManager.h"

Player::Player(sf::RenderWindow* window)
	: GameObject(window)
	, m_texture("resources/Sprites/CupHead/cuphead_spritesheet.png")
	, m_sprite(m_texture)
	, m_orientation(PlayerOrientation::Right)
	, m_newOrientationRequest(PlayerOrientation::Right)
{
	m_spriteIntRect = sf::IntRect({0, 0}, {100, 150}); // x + 100
	m_sprite.setTextureRect(m_spriteIntRect);
	m_sprite.scale({ 1.0f, 1.0f });

	sf::FloatRect spriteLocalBounds = m_sprite.getLocalBounds();
	m_sprite.setOrigin({ spriteLocalBounds.size.x / 2.0f, spriteLocalBounds.size.y / 2.0f });

	const sf::Vector2u windowSize = m_window->getSize(); // Vector2u - save w and h in unsigned type
	const sf::FloatRect spriteSize = m_sprite.getGlobalBounds(); //returns a resctangle sizes
	
	sf::Vector2f newPosition = sf::Vector2f{ static_cast<float>(windowSize.x) / 3.0f, static_cast<float>(windowSize.y) - spriteSize.size.y / 2.0f};
	m_sprite.setPosition(newPosition);
}

void Player::update(float dt)
{
	handleInput(dt);
	updateJumpInput(dt);

	updateGravity(dt);
	applyVelocity(dt);
	
	handleArenaBounds();
	
	handlePlayerOrientation();
	animation(dt);
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
	const float acceleration = 2000.0f;
	m_velocity.y += acceleration * dt;
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
	const float jumpImpulse = -65000.f * dt;

	m_velocity.y = jumpImpulse;
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
		m_hp--;
		std::cout << "[PLAYER] HITTED by Projectile" << std::endl;
	}
	if (colidable->getType() == Type::Boss)
	{
		float spriteWidth = m_sprite.getGlobalBounds().size.x;
		m_hp--;
		std::cout << "--[BOSS HIT'S THE PLAYER by colision]--" << std::endl;
		
		////Right Boss side
		if (m_position.x + spriteWidth / 2.0f > colidable->getPosition().x + colidable->getSpriteWidth() / 2.0f)
		{
			m_position.x = colidable->getPosition().x + colidable->getSpriteWidth() / 2.0f + spriteWidth / 2.0f;
		}
		//Left Boss side
		if (m_position.x + spriteWidth / 2.0f > colidable->getPosition().x - colidable->getSpriteWidth() / 2.0f)
		{
			m_position.x = colidable->getPosition().x - colidable->getSpriteWidth() / 2.0f - spriteWidth / 2.0f;
		}
		m_sprite.setPosition(m_position);
	}
	else if (colidable->getType() == Type::Unknown)
	{
		std::cerr << "Unknown type detected, check the code!" << std::endl;
	}
	
}

void Player::animation(float dt)
{
	m_timer += 0.1+dt;
	
	if (m_timer >= m_timerMax)
	{
		const float spriteLocalWidth = m_sprite.getGlobalBounds().size.x;
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

bool Player::IsPlayerAlive()
{
	if (m_hp > 0)
	{
		SoundManager::getInstance().playPlayerDeathSound();
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
		//m_texture.loadFromFile("resources/cuphead_duck_shoot_0001.png");
		//m_sprite.setTexture(m_texture);
		//m_sprite.setScale({1.2f, 0.3f});
	}
	m_position = m_sprite.getPosition() + sf::Vector2f{ deltaX, deltaY };
}
