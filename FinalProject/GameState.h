#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "GameWorld.h"

class GameStateManager;

class GameState
{
public:
	GameState(GameStateManager& context, sf::RenderWindow* window) : m_gameStateManager(context), m_window(window) {}

	virtual void updateState() = 0;
	virtual void update(float DeltaTime) = 0;
	virtual void draw() = 0;

	virtual void onEnter() {} 
	virtual void onExit() {} 

protected:
	sf::RenderWindow* m_window;
	GameStateManager& m_gameStateManager;
};

class GameState_TitleScreen : public GameState
{
public:
	GameState_TitleScreen(GameStateManager& context, sf::RenderWindow* window);

	void onEnter() override;
	void onExit() override;

	void updateState() override;
	void update(float DeltaTime) override;
	void draw() override;

private:
	sf::Text m_text;

	sf::Texture m_startTexture;
	sf::Sprite m_startSprite;

	Animation m_animation;
	sf::Texture m_animatedTexture;
	sf::Sprite m_animatedSprite;
};

class GameState_Playing : public GameState
{
public:
	GameState_Playing(GameStateManager& context, GameWorld* gameWorld, sf::RenderWindow* window);

	void onEnter() override;
	void onExit() override;

	void updateState() override;
	void update(float DeltaTime) override;
	void draw() override;

private:
	sf::RenderWindow* m_window;
	GameWorld* m_GameWorld;
	bool m_pressedLastFrame = true;
	bool m_playEffectOnce = true;
	sf::Clock m_gameOverDelayClock;
	sf::Clock m_victoryDelayClock;
	bool m_bossJustDied = false;
	bool m_playerJustDied = false;
};

class GameState_Pause : public GameState
{
public:
	GameState_Pause(GameStateManager& context, GameWorld* gameWorld, sf::RenderWindow* window);

	void updateState() override;
	void update(float DeltaTime) override;
	void draw() override;
	
	void onEnter() override;
	void onExit() override;

private:
	GameWorld* m_gameWorld;

	bool m_pressedLastFrame = true;

	sf::Texture m_pauseTexture;
	sf::Sprite m_pauseSprite;

	sf::Text m_pauseText;
	sf::Clock m_textLoopClock;
	bool m_isVisible = true;
};

class GameState_Victory : public GameState
{
public:
	GameState_Victory(GameStateManager& context, sf::RenderWindow* window);

	virtual void updateState() override;
	virtual void update(float DeltaTime) override;
	virtual void draw() override;

	virtual void onEnter();
	virtual void onExit();
private:
	sf::Texture m_victoryTexture;
	sf::Sprite m_victorySprite;

	sf::Texture m_boardTexture;
	sf::Sprite m_boardSprite;

	sf::Texture m_playerTexture;
	sf::Sprite m_playerSprite;
	Animation m_playerAnimation;

	sf::Texture m_textTexture;
	sf::Sprite m_textSprite;
};

class GameState_GameOver : public GameState
{
public:
	GameState_GameOver(GameStateManager& context, sf::RenderWindow* window, GameWorld* gameWorld);

	virtual void updateState() override;
	virtual void update(float DeltaTime) override;
	virtual void draw() override;

	virtual void onEnter();
	virtual void onExit();
private:
	GameWorld* m_gameWorld;
	sf::Texture m_gameOverTexture;
	sf::Sprite m_gameOverSprite;
	sf::Text m_text;
};

