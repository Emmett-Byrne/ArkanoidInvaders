#include "Bolt.h"



Bolt::Bolt() :
	m_angle(45),
	m_speed(200)
{
}


Bolt::~Bolt()
{
}

void Bolt::update(sf::Time t)
{
	float x = cos(m_angle * acos(-1.0f) / 180.0);
	float y = sin(m_angle * acos(-1.0f) / 180.0);

	sf::Vector2f velocity(x, y);

	velocity *= m_speed * t.asSeconds();
	m_position += velocity;

	m_shape.setPosition(m_position);
}

void Bolt::setPosition(sf::Vector2f pos)
{
	m_position = pos;
	m_shape.setPosition(pos);
}

void Bolt::setTexture(sf::Texture & tex)
{
	m_shape.setTexture(tex);
	m_shape.setOrigin(m_shape.getLocalBounds().width / 2, m_shape.getLocalBounds().height / 2);
}

void Bolt::render(sf::RenderWindow & window)
{
	window.draw(m_shape);
}

void Bolt::reflectPaddle(sf::Sprite sprite)
{
	float x = cos(m_angle * acos(-1.0f) / 180.0);

	float length = sprite.getLocalBounds().width;
	float distance = m_position.x - (sprite.getPosition().x - sprite.getOrigin().x);

	float newAngle = 90 - (90 * abs(distance / length - 0.5f));

	std::cout << newAngle << std::endl;

	m_angle = newAngle + 180;

	//Could still get stuck in paddle set y to top of paddle + radius
}

sf::Sprite Bolt::getSprite()
{
	return m_shape;
}
