#pragma once
#include <SFML/Graphics.hpp>
#include "Animation.h"

class Background
{
public:
	Background(sf::RenderWindow* window);

	void update(float dt);
	void draw();
	

private:

	/*sf::Sprite m_sprite;
	sf::Texture m_texture;*/

	sf::Sprite m_starSprite;
	sf::Texture m_starTexture;

	sf::Sprite m_northernLightSprite_1;
	sf::Texture m_northernLightTexture_1;
	Animation m_northernLightAnimation_1;

	sf::Sprite m_castleBackSprite;
	sf::Texture m_castleBackTexture;

	sf::Sprite m_northernLightSprite_2;
	sf::Texture m_northernLightTexture_2;
	Animation m_northernLightAnimation_2;

	sf::Sprite m_audienceBackSprite;
	sf::Texture m_audienceBackTexture;
	Animation m_audienceBackAnimation;

	sf::Sprite m_castleFrontSprite;
	sf::Texture m_castleFrontTexture;

	sf::Sprite m_audienceFrontSprite;
	sf::Texture m_audienceFrontTexture;
	Animation m_audienceFrontAnimation;

	sf::RenderWindow* m_window = nullptr;
};