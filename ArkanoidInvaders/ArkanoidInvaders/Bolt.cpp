/// author Emmett Byrne
// date 25-11-17
#include "Bolt.h"



Bolt::Bolt() :
	m_angle(45),
	m_speed(200),
	m_boosting(false)
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

	if (m_boosting)
	{
		velocity *= 2.5f;
		m_boostTime -= t;

		if (m_boostTime.asSeconds() < 0)
		{
			m_boosting = false;
		}
	}

	m_position += velocity;

	m_shape.setPosition(m_position);
	wallCol();
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

	if (distance <= sprite.getOrigin().x)
	{
		m_angle = newAngle + 180;
	}
	if (distance > sprite.getOrigin().x)
	{
		m_angle = 360 - newAngle;
	}



	//Could still get stuck in paddle set y to top of paddle + radius
}

void Bolt::wallCol()
{
	if (m_position.y - m_shape.getOrigin().y < 0)
	{
		reflectX();
	}
	if (m_position.x - m_shape.getOrigin().x < 0)
	{
		reflectY();
	}
	if (m_position.x + m_shape.getOrigin().x > 800)
	{
		reflectY();
	}
}

void Bolt::reflectY()
{
	m_angle = 180 - m_angle;
	if (m_angle < 0)
	{
		m_angle += 360;
	}
}

void Bolt::reflectX()
{
	m_angle = 360 - m_angle;
}

void Bolt::setAngle(float a)
{
	m_angle = a;
}

void Bolt::boost()
{
	m_boosting = true;
	m_boostTime = sf::seconds(5);
}

bool Bolt::isBoosting()
{
	return m_boosting;
}

sf::Sprite Bolt::getSprite()
{
	return m_shape;
}
