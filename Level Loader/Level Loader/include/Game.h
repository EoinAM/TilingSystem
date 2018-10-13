#ifndef GAME
#define GAME

#include "RoomBuilder.h"

class Game
{
public: //Functions
	Game();
	~Game();
	void run();

private: //Functions
	void processEvents();
	void processGameEvents(sf::Event & t_event);
	void update(double t_dt);
	void render();

	RoomBuilder m_builder;

public : //Variables

private: //Variables
	sf::RenderWindow m_window; 

};

#endif // !GAME


