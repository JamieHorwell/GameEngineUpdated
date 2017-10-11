#pragma once
#include <string>
#include <vector>
#include <stack>
using namespace std;
class ResourceBase
{
public:
	ResourceBase(const unsigned int handle, const std::string& name, const std::string& path = "../Resources/");
	~ResourceBase();

	std::string GetName();
	std::string GetPath();
	std::string GetFilename();
	unsigned int GetHandle();

	void IncRef();
	void DecRef();
	unsigned long GetRefCount();

protected:
	std::string	m_name;
	std::string	m_path;
	std::string	m_filename;
	unsigned int m_handle;
	unsigned long m_refCount;
};

