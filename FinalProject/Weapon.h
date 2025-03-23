#pragma once
#include "Projectile.h"
#include <vector>
#include "SFML/Graphics.hpp"
#include "Player.h"
#include "GameObj.h"

class Weapon : public GameObject
{
public:
	Weapon(sf::RenderWindow* window, Player* player);
	void update(float dt) override;
	void draw() override;

	void shoot(float dt);
	void deleteProjectile(float dt);
private:
	Player* m_player = nullptr;

	std::vector<Projectile*> m_projectiles;
	sf::Vector2f m_position;

	float m_shootTimer = 0.f;
};