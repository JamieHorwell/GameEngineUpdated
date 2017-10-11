#pragma once
#include <SFML\Audio.hpp>

class soundItem : sf::Sound
{
public:
	soundItem();
	soundItem(const sf::SoundBuffer &buffer);
	~soundItem();

	void setToPlay(bool playSound) { toPlay = playSound; };
	bool getToPlay() { return toPlay; };

private:
	bool toPlay = false;
};

