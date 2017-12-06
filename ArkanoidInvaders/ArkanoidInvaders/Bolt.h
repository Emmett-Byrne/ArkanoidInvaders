#pragma once
#include <SFML\Graphics.hpp>

class Bolt
{
public:
	Bolt();
	~Bolt();

	void setPosition(sf::Vector2f pos);
	void render(sf::RenderWindow & window);

private:
	sf::Vector2f m_velocity;
	sf::Vector2f m_position;
	sf::CircleShape m_shape;
};

