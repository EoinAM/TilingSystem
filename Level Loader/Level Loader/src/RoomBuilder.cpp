#include "RoomBuilder.h"

RoomBuilder::RoomBuilder(sf::RenderWindow & t_window) :
	m_window(t_window)
{
	loadAssets();

	for (int i = 0; i < M_TOTALHEIGHT; i++)
	{
		for (int j = 0; j  < M_TOTALWIDTH; i++)
		{
			m_tiles[i][j].init(sf::Vector2f(0, 0),floor1, floor2, wall1, wall2, door1,door2);
		}
	}
}

RoomBuilder::~RoomBuilder()
{
}

void RoomBuilder::loadFile(std::string t_roomName)
{
	emptyRoom();

	std::cout << "builder" << std::endl;

	std::ifstream lvlfile;
	lvlfile.open(t_roomName);
	if (lvlfile.is_open())
	{
		std::cout << "file opened" << std::endl;
		while (!lvlfile.eof())
		{
			
			for (int i = 0; i < M_TOTALHEIGHT; i++)
			{
				
				for (int j = 0; j < M_TOTALWIDTH; j++)
				{
					lvlfile >> m_tileValue[i][j];
					std::cout << m_tileValue[i][j];

					if (j == M_TOTALWIDTH - 1)
					{
						std::cout  << std::endl;
					}
				}

			} // !for loop
						
		} // !while loop
		std::cout << "closed" << std::endl;
		lvlfile.close();
	} // !if(lvl.is_open) 
	
}

void RoomBuilder::emptyRoom()
{
	for (int i = 0; i < M_TOTALHEIGHT; i++)
	{
		for (int j = 0; j < M_TOTALWIDTH; j++)
		{

			m_tileValue[i][j] = 0;
		}
	}
}

void RoomBuilder::loadAssets()
{
	if (floor1.loadFromFile("Assets\\Sprites\\Floor1.png")) { std::cout << "loaded"; }
	if (floor2.loadFromFile("Assets\\Sprites\\Floor2.png")) { std::cout << "loaded"; }
	if (wall1.loadFromFile("Assets\\Sprites\\Wall1.png")) { std::cout << "loaded"; }
	if (wall2.loadFromFile("Assets\\Sprites\\wall2.png")) { std::cout << "loaded"; }
	if (door1.loadFromFile("Assets\\Sprites\\DoorClosed.png")) { std::cout << "loaded"; }
	if (door2.loadFromFile("Assets\\Sprites\\DoorOpen.png")) { std::cout << "loaded"; }
}
