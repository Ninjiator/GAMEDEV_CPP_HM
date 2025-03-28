#include "SoundManager.h"

SoundManager::SoundManager()
	: m_playerJumpSoundBuffer("resources/Audio/SFX/cuphead-jump.mp3")
	, m_playerJumpSound(m_playerJumpSoundBuffer)

	, m_playerGroundSoundBuffer("resources/Audio/SFX/Player_Land_on_Ground.mp3")
	, m_playerGroundSound(m_playerGroundSoundBuffer)

	, m_playerShootSoundBuffer("resources/Audio/SFX/player_shoot.wav")
	, m_playerShootSound(m_playerShootSoundBuffer)

	, m_playerHittedSoundBuffer("resources/Audio/SFX/Player_Hitted.mp3")
	, m_playerHittedSound(m_playerHittedSoundBuffer)

	, m_playerDeathSoundBuffer("resources/Audio/SFX/Voicy_Player_death_SFX.mp3")
	, m_playerDeathSound(m_playerDeathSoundBuffer)

	, m_comentatorStartSoundBuffer("resources/Audio/SFX/a-good-day-for-a-swell-battle.mp3")
	, m_comentatorStartSound(m_comentatorStartSoundBuffer)

	, m_comentatorPauseSoundBuffer("resources/Audio/SFX/king-dice-well-be-right-back.mp3")
	, m_comentatorPauseSound(m_comentatorPauseSoundBuffer)

	, m_bossHittedSoundBuffer("resources/Audio/SFX/Boss_Hitted.mp3")
	, m_bossHittedSound(m_bossHittedSoundBuffer)

	, m_inGameMusic("resources/Audio/Music/Botanic_Panic.mp3")
	, m_titleMusic("resources/Audio/Music/cuphead-dont-deal-with-the-devil-2.mp3")
{
}

void SoundManager::playJumpSound()
{
	m_playerJumpSound.setVolume(10.f);
	m_playerJumpSound.play();
}

void SoundManager::playPlayerGroundSound()
{
	m_playerGroundSound.setVolume(10.f);
	m_playerGroundSound.play();
}

void SoundManager::playPlayerShoot()
{
	m_playerShootSound.setVolume(10.f);
	m_playerShootSound.play();
}

void SoundManager::playBossShootSound()
{
}

void SoundManager::playBossHittedSound()
{
	m_bossHittedSound.setVolume(10.f);
	m_bossHittedSound.play();
}

void SoundManager::playPlayerHittedSound()
{
	m_playerHittedSound.setVolume(10.f);
	m_playerHittedSound.play();
}

void SoundManager::playPlayerDeathSound()
{
	m_playerDeathSound.play();
}

void SoundManager::playComentatorStart()
{
	m_comentatorStartSound.play();
}

void SoundManager::playComentatorPause()
{
	m_comentatorPauseSound.play();
}

void SoundManager::playTitleMusic()
{
	m_titleMusic.play();
}

void SoundManager::stopTitleMusic()
{
	m_titleMusic.stop();
}

void SoundManager::playInGameMusic()
{
	m_inGameMusic.setVolume(5.f);
	m_inGameMusic.play();
	m_inGameMusic.setLooping(true);
	
}

void SoundManager::pauseInGameMusic()
{
	m_inGameMusic.pause();
}
