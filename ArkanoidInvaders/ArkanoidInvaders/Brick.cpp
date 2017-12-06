#include "Brick.h"



Brick::Brick() : m_alive(true)
{
	m_shape.setFillColor(sf::Color::Green);
	m_shape.setSize(sf::Vector2f(100, 30));
	m_shape.setOrigin(50, 15);
}


Brick::~Brick()
{
}

void Brick::setPosition(sf::Vector2f pos)
{
	m_position = pos;
	m_shape.setPosition(m_position);
}

void Brick::render(sf::RenderWindow & window)
{
	window.draw(m_shape);
}
