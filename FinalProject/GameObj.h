#pragma once
#include "SFML/Graphics.hpp"

class GameObject
{
public:
	GameObject(sf::RenderWindow* window) : m_window(window) {}

	virtual void update(float dt) {}
	virtual void draw() = 0;

protected:
	sf::RenderWindow* m_window = nullptr;
};