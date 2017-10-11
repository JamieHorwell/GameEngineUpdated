#pragma once
#include <SFML\Audio.hpp>
#include <map>




class AudioComponent
{
public:
	AudioComponent();
	~AudioComponent();

	void queueSoundToPlay(std::string sound, sf::Vector2f soundPos) { playThisSound = sound; toPlay = true; 
	this->soundPos = soundPos;
	};

	bool getToPlay() { return toPlay; };

	void setToPlay(bool toPlay) { this->toPlay = toPlay; };

	void Delete() { toDelete = true; };
	bool getDelete() { return toDelete; };

	sf::Vector2f getPos() { return soundPos; };

	std::string whichSound() { return playThisSound; };



private:

	std::string playThisSound;
	bool toPlay = false;
	sf::Vector2f soundPos;
	
	bool toDelete = false;
};

