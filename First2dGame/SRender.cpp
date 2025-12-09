#include "SRender.h"

void SRender::render(EntityManager& em, sf::RenderWindow& window)
{
	for (auto e : em.GetEntities())
	{
		if (em.GetComponent<CSprite>(e) && em.GetComponent<CTransform>(e))
		{
			auto* spr = em.GetComponent<CSprite>(e);
			auto* tr = em.GetComponent<CTransform>(e);

			spr->sprite.setPosition(tr->position);
			spr->sprite.setScale(tr->scale);
			spr->sprite.setRotation(tr->angle);
			window.draw(spr->sprite);
		}
	}
	
}