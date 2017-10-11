#pragma once
#include <SFML\Graphics.hpp>
#include <math.h>
class VectorCalc
{
public:
	VectorCalc();
	~VectorCalc();


	static sf::Vector2f normalise(sf::Vector2f vector);

	static float getLength(sf::Vector2f vector);

};

