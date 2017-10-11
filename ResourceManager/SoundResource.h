#pragma once
#include "ResourceBase.h"
#include <SFML/Audio.hpp>

class SoundResource :
	public ResourceBase
{
public:
	SoundResource(const unsigned int handle, const string& name, const string& path = "../Resources/");
	~SoundResource();


	sf::SoundBuffer & getSBuffer() { return SBuffer; };

	void init(string soundId);

	string getId() { return soundId; };

private:
	sf::SoundBuffer SBuffer;
	string soundId;
};

