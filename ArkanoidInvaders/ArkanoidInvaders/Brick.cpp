/// author Emmett Byrne
// date 25-11-17
#include "Brick.h"



Brick::Brick(sf::Texture & tex) : m_alive(true)
{
	m_shape.setTexture(tex);
	m_shape.setOrigin(m_shape.getLocalBounds().width / 2, m_shape.getLocalBounds().height / 2);
}


Brick::~Brick()
{
}

/// <summary>
/// sets the position of the brick
/// </summary>
void Brick::setPosition(sf::Vector2f pos)
{
	m_position = pos;
	m_shape.setPosition(pos);
}

/// <summary>
/// renders the brick
/// </summary>
void Brick::render(sf::RenderWindow & window)
{
	window.draw(m_shape);
}

/// <summary>
/// returns the sprite for the brick
/// </summary>
sf::Sprite Brick::getSprite()
{
	return m_shape;
}

/// <summary>
/// kills the brick
/// </summary>
void Brick::kill()
{
	m_alive = false;
}

/// <summary>
/// returns wheather the brick is alive
/// </summary>
bool Brick::isAlive()
{
	return m_alive;
}
