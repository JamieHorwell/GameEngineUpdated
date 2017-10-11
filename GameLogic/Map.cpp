#include "Map.h"
#include "../Renderer/Display.h"

//test initilisation of map
Map::Map(MainManager* mm, PhysicsMain* pm)
{
	//load map file 
	this->mm = mm;
	this->pm = pm;
	//automate this? 

	
}


Map::~Map()
{
}



MapTile Map::MapTileMapper(Tile_Type type)
{
	return tiles.at(type);
}

void Map::init(int width, int height, int tileSize)
{
	setWidth(width);
	setHeight(height);
	this->tileSize = tileSize;
	map.resize(width);

	for (int i = 0; i < width; ++i) {
		map.at(i).resize(height);
	}
}

void Map::AddTile(int x, int y,std::string TileType, bool solid)
{
	//go get texture for this maptile 
	

	//where to place tile? half of tile size + x,y * tile size
	sf::Vector2f offset(x*tileSize+tileSize/2,y*tileSize+tileSize/2);

	MapTile* maptile = new MapTile(mm->SSManager.GetElement("medievalRTS_spritesheet.xml")->getSprite(TileType), offset, solid);
	//add to renderer and physics subsystems
	if (solid) {
		pm->addPhysObj(new PhysicsComponent(b2Vec2(maptile->getPos().x, maptile->getPos().y), b2Vec2(tileSize, tileSize), solid));
	}
	Display::addRenderObj(maptile->getRenderObj());
	map[x][y] = maptile;
}

void Map::clean()
{
	for (int i = 0; i < map.size(); ++i) {


		std::vector<MapTile*>::iterator currentTile;
		for (currentTile = map[i].begin(); currentTile != map[i].end();) {

			(*currentTile)->Delete();
			currentTile = map[i].erase(currentTile);

		}
	}
}
