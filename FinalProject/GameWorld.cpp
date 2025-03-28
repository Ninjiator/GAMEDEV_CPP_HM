#include "GameWorld.h"

GameWorld::GameWorld(sf::RenderWindow* window)
    : m_window(window)
    , m_player(window)
    , m_boss(window)
    , m_background(window)
    , m_playerProjectiles(window, &m_player)
    , m_bossProjectiles(window, &m_boss)
    , m_physicsEngine(&m_player, m_playerProjectiles.getProjectile(), &m_boss, m_bossProjectiles.getProjectile())
{
    m_rectangle.setFillColor(sf::Color{ 255, 255, 255, 150 });
    m_rectangle.setSize({ static_cast<float>(m_window->getSize().x), static_cast<float>(m_window->getSize().y) });
}

GameWorld::~GameWorld()
{
    //TODO: Delete memory used
}

void GameWorld::blur()
{
    m_blurred = true;
}

void GameWorld::unblur()
{
    m_blurred = false;
}

void GameWorld::update(float dt)
{
    m_player.update(dt);
    m_boss.update(dt);
    m_playerProjectiles.update(dt);
    m_bossProjectiles.update(dt);
    m_physicsEngine.update(dt);
}

void GameWorld::draw()
{
    m_window->clear(sf::Color{ 0, 255, 0 });

    m_background.draw();
    m_player.draw();
    m_boss.draw();
    m_playerProjectiles.draw();
    m_bossProjectiles.draw();

    if (m_blurred)
    {
        m_window->draw(m_rectangle);
    }
}