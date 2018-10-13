#ifndef TILE
#define TILE

#include "Global.h"

enum class TileType
{
	FLOOR,
	WALL,
	DOOR
};

class Tile
{
public: //functions
	Tile();

	~Tile();

	void init(sf::Vector2f t_pos,
		sf::Texture & t_floor1,
		sf::Texture & t_floor2,
		sf::Texture & t_wall1,
		sf::Texture & t_wall2,
		sf::Texture & t_doorOpen,
		sf::Texture & t_doorClosed);

	void setTexture(TileType t_type, const int T_XPOS = 0, const int T_YPOS= 0);

private: //functions
	void render(sf::RenderWindow & t_window);

public: //variables
	std::map<std::string, sf::Texture> m_textureDict;

private: //variables 
	TileType m_type;
	sf::IntRect m_textureRect;
	int const M_SIZE{ 32 };
	sf::RectangleShape m_bodySquare;
	sf::Vector2f m_position{ 0,0 };
};

#endif // !TILE