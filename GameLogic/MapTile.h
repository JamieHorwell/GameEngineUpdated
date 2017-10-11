#pragma once
#include "Entity.h"
#include "../Renderer/RenderComponent.h"

enum class Tile_Type
{
	Grass,
	TreesSparse,
	TreesDense
};


class MapTile :
	public Entity
{
public:
	MapTile(const sf::Texture &text, bool solid = false);

	MapTile(sf::Sprite TileSprite, sf::Vector2f pos, bool solid = false);

	MapTile(const sf::Texture &text, sf::Vector2f pos, bool solid = false);

	MapTile(const MapTile &maptile);
	~MapTile();

	RenderComponent* getRenderObj() const;

	void setRenderObj(RenderComponent *renderObj);

	void setPostion(sf::Vector2f newPos) { this->position = newPos; 
	renderObj->setPos(position);
	};

	sf::Vector2f getPos() { return position; };

	void Delete();

private:
	bool solid;
	RenderComponent* renderObj;
	sf::Vector2f position;

};

