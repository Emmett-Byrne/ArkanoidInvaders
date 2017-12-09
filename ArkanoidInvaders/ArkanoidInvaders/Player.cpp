/// author Emmett Byrne
// date 25-11-17
#include "Player.h"



Player::Player() : 
	m_moveLeft(false),
	m_moveRight(false),
	m_moveSpeed(300)
{
}


Player::~Player()
{
}

void Player::update(sf::Time t)
{
	if (m_moveLeft)
	{
		m_position.x -= (m_moveSpeed * t.asSeconds());
	}
	if (m_moveRight)
	{
		m_position.x += (m_moveSpeed * t.asSeconds());
	}

	if (m_position.x - m_shape.getOrigin().x < 0)
	{
		m_position.x = m_shape.getOrigin().x;
	}
	if (m_position.x + m_shape.getOrigin().x > 800)
	{
		m_position.x = 800 - m_shape.getOrigin().x;
	}

	m_shape.setPosition(m_position);
}

void Player::setPosition(sf::Vector2f pos)
{
	m_position = pos;
	m_shape.setPosition(pos);
}

void Player::setTexture(sf::Texture & tex)
{
	m_shape.setTexture(tex);
	m_shape.setOrigin(m_shape.getLocalBounds().width / 2, m_shape.getLocalBounds().height / 2);
}

void Player::render(sf::RenderWindow & window)
{
	window.draw(m_shape);
}

sf::Sprite Player::getSprite()
{
	return m_shape;
}

void Player::moveLeft()
{
	m_moveLeft = true;
}

void Player::moveRight()
{
	m_moveRight = true;
}

void Player::stopLeft()
{
	m_moveLeft = false;
}

void Player::stopRight()
{
	m_moveRight = false;
}
