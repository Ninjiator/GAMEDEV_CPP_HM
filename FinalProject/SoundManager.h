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
	void playPlayerShoot();
	void playBossShoot();
	void playPlayerDeathSound();

	//Commentator
	void playComentatorStart();

	//Music
	void playInGameMusic();

private:
	SoundManager();

	sf::SoundBuffer m_playerJumpSoundBuffer;
	sf::Sound m_playerJumpSound;

	sf::SoundBuffer m_playerShootSoundBuffer;
	sf::Sound m_playerShootSound;

	sf::SoundBuffer m_playerDeathSoundBuffer;
	sf::Sound m_playerDeathSound;

	sf::SoundBuffer m_comentatorStartSoundBuffer;
	sf::Sound m_comentatorStartSound;

	sf::Music m_inGameMusic;
};