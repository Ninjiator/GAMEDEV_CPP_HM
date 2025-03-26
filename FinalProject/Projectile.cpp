#include "Projectile.h"
#include "SoundManager.h"

Projectile::Projectile(sf::RenderWindow* window, const std::string& fileName, const float& scale, const sf::Vector2f& position, float speed_x, float speed_y)
	: GameObject(window)
	, m_texture(fileName)
	, m_sprite(m_texture)
	, m_position(position)
	, m_speed_x(speed_x)
	, m_speed_y(speed_y)
{
	m_sprite.setPosition(m_position);
	m_sprite.setScale({ scale, scale });
}



void Projectile::update(float dt)
{
	m_position.x += m_speed_x * dt; 
	if (m_speed_y != 0.f)
	{
		m_position.y += m_speed_y * dt;
	}
	m_sprite.setPosition(m_position);
}

void Projectile::draw()
{
	m_window->draw(m_sprite);
}

void Projectile::onCollision(GameObject* colidable)
{
	if (colidable->getType() == Type::Boss)
	{
		m_isDestroyed = true;
	}
	if (colidable->getType() == Type::Player)
	{
		m_isDestroyed = true;
	}
	else if (colidable->getType() == Type::Unknown)
	{
		std::cerr << "Unknown TYPE" << std::endl;
	}
}