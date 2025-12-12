#pragma once
#include "EntityManager.h"
#include "Tilemap.h"

class SGameState
{
	void update(float dt, EntityManager& em, Tilemap* = nullptr);
};