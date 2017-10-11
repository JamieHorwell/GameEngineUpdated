#include "SoundResource.h"
#include <sstream>




SoundResource::SoundResource(const unsigned int handle, const string & name, const string & path)
	:ResourceBase(handle,name,path)
{
	stringstream s;
	s << path << name;
	this->SBuffer.loadFromFile(s.str());
}

SoundResource::~SoundResource()
{
}

void SoundResource::init(string soundId)
{
	this->m_name = soundId;
}
