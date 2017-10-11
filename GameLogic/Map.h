#pragma once
#include "MapTile.h"

#include "../ResourceManager/MainManager.h"
#include "../GameLogic/Map.h"
#include "../Physics/PhysicsMain.h"
#include <vector>


class Map
{
public:
	Map(MainManager* mm, PhysicsMain* pm);
	~Map();

	
	


	//will create MapTile associated with tile type
	MapTile MapTileMapper(Tile_Type type);
	
	inline int getWidth() { return width*tileSize; };
	inline int getHeight() { return height*tileSize; };


	void init(int width, int height, int tileSize);
	void AddTile(int x, int y, std::string TileType, bool solid);



	void setWidth(int width) { this->width = width; };
	void setHeight(int height) { this->height = height; };


	void clean();

private:
	
	//map size in tiles
	int width;
	int height;

	int tileSize;

	//2D vector containing all map tiles
	std::vector<std::vector<MapTile*>> map;

	std::map<Tile_Type, MapTile> tiles;


	MainManager* mm;
	PhysicsMain* pm;
};

