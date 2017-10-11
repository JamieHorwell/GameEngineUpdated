#include "MapTile.h"


/*To do:	-add static physicsComponent if solid
			-add animation to some tiles, i.e. trigger 
			tree being cut down if cut down...*/
MapTile::MapTile(const sf::Texture &text, bool solid)
{
	renderObj = new RenderComponent(text);
	this->solid = solid;
}

MapTile::MapTile(sf::Sprite TileSprite, sf::Vector2f pos, bool solid)
{
	renderObj = new RenderComponent(TileSprite);
	this->solid = solid;
	setPostion(pos);
}

MapTile::MapTile(const sf::Texture & text, sf::Vector2f pos, bool solid)
{
	this->solid = solid;
	renderObj = new RenderComponent(text);
	setPostion(pos);
}



MapTile::MapTile(const MapTile & maptile)
{
	this->solid = solid;
	renderObj = new RenderComponent();
	*renderObj = *(maptile.getRenderObj());
}


MapTile::~MapTile()
{
}

RenderComponent * MapTile::getRenderObj() const
{
	return renderObj;
}

void MapTile::setRenderObj(RenderComponent * renderObj)
{
	this->renderObj = renderObj;
}

void MapTile::Delete()
{
	renderObj->Delete();
}
