#include "SGameState.h"
#include <iostream>

void SGameState::update(float dt, EntityManager& em, Tilemap*)
{
	for (auto e : em.GetEntities())
	{
		if (em.GetComponent<CState>(e) && em.GetComponent<CPhysics>(e))
		{
			auto* st = em.GetComponent<CState>(e);
			auto* ph = em.GetComponent<CPhysics>(e);

			//if velocity in non zero, start running
			if (std::abs(ph->mass) > 0.f)
			{
				//start running
			
			}
		}
	}
}