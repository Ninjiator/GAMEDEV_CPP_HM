#include "Effect.h"

Effect::Effect(sf::Texture& texture, sf::Vector2f position, sf::Vector2i frameSize, int frameCount, float duration, float scale)
	: m_animation(texture, frameSize, frameCount, duration)
	, m_sprite(texture)
	, m_scale(scale)
{
	m_sprite.setScale({ m_scale, m_scale });
	m_animation.setLoopFalse();
	m_sprite.setPosition(position);
	m_sprite.setOrigin({ frameSize.x / 2.f, frameSize.y / 2.f });
}

void Effect::update(float dt)
{
	m_animation.update(dt);
	m_animation.applyToSprite(m_sprite);
}

void Effect::draw(sf::RenderWindow& window)
{
	window.draw(m_sprite);
}

bool Effect::isFinished() const
{
	return m_animation.isFinished();
}
