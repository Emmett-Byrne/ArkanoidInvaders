/// author Emmett Byrne
// date 25-11-17

#ifndef GAME
#define GAME

#include <iostream>
#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include "LevelLoader.h"
#include "Player.h"
#include "Bolt.h"
#include "Brick.h"
#include "Invader.h"
#include "CollisionDetector.h"
#include "Hud.h"

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

	void setupLevel();
	void setupInvaders();
	void setupBricks();

	void checkCollisions();
	void checkGameOver();
	void restartLevel();


	sf::RenderWindow m_window; // main SFML window
	bool m_exitGame; // control exiting game


	sf::Texture m_invaderTexture; // invader texture
	sf::Texture m_brickTexture; // brick texture
	sf::Texture m_playerTexture; // player texture
	sf::Texture m_boltTexture; // bolt texture
	sf::Font m_font; // font used in the game
	sf::Text m_gameOverText; // game over message

	sf::SoundBuffer m_paddleBuffer; //buffer for the bolt - paddle sound
	sf::SoundBuffer m_enemyBuffer; //buffer for the bolt - enemy sound

	sf::Sound m_paddleSound; //paddle sound
	sf::Sound m_enemySound; //enemy sound

	LevelData m_level; //contains the data for the level

	Player m_player; //Object to control and manipulate the palyer
	Bolt m_bolt; //Object to control and manipulate the bolt

	std::vector<Brick> m_bricks; //Object to control and manipulate the bricks
	std::vector<Invader> m_invaders; //Object to control and manipulate the invaders

	Hud m_hud; //Object to control and manipulate the HUD

	float moveInvader; //amount the inader moves
	bool gameOver; //If game is over
};

#endif // !GAME

