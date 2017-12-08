#include "Player.h"



Player::Player()
{
}


Player::~Player()
{
}

void Player::update(sf::Time t)
{
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
