#include <iostream>
#include <algorithm>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Background.h"
#include "Player.h"


bool handleCollision(const sf::Sprite& sprite1, const sf::Sprite& sprite2)
{
    sf::FloatRect box1 = sprite1.getGlobalBounds();
    sf::FloatRect box2 = sprite2.getGlobalBounds();

    if (std::optional intersectedBox = box1.findIntersection(box2))
    {
        return true;
    }

    return false;
}



int main()
{
    sf::RenderWindow window(sf::VideoMode{ {1280, 720} }, "Doodle Jump, pt.2");
    window.setFramerateLimit(60);

    Background background(&window);
    Player player(&window);

    sf::Clock frameRateClock;

    //Game loop
    while (window.isOpen())
    {
        const float dt = frameRateClock.restart().asSeconds();

        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
        }
        
        //UPDATE STEP
        player.update(dt);
        //bool collision = handleCollision(background.getSprite(), player.getSprite());
        
        //DRAW STEP
        window.clear(sf::Color{ 0, 255, 0 });
        background.draw();
        player.draw();

        //DISPLAY STEP
        window.display();
    }

    return 0;
}