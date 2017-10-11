#pragma once

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <stack>
#include <iostream>
template <class T>


/*CLASS NOT WRITTEN BY ME*/


class ResourceManager
{
public:
	
	ResourceManager(void(*CreateResource)(T **resource, const unsigned int handle, const std::string &name, const std::string &path))
	{
		m_list = new std::vector<T*>;

		CreateResource = CreateResourceFunction;
	}

	ResourceManager() {
		m_list = new std::vector<T*>;
	}

	
	~ResourceManager()
	{
	}

	//template<class T>
	std::vector<T*>* getList()
	{
		return m_list;
	}

	//template<class T>
	T * GetElement(const std::string & name, const std::string & path = "../Resources/")
	{
		
		// Ensure the name and path are valid, and the list is valid and not empty.
		if (name.empty() || path.empty() || m_list == NULL || m_list->empty()) {
			std::cout << m_list->size();
			return NULL;
		}
			

		//// Iterate the list looking for the specified resource.
		for (std::vector<T*>::iterator i = m_list->begin();
		i != m_list->end(); i++)
		{
			if ((*i) != NULL)
				if ((*i)->GetName() == name)
					if ((*i)->GetPath() == path)
						
						return (*i);
		}

		// Return NULL if the resource was not found.
		return NULL;
	}

	//template<class T>
	void EmptyList()
	{
		for (std::vector<T*>::iterator i = m_list->begin();
		i != m_list->end(); i++)
			if (*i) { delete *i };
		*i = NULL;


		while (!m_handles.empty())
			m_handles.pop();

		//use vector swapping trick to release previously used memory.
		m_list->clear();
		m_list->swap(*m_list);
	}

	//template<class T>
	void Remove(const unsigned int handle)
	{
		// Ensure the resource to be removed and the list is valid.
		if (handle < 0 || m_list == NULL || handle >= m_list->size() || (*m_list)[handle] == NULL)
			return;

		T * resource = (*m_list)[handle];

		// Decrement the resource's reference count.
		resource->DecRef();

		// If the resource is no longer being used then destroy it.
		if (resource->GetRefCount() == 0)
		{
			//add the handle to the stack of free handles
			m_handles.push(handle);
			//delete the resource
			delete resource;
			//mark the slot as NULL
			(*m_list)[handle] = NULL;
		}
	}

	//template<class T>
	unsigned int ResourceManager<T>::Add(const std::string & name, const std::string & path = "../Resources/")
	{
		// Ensure the list, the resource name, and its path are valid.
		if (m_list == NULL || name.empty() || path.empty())
			return -1;

		// If the element already exists, then return a pointer to it.
		T *element = GetElement(name, path);
		if (element != NULL)
		{
			element->IncRef();
			return element->GetHandle();
		}


		//Check if there is an available handle. If not, use new handle.
		bool handleAvailable = !m_handles.empty();
		unsigned int handle;
		if (handleAvailable)
		{
			handle = m_handles.top();
			m_handles.pop();
		}
		else handle = m_list->size();

		// Create the resource, preferably through the application specific
		// function if it is available.
		T *resource = NULL;
		if (CreateResource != NULL)
			CreateResource(&resource, handle, name, path);
		else
			resource = new T(handle, name, path);


		//Add the resource to the manager. If there is an available handle, then 
		//we store the resource using the handle. Otherwise we add it to the vector.
		if (handleAvailable)
			(*m_list)[handle] = resource;
		else
			m_list->push_back(resource);

		//return the handle
		return handle;
	}





private:
	std::stack<unsigned int> m_handles;
	std::vector<T*> *m_list;	//List of pointers to resources
	void(*CreateResource)(T **resource, const unsigned int handle, const std::string& name, const std::string& path); // Application specific resource creation.
};

