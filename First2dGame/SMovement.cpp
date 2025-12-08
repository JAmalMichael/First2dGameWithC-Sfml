#include "SMovement.h"

void SMovement::update(EntityManager& em)
{
	for (auto &e : em.GetEntities())
	{
		auto trans = em.GetComponent<CTransform>(e);
		if (!trans) continue;

		trans->position += trans->velocity;
	}
}