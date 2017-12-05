#pragma once
#include <SFML\Graphics.hpp>

class Brick
{
public:
	Brick();
	~Brick();

	void render(sf::RenderWindow & window);

private:
	sf::Vector2f m_position;
	sf::RectangleShape m_shape;
};

