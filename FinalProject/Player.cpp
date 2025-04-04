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
	m_spriteIntRect = sf::IntRect({0, 0}, {100, 150}); 
	m_sprite.setTextureRect(m_spriteIntRect);
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
	const float jumpImpulse = -70000.f * dt;

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


void Player::giveDamage()
{
	if (m_damageCooldown.getElapsedTime().asSeconds() > m_invincibilityDuration)
	{
		m_hp--;
		m_damageCooldown.restart();
		SoundManager::getInstance().playPlayerHittedSound();
		std::cout << "[PLAYER] HIT — HP = " << m_hp << std::endl;
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
		//m_texture.loadFromFile("resources/Sprites/CupHead/player_spritesheet_duck.png");
		//m_sprite.setTexture(m_texture);
		//m_sprite.setScale({1.0f, 1.0f});
		//m_spriteIntRect = sf::IntRect({ 0, 0 }, { 163, 92 }); // x + 100
		//m_sprite.setTextureRect(m_spriteIntRect);
	}
	else
	{
		//m_texture.loadFromFile("resources/Sprites/CupHead/cuphead_spritesheet.png");
		//m_sprite.setTexture(m_texture);
		////m_spriteIntRect = sf::IntRect({ 0, 0 }, { 100, 150 });
		////m_sprite.setTextureRect(m_spriteIntRect);
	}
	m_position = m_sprite.getPosition() + sf::Vector2f{ deltaX, deltaY };
}
