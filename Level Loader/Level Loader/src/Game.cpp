#include "Game.h"

const int MS_PER_UPDATE{ 10 };


Game::Game() :
	m_window(sf::VideoMode(GlobalSettings::s_width, GlobalSettings::s_height, 32), "UI Library", sf::Style::Default),
	m_builder(m_window)
{
	m_builder.loadFile("Assets\\testLevel.txt");
}

Game::~Game()
{
}// !~Game

void Game::run()
{
	sf::Clock clock;
	sf::Int32 lag = 0;

	while (m_window.isOpen())
	{
		sf::Time dt = clock.restart();
		lag += dt.asMilliseconds();

		processEvents();

		while (lag > MS_PER_UPDATE)
		{
			update(MS_PER_UPDATE);
			lag -= MS_PER_UPDATE;
		}
		update(MS_PER_UPDATE);

		render();
	}
}// !run

void Game::processEvents()
{
	sf::Event event;
	while (m_window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			m_window.close();
		}
		processGameEvents(event);
	}
}// !processEvents

void Game::processGameEvents(sf::Event & t_event)
{
}// !processGameEvents

void Game::update(double t_dt)
{

}// !update


void Game::render()
{
	m_window.clear(sf::Color::Red);
	m_window.display();
}// !render
