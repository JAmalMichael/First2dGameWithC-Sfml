#pragma once
#include "EntityManager.h"
#include "Tilemap.h"

class SSound
{
public:
	void update(float dt, EntityManager &em, Tilemap * = nullptr);
};