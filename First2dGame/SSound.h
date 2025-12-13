#pragma once
#include "EntityManager.h"
#include "Assetsmanager.h"
#include "Tilemap.h"
#include "SFML/Audio.hpp"

class SSound
{
	AssetsManager m_assets;
public:
	void update(float dt, EntityManager &em, Tilemap * = nullptr);
};