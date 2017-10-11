#include "Display.h"

sf::RenderWindow* Display::window = 0;
int Display::width = 0;
int Display::height = 0;
sf::View Display::cameraView = sf::View();
sf::RectangleShape Display::cursorbox;
std::vector<RenderComponent*> Display::renderObjs;
std::vector<GUIDrawable*> Display::guiObjs;

Display::Display(int width, int height)
{
	
	this->width = width;
	this->height = height;
	window = new sf::RenderWindow(sf::VideoMode(width, height), "Jamies Game");
	window->setFramerateLimit(60);
}

Display::Display()
{
	window = new sf::RenderWindow(sf::VideoMode(width, height), "Jamies Game");
}


Display::~Display()
{
	delete window;
}

void Display::initWindow(int width, int height)
{
	window = new sf::RenderWindow(sf::VideoMode(width, height), "Jamies Game");
	window->setFramerateLimit(60);
	cameraView = sf::View(sf::FloatRect(0, 0, width, height));
	window->setView(cameraView);
}

void Display::draw(const sf::Drawable & sprite)
{
	
	window->draw(sprite);
	
}


void Display::drawObjs()
{
	
	std::vector<RenderComponent*>::iterator currentObj;
	for (currentObj = renderObjs.begin(); currentObj != renderObjs.end(); ) {
		//check if object needs to be deleted
		if ((*currentObj)->getDelete()) {
			delete(*currentObj);
			currentObj = renderObjs.erase(currentObj);

		}
		else {
			draw(*(*currentObj)->getsprite());
			
			for (RenderComponent *c : (*currentObj)->getChildren()) {
				draw(*c->getsprite());
			}



			++currentObj;
		}
	}

	window->setView(window->getDefaultView());
	std::vector<GUIDrawable*>::iterator currentGUIObj;
	for (currentGUIObj = guiObjs.begin(); currentGUIObj != guiObjs.end(); ) {
		//check if object needs to be deleted
		if ((*currentGUIObj)->getDelete()) {
			delete(*currentGUIObj);
			currentGUIObj = guiObjs.erase(currentGUIObj);

		}
		else {
			draw(*(*currentGUIObj)->getDrawable());

			for (GUIDrawable *c : (*currentGUIObj)->getChildren()) {
				draw(*c->getDrawable());
			}



			++currentGUIObj;
		}
	}
	window->setView(cameraView);



}





void Display::clear()
{
	window->clear();
}

void Display::display()
{
	window->display();
}

void Display::checkWindowEvents()
{
	sf::Event e;
	while (window->pollEvent(e))
	{
		if (e.type == sf::Event::Closed) {
			window->close();
		}
	}
}

bool Display::isOpen()
{
	return window->isOpen();
}

void Display::moveView(sf::Vector2f move)
{
	cameraView.move(move);
	
}

sf::Vector2f Display::getMousePos()
{
	sf::Vector2i mouseWindow = sf::Mouse::getPosition(*window);
	sf::Vector2f mousePos = window->mapPixelToCoords(mouseWindow);
	return mousePos;
}

sf::Vector2f Display::getRelativePos()
{
	window->setView(window->getDefaultView());
	sf::Vector2i mouseWindow = sf::Mouse::getPosition(*window);
	sf::Vector2f mousePos = window->mapPixelToCoords(mouseWindow);
	window->setView(cameraView);
	return mousePos;
}

sf::RectangleShape Display::drawBox(sf::Vector2f startPos)
{
	sf::Vector2f endPos = getMousePos();



	cursorbox.setSize({ endPos.x - startPos.x, endPos.y - startPos.y });
	cursorbox.setPosition(startPos);
	cursorbox.setOutlineColor(sf::Color::Green);
	cursorbox.setOutlineThickness(2);
	cursorbox.setFillColor(sf::Color::Transparent);
	window->draw(cursorbox);

	return cursorbox;
}

void Display::update()
{

}
