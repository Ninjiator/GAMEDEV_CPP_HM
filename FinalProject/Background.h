#pragma once
#include <SFML/Graphics.hpp>

class Background
{
public:
	Background(sf::RenderWindow* window);

	void draw();

private:

	sf::Sprite m_sprite;
	sf::Texture m_texture;

	sf::RenderWindow* m_window = nullptr;
};