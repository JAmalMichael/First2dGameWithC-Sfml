#include "SLifespan.h"
#include "iostream"
#include "vector"

void SLifespan::update(float dt, EntityManager& em, Tilemap*)
{
	std::vector<std::shared_ptr<Entity>> toremove;

	for (auto e : em.GetEntities())
	{
		if (em.GetComponent<CLifeSpan>(e))
		{
			auto* ls = em.GetComponent<CLifeSpan>(e);
			ls->remaining -= dt;

			if (ls->remaining < 0.f && ls->destroyOnEnd)
			{
				toremove.push_back(e);
			}
		}
	}

	//removal for vector map
	for ( auto &ent : toremove)
	{
		ent->Destroy();
		std::cout << "Lifespan exceeded for entity: " << ent->GetID() << std::endl;
	}
}