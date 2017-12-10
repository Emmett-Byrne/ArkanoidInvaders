/// author Emmett Byrne
// date 25-11-17
#include "Invader.h"



Invader::Invader(sf::Texture & tex) : m_alive(true)
{
	m_shape.setTexture(tex);
	m_shape.setOrigin(m_shape.getLocalBounds().width / 2, m_shape.getLocalBounds().height / 2);
}


Invader::~Invader()
{
}

/// <summary>
/// sets teh invaders position
/// </summary>
void Invader::setPosition(sf::Vector2f pos)
{
	m_shape.setPosition(pos);
}

/// <summary>
/// renders the invader
/// </summary>
void Invader::render(sf::RenderWindow & window)
{
	window.draw(m_shape);
}

/// <summary>
/// returns the invaders sprite
/// </summary>
sf::Sprite Invader::getSprite()
{
	return m_shape;
}

/// <summary>
/// returns if the invader is alive
/// </summary>
bool Invader::isAlive()
{
	return m_alive;
}

/// <summary>
/// Kills the invader
/// </summary>
void Invader::kill()
{
	m_alive = false;
}

/// <summary>
/// moves the invader
/// </summary>
void Invader::move(sf::Vector2f move)
{
	m_shape.move(move);
}
