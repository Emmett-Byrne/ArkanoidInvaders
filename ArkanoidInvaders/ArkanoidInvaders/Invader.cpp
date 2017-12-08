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
	m_position = pos;
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
