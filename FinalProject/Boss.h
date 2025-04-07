#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include "GameObj.h"
#include "Animation.h"

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

	int getHealthPoints() override { return m_hp; }

	void giveDamage();
	bool isEntityAlive() override;

	sf::FloatRect getBoundingBox() { return m_sprite.getGlobalBounds(); }
	const BossOrientation& getBossOrientation() { return m_orientation; }
	
private:
	void handleBossOrientation();
	void move(float dt); 

private:
	sf::Clock m_damageCooldown;
	float m_invincibilityDuration = 0.1f;

	sf::Texture m_texture;
	sf::Sprite m_sprite;
	Animation m_animation;

	sf::Texture m_deathTexture;
	Animation m_deathAnimation;

	int m_hp = 200;

	sf::Vector2f m_position;
	
	bool m_reverse = false;

	BossOrientation m_newOrientationRequest;
	BossOrientation m_orientation;

	std::vector<sf::Vector2f >m_waypoints;
	int m_currentWaypoint = 0;
};