#pragma once
#include "EntityManager.h"
#include "SFML/Graphics.hpp"

class STileRender
{
public:
	void render(EntityManager& em, sf::RenderWindow& window);
};