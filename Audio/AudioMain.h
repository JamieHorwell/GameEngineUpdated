#pragma once
#include "../ResourceManager/MainManager.h"
#include <SFML\Audio.hpp>
#include <queue>
#include <map>
#include <vector>
#include "AudioComponent.h"
class AudioMain
{
public:
	AudioMain();
	~AudioMain();

	//initialise music
	void init(std::string musicFilename, MainManager * mm);

	void update();

	void addSoundToQueue(sf::Sound sound, sf::Vector2f position);

	void changeMusic(std::string filename);

	void addAudioComponent(AudioComponent* audioComp) { audioObjects.push_back(audioComp); };


private:
	sf::Music lm;

	std::queue<sf::Sound> soundsPlaying;

	MainManager* mm;


	std::vector<AudioComponent*> audioObjects;
};

