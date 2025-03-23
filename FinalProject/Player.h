#pragma once
#include <SFML/Graphics.hpp>
#include "GameObj.h"

enum class PlayerOrientation
{
	Left,
	Right,
	Down,
	Jump,
};

class Player : public GameObject
{
public:
	Player(sf::RenderWindow* window);
	void update(float dt) override;
	void draw() override;

	sf::Vector2f getPosition() { return m_position; }
	const PlayerOrientation& getPlayerOrientation() { return m_orientation; }

	void animation(float dt);
	
	

private:
	void handleInput(float dt);
	void handlePlayerOrientation();
	void handleArenaBounds();
	void updateGravity(float dt);
	void applyVelocity(float dt);
	void updateJumpInput(float dt);
	void jumpImpulse(float dt);

private:
	sf::Texture m_texture;
	sf::Sprite m_sprite;
	
	sf::Vector2f m_position;
	PlayerOrientation m_orientation;
	PlayerOrientation m_newOrientationRequest;

	sf::Vector2f m_velocity; //Player speed for x & y, used for gravity
	bool m_onGround = true;

	sf::Clock m_jumpCoolDownTimer;
	float m_jumpCoolDownSec = 0.8f;

	sf::IntRect m_spriteIntRect;
	float m_timer = 0.0f;
	const float m_timerMax = 0.65f;
	float m_spriteWidth = 100.0f;
};