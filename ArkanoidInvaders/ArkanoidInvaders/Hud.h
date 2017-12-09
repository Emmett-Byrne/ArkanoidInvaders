/// author Emmett Byrne
// date 8-12-17
#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>
class Hud
{
public:
	Hud();
	~Hud();

	void update(sf::Time t);
	void decreasePower(int p);
	void decreaseTime(float t);
	void render(sf::RenderWindow & window);
	sf::Time getTime();
	int getPower();
	void restart();

private:
	sf::Time m_timeRemaining;
	int m_powerUps;

	sf::Font m_font;
	sf::Text m_timeText;
	sf::Text m_powerText;
};

