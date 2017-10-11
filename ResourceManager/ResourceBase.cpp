#include "ResourceBase.h"





ResourceBase::ResourceBase(const unsigned int handle, const std::string & name, const std::string & path)
{
	// Store the name.
	if (!name.empty())
		m_name = name;

	// Store the path.
	if (!path.empty())
		m_path = path;

	//Store the handle
	m_handle = handle;

	// Create the filename.
	if (!name.empty() && !path.empty())
		m_filename = path + name;

	// Start the reference count.
	m_refCount = 1;
}

ResourceBase::~ResourceBase()
{
}

std::string ResourceBase::GetName()
{
	return m_name;
}

std::string ResourceBase::GetPath()
{
	 return m_path;
}

std::string ResourceBase::GetFilename()
{
	return m_filename;
}

unsigned int ResourceBase::GetHandle()
{
	return m_handle;
}

void ResourceBase::IncRef()
{
	m_refCount++;
}

void ResourceBase::DecRef()
{
	m_refCount--;
}

unsigned long ResourceBase::GetRefCount()
{
	return m_refCount;
}
