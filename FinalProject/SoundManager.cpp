#include "SoundManager.h"

SoundManager::SoundManager()
	: m_playerJumpSoundBuffer("resources/Audio/SFX/cuphead-jump.mp3")
	, m_playerJumpSound(m_playerJumpSoundBuffer)

	, m_playerShootSoundBuffer("resources/Audio/SFX/player_shoot.wav")
	, m_playerShootSound(m_playerShootSoundBuffer)

	, m_playerDeathSoundBuffer("resources/Audio/SFX/Voicy_Player_death_SFX.mp3")
	, m_playerDeathSound(m_playerDeathSoundBuffer)

	, m_comentatorStartSoundBuffer("resources/Audio/SFX/a-good-day-for-a-swell-battle.mp3")
	, m_comentatorStartSound(m_comentatorStartSoundBuffer)

	, m_inGameMusic("resources/Audio/Music/Botanic_Panic.mp3")
{
}

void SoundManager::playJumpSound()
{
	m_playerJumpSound.setVolume(45.f);
	m_playerJumpSound.play();
}

void SoundManager::playPlayerShoot()
{
	m_playerShootSound.setVolume(50.f);
	m_playerShootSound.play();
}

void SoundManager::playBossShoot()
{
}

void SoundManager::playPlayerDeathSound()
{
	m_playerDeathSound.play();
}

void SoundManager::playComentatorStart()
{
	m_comentatorStartSound.play();
}

void SoundManager::playInGameMusic()
{
	m_inGameMusic.play();
	m_inGameMusic.setLooping(true);
	m_inGameMusic.setVolume(43.f);
}
