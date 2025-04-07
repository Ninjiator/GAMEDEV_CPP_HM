#include <iostream>
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Background.h"
#include "Boss.h"
#include "Projectile.h"
#include "Weapon.h"
#include "BossWeapon.h"
#include "PhysicsEngine.h"
#include "SoundManager.h"
#include "GameState.h"
#include "GameStateManager.h"
#include "GameWorld.h"

void handleSystemIvents(sf::RenderWindow& window)
{
	while (const std::optional event = window.pollEvent())
	{
		if (event->is<sf::Event::Closed>())
		{
			window.close();
		}
	}
}

int main()
{
    sf::RenderWindow window(sf::VideoMode( {1280, 720}), "CupHead" );
    window.setFramerateLimit(60);

	sf::Clock frameRateClock;
	std::srand(std::time(nullptr));
	GameWorld* gameWorld = new GameWorld(&window);
	GameStateManager gameStateManager(gameWorld, GameStateId::TitleScreen, &window);

	while (window.isOpen()) 
	{
		float deltaTimeSec = frameRateClock.restart().asSeconds();
		//Step:1 Handle System events
		handleSystemIvents(window);

		//Step:2 update all game obj
		gameStateManager.getCurrentGameState()->update(deltaTimeSec);

		//Step:3 draw all game obj
		gameStateManager.getCurrentGameState()->draw();

		//Step:4 vizualize
		gameStateManager.getCurrentGameState()->updateState();
		window.display();
	}
	delete gameWorld;
}
