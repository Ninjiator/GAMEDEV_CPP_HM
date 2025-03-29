#include "Projectile.h"
#include "SoundManager.h"

Projectile::Projectile(sf::RenderWindow* window, const std::string& fileName, const float& scale, const sf::Vector2f& position, float deltaX, float deltaY)
	: GameObject(window)
	, m_texture(fileName)
	, m_sprite(m_texture)
	, m_position(position)
	, m_deltaX(deltaX)
	, m_deltaY(deltaY)
{
	m_sprite.setPosition(m_position);
	m_sprite.setScale({ scale, scale });
}



void Projectile::update(float dt)
{
	m_position.x += m_deltaX * dt; 
	if (m_deltaY != 0.f)
	{
		m_position.y += m_deltaY * dt;
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