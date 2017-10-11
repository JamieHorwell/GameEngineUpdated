#include "VectorCalc.h"



VectorCalc::VectorCalc()
{
}


VectorCalc::~VectorCalc()
{
}

sf::Vector2f VectorCalc::normalise(sf::Vector2f vector)
{
	float length = getLength(vector);
	return sf::Vector2f(vector.x/length,vector.y/length);
}

float VectorCalc::getLength(sf::Vector2f vector)
{
	return sqrtf((vector.x*vector.x) + (vector.y*vector.y));
}
