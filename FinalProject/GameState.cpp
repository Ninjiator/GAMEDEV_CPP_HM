#include "GameState.h"
#include "GameStateManager.h"
#include "FontManager.h"
#include "SoundManager.h"

GameState_TitleScreen::GameState_TitleScreen(GameStateManager& context, sf::RenderWindow* window)
	: GameState(context, window)
	, m_startTexture("resources/Sprites/Enviroment/Title_screen_choose_player.png")
	, m_startSprite(m_startTexture)
	, m_text(FontManager::getInstance().getDefaultFont())
{
	m_text.setCharacterSize(50); 
	m_text.setFillColor(sf::Color::Cyan);
	m_text.setString("PRESS ENTER TO START THE GAME!");
	m_text.setOrigin({ m_text.getGlobalBounds().size.x / 2, m_text.getGlobalBounds().size.y / 2 });
	m_text.setPosition({ m_window->getSize().x / 2.0f, m_window->getSize().y - m_window->getSize().y / 3.0f });
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

void GameState_TitleScreen::update(float DeltaTime)
{

}

void GameState_TitleScreen::draw()
{
	m_window->clear(sf::Color::White);

	m_window->draw(m_startSprite);
	m_window->draw(m_text);
}

GameState_Playing::GameState_Playing(GameStateManager& context, GameWorld* gameWorld, sf::RenderWindow* window)
	: GameState(context, m_window), m_GameWorld(gameWorld)
{

}

void GameState_Playing::onEnter()
{
	SoundManager::getInstance().playInGameMusic();
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

	if (m_GameWorld->getPlayer()->getHealthPoints() == 0)
	{
		m_gameStateManager.setGameState(GameStateId::GameOver);
	}
	if (m_GameWorld->getBoss()->getHealthPoints() == 0)
	{
		m_gameStateManager.setGameState(GameStateId::Victory);
	}
}

void GameState_Playing::update(float DeltaTime)
{
	m_GameWorld->update(DeltaTime);
}

void GameState_Playing::draw()
{
	m_GameWorld->draw();
}

GameState_Pause::GameState_Pause(GameStateManager& context, GameWorld* gameWorld, sf::RenderWindow* window)
	: GameState(context, window)
	, m_GameWorld(gameWorld)
	, m_pauseText(FontManager::getInstance().getDefaultFont())
{
	m_pauseText.setCharacterSize(240);
	m_pauseText.setFillColor(sf::Color::Blue);
	m_pauseText.setString("PAUSED");
	m_pauseText.setRotation(sf::degrees(45));

	m_pauseText.setPosition({ m_window->getSize().x / 2.0f - m_pauseText.getGlobalBounds().size.x / 2.0f
		, m_window->getSize().y / 2.0f - m_pauseText.getGlobalBounds().size.y / 2.0f });
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
	//Don't update GameWorld, just skipping gameWorld update makes the world freeze in Paused Mode
	constexpr unsigned int BlinkPeriod = 500;

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
	m_window->draw(m_pauseText);
}

void GameState_Pause::onEnter()
{
	m_isVisible = true;
	m_textLoopClock.restart();
	m_GameWorld->blur();

	SoundManager::getInstance().pauseInGameMusic();
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
	, m_text(FontManager::getInstance().getDefaultFont())
{
	m_victorySprite.setOrigin({ m_victorySprite.getGlobalBounds().size.x / 2, m_victorySprite.getGlobalBounds().size.y / 2 });
	m_victorySprite.setPosition({ m_window->getSize().x / 2.0f, m_window->getSize().y - m_window->getSize().y / 5.0f });
	m_victorySprite.setScale(sf::Vector2f{ 1.0f, 0.75f });

	m_text.setCharacterSize(70);
	m_text.setFillColor(sf::Color::Yellow);
	m_text.setString("RESULT'S!");
	m_text.setOrigin({ m_text.getGlobalBounds().size.x / 2, m_text.getGlobalBounds().size.y / 2 });
	m_text.setPosition({ m_window->getSize().x / 2.0f, m_window->getSize().y / 6.0f });
}

void GameState_Victory::updateState()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter))
	{
		m_gameStateManager.resetGameWorld();
	}
}

void GameState_Victory::update(float DeltaTime)
{
}

void GameState_Victory::draw()
{
	m_window->clear();
	m_window->draw(m_victorySprite);
	m_window->draw(m_text);
}

void GameState_Victory::onEnter()
{
}

void GameState_Victory::onExit()
{
}

GameState_GameOver::GameState_GameOver(GameStateManager& context, sf::RenderWindow* window)
	: GameState(context, window)
	, m_gameOverTexture("resources/Sprites/UI/winscreen_bg.png")
	, m_gameOverSprite(m_gameOverTexture)
	, m_text(FontManager::getInstance().getDefaultFont())
{
	m_gameOverSprite.setOrigin({ m_gameOverSprite.getGlobalBounds().size.x / 2, m_gameOverSprite.getGlobalBounds().size.y / 2 });
	m_gameOverSprite.setPosition({ m_window->getSize().x / 2.0f, m_window->getSize().y - m_window->getSize().y / 5.0f });
	m_gameOverSprite.setScale(sf::Vector2f{ 1.0f, 0.75f });
	
	m_text.setCharacterSize(50); 
	m_text.setFillColor(sf::Color::Cyan);
	m_text.setString("PRESS ENTER TO TRY AGAIN!");
	m_text.setOrigin({ m_text.getGlobalBounds().size.x / 2, m_text.getGlobalBounds().size.y / 2 });
	m_text.setPosition({ m_window->getSize().x / 2.0f, m_window->getSize().y / 6.0f });
}

void GameState_GameOver::updateState()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter))
	{
		m_gameStateManager.resetGameWorld();
	}
}

void GameState_GameOver::update(float DeltaTime)
{
}

void GameState_GameOver::draw()
{
	m_window->clear(sf::Color::White);
	m_window->draw(m_gameOverSprite);
	m_window->draw(m_text);
}

void GameState_GameOver::onEnter()
{
}

void GameState_GameOver::onExit()
{
}
