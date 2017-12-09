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

void Invader::setPosition(sf::Vector2f pos)
{
	m_shape.setPosition(pos);
}

void Invader::render(sf::RenderWindow & window)
{
	window.draw(m_shape);
}

sf::Sprite Invader::getSprite()
{
	return m_shape;
}

bool Invader::isAlive()
{
	return m_alive;
}

void Invader::kill()
{
	m_alive = false;
}

void Invader::move(sf::Vector2f move)
{
	m_shape.move(move);
}
