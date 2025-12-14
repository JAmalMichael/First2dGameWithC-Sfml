#include "SRender.h"

void SRender::render(EntityManager& em, sf::RenderWindow& window)
{

	window.setView(window.getDefaultView());

	for (auto& e : em.GetEntities("background"))
	{
		auto tr = em.GetComponent<CTransform>(e);
		auto sp = em.GetComponent<CSprite>(e);
		if (!tr || !sp) continue;

		sp->sprite.setPosition(tr->position);
		sp->sprite.setRotation(tr->angle);
		window.draw(sp->sprite);
	}

	for (auto e : em.GetEntities())
	{
		if (em.GetComponent<CSprite>(e) && em.GetComponent<CTransform>(e))
		{

			if (e->GetTag() == "background") continue;

			auto* spr = em.GetComponent<CSprite>(e);
			auto* tr = em.GetComponent<CTransform>(e);

			
			spr->sprite.setPosition(tr->position);
			spr->sprite.setRotation(tr->angle);
			window.draw(spr->sprite);
		}
	}
	
}