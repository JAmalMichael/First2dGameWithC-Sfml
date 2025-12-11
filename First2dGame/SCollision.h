#pragma once
#include "EntityManager.h"
#include "Tilemap.h"

class SCollision
{
private:
	Tilemap* m_tilemap{ nullptr };
public:
	SCollision(Tilemap* tilemap = nullptr): m_tilemap(tilemap) {};
	void update(float dt, EntityManager& em, Tilemap* = nullptr);
};