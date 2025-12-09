#include "SGravity.h"

void SGravity::update(float dt, EntityManager& em, Tilemap*)
{
	for ( auto e : em.GetEntities() )
	{
		if (em.GetComponent<CTransform>(e) && em.GetComponent<CPhysics>(e) && em.GetComponent<CGravity>(e))
		{
			auto* tran = em.GetComponent<CTransform>(e);
			auto* ph = em.GetComponent<CPhysics>(e);
			auto* gr = em.GetComponent<CGravity>(e);

			if (ph->affectedByGravity)
			{
				tran->velocity.y += gr->value * dt;
			}
		}
	}
}