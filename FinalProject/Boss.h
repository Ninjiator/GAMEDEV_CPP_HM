#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include "GameObj.h"

class Boss : public GameObject
{
public:
	Boss(sf::RenderWindow* window);

	void update(float dt) override;
	void draw() override;

	sf::Vector2f getPosition() { return m_position = m_sprite.getPosition(); }
	const float getBossWidth() { return m_spriteWidth; }
	
	//TODO:
	void movement(float dt) {}; // boss moveset accordingly to the phase
	void rainBombAbility() {}; //spawn falling bomb's

	void animation(float dt);
	
private:
	
	sf::Texture m_texture;
	sf::Sprite m_sprite;

	sf::Vector2f m_position;

	sf::IntRect m_spriteIntRect;

	float m_timer = 0.0f;
	const float m_timerMax = 0.45f;
	const float m_spriteWidth = 566.0f;
};