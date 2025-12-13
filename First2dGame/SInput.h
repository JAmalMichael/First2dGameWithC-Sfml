#pragma once
//players movement
#include "EntityManager.h"
#include "SFML/Graphics.hpp"

class SInput
{
public:
	void update(float dt, EntityManager& em);
};