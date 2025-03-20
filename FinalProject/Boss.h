#pragma once
#include <SFML/Graphics.hpp>

class Boss
{
public:
	Boss(sf::RenderWindow* window);

	void update(float dt);
	void draw();
private:
	sf::RenderWindow* m_window = nullptr;

	sf::Texture m_texture;
	sf::Sprite m_sprite;
};