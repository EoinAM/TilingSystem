#ifndef TILE
#define TILE

#include "Global.h"

/// <summary>
/// Different Types of Tiles 
/// More Can Be added as Needed
/// </summary>
enum class TileType
{
	FLOOR,
	WALL,
	DOOR,
	EMPTY
};


class Tile
{
public: //functions
	Tile();

	~Tile();
	void render(sf::RenderWindow& t_window);

	/// <summary>
	/// Initialises the Textures
	/// Also Possible ot use a Resource manager instead of using singular textures
	/// </summary>
	void init(sf::Vector2f t_pos,
		sf::Texture* t_floor1,
		sf::Texture* t_floor2,
		sf::Texture* t_wall1,
		sf::Texture* t_wall2,
		sf::Texture* t_doorOpen,
		sf::Texture* t_doorClosed);

	void setTexture(TileType t_type, const int T_XPOS = 0, const int T_YPOS = 0);

private: //functions


public: //variables
	std::map<std::string, sf::Texture*> m_textureDict;
	int const M_SIZE{ 26 };
	sf::RectangleShape m_bodySquare;
	TileType m_type;

private: //variables 

	sf::IntRect m_textureRect;

	sf::Vector2f m_position{ 0,0 };
};

#endif // !TILE