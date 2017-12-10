/// author Emmett Byrne
// date 25-11-17

#include "Game.h"
#include <iostream>



Game::Game() :
	m_window{ sf::VideoMode{ 800, 600, 32 }, "Arkanoid Invaders" },
	m_exitGame{ false }, //when true game will exit
	moveInvader(100),
	gameOver(false)
{
	if (!LevelLoader::load(1, m_level))
	{
		return;
	}

	if (!m_invaderTexture.loadFromFile("Assets\\Invader.png"))
	{
		// simple error message if previous call fails
		std::cout << "problem image" << std::endl;
	}

	if (!m_brickTexture.loadFromFile("Assets\\Brick.png"))
	{
		// simple error message if previous call fails
		std::cout << "problem image" << std::endl;
	}
	if (!m_boltTexture.loadFromFile("Assets\\Bolt.png"))
	{
		// simple error message if previous call fails
		std::cout << "problem image" << std::endl;
	}
	if (!m_playerTexture.loadFromFile("Assets\\Player.png"))
	{
		// simple error message if previous call fails
		std::cout << "problem image" << std::endl;
	}
	if (!m_font.loadFromFile("Assets\\ariblk.ttf"))
	{
		std::cout << "problem loading arial black font" << std::endl;
	}
	if (!m_paddleBuffer.loadFromFile("Assets\\paddleSound.wav"))
	{
		std::cout << "problem loading sound" << std::endl;
	}
	if (!m_enemyBuffer.loadFromFile("Assets\\brickSound.wav"))
	{
		std::cout << "problem loading sound" << std::endl;
	}

	m_paddleSound.setBuffer(m_paddleBuffer);
	m_enemySound.setBuffer(m_enemyBuffer);


	m_gameOverText.setFont(m_font);
	m_gameOverText.setCharacterSize(35);
	m_gameOverText.setPosition(60, 350);
	m_gameOverText.setString("Game Over - Press Space to restart");

	setupLevel();
}


Game::~Game()
{
}


void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	sf::Time timePerFrame = sf::seconds(1.f / 60.f); // 60 fps
	while (m_window.isOpen())
	{
		processEvents(); // as many as possible
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > timePerFrame)
		{
			timeSinceLastUpdate -= timePerFrame;
			processEvents(); // at least 60 fps
			if (!gameOver)
			{
				update(timePerFrame); //60 fps
			}
		}
		render(); // as many as possible
	}
}
/// <summary>
/// handle user and system events/ input
/// get key presses/ mouse moves etc. from OS
/// and user :: Don't do game update here
/// </summary>
void Game::processEvents()
{
	sf::Event event;
	while (m_window.pollEvent(event))
	{
		if (sf::Event::Closed == event.type) // window message
		{
			m_window.close();
		}
		if (sf::Event::KeyPressed == event.type) //user key press
		{
			if (sf::Keyboard::Escape == event.key.code)
			{
				m_exitGame = true;
			}
			if (sf::Keyboard::Left == event.key.code)
			{
				m_player.moveLeft();
			}
			if (sf::Keyboard::Right == event.key.code)
			{
				m_player.moveRight();
			}
			if (sf::Keyboard::Up == event.key.code)
			{
				if (m_hud.getPower() > 0 && !m_bolt.isBoosting())
				{
					m_hud.decreasePower(1);
					m_bolt.boost();
				}
			}
			if (sf::Keyboard::Space == event.key.code && gameOver)
			{
				gameOver = false;
				restartLevel();
			}
		}

		if (sf::Event::KeyReleased == event.type) //user key press
		{
			if (sf::Keyboard::Left == event.key.code)
			{
				m_player.stopLeft();
			}
			if (sf::Keyboard::Right == event.key.code)
			{
				m_player.stopRight();
			}
		}
	}
}

/// <summary>
/// Update the game world
/// </summary>
/// <param name="t_deltaTime">time interval per frame</param>
void Game::update(sf::Time t_deltaTime)
{
	bool Left = false;
	bool right = false;
	if (m_exitGame)
	{
		m_window.close();
	}

	m_player.update(t_deltaTime);
	m_bolt.update(t_deltaTime);
	for (Invader & invader : m_invaders)
	{
		if (invader.isAlive())
		{
			if (invader.getSprite().getPosition().x + invader.getSprite().getOrigin().x > 800)
			{
				Left = true;
			}
			if (invader.getSprite().getPosition().x - invader.getSprite().getOrigin().x < 0)
			{
				right = true;
			}
			invader.move(sf::Vector2f(moveInvader * t_deltaTime.asSeconds(), 0));
		}
	}
	if (Left)
	{
		moveInvader = -100;
	}
	if (right)
	{
		moveInvader = 100;
	}

	checkCollisions();
	checkGameOver();
	m_hud.update(t_deltaTime);
}

/// <summary>
/// draw the frame and then switch bufers
/// </summary>
void Game::render()
{
	m_window.clear(sf::Color::Black);

	for (Brick brick : m_bricks)
	{
		if (brick.isAlive())
		{
			brick.render(m_window);
		}
	}

	for (Invader invader : m_invaders)
	{
		if (invader.isAlive())
		{
			invader.render(m_window);
		}
	}

	m_player.render(m_window);
	m_bolt.render(m_window);
	m_hud.render(m_window);
	if (gameOver)
	{
		m_window.draw(m_gameOverText);
	}

	m_window.display();
}

/// <summary>
/// Uses the data retrieve from the yaml file to set up the level
/// </summary>
void Game::setupLevel()
{
	m_player.setPosition(m_level.m_player.m_position);
	m_player.setTexture(m_playerTexture);
	m_bolt.setPosition(m_level.m_bolt.m_position);
	m_bolt.setTexture(m_boltTexture);
	setupBricks();
	setupInvaders();
}

/// <summary>
/// gives the invaders the data from the yaml fule
/// </summary>
void Game::setupInvaders()
{
	for (InvaderData const & invaderData : m_level.m_invaders)
	{
		Invader invader(m_invaderTexture);
		invader.setPosition(invaderData.m_position);
		m_invaders.push_back(invader);
	}
}

/// <summary>
/// gives the bricks the data from the yaml fule
/// </summary>
void Game::setupBricks()
{
	for (BrickData const & brickData : m_level.m_bricks)
	{
		Brick brick(m_brickTexture);
		brick.setPosition(brickData.m_position);
		m_bricks.push_back(brick);
	}
}

/// <summary>
/// Checks for collisions between game objects
/// </summary>
void Game::checkCollisions()
{
	//player - bolt
	if (CollisionDetector::collision(m_player.getSprite(), m_bolt.getSprite()))
	{
		m_bolt.reflectPaddle(m_player.getSprite());
		m_paddleSound.play();
	}

	//bolt - invader
	for (Invader &invader : m_invaders)
	{
		if (CollisionDetector::collision(invader.getSprite(), m_bolt.getSprite()))
		{
			if (invader.isAlive())
			{
				invader.kill();
				m_bolt.reflectX();
				m_enemySound.play();
			}
		}
	}

	//bolt - brick
	for (Brick &brick : m_bricks)
	{
		if (CollisionDetector::collision(brick.getSprite(), m_bolt.getSprite()))
		{
			if (brick.isAlive())
			{
				brick.kill();
				m_bolt.reflectX();
				m_enemySound.play();
			}
		}
	}

	//bolt - ground
	if (m_bolt.getSprite().getPosition().y + m_bolt.getSprite().getOrigin().y > 600)
	{
		m_bolt.setPosition(m_level.m_bolt.m_position);
		m_hud.decreaseTime(5);
	}
}

/// <summary>
/// Checks of the game is over
/// </summary>
void Game::checkGameOver()
{
	gameOver = true;
	for (Invader invader : m_invaders)
	{
		if (invader.isAlive())
		{
			gameOver = false;
		}
	}
	for (Brick brick : m_bricks)
	{
		if (brick.isAlive())
		{
			gameOver = false;
		}
	}
}

/// <summary>
/// Restarts all the objects to their original position
/// </summary>
void Game::restartLevel()
{
	m_hud.restart();
	m_invaders.clear();
	m_bricks.clear();
	setupLevel();
	moveInvader = 100;
	m_bolt.setAngle(45);
}
