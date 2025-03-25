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
	void onCollision(GameObject* colidable) override;

	sf::Vector2f getPosition() { return m_position = m_sprite.getPosition(); }
	const float getSpriteWidth() { return m_spriteWidth; }

	sf::FloatRect getBoundingBox() { return m_sprite.getGlobalBounds(); }

	Type getType() override { return Type::Boss; }
	
private:
	void animation(float dt);
	//TODO:
	void movement(float dt) {}; // boss moveset accordingly to the phase
	void rainBombAbility() {}; //spawn falling bomb's

private:
	sf::Texture m_texture;
	sf::Sprite m_sprite;

	int m_hp = 1000;

	sf::Vector2f m_position;

	sf::IntRect m_spriteIntRect;

	float m_timer = 0.0f;
	const float m_timerMax = 0.45f;
	const float m_spriteWidth = 566.0f;
};