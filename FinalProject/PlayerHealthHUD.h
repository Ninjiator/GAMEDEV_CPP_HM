#pragma once
#include "SFML/Graphics.hpp"

class Player;

class PlayerHealthHUD {
public:
	PlayerHealthHUD(sf::RenderWindow* window);
	

	void update(int hp);
	void draw();              

private:
	sf::RenderWindow* m_window;
	sf::Texture m_texture;
	sf::Sprite m_sprite;
};