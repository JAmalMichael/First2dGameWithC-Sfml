#pragma once
#include "EntityManager.h"
#include "Tilemap.h"
#include "SFML/Audio.hpp"

class SSound
{
public:
	void update(float dt, EntityManager &em, Tilemap * = nullptr);
};