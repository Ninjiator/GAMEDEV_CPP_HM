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

void handleSystemIvents(sf::RenderWindow& window)
{
	while (const std::optional event = window.pollEvent())
	{
		if (event->is<sf::Event::Closed>())
		{
			window.close();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
		{
			window.close();
		}
	}
}

int main()
{
    sf::RenderWindow window(sf::VideoMode( {1280, 720}), "CupHead" );
    window.setFramerateLimit(60);
	Background background(&window);

	Player player(&window);
	Boss boss(&window);

	Weapon weapon(&window, &player);
	BossWeapon bossWeapon(&window, &boss);

	PhysicsEngine physicsEngine(&player, weapon.getProjectile(), &boss, bossWeapon.getProjectile());

	sf::Clock frameRateClock;
	SoundManager::getInstance().playInGameMusic();
	SoundManager::getInstance().playComentatorStart();
	while (window.isOpen()) //&& player.IsPlayerAlive()
	{
		player.IsPlayerAlive();
		float deltaTimeSec = frameRateClock.restart().asSeconds();
		//Step:1 Handle System events
		handleSystemIvents(window);

		//Step:2 update all game obj
		player.update(deltaTimeSec);
		boss.update(deltaTimeSec);
		weapon.update(deltaTimeSec);
		bossWeapon.update(deltaTimeSec);

		physicsEngine.update(deltaTimeSec);

		//Step:3 draw all game obj
		window.clear(sf::Color::White);
		background.draw();

		player.draw();
		boss.draw();
		weapon.draw();
		bossWeapon.draw();

		//Step:4 vizualize
		window.display();
	}
}
