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
	GameWorld* m_GameWorld;

	bool m_pressedLastFrame = true;
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
	GameWorld* m_GameWorld;

	bool m_pressedLastFrame = true;

	/*sf::Texture m_pauseTexture;
	sf::Sprite m_pauseSprite;*/

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
	sf::Text m_text;
};

class GameState_GameOver : public GameState
{
public:
	GameState_GameOver(GameStateManager& context, sf::RenderWindow* window);

	virtual void updateState() override;
	virtual void update(float DeltaTime) override;
	virtual void draw() override;

	virtual void onEnter();
	virtual void onExit();
private:

	sf::Texture m_gameOverTexture;
	sf::Sprite m_gameOverSprite;
	sf::Text m_text;
};

