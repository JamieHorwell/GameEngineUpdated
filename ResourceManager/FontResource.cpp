#include "FontResource.h"
#include <sstream>



FontResource::FontResource(const unsigned int handle, const std::string & name, const std::string & path)
	:ResourceBase(handle,name,path)
{
	stringstream s;
	s << path << name;

	font.loadFromFile(s.str());
}

FontResource::~FontResource()
{

}
