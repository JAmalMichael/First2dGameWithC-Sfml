#pragma once
#include "EntityManager.h"
#include "Tilemap.h"
#include "SFML/Graphics.hpp"

class SGravity
{
	float m_gravity = 900.f;
public:
	SGravity(float g) : m_gravity(g) {}
	void update(float dt, EntityManager& em, Tilemap* = nullptr);
};