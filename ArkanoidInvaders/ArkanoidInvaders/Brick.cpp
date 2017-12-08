#include "Brick.h"



Brick::Brick(sf::Texture & tex) : m_alive(true)
{
	m_shape.setTexture(tex);
	m_shape.setOrigin(m_shape.getLocalBounds().width / 2, m_shape.getLocalBounds().height / 2);
}


Brick::~Brick()
{
}

void Brick::setPosition(sf::Vector2f pos)
{
	m_position = pos;
	m_shape.setPosition(pos);
}

void Brick::render(sf::RenderWindow & window)
{
	window.draw(m_shape);
}

sf::Sprite Brick::getSprite()
{
	return m_shape;
}

void Brick::kill()
{
	m_alive = false;
}

bool Brick::isAlive()
{
	return m_alive;
}
