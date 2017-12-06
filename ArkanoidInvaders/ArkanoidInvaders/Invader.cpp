#include "Invader.h"



Invader::Invader()
{
}


Invader::~Invader()
{
}

void Invader::setPosition(sf::Vector2f pos)
{
	m_position = pos;
}

void Invader::render(sf::RenderWindow & window)
{
	window.draw(m_shape);
}
