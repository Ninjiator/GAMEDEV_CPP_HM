#include "Background.h"

Background::Background(sf::RenderWindow* window) 
	: m_window(window)
	, m_starTexture("resources/Sprites/Background/sky.png")
	, m_starSprite(m_starTexture)

	, m_northernLightTexture_1("resources/Sprites/Background/sky_effect_f_spritesheet_horizontal.png")
	, m_northernLightSprite_1(m_northernLightTexture_1)
	, m_northernLightAnimation_1(m_northernLightTexture_1,{326, 512}, 10, 1.1f)
	, m_northernLightTexture_2("resources/Sprites/Background/sky_effect_spritesheet_horizontal.png")
	, m_northernLightSprite_2(m_northernLightTexture_2)
	, m_northernLightAnimation_2(m_northernLightTexture_2, { 686, 510 }, 10, 0.9f)
	
	, m_castleBackTexture("resources/Sprites/Background/castle_4.png")
	, m_castleBackSprite(m_castleBackTexture)
	
	, m_audienceBackTexture("resources/Sprites/Background/cult_members_spritesheet_back.png")
	, m_audienceBackSprite(m_audienceBackTexture)
	, m_audienceBackAnimation(m_audienceBackTexture, {1497, 256}, 5, 0.9f)
	, m_audienceFrontTexture("resources/Sprites/Background/cult_members_spritesheet_front.png")
	, m_audienceFrontSprite(m_audienceFrontTexture)
	, m_audienceFrontAnimation(m_audienceFrontTexture, {1507, 252}, 5, 0.9f)

	, m_castleFrontTexture("resources/Sprites/Background/min-main_front.png")
	, m_castleFrontSprite(m_castleFrontTexture)
{
	//Setup background lair's:
	//sky background
	m_starTexture.setRepeated(true);
	m_starSprite.setTextureRect(sf::IntRect({ 0, 0 }, { static_cast<int>(m_window->getSize().x), static_cast<int>(m_window->getSize().y) }));
	//northernLight's
	m_northernLightSprite_1.setOrigin({ m_northernLightSprite_1.getGlobalBounds().size.x / 2.f, m_northernLightSprite_1.getGlobalBounds().size.y / 2.f });
	m_northernLightSprite_1.setScale({ 0.75f, 0.75f });
	m_northernLightSprite_1.setPosition({ m_window->getSize().x / 2.f + m_window->getSize().x / 10.f, m_window->getSize().y / 2.f - m_window->getSize().y / 4.0f });

	m_northernLightSprite_2.setOrigin({ m_northernLightSprite_2.getGlobalBounds().size.x / 2.f, m_northernLightSprite_2.getGlobalBounds().size.y / 2.f });
	m_northernLightSprite_2.setScale({ 0.75f, 0.75f });
	m_northernLightSprite_2.setPosition({ m_window->getSize().x / 2.f - m_window->getSize().x / 3.f, m_window->getSize().y / 2.f - m_window->getSize().y / 6.0f });
	//castle
	m_castleBackTexture.setRepeated(true);
	m_castleBackSprite.setTextureRect(sf::IntRect({ 0, 0 }, { static_cast<int>(m_window->getSize().x), static_cast<int>(m_window->getSize().y) }));
	sf::FloatRect castleBackSize = m_castleBackSprite.getGlobalBounds();
	sf::Vector2u windowSize = m_window->getSize();
	float scaleX = static_cast<float>(windowSize.x) / castleBackSize.size.x;
	float scaleY = static_cast<float>(windowSize.y) / castleBackSize.size.y;
	m_castleBackSprite.setScale({ scaleX, scaleY });

	m_castleFrontTexture.setRepeated(true);
	m_castleFrontSprite.setTextureRect(sf::IntRect({ 0, 0 }, { static_cast<int>(m_window->getSize().x), static_cast<int>(m_window->getSize().y) }));
	sf::FloatRect castleFrontSize = m_castleFrontSprite.getGlobalBounds();
	float scaleX_1 = static_cast<float>(windowSize.x) / castleFrontSize.size.x;
	float scaleY_1 = static_cast<float>(windowSize.y) / castleFrontSize.size.y;
	m_castleFrontSprite.setScale({ scaleX_1, scaleY_1 });

	
	//audience
	m_audienceBackSprite.setOrigin({ m_audienceBackSprite.getGlobalBounds().size.x / 2.f, m_audienceBackSprite.getGlobalBounds().size.y / 2.f });
	m_audienceBackSprite.setPosition({ m_window->getSize().x / 2.f, m_window->getSize().y / 2.f - m_window->getSize().y / 8.3f });

	m_audienceFrontSprite.setOrigin({ m_audienceBackSprite.getGlobalBounds().size.x / 2.f, m_audienceBackSprite.getGlobalBounds().size.y / 2.f });
	m_audienceFrontSprite.setPosition({ m_window->getSize().x / 2.f, m_window->getSize().y / 2.f - m_window->getSize().y / 17.0f });
	
}

void Background::update(float dt)
{
	m_northernLightAnimation_1.update(dt);
	m_northernLightAnimation_1.applyToSprite(m_northernLightSprite_1);

	m_northernLightAnimation_2.update(dt);
	m_northernLightAnimation_2.applyToSprite(m_northernLightSprite_2);

	m_audienceBackAnimation.update(dt);
	m_audienceBackAnimation.applyToSprite(m_audienceBackSprite);

	m_audienceFrontAnimation.update(dt);
	m_audienceFrontAnimation.applyToSprite(m_audienceFrontSprite);
}

void Background::draw()
{
	m_window->draw(m_starSprite);
	m_window->draw(m_northernLightSprite_1);
	m_window->draw(m_northernLightSprite_2);
	m_window->draw(m_castleBackSprite);
	m_window->draw(m_audienceBackSprite);
	m_window->draw(m_audienceFrontSprite);
	m_window->draw(m_castleFrontSprite);
}