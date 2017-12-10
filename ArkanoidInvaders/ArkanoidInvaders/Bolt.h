/// author Emmett Byrne
// date 25-11-17
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
	void setAngle(float a);

	void boost();
	bool isBoosting();

	sf::Sprite getSprite();
private:
	sf::Vector2f m_position; //Position of bold
	sf::Sprite m_shape; //Bolt shape object

	float m_angle; //angle the ball moves at;
	float m_speed; //scaler for how fast the ball moves

	bool m_boosting; //If bolt has been speed boosted
	sf::Time m_boostTime; //Remaining time of boost

	void wallCol();
};

