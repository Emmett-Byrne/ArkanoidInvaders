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


	sf::Texture m_invaderTexture; // texture used for invader
	sf::Texture m_brickTexture;
	sf::Texture m_playerTexture;
	sf::Texture m_boltTexture;
	sf::Font m_font;
	sf::Text m_gameOverText;

	sf::SoundBuffer m_paddleBuffer;
	sf::SoundBuffer m_enemyBuffer;

	sf::Sound m_paddleSound;
	sf::Sound m_enemySound;

	LevelData m_level;

	Player m_player;
	Bolt m_bolt;

	std::vector<Brick> m_bricks;
	std::vector<Invader> m_invaders;

	Hud m_hud;

	float moveInvader;
	bool gameOver;
};

#endif // !GAME

