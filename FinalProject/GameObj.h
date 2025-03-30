#pragma once
#include "SFML/Graphics.hpp"

enum class Type // in use instead of dynamic_cast
{
	Unknown,
	Projectile,
	Boss,
	Player
};

class GameObject
{
public:
	GameObject(sf::RenderWindow* window) : m_window(window) {}

	virtual void update(float dt) {}
	virtual void draw() = 0;

	virtual void onCollision(GameObject* gameObject) {}

	virtual Type getType() { return Type::Unknown; }
	virtual sf::Vector2f getPosition() = 0;
	virtual const float getSpriteWidth() { return 0.0f; }
	virtual const float getSpriteHeight() { return 0.0f; }
	virtual int getHealthPoints() { return 0; }

protected:
	sf::RenderWindow* m_window = nullptr;
};