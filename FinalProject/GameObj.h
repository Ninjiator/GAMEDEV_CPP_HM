#pragma once
#include "SFML/Graphics.hpp"

class GameObject
{
public:
	GameObject(sf::RenderWindow* window) : m_window(window) {}

	virtual void update(float dt) {}
	virtual void draw() = 0;

	virtual void onCollision(GameObject* gameObject) {}

protected:
	sf::RenderWindow* m_window = nullptr;
};