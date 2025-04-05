#pragma once
#include "SFML/Graphics.hpp"
#include "GameObj.h"
#include <iostream>
#include <string>
#include "Animation.h"


class Projectile : public GameObject
{
public:
	//Projectile(sf::RenderWindow* window, const ProjectileConfig& config, const sf::Vector2f& position, float deltaX, float deltaY);
	Projectile(sf::RenderWindow* window, const std::string& fileName, const float& scale, const sf::Vector2f& position, float deltaX, float deltaY);
	~Projectile() = default;

	void update(float dt) override;
	void draw() override;
	void onCollision(GameObject* colidable) override;

	sf::Vector2f getPosition() { return m_position; };
	sf::FloatRect getBoundingBox() { return m_sprite.getGlobalBounds(); }
	Type getType() override { return Type::Projectile; }
	bool getIsDestroyed() { return m_isDestroyed; }
	void setPosition(sf::Vector2f& position) { m_position = position; }
private:
	//Animation m_animation;
	sf::Texture m_texture;
	sf::Sprite m_sprite;
	float m_width = 50.f;

	sf::Vector2f m_position;
	float m_deltaX;
	float m_deltaY = 0.f;
	float m_scale = 1.f;
	bool m_isDestroyed = false;
};

