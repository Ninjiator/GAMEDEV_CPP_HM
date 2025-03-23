#include "Projectile.h"

Projectile::Projectile(sf::RenderWindow* window, const sf::Vector2f& position, float speed)
	: GameObject(window)
	, m_texture("resources/cuphead_projectile.png")
	, m_sprite(m_texture)
	, m_position(position)
	, m_speed_x(speed)
{
	m_sprite.setPosition(m_position);
}



void Projectile::update(float dt)
{
	m_position.x += m_speed_x * dt; 
	m_sprite.setPosition(m_position);
}

void Projectile::draw()
{
	m_window->draw(m_sprite);
}
