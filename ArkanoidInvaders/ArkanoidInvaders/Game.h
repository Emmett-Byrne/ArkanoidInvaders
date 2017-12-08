/// author Emmett Byrne
// date 25-11-17

#ifndef GAME
#define GAME

#include <iostream>
#include <SFML\Graphics.hpp>
#include "LevelLoader.h"
#include "Player.h"
#include "Bolt.h"
#include "Brick.h"
#include "Invader.h"
#include "CollisionDetector.h"

class Game
{
public:
	Game();
	~Game();
	/// <summary>
	/// main method for game
	/// </summary>
	void run();

private:

	void processEvents();
	void update(sf::Time t_deltaTime);
	void render();

	void setupInvaders();
	void setupBricks();

	void checkCollisions();

	void setupFontAndText();


	sf::RenderWindow m_window; // main SFML window
	sf::Font m_ArialBlackfont; // font used by message
	sf::Text m_welcomeMessage; // text used for message on screen
	bool m_exitGame; // control exiting game


	sf::Texture m_invaderTexture; // texture used for invader
	sf::Texture m_brickTexture;
	sf::Texture m_playerTexture;
	sf::Texture m_boltTexture;

	LevelData m_level;

	Player m_player;
	Bolt m_bolt;

	std::vector<Brick> m_bricks;
	std::vector<Invader> m_invaders;
};

#endif // !GAME

