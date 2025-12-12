#include "SSound.h"

void SSound::update(float dt, EntityManager& em, Tilemap*)
{
	for (auto e : em.GetEntities())
	{
		if (em.GetComponent<CSound>(e))
		{
			auto* sd = em.GetComponent<CSound>(e);
			//attach buffer
		}
	}
}