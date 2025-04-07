#include "GameState.h"
#include "GameStateManager.h"
#include "FontManager.h"
#include "SoundManager.h"

GameState_TitleScreen::GameState_TitleScreen(GameStateManager& context, sf::RenderWindow* window)
	: GameState(context, window)
	, m_startTexture("resources/Sprites/UI/title_screen_background.png")
	, m_startSprite(m_startTexture)
	, m_text(FontManager::getInstance().getDefaultFont())
	, m_animatedTexture("resources/Sprites/UI/cuphead_title_aligned_spritesheet.png")
	, m_animatedSprite(m_animatedTexture)
	, m_animation(m_animatedTexture, {1093, 612}, 10, 1.5f)
{
	m_animatedSprite.setOrigin({ m_animatedSprite.getLocalBounds().size.x / 2.f,  m_animatedSprite.getLocalBounds().size.y / 2.f });
	m_animatedSprite.setPosition({ m_window->getSize().x / 2.f, m_window->getSize().y / 2.f + m_animatedSprite.getLocalBounds().size.y / 10.f});
	m_animation.setLoopFalse();

	m_text.setCharacterSize(30); 
	m_text.sf::Text::Bold;
	m_text.setFillColor(sf::Color::Yellow);
	m_text.setString("PRESS ENTER TO START THE GAME!");
	m_text.setOrigin({ m_text.getGlobalBounds().size.x / 2, m_text.getGlobalBounds().size.y / 2 });
	m_text.setPosition({ m_window->getSize().x / 2.0f, m_window->getSize().y - m_window->getSize().y / 5.0f });
}

void GameState_TitleScreen::onEnter()
{
	SoundManager::getInstance().playTitleMusic();
}

void GameState_TitleScreen::onExit()
{
	SoundManager::getInstance().stopTitleMusic();
	SoundManager::getInstance().playComentatorStart();
}

void GameState_TitleScreen::updateState()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter))
	{
		m_gameStateManager.setGameState(GameStateId::Playing);
	}
}

void GameState_TitleScreen::update(float dt)
{
	m_animation.update(dt);
	m_animation.applyToSprite(m_animatedSprite);
}

void GameState_TitleScreen::draw()
{
	m_window->clear(sf::Color::White);
	m_window->draw(m_startSprite);
	m_window->draw(m_animatedSprite);
	m_window->draw(m_text);
}

GameState_Playing::GameState_Playing(GameStateManager& context, GameWorld* gameWorld, sf::RenderWindow* window)
	: GameState(context, m_window), m_GameWorld(gameWorld) , m_window(window)
{
}

void GameState_Playing::onEnter()
{
	SoundManager::getInstance().playInGameMusic();
	if (m_playEffectOnce == true)
	{
		m_GameWorld->spawnEffect({ m_window->getSize().x / 2.f, m_window->getSize().y / 2.f - m_window->getSize().y / 3.f }, EffectType::READY);
		m_playEffectOnce = false;
	}
}

void GameState_Playing::onExit()
{
	SoundManager::getInstance().pauseInGameMusic();
}

void GameState_Playing::updateState()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
	{
		if (!m_pressedLastFrame)
		{
			m_pressedLastFrame = true;
			m_gameStateManager.setGameState(GameStateId::Pause);
		}
	}
	else
	{
		m_pressedLastFrame = false;
	}

	if (m_GameWorld->getPlayer()->isDead())
	{
		if (!m_playerJustDied)
		{
			SoundManager::getInstance().playPlayerDeathSound();
			m_playerJustDied = true;
			m_victoryDelayClock.restart();
		}
		else if (m_victoryDelayClock.getElapsedTime().asSeconds() > 2.1f)
		{
			m_gameStateManager.setGameState(GameStateId::GameOver);
		}
	}
	if (!m_GameWorld->getBoss()->isEntityAlive())
	{
		if (!m_bossJustDied)
		{
			m_bossJustDied = true;
			m_gameOverDelayClock.restart();
		}
		else if (m_gameOverDelayClock.getElapsedTime().asSeconds() > 3.0f)
		{
			m_gameStateManager.setGameState(GameStateId::Victory);
		}
	}
}

void GameState_Playing::update(float dt)
{
	m_GameWorld->update(dt);
}

void GameState_Playing::draw()
{
	m_GameWorld->draw();
}

GameState_Pause::GameState_Pause(GameStateManager& context, GameWorld* gameWorld, sf::RenderWindow* window)
	: GameState(context, window)
	, m_GameWorld(gameWorld)
	, m_pauseText(FontManager::getInstance().getDefaultFont())
	, m_pauseTexture("resources/Sprites/UI/pause_menu_v2.png")
	, m_pauseSprite(m_pauseTexture)
{

	m_pauseSprite.setOrigin({m_pauseSprite.getLocalBounds().size.x / 2.f, m_pauseSprite.getLocalBounds().size.y / 2.f});
	m_pauseSprite.setScale({ 0.5f,0.5f });
	m_pauseSprite.setPosition({ m_window->getSize().x / 2.f, m_window->getSize().y / 2.f });
	
	m_pauseText.setCharacterSize(45);
	m_pauseText.setFillColor(sf::Color::Black);
	m_pauseText.setString("PAUSED");
	m_pauseText.setOrigin({ m_pauseText.getLocalBounds().size.x / 2.f, m_pauseText.getLocalBounds().size.y / 2.f });

	m_pauseText.setPosition({ m_window->getSize().x / 2.f, m_window->getSize().y / 2.f - m_pauseText.getLocalBounds().size.y / 2.f });
}

void GameState_Pause::updateState()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
	{
		if (!m_pressedLastFrame)
		{
			m_pressedLastFrame = true;
			m_gameStateManager.setGameState(GameStateId::Playing);
		}
	}
	else
	{
		m_pressedLastFrame = false;
	}
}

void GameState_Pause::update(float DeltaTime)
{
	constexpr unsigned int BlinkPeriod = 1200;
	bool needUpdate = false;

	if (m_textLoopClock.getElapsedTime().asMilliseconds() > BlinkPeriod)
	{
		m_textLoopClock.restart();
		m_isVisible = !m_isVisible;
		needUpdate = true;
	}

	if (needUpdate)
	{
		sf::Color color = m_pauseText.getFillColor();
		color.a = (m_isVisible) ? 255 : 0;
		m_pauseText.setFillColor(color);
	}
}

void GameState_Pause::draw()
{
	m_GameWorld->draw();
	m_window->draw(m_pauseSprite);
	m_window->draw(m_pauseText);

}

void GameState_Pause::onEnter()
{
	m_isVisible = true;
	m_textLoopClock.restart();
	m_GameWorld->blur();

	SoundManager::getInstance().playComentatorPause();
}

void GameState_Pause::onExit()
{
	m_GameWorld->unblur();
	SoundManager::getInstance().playInGameMusic();
}

GameState_Victory::GameState_Victory(GameStateManager& context, sf::RenderWindow* window)
	: GameState(context, window)
	, m_victoryTexture("resources/Sprites/UI/winscreen_bg.png")
	, m_victorySprite(m_victoryTexture)
	, m_textTexture("resources/Sprites/UI/winscreen_results_title_a_0001.png")
	, m_textSprite(m_textTexture)
	, m_boardTexture("resources/Sprites/UI/winscreen_board.png")
	, m_boardSprite(m_boardTexture)
	, m_playerTexture("resources/Sprites/UI/cuphead_winscreen_spritesheet.png")
	, m_playerSprite(m_playerTexture)
	, m_playerAnimation(m_playerTexture, {301,433}, 7, 0.7f)
{

	m_victorySprite.setOrigin({ m_victorySprite.getGlobalBounds().size.x / 2, m_victorySprite.getGlobalBounds().size.y / 2 });
	m_victorySprite.setPosition({ m_window->getSize().x / 2.0f, m_window->getSize().y - m_window->getSize().y / 5.0f });
	m_victorySprite.setScale(sf::Vector2f{ 1.0f, 0.75f });

	m_boardSprite.setOrigin({ m_boardSprite.getGlobalBounds().size.x / 2, m_boardSprite.getGlobalBounds().size.y / 2 });
	m_boardSprite.setPosition({ m_window->getSize().x - m_window->getSize().x / 3.f, m_window->getSize().y / 2.0f + m_window->getSize().y / 10.f});

	m_playerSprite.setOrigin({ m_playerSprite.getGlobalBounds().size.x / 2, m_playerSprite.getGlobalBounds().size.y / 2 });
	m_playerSprite.setPosition({ m_window->getSize().x / 3.f, m_window->getSize().y / 2.0f + m_window->getSize().y / 10.f });

	m_textSprite.setOrigin({ m_textSprite.getGlobalBounds().size.x / 2, m_textSprite.getGlobalBounds().size.y / 2 });
	m_textSprite.setPosition({ m_window->getSize().x / 2.0f, m_window->getSize().y / 7.0f });
}

void GameState_Victory::updateState()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::R))
	{
		m_gameStateManager.resetGameWorld();
	}
}

void GameState_Victory::update(float dt)
{
	m_playerAnimation.update(dt);
	m_playerAnimation.applyToSprite(m_playerSprite);
}

void GameState_Victory::draw()
{
	m_window->clear();
	m_window->draw(m_victorySprite);
	m_window->draw(m_playerSprite);
	m_window->draw(m_boardSprite);
	m_window->draw(m_textSprite);
}

void GameState_Victory::onEnter()
{
	SoundManager::getInstance().playVictoryMusic();
}

void GameState_Victory::onExit()
{
	SoundManager::getInstance().stopVictoryMusic();
}

GameState_GameOver::GameState_GameOver(GameStateManager& context, sf::RenderWindow* window, GameWorld* gameWorld)
	: GameState(context, window)
	, m_gameWorld(gameWorld)
	, m_gameOverTexture("resources/Sprites/UI/GameOver_final.png")
	, m_gameOverSprite(m_gameOverTexture)
	, m_text(FontManager::getInstance().getDefaultFont())
{
	m_gameOverSprite.setOrigin({ m_gameOverSprite.getGlobalBounds().size.x / 2, m_gameOverSprite.getGlobalBounds().size.y / 2 });
	m_gameOverSprite.setPosition({ m_window->getSize().x / 2.0f,  m_window->getSize().y / 2.0f });
	m_gameOverSprite.setScale(sf::Vector2f{ 0.5f, 0.5f });
	
	m_text.setCharacterSize(20); 
	m_text.setFillColor(sf::Color::Black);
	m_text.setString("PRESS R FOR RESTART");
	m_text.setOrigin({ m_text.getGlobalBounds().size.x / 2, m_text.getGlobalBounds().size.y / 2 });
	m_text.setPosition({ m_window->getSize().x / 2.0f, m_window->getSize().y / 2.0f + m_text.getGlobalBounds().size.y * 3.f });
}

void GameState_GameOver::updateState()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::R))
	{
		m_gameStateManager.resetGameWorld();
	}
}

void GameState_GameOver::update(float DeltaTime)
{

}

void GameState_GameOver::draw()
{
	m_gameWorld->draw();
	m_window->draw(m_gameOverSprite);
	m_window->draw(m_text);
}

void GameState_GameOver::onEnter()
{
	
	SoundManager::getInstance().playGameOverSound();
}

void GameState_GameOver::onExit()
{

}
