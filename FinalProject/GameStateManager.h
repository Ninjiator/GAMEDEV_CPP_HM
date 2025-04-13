#pragma once
#include <cstddef>
#include <SFML/Graphics.hpp>

class GameState;
class GameWorld;

enum  class GameStateId
{
	TitleScreen,
	Playing,
	Pause,
	GameOver,
	Victory,
	Count
};

class GameStateManager
{
public:
	GameStateManager(GameWorld* gameWorld, GameStateId initialGameStateId, sf::RenderWindow* window);
	~GameStateManager();

	void setGameState(GameStateId newGameState);
	GameState* getCurrentGameState() const { return m_currentGameState; }
	void resetGameWorld();

private:
	GameWorld* m_gameWorld = nullptr;
	sf::RenderWindow* m_window = nullptr;
	GameState* m_currentGameState = nullptr;
	GameState* m_gameStates[static_cast<std::size_t>(GameStateId::Count)];
};