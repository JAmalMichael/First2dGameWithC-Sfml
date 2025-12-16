#pragma once
#include "EntityManager.h"
#include "SFML/Graphics.hpp"

class STileRender
{
	void update(EntityManager& em, sf::RenderWindow& window) 
	{
		for (auto e : em.GetEntities())
		{
			if (!em.GetComponent<CTileMap>(e)) continue;

			auto* tile = em.GetComponent<CTileMap>(e);

			sf::RenderStates states;
			states.texture = tile->texture;

			window.draw(tile->vertices, states);
		}
	}
};