#pragma once
#include <SFML/Graphics.hpp>

class FontManager
{
public:
	const sf::Font& getDefaultFont() const { return m_defaultFont; }
	static FontManager& getInstance()
	{
		static FontManager instance;
		return instance;
	}

private:
	FontManager() : m_defaultFont("resources/Fonts/cuphead_font_by_ripoof_dept3h3.ttf") {}
	sf::Font m_defaultFont;
};