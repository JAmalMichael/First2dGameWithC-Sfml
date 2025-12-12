#include "SScore.h"

void SScore::update(float dt, EntityManager& em, Tilemap*)
{
	totalScore = 0;
	for (auto e : em.GetEntities())
	{
		if (em.GetComponent<CScore>(e))
		{
			auto* sc = em.GetComponent<CScore>(e);
			totalScore += sc->value;
		}
	}
}