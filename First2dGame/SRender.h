#pragma once
#include "EntityManager.h"
#include "SFML/Graphics.hpp"

class SRender
{
public:
	void render(EntityManager& em, sf::RenderWindow &window);
};