#include "PlayerHealthHUD.h"

PlayerHealthHUD::PlayerHealthHUD(sf::RenderWindow* window)
	: m_window(window)
	, m_texture("resources/Sprites/UI/hp.png")
	, m_sprite(m_texture)
{
	const int frameWidth = m_texture.getSize().x / 9;
	const int frameHeight = m_texture.getSize().y;

	sf::IntRect rect({ 0, 0 }, { frameWidth, frameHeight });
	m_sprite.setTextureRect(rect);

	m_sprite.setPosition({10.f, m_window->getSize().y - m_sprite.getLocalBounds().size.y});
}

void PlayerHealthHUD::update(int hp)
{
	const int frameWidth = m_texture.getSize().x / 9;
	const int frameHeight = m_texture.getSize().y;

	int frameIndex = std::clamp(hp, 0, 8);

	sf::IntRect rect({ frameIndex * frameWidth, 0 }, { frameWidth, frameHeight });
	m_sprite.setTextureRect(rect);
}

void PlayerHealthHUD::draw()
{
	m_window->draw(m_sprite);
}
