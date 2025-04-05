#include "GameWorld.h"

GameWorld::GameWorld(sf::RenderWindow* window)
    : m_window(window)
{
    
    m_background = new Background(window);
    m_playerHealthHUD = new PlayerHealthHUD(window);
    m_player = new Player(window);
    m_boss = new Boss(window);
    m_playerProjectiles = new Weapon(window, m_player);
    m_bossProjectiles = new BossWeapon(window, m_boss);
    m_physicsEngine = new PhysicsEngine(m_player, m_playerProjectiles->getProjectile(), m_boss, m_bossProjectiles->getProjectile());

    m_rectangle.setFillColor(sf::Color{ 255, 255, 255, 150 });
    m_rectangle.setSize({ static_cast<float>(m_window->getSize().x), static_cast<float>(m_window->getSize().y) });
}

GameWorld::~GameWorld()
{
    delete m_playerHealthHUD;
    delete m_player;
    delete m_boss;
    delete m_playerProjectiles;
    delete m_bossProjectiles;
    delete m_physicsEngine;
}

void GameWorld::blur()
{
    m_blurred = true;
}

void GameWorld::unblur()
{
    m_blurred = false;
}

//void GameWorld::init()
//{
//    m_cupHeadSimpleShotTexture.loadFromFile("resources/fireball.png");
//    if (!m_BossSimpleShotTexture.loadFromFile("resources/Sprites/Boss/moon_spritesheet.png")) {
//        std::cerr << "FAILED to load moon_spritesheet.png" << std::endl;
//    }
//    m_IceCreamBombTexture.loadFromFile("resources/Sprites/Boss/icecream_cone_spritesheet.png");
//    initProjectileConfigs(m_cupHeadSimpleShotTexture, m_BossSimpleShotTexture, m_IceCreamBombTexture);
//}

void GameWorld::update(float dt)
{
    m_player->update(dt);
    m_boss->update(dt);
    m_playerProjectiles->update(dt);
    m_bossProjectiles->update(dt);
    m_physicsEngine->update(dt);
    m_playerHealthHUD->update(m_player->getHealthPoints());
}

void GameWorld::draw()
{
    m_window->clear(sf::Color{ 0, 255, 0 });

    m_background->draw();
    m_playerHealthHUD->draw();
    m_player->draw();
    m_boss->draw();
    m_playerProjectiles->draw();
    m_bossProjectiles->draw();
    

    if (m_blurred)
    {
        m_window->draw(m_rectangle);
    }
}