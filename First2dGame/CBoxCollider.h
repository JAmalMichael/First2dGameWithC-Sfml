#pragma once
// hitbox, collision box
#include "SFML/Graphics.hpp"

struct CBoxCollider
{
	sf::Vector2f size{ 0.f, 0.f };
	bool isTriggered = false;

	CBoxCollider() {};
	CBoxCollider(sf::Vector2f s, bool trigger = false) 
		: size(s), isTriggered(trigger) {};
};