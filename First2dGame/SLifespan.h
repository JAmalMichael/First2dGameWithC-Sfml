#pragma once
#include "EntityManager.h"
#include "Tilemap.h"

class SLifespan
{
public:
	void update(float dt, EntityManager& em, Tilemap* = nullptr);
};