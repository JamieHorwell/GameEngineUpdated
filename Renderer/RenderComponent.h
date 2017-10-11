#pragma once
#include <SFML/Graphics.hpp>

class RenderComponent
{
public:
	
	RenderComponent(sf::Sprite sprite);
	RenderComponent(const sf::Texture &text);
	RenderComponent(sf::Text text);
	RenderComponent();
	~RenderComponent();

	 inline sf::Sprite* getsprite() { return &sprite; };

	 inline const sf::Sprite getSpriteObj() const { return sprite; };

	 //when we set sprite we will always set origin as centre of the sprite
	 inline void setsprite(sf::Sprite sprite) { this->sprite = sprite; 
	 this->sprite.setOrigin(sprite.getLocalBounds().width/2, sprite.getLocalBounds().height/2); };
	 
	 inline void setTexture(const sf::Texture &text) {
		 sprite = sf::Sprite(text);  
	 sprite.setOrigin(sprite.getLocalBounds().width / 2, sprite.getLocalBounds().height / 2);
	 };
	 const inline sf::Texture getTexture() { return *sprite.getTexture(); };

	 inline sf::Vector2f getPos() { return sprite.getPosition(); };
	 
	 
	 void setPos(sf::Vector2f newPos);

	 inline void addChild(RenderComponent* child) { children.push_back(child); };
	 std::vector<RenderComponent*> getChildren() { return children; };

	 void Delete();
	 bool getDelete() { return toDelete; };



private:
	sf::Sprite sprite;
	
	//renderComponent may contain children (i.e. health bar of unit can auto follow unit?)
	std::vector<RenderComponent*> children;
	bool toDelete = false;
	//whether to take cameraview into account?
	bool isStatic = false;
};

