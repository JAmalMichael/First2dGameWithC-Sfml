#pragma once
#include "bitset"
#include "memory"

const size_t MAX_COMPONENTS = 32;
typedef std::bitset<MAX_COMPONENTS> ComponentMask;
typedef size_t ComponentTypeID;

//generate incremental IDs for component types

inline ComponentTypeID GetUniqueComponentTypeID()
{
	static ComponentTypeID lastID = 0;
	return lastID++;
}

