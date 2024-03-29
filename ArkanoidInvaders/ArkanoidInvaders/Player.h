/// author Emmett Byrne
// date 25-11-17
#pragma once
#include <SFML\Graphics.hpp>

class Player
{
public:
	Player();
	~Player();

	void update(sf::Time t);

	void setPosition(sf::Vector2f pos);
	void setTexture(sf::Texture & tex);
	void render(sf::RenderWindow & window);

	sf::Sprite getSprite();
	void moveLeft();
	void moveRight();
	void stopLeft();
	void stopRight();

private:
	sf::Vector2f m_position; //Platers position
	sf::Sprite m_shape; //Player shape object

	bool m_moveLeft;
	bool m_moveRight;

	float m_moveSpeed;
};

