#include "Player.h"



Player::Player()
{
}


Player::~Player()
{
}

void Player::setPosition(sf::Vector2f pos)
{
	m_position = pos;
}

void Player::render(sf::RenderWindow & window)
{
	window.draw(m_shape);
}
