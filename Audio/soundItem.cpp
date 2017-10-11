#include "soundItem.h"



soundItem::soundItem():
	sf::Sound()
{
}

soundItem::soundItem(const sf::SoundBuffer & buffer):
	sf::Sound(buffer)
{
}


soundItem::~soundItem()
{
}
