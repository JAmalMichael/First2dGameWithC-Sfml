#include "SRender.h"

void SRender::Draw(EntityManager& em, sf::RenderWindow& window)
{
	for (auto & e : em.GetEntities())
	{
		auto trans = em.GetComponent<CTransform>(e);
		auto sh = em.GetComponent<CShape>(e);

		if (!trans || !sh) continue;

		sh->shape.setPosition(trans->position);
		sh->shape.setRotation(trans->angle);
		window.draw(sh->shape);
	}
}