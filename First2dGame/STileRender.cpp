#include "STileRender.h"

void STileRender::render(EntityManager& em, sf::RenderWindow& window)
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