#pragma once
#include <SFML/Graphics.hpp>

enum class PlayerOrientation
{
	Left,
	Right,
	Down,
	Jump,
};

class Player
{
public:
	Player(sf::RenderWindow* window);
	void update(float dt);
	void draw();
	

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

	sf::RenderWindow* m_window = nullptr;

	sf::Vector2f m_position;
	PlayerOrientation m_orientation;
	PlayerOrientation m_newOrientationRequest;

	sf::Vector2f m_velocity; //base Player speed for x & y, used for gravity
	bool m_onGround = true;

	sf::Clock m_jumpCoolDownTimer;
	float m_jumpCoolDownSec = 0.8f;
};