#pragma once
#include "SFML/Graphics.hpp"
#include "GameObj.h"
#include <iostream>

class Projectile : public GameObject
{
public:
	Projectile(sf::RenderWindow* window, const sf::Vector2f& position, float speed);
	~Projectile() { std::cout << "deleted\n"; };

	void update(float dt) override;
	void draw() override;

	void setPosition(sf::Vector2f& position) { m_position = position; }
	sf::Vector2f getPosition() { return m_position; };
private:
	sf::Texture m_texture;
	sf::Sprite m_sprite;
	float m_width = 50.f;

	sf::Vector2f m_position;
	float m_speed_x;
};

