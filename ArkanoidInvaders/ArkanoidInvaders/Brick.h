#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>

class Brick
{
public:
	Brick(sf::Texture & tex);
	~Brick();

	void setPosition(sf::Vector2f pos);
	void render(sf::RenderWindow & window);

	sf::Sprite getSprite();
	void kill();
	bool isAlive();
private:
	sf::Vector2f m_position;
	sf::Sprite m_shape;

	bool m_alive;
};