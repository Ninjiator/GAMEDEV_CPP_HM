#include "Boss.h"
#include <SFML/Graphics.hpp>


Boss::Boss(sf::RenderWindow* window)
	: m_window(window)
	, m_texture("resources/boss_dead.png")
	, m_sprite(m_texture)
{
	m_sprite.setScale({ 0.3f, 0.3f });
	
	//m_sprite.setPosition({ 1200.f, 450.f });
}

void Boss::update(float dt)
{
	
}

void Boss::draw()
{
	m_window->draw(m_sprite);
}
