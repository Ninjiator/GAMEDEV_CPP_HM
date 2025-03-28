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

	virtual void shoot(float dt);
	void deleteProjectile(float dt);

	std::vector<Projectile*>& getProjectile() { return m_projectiles; }
	sf::Vector2f getPosition() override { return m_position; }

private:
	Player* m_player = nullptr;
	sf::Vector2f m_position;

protected:
	std::vector<Projectile*> m_projectiles;
	float m_shootTimer = 0.f;
	
};