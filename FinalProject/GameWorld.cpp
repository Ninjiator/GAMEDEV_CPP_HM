#include "GameWorld.h"

GameWorld::GameWorld(sf::RenderWindow* window)
    : m_window(window)
    , m_bossBombExplosionTexture("resources/Sprites/Boss/smoke_spritesheet_centered_spacing.png")
    , m_playerDefaultExplosion("resources/Sprites/Cuphead/effect_spritesheet_1a_6a.png")
    , m_bossFinalStageExplosion("resources/Sprites/Boss/ice_cube_medium_explosion_sheet.png")
    , m_readyTexture("resources/Sprites/UI/get_ready_sprite_sheet.png")
    , m_victoryTexture("resources/Sprites/UI/victory.png")
{
    m_background = new Background(window);
    m_playerHealthHUD = new PlayerHealthHUD(window);
    m_player = new Player(window);
    m_boss = new Boss(window);
    m_playerProjectiles = new Weapon(window, m_player);
    m_bossProjectiles = new BossWeapon(window, m_boss);
    m_physicsEngine = new PhysicsEngine(m_player, m_playerProjectiles->getProjectile(), m_boss, m_bossProjectiles->getProjectile(), this);

    m_rectangle.setFillColor(sf::Color{ 255, 255, 255, 50 });
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
    delete m_background;
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
    m_background->update(dt);
    m_player->update(dt);
    m_boss->update(dt);
    m_playerProjectiles->update(dt);
    m_bossProjectiles->update(dt);
    m_physicsEngine->update(dt);
    m_playerHealthHUD->update(m_player->getHealthPoints());

    for (auto it = m_effects.begin(); it != m_effects.end(); )
    {
        (*it)->update(dt);
        if ((*it)->isFinished())
        {
            delete* it;
            it = m_effects.erase(it);
        }
        else ++it;
    }
}

void GameWorld::draw()
{
    m_window->clear(sf::Color::White);

    m_background->draw();
    m_playerHealthHUD->draw();
    m_player->draw();
    m_boss->draw();
    m_playerProjectiles->draw();
    m_bossProjectiles->draw();
    
    for (auto* e : m_effects)
        e->draw(*m_window);

    if (m_blurred)
    {
        m_window->draw(m_rectangle);
    }
}

void GameWorld::spawnEffect(sf::Vector2f position, EffectType type)
{
    switch (type)
    {
    case EffectType::BossIceCreamEffect:
        m_effects.push_back(new Effect(m_bossBombExplosionTexture, position, { 180, 182 }, 9, 0.9f, 0.9f));
        break;
    case EffectType::PlayerHitSparkEffect:
        m_effects.push_back(new Effect(m_playerDefaultExplosion, position, {256 , 276}, 6, 0.25f, 0.5f));
        break;
    case EffectType::READY:
        m_effects.push_back(new Effect(m_readyTexture, position, { 512 , 288 }, 10, 1.0f, 1.0f));
        break; 
    case EffectType::VICTORY:
        m_effects.push_back(new Effect(m_victoryTexture, position, { 1284 , 715 }, 8, 1.0f, 0.8f));
        break;
    case EffectType::BossIceCubsEffect:
        m_effects.push_back(new Effect(m_bossFinalStageExplosion, position, { 368 , 258 }, 10, 1.0f, 0.5f));
        break;
    }
}


    
    
