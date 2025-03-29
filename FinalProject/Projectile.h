#pragma once
#include "SFML/Graphics.hpp"
#include "GameObj.h"
#include <iostream>
#include <string>

class Projectile : public GameObject
{
public:
	Projectile(sf::RenderWindow* window, const std::string& fileName, const float& scale, const sf::Vector2f& position, float speed_x, float speed_y);
	//~Projectile() { std::cout << "deleted\n"; };

	void update(float dt) override;
	void draw() override;
	void onCollision(GameObject* colidable) override;

	sf::Vector2f getPosition() { return m_position; };
	sf::FloatRect getBoundingBox() { return m_sprite.getGlobalBounds(); }
	Type getType() override { return Type::Projectile; }
	bool getIsDestroyed() { return m_isDestroyed; }

	void setPosition(sf::Vector2f& position) { m_position = position; }
private:
	sf::Texture m_texture;
	sf::Sprite m_sprite;
	float m_width = 50.f;

	sf::Vector2f m_position;
	float m_deltaX;
	float m_deltaY = 0.f;
	
	bool m_isDestroyed = false;
};

