#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include "GameObj.h"

enum class BossOrientation
{
	Left,
	Right,
};

enum class BossMovementState {
	MovingUp,
	MovingLeft,
	MovingRight,
	MovingDown,
};

class Boss : public GameObject
{
public:
	Boss(sf::RenderWindow* window);

	void update(float dt) override;
	void draw() override;
	void onCollision(GameObject* colidable) override;

	sf::Vector2f getPosition() override{ return m_position = m_sprite.getPosition(); }
	const float getSpriteWidth() override  { return m_sprite.getGlobalBounds().size.x; }
	const float getSpriteHeight() override { return m_sprite.getGlobalBounds().size.y; }
	Type getType() override { return Type::Boss; }
	int getHealthPoints() override{ return m_hp; }

	sf::FloatRect getBoundingBox() { return m_sprite.getGlobalBounds(); }
	const BossOrientation& getBossOrientation() { return m_orientation; }
	
private:
	void animation(float dt);
	void handleBossOrientation();
	void move(float dt); // boss moveset accordingly to the phase/hp

private:
	sf::Texture m_texture;
	sf::Sprite m_sprite;

	int m_hp = 16;

	sf::Vector2f m_position;

	sf::IntRect m_spriteIntRect;

	float m_timer = 0.0f;
	const float m_timerMax = 0.45f;
	
	bool m_reverse = false;

	BossOrientation m_newOrientationRequest;
	BossOrientation m_orientation;
	BossMovementState m_state = BossMovementState::MovingUp;

	std::vector<sf::Vector2f >m_waypoints;
	int m_currentWaypoint = 0;
};