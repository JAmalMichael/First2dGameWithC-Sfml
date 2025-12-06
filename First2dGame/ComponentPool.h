#pragma once
//creates a componenet array for each component
#include <vector>
#include <memory>

template <class T>
class ComponentPool
{
	std::vector<std::shared_ptr<T>> m_data;


public:
	ComponentPool() : m_data(1000) {};

	T* Add(size_t entityID)
	{
		m_data[entityID] = std::make_shared<T>();
		return m_data[entityID].get();
	}

	T* Get(size_t entityID)
	{
		return m_data[entityID].get();
	}

	void Remove(size_t entityID)
	{
		m_data[entityID].reset();
	}
};