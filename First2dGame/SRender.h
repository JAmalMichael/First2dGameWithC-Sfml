#pragma once
#include "EntityManager.h"
#include "SFML/Graphics.hpp"

class SRender
{
public:
	void Draw(EntityManager& em, sf::RenderWindow &window);
};