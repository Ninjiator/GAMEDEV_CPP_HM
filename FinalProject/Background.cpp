#include "Background.h"

Background::Background(sf::RenderWindow* window) : m_window(window), m_texture(), m_sprite(m_texture)
{
	m_texture.setRepeated(true);
	m_sprite.setTextureRect(sf::IntRect({ 0, 0 }, { static_cast<int>(m_window->getSize().x), static_cast<int>(m_window->getSize().y) }));
}
//"resources/background_(test).png"
void Background::draw()
{
	m_window->draw(m_sprite);
}