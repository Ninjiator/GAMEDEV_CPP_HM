#include "Animation.h"
#include "SFML/Graphics.hpp"

Animation::Animation(sf::Texture& texture, sf::Vector2i frameSize, int frameCount, float duration)
    : m_texture(&texture)
    , m_frameSize(frameSize)
    , m_frameCount(frameCount)
    , m_duration(duration)
{
}

void Animation::update(float dt)
{
    if (m_finished) return;

    m_elapsed += dt;
    float timePerFrame = m_duration / m_frameCount;

    while (m_elapsed >= timePerFrame) 
    {
        m_elapsed -= timePerFrame;
        m_currentFrame++;

        if (m_currentFrame >= m_frameCount) 
        {
            if (m_loop)
            {
                m_currentFrame = 0;
            }
            else 
            {
                m_currentFrame = m_frameCount - 1;
                m_finished = true;
            }
        }
    }
}

void Animation::applyToSprite(sf::Sprite& sprite)
{
    int x = m_currentFrame * m_frameSize.x;
    sprite.setTexture(*m_texture);
    sprite.setTextureRect(sf::IntRect({ x, 0 }, m_frameSize));
    sprite.setOrigin(sf::Vector2f( m_frameSize.x / 2.f, m_frameSize.y / 2.f ));
}

bool Animation::isFinished() const
{
	return m_finished;
}

void Animation::reset()
{
    m_elapsed = 0.f;
    m_currentFrame = 0;
    m_finished = false;
}