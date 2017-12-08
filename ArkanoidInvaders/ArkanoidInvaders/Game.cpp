/// author Emmett Byrne
// date 25-11-17

#include "Game.h"
#include <iostream>



Game::Game() :
	m_window{ sf::VideoMode{ 800, 600, 32 }, "Arkanoid Invaders" },
	m_exitGame{ false } //when true game will exit
{
	if (!LevelLoader::load(1, m_level))
	{
		return;
	}

	if (!m_invaderTexture.loadFromFile("Assets\\Invader.png"))
	{
		// simple error message if previous call fails
		std::cout << "problem loading logo" << std::endl;
	}

	if (!m_brickTexture.loadFromFile("Assets\\Brick.png"))
	{
		// simple error message if previous call fails
		std::cout << "problem loading logo" << std::endl;
	}
	if (!m_boltTexture.loadFromFile("Assets\\Bolt.png"))
	{
		// simple error message if previous call fails
		std::cout << "problem loading logo" << std::endl;
	}
	if (!m_playerTexture.loadFromFile("Assets\\Player.png"))
	{
		// simple error message if previous call fails
		std::cout << "problem loading logo" << std::endl;
	}

	m_player.setPosition(m_level.m_player.m_position);
	m_player.setTexture(m_playerTexture);
	m_bolt.setPosition(m_level.m_bolt.m_position);
	m_bolt.setTexture(m_boltTexture);
	setupBricks();
	setupInvaders();

	//setupFontAndText(); // load font 
	//setupSprite(); // load texture
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
			update(timePerFrame); //60 fps
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
	if (m_exitGame)
	{
		m_window.close();
	}

	m_player.update(t_deltaTime);
	m_bolt.update(t_deltaTime);

	checkCollisions();
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

	m_window.display();
}

void Game::setupInvaders()
{
	for (InvaderData const & invaderData : m_level.m_invaders)
	{
		Invader invader(m_invaderTexture);
		invader.setPosition(invaderData.m_position);
		m_invaders.push_back(invader);
	}
}

void Game::setupBricks()
{
	for (BrickData const & brickData : m_level.m_bricks)
	{
		Brick brick(m_brickTexture);
		brick.setPosition(brickData.m_position);
		m_bricks.push_back(brick);
	}
}

void Game::checkCollisions()
{
	//player - bolt
	if (CollisionDetector::collision(m_player.getSprite(), m_bolt.getSprite()))
	{
		m_bolt.reflectPaddle(m_player.getSprite());
		//std::cout << "collision" << std::endl;
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
			}
		}
	}
}

/// <summary>
/// load the font and setup the text message for screen
/// </summary>
void Game::setupFontAndText()
{
	if (!m_ArialBlackfont.loadFromFile("ASSETS\\FONTS\\ariblk.ttf"))
	{
		std::cout << "problem loading arial black font" << std::endl;
	}
	m_welcomeMessage.setFont(m_ArialBlackfont);
	m_welcomeMessage.setString("SFML Game");
	m_welcomeMessage.setStyle(sf::Text::Underlined | sf::Text::Italic | sf::Text::Bold);
	m_welcomeMessage.setPosition(40.0f, 40.0f);
	m_welcomeMessage.setCharacterSize(80);
	m_welcomeMessage.setOutlineColor(sf::Color::Red);
	m_welcomeMessage.setFillColor(sf::Color::Black);
	m_welcomeMessage.setOutlineThickness(3.0f);

}
