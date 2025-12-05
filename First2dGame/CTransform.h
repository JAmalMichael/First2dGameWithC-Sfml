//position, velocity, previous position, scale, rotation
#pragma once
#include "Typesdef.h"
#include "SFML/Graphics.hpp"

struct CTransform {
	sf::Vector2f position;
	sf::Vector2f velocity;
	sf::Vector2f scale;
	float angle = 0.f;

	CTransform() = default;
	CTransform(const sf::Vector2f &pos,const sf::Vector2f &vel, const sf::Vector2f &sca, float ang) :
		position(pos), velocity(vel), angle(ang), scale(sca) {}
};