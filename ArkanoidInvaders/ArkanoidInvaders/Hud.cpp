/// author Emmett Byrne
// date 8-12-17
#include "Hud.h"



Hud::Hud() : 
	m_timeRemaining(sf::seconds(90)),
	m_powerUps(3)
{
	if (!m_font.loadFromFile("Assets\\ariblk.ttf"))
	{
		std::cout << "problem loading arial black font" << std::endl;
	}
	m_powerText.setFont(m_font);
	m_powerText.setCharacterSize(30);
	m_powerText.setString("test");
	m_powerText.setPosition(50, 10);
	m_timeText.setFont(m_font);
	m_timeText.setCharacterSize(30);
	m_timeText.setString("test");
	m_timeText.setPosition(600, 10);
}


Hud::~Hud()
{
}

/// <summary>
/// updates the state of the hud
/// </summary>
void Hud::update(sf::Time t)
{
	m_timeRemaining -= t;
}

/// <summary>
/// decresases the amount of powerUps
/// </summary>
void Hud::decreasePower(int p)
{
	m_powerUps -= p;
}

/// <summary>
/// decreases time
/// </summary>
void Hud::decreaseTime(float t)
{
	m_timeRemaining -= sf::seconds(t);
}

/// <summary>
/// renders the hud
/// </summary>
void Hud::render(sf::RenderWindow & window)
{
	m_timeText.setString("Time: " + std::to_string(static_cast<int>(m_timeRemaining.asSeconds())));
	m_powerText.setString("boosts: " + std::to_string(m_powerUps));
	window.draw(m_timeText);
	window.draw(m_powerText);
}

/// <summary>
/// Returns the current time fo the hud
/// </summary>
sf::Time Hud::getTime()
{
	return m_timeRemaining;
}

/// <summary>
/// returns the amount of powerups left
/// </summary>
int Hud::getPower()
{
	return m_powerUps;
}

/// <summary>
/// restarts the hud to it's original values
/// </summary>
void Hud::restart()
{
	m_timeRemaining = sf::seconds(90);
	m_powerUps = 3;
}
