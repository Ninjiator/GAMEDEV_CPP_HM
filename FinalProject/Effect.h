#pragma once
#include <SFML/Graphics.hpp>
#include "Animation.h"

class Effect
{
public:
    Effect(sf::Texture& texture, sf::Vector2f position, sf::Vector2i frameSize, int frameCount, float duration, float scale);

    void update(float dt);
    void draw(sf::RenderWindow& window);
    bool isFinished() const;

private:
    float m_scale;
    sf::Sprite m_sprite;
    Animation m_animation;
};