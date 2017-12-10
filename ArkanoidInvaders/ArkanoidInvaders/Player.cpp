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

/// <summary>
/// updates the state of the player
/// </summary>
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

/// <summary>
/// sets the players postion
/// </summary>
void Player::setPosition(sf::Vector2f pos)
{
	m_position = pos;
	m_shape.setPosition(pos);
}

/// <summary>
/// Sets the players texture
/// </summary>
void Player::setTexture(sf::Texture & tex)
{
	m_shape.setTexture(tex);
	m_shape.setOrigin(m_shape.getLocalBounds().width / 2, m_shape.getLocalBounds().height / 2);
}

/// <summary>
/// renders the player
/// </summary>
void Player::render(sf::RenderWindow & window)
{
	window.draw(m_shape);
}

/// <summary>
/// returns the players sprite
/// </summary>
sf::Sprite Player::getSprite()
{
	return m_shape;
}

/// <summary>
/// sets the player to be moving left
/// </summary>
void Player::moveLeft()
{
	m_moveLeft = true;
}

/// <summary>
/// sets the player to be moving Right
/// </summary>
void Player::moveRight()
{
	m_moveRight = true;
}

/// <summary>
/// stops the player moving left
/// </summary>
void Player::stopLeft()
{
	m_moveLeft = false;
}

/// <summary>
/// stops the player moving right
/// </summary>
void Player::stopRight()
{
	m_moveRight = false;
}
