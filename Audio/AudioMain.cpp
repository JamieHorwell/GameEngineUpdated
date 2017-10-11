#include "AudioMain.h"



AudioMain::AudioMain()
{
}


AudioMain::~AudioMain()
{
}



void AudioMain::init(std::string musicFilename, MainManager * mm)
{
	this->mm = mm;
	changeMusic(musicFilename);
	sf::Sound attack;
}

void AudioMain::update()
{
	//loop through audio components, if a sound needs to be played, push it to the queue, set flag to false
	for (int i = 0; i < audioObjects.size(); ++i) {
		if (audioObjects[i]->getToPlay()) {
			addSoundToQueue(sf::Sound(mm->soundManager.GetElement(audioObjects[i]->whichSound())->getSBuffer()),audioObjects[i]->getPos());
			audioObjects[i]->setToPlay(false);
		}
	}
	//check if sounds in queue are finished playing, if so, pop them from the queue
	if (soundsPlaying.size() > 0) {
		while (soundsPlaying.size() > 0 && soundsPlaying.front().getStatus() == sf::Sound::Status::Stopped ) {
			soundsPlaying.pop();
		}
	}
	//now check if any audioComponents need to be deleted 
	std::vector<AudioComponent*>::iterator currentObj;
	for (currentObj = audioObjects.begin(); currentObj != audioObjects.end(); ) {
		//check if object needs to be deleted
		if ((*currentObj)->getDelete()) {
			delete(*currentObj);
			currentObj = audioObjects.erase(currentObj);

		}
		else {
			++currentObj;
		}
	}
}

void AudioMain::addSoundToQueue(sf::Sound sound,sf::Vector2f position)
{
	soundsPlaying.push(sound);
	soundsPlaying.back().setPosition(position.x,position.y,0);
	soundsPlaying.back().setVolume(10);
	soundsPlaying.back().play();
}

void AudioMain::changeMusic(std::string filename)
{
	lm.stop();
	lm.openFromFile(filename);
	lm.setVolume(10);
	lm.setLoop(true);
	lm.play();
}
