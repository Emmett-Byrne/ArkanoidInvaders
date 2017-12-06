#pragma once
#include <SFML\Graphics.hpp>
class Player
{
public:
	Player();
	~Player();

	void setPosition(sf::Vector2f pos);
	void render(sf::RenderWindow & window);

private:
	sf::Vector2f m_position;
	sf::RectangleShape m_shape;
};

