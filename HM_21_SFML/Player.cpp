#include <SFML/Graphics.hpp>
#include "Player.h"


Player::Player(sf::RenderWindow* window)
	: m_window(window)
	, m_texture("resources/doodle.png")
	, m_sprite(m_texture)
	, m_orientation(PlayerOrientation::Right)
	, m_newOrientationRequest(PlayerOrientation::Right)
{
	m_sprite.setOrigin({ m_sprite.getLocalBounds().size.x / 2.0f, m_sprite.getLocalBounds().size.y / 2.0f });

	m_sprite.setScale({ 0.2f, 0.2f });

	const sf::Vector2u windowSize = m_window->getSize();

	m_sprite.setPosition(sf::Vector2f{ windowSize.x / 2.0f,
		windowSize.y - m_sprite.getGlobalBounds().size.y });

	m_position = m_sprite.getPosition();
}

void Player::update(float dt)
{
	//Input step
	handleInput(dt);
	updateJumpInput(dt);

	//Physic step
	updateGravity(dt);
	applyVelocity(dt);

	updateOrientation();

	outOfBoundsUpdate();

	m_sprite.setPosition(m_position);
}

void Player::outOfBoundsUpdate()
{
	sf::Vector2u windowSize = m_window->getSize();

	sf::FloatRect spriteBounds = m_sprite.getGlobalBounds();

	float spriteHalfWigth = spriteBounds.size.x / 2.0f;

	if (m_position.x - spriteHalfWigth < 0)
	{
		m_position.x = spriteHalfWigth;
	}
	if (m_position.x + spriteHalfWigth > windowSize.x)
	{
		m_position.x = windowSize.x - spriteHalfWigth;
	}
	m_sprite.setPosition(m_position);
}



void Player::draw()
{
	m_window->draw(m_sprite);
}

void Player::handleInput(float dt)
{
	const float SPEED_X = 1500.0f * dt;

	float deltaX = 0.0f;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
	{
		deltaX += -SPEED_X;
		m_newOrientationRequest = PlayerOrientation::Left;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
	{
		deltaX += SPEED_X;
		m_newOrientationRequest = PlayerOrientation::Right;
	}

	m_position.x += deltaX;

	/*sf::Vector2u windowSize = m_window->getSize();

	sf::FloatRect spriteBounds = m_sprite.getGlobalBounds();

	float spriteHalfWigth = spriteBounds.size.x / 2.0f;

	if (m_position.x - spriteHalfWigth < 0)
	{
		m_position.x = spriteHalfWigth;
	}
	if (m_position.x + spriteHalfWigth > windowSize.x)
	{
		m_position.x = windowSize.x - spriteHalfWigth;
	}*/
	m_sprite.setPosition(m_position);
}

void Player::updateGravity(float dt)
{
	//Apply acceleration DOWN
	const float acceleration = 800.0f;

	m_velocity.y += acceleration * dt;
}

void Player::applyVelocity(float dt)
{
	const sf::Vector2f displacement{ m_velocity.x * dt, m_velocity.y * dt };
	m_position += displacement;
}

void Player::jumpImpulse(float dt)
{
	const float jumpImpulse = -50000.f * dt;

	//Apply INSTANT velocity UP
	m_velocity.y = jumpImpulse;
}

void Player::updateJumpInput(float dt)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space) && m_jumpCooldownTimer.getElapsedTime().asSeconds() > m_jumpCooldownSec)
	{
		jumpImpulse(dt);
		m_jumpCooldownTimer.restart();
	}
}

void Player::updateOrientation()
{
	if (m_newOrientationRequest != m_orientation)
	{
		m_sprite.setScale({ m_sprite.getScale().x * -1.0f, m_sprite.getScale().y });
		m_orientation = m_newOrientationRequest;
	}
}

