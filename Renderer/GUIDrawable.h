#pragma once
#include <SFML\Graphics.hpp>
#include <vector>
class GUIDrawable
{
public:
	GUIDrawable(sf::Drawable* drawable);
	~GUIDrawable();

	inline void addChild(GUIDrawable* child) { children.push_back(child); };
	std::vector<GUIDrawable*> getChildren() { return children; };

	sf::Drawable* getDrawable() { return drawable; };

	void Delete();
	bool getDelete() { return toDelete; };

private:
	sf::Drawable* drawable;
	sf::Vector2f pos;
	std::vector<GUIDrawable*> children;
	bool toDelete;
};

