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

	//Commentator
	void playComentatorStart();

	//Boss
	void playBossShootSound();
	void playBossHittedSound();

	//Music
	void playTitleMusic();
	void stopTitleMusic();

	void playInGameMusic();

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
	//Boss
	sf::SoundBuffer m_bossHittedSoundBuffer;
	sf::Sound m_bossHittedSound;

	//InGame
	sf::Music m_inGameMusic;
	sf::Music m_titleMusic;
};