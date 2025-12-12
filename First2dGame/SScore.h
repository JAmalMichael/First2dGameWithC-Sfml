#pragma once
#include "EntityManager.h"
#include "Tilemap.h"

class SScore
{
public:
	int totalScore = 0;
	void update(float dt, EntityManager& em, Tilemap* = nullptr);
};