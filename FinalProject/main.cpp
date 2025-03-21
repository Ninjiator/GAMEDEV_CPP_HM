#include <iostream>
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Background.h"
#include "Boss.h"


int main()
{
    sf::RenderWindow window(sf::VideoMode( {1280, 720}), "CupHead" );
    window.setFramerateLimit(60);
	Background background(&window);
	Player player(&window);
	Boss boss(&window);

	sf::Clock frameRateClock;

	while (window.isOpen())
	{
		float deltaTimeSec = frameRateClock.restart().asSeconds(); //  dt

		//Step:1 Handle System events
		while (const std::optional event = window.pollEvent())
		{
			if (event->is<sf::Event::Closed>())
			{
				window.close();
			}
		}
		//Step:2 update all game obj
		player.update(deltaTimeSec);
		boss.update(deltaTimeSec);

		//Step:3 draw all game obj
		window.clear(sf::Color::White);
		background.draw();
		player.draw();
		boss.draw();

		//Step:4 vizualize
		window.display();
	}
}
