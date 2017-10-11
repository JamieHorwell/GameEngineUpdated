#pragma once
#include <SFML/Graphics.hpp>
#include "RenderComponent.h"
#include "GUIDrawable.h"



class Display
{
public:
	Display(int width, int height);
	Display();
	~Display();

	inline static void addRenderObj(RenderComponent *renderObj) { renderObjs.push_back(renderObj); };

	inline static void addGUIDrawable(GUIDrawable *guiObj) { guiObjs.push_back(guiObj); };

	static void initWindow(int width, int height);
	static void draw(const sf::Drawable& sprite);
	static void drawObjs();
	static void clear();
	static void display();
	static void checkWindowEvents();
	static bool isOpen();
	static void moveView(sf::Vector2f move);

	static sf::Vector2f getMousePos();
	static sf::Vector2f getRelativePos();
	static sf::RectangleShape drawBox(sf::Vector2f startPos);


	void update();

	static sf::RenderWindow* window;
	static int width;
	static int height;
	static sf::View cameraView;
	static sf::RectangleShape cursorbox;
	
	//contains all entities, drawn first
	static std::vector<RenderComponent*> renderObjs;
	//contains all gui elements, draw these last to ensure nothing overlaps
	static std::vector<GUIDrawable*> guiObjs;
};

