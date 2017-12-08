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

private:
	sf::Vector2f m_position;
	sf::Sprite m_shape;
};

