#pragma once
#include <SFML/Audio.hpp>

class SoundManager
{
public:

	static SoundManager& getInstance()
	{
		static SoundManager instance;
		return instance;
	}

	//SFX Player
	void playJumpSound();
	void playPlayerGroundSound();
	void playPlayerShoot();
	
	void playPlayerHittedSound();
	void playPlayerDeathSound();
	
	void playGameOverSound();
	//Commentator
	void playComentatorStart();
	void playComentatorPause();

	//Boss
	void playBossShootSound();
	void playBossHittedSound();

	//Music
	void playTitleMusic();
	void stopTitleMusic();

	void playInGameMusic();
	void pauseInGameMusic();

	void playVictoryMusic();
	void stopVictoryMusic();



private:
	SoundManager();
	//Player
	sf::SoundBuffer m_playerJumpSoundBuffer;
	sf::Sound m_playerJumpSound;

	sf::SoundBuffer m_playerGroundSoundBuffer;
	sf::Sound m_playerGroundSound;

	sf::SoundBuffer m_playerShootSoundBuffer;
	sf::Sound m_playerShootSound;

	sf::SoundBuffer m_playerHittedSoundBuffer;
	sf::Sound m_playerHittedSound;

	sf::SoundBuffer m_playerDeathSoundBuffer;
	sf::Sound m_playerDeathSound;
	//Comentator
	sf::SoundBuffer m_comentatorStartSoundBuffer;
	sf::Sound m_comentatorStartSound;

	sf::SoundBuffer m_comentatorPauseSoundBuffer;
	sf::Sound m_comentatorPauseSound;
	//Boss
	sf::SoundBuffer m_bossShotSoundBuffer;
	sf::Sound m_bossShotSound;

	sf::SoundBuffer m_bossHittedSoundBuffer;
	sf::Sound m_bossHittedSound;

	//InGameMusic
	sf::Music m_inGameMusic;
	sf::Music m_titleMusic;
	sf::Music m_victoryMusic;

	sf::SoundBuffer m_gameOverSoundBuffer;
	sf::Sound m_gameOverSound;
	
};