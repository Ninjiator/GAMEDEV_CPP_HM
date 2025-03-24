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

protected:
	sf::RenderWindow* m_window = nullptr;
};