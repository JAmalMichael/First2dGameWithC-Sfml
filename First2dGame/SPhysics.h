#pragma once
#include "EntityManager.h"
#include "SFML/Graphics.hpp"
//#include "System.h"
#include "Tilemap.h"


class SPhysics
{
public:
	void update(float dt, EntityManager &em, Tilemap* = nullptr);
};