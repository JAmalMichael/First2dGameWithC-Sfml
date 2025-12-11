#pragma once
#include "EntityManager.h"
#include "Tilemap.h"

class SAnimation
{
public:
	void update(float dt, EntityManager& em, Tilemap* = nullptr);
};