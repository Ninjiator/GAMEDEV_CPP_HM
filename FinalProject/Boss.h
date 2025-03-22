#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class Boss
{
public:
	Boss(sf::RenderWindow* window);

	void update(float dt);
	void animation(float dt);
	void draw();
private:
	sf::RenderWindow* m_window = nullptr;
	
	sf::Texture m_texture;
	sf::Sprite m_sprite;

	sf::IntRect m_spriteIntRect;
	float m_timer = 0.0f;
	const float m_timerMax = 0.45f;
	const float m_spriteWidth = 566.0f;
};