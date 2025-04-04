#pragma once
#include "SFML/Graphics.hpp"

class Animation
{
public:
    Animation(sf::Texture& texture, sf::Vector2i frameSize, int frameCount, float duration);
    void update(float dt); 
    void applyToSprite(sf::Sprite& sprite); // new rect

    void reset(); //start from 0
    bool isFinished() const;

private:
    sf::Texture* m_texture = nullptr;

    sf::Vector2i m_frameSize;
    int m_frameCount = 0;
    float m_duration = 0.f;

    float m_elapsed = 0.f;
    int m_currentFrame = 0;
    bool m_loop = true;
    bool m_finished = false;
}