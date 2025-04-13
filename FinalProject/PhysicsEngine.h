#pragma once
#include "SFML/Graphics.hpp"
#include <vector>
#include "IEffectSpawner.h"

class Projectile;
class Player;
class Boss;

class PhysicsEngine
{
public:
	PhysicsEngine(Player* player, std::vector<Projectile*>& playerProjectiles, Boss* boss, std::vector<Projectile*>& bossProjectiles, IEffectSpawner* effectSpawner);
	void update(float dt);

private:
	Player* m_player = nullptr;
	std::vector<Projectile*>& m_playerProjectiles;

	Boss* m_boss = nullptr;
	std::vector<Projectile*>& m_bossProjectiles;

	IEffectSpawner* m_effectSpawner;
};