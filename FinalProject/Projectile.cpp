#include "Projectile.h"

Projectile::Projectile(sf::RenderWindow* window, const sf::Vector2f& position)
	: m_window(window)
	, m_texture("resources/cuphead_projectile.png")
	, m_sprite(m_texture)
	, m_position(position)
{
	m_sprite.setPosition(m_position);
}

void Projectile::update(float dt)
{
	m_sprite.setPosition(m_position);
}

void Projectile::draw()
{
	m_window->draw(m_sprite);
}
