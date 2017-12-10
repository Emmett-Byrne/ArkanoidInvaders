/// author Emmett Byrne
// date 25-11-17
#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>

class Invader
{
public:
	Invader(sf::Texture & tex);
	~Invader();

	void setPosition(sf::Vector2f pos);
	void render(sf::RenderWindow & window);

	sf::Sprite getSprite();
	bool isAlive();
	void kill();
	void move(sf::Vector2f move);
private:
	sf::Vector2f m_position; //Invaders position
	sf::Vector2f m_velocity; //Invaders velocity
	sf::Sprite m_shape; //Invader shape object

	bool m_alive; //If invader is alive
};