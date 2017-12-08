#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>
#include <cmath>

class Bolt
{
public:
	Bolt();
	~Bolt();

	void update(sf::Time t);

	void setPosition(sf::Vector2f pos);
	void setTexture(sf::Texture & tex);
	void render(sf::RenderWindow & window);

	void reflectPaddle(sf::Sprite sprite);
	void reflectY();
	void reflectX();

	sf::Sprite getSprite();
private:
	sf::Vector2f m_velocity;
	sf::Vector2f m_position;
	sf::Sprite m_shape;

	float m_angle; //angle the ball moves at;
	float m_speed; //scaler for how fast the ball moves


	void wallCol();
};

