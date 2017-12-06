#include "Bolt.h"



Bolt::Bolt()
{
}


Bolt::~Bolt()
{
}

void Bolt::setPosition(sf::Vector2f pos)
{
	m_position = pos;
}

void Bolt::render(sf::RenderWindow & window)
{
	window.draw(m_shape);
}
