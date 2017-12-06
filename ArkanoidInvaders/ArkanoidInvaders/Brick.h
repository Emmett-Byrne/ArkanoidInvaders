#pragma once
#include <SFML\Graphics.hpp>

class Brick
{
public:
	Brick();
	~Brick();

	void setPosition(sf::Vector2f pos);
	void render(sf::RenderWindow & window);

private:
	sf::Vector2f m_position;
	sf::RectangleShape m_shape;

	bool m_alive;
};