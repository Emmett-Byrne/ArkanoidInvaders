#pragma once
#include <SFML\Graphics.hpp>

class Invader
{
public:
	Invader();
	~Invader();

	void setPosition(sf::Vector2f pos);
	void render(sf::RenderWindow & window);

private:
	sf::Vector2f m_position;
	sf::Vector2f m_velocity;

	sf::Sprite m_shape;

	bool m_alive;
};