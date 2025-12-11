#pragma once
#include "EntityManager.h"
#include "Tilemap.h"

class SHitbox
{
public:
	void update(float dt, EntityManager& em, Tilemap* = nullptr);
};