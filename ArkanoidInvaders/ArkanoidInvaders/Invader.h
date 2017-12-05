#pragma once
#include <SFML\Graphics.hpp>

class Invader
{
public:
	Invader();
	~Invader();

	void render(sf::RenderWindow & window);

private:
	sf::Vector2f m_position;
	sf::Vector2f m_velocity;
};

