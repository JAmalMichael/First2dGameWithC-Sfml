//position, velocity, previous position, scale, rotation
#pragma once
#include "Typesdef.h"
#include "SFML/Graphics.hpp"

struct CTransform {
	sf::Vector2f position;
	sf::Vector2f velocity;
	float angle = 0.f;

	CTransform() {};
	CTransform(const sf::Vector2f &pos,const sf::Vector2f &vel, float ang) :
		position(pos), velocity(vel), angle(ang) {}
};