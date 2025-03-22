#pragma once
#include "SFML/Graphics.hpp"
class Projectile
{
public:
	Projectile(sf::RenderWindow* window, const sf::Vector2f& position);
	void update(float dt);
	void draw();

	void setPosition(sf::Vector2f& position) { m_position = position; }
	sf::Vector2f getPosition() { return m_position; };
private:
	sf::RenderWindow* m_window;
	sf::Texture m_texture;
	sf::Sprite m_sprite;
	float m_width = 50.f;

	sf::Vector2f m_position;
};

