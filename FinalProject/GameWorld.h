#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Background.h"
#include "Player.h"
#include "Boss.h"
#include "Weapon.h"
#include "BossWeapon.h"
#include "PhysicsEngine.h"
#include "PlayerHealthHUD.h"
#include <map>



class GameWorld
{
public:
	GameWorld(sf::RenderWindow* window);
	~GameWorld();

	void blur();
	void unblur();
	void init();
	void update(float DeltaTime);
	void draw();

	Player* getPlayer() { return m_player; }
	Boss* getBoss() { return m_boss; }

private:
	sf::RenderWindow* m_window;

	PlayerHealthHUD* m_playerHealthHUD;
	
	Player* m_player;
	Boss* m_boss;

	Background* m_background;
	Weapon* m_playerProjectiles;
	BossWeapon* m_bossProjectiles;

	PhysicsEngine* m_physicsEngine;

	bool m_blurred = false;
	sf::RectangleShape m_rectangle;

	sf::Texture m_cupHeadSimpleShotTexture;
	sf::Texture m_BossSimpleShotTexture;
	sf::Texture m_IceCreamBombTexture;
};