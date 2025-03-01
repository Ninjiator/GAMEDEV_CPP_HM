#pragma once
#include <SFML/Graphics.hpp>



class Background
{
public:
	Background(sf::RenderWindow* window);

	void draw();
	const sf::Sprite& getSprite() const { return m_sprite; }

private:

	sf::Sprite m_sprite;
	sf::Texture m_texture;

	sf::RenderWindow* m_window = nullptr;
};