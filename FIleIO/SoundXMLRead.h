#pragma once
#include "../ResourceManager/ResourceManager.h"
#include "../ResourceManager/SoundResource.h"
class SoundXMLRead
{
public:
	SoundXMLRead();
	~SoundXMLRead();


	static void loadSound(std::string filename, ResourceManager<SoundResource>* soundManager);


};

