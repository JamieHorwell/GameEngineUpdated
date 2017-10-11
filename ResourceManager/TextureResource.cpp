#include "TextureResource.h"
#include <sstream>





TextureResource::TextureResource(const unsigned int handle, const string & name, const string & path)
	:ResourceBase(handle, name, path)
{

	//load and set texture from name and path
	stringstream s;
	s << path << name;
	texture.loadFromFile(s.str());
}

TextureResource::~TextureResource()
{
}
