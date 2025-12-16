#include "STileRender.h"

void STileRender::render(EntityManager& em, sf::RenderWindow& window)
{

	auto tiles = em.GetEntities("tile1");

	for (auto e : em.GetEntities())
	{
		if (!em.GetComponent<CTileMap>(e)) continue;

		auto* tile = em.GetComponent<CTileMap>(e);
		if (!tile || !tile->texture) continue;

		sf::RenderStates states;
		states.texture = tile->texture;

		window.draw(tile->vertices, states);
	}
}