#pragma once
#include "Projectile.h"
#include <vector>
#include "SFML/Graphics.hpp"
#include "Player.h"

class Weapon
{
public:
	Weapon(sf::RenderWindow* window, Player* player);
	void update(float dt);
	void draw();
	void shoot(float dt);

private:
	sf::RenderWindow* m_window = nullptr;
	Player* m_player = nullptr;

	std::vector<Projectile*> m_projectiles;
	sf::Vector2f m_position;
};