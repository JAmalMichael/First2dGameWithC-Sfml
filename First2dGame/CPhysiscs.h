#pragma once
//friction, drag, weight drag
#include "SFML/Graphics.hpp"

struct CPhysics
{
	sf::Vector2f velocity{ 0.f, 0.f };
	float mass = 1.f;
	float drag = 0.1f;
	bool affectedByGravity = true;
	bool grounded = true;

	CPhysics() = default;
};