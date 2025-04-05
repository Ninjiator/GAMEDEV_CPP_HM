#include "Projectile.h"
#include "SoundManager.h"

Projectile::Projectile(sf::RenderWindow* window, const std::string& fileName, const float& scale, const sf::Vector2f& position, float deltaX, float deltaY)
	: GameObject(window)
	, m_texture(fileName)
	, m_sprite(m_texture)
	, m_position(position)
	, m_deltaX(deltaX)
	, m_deltaY(deltaY)
	, m_animation(m_texture, sf::Vector2i(0, 0), 0, 0.f)
{
	m_sprite.setPosition(m_position);
	m_sprite.setScale({ scale, scale });
}

void Projectile::initAnimation(AttackType attackType) {
	switch (attackType) {
	case AttackType::PlayerAttack:
		m_animation = Animation(m_texture, { 157, 47 }, 8, 0.7f);
		break;
	case AttackType::BossAttack:
		m_animation = Animation(m_texture, { 80, 80 }, 9, 0.6f);
		break;
	case AttackType::BossBombAttack:
		m_animation = Animation(m_texture, { 96, 136 }, 10, 0.6f);
		break;
	}
}

void Projectile::update(float dt)
{
	m_position.x += m_deltaX * dt; 
	if (m_deltaY != 0.f)
	{
		m_position.y += m_deltaY * dt;
	}
	m_sprite.setPosition(m_position);

	m_animation.update(dt);
	m_animation.applyToSprite(m_sprite);
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


