#include "SPhysics.h"

void SPhysics::update(float dt, EntityManager& em, Tilemap*)
{
	for (auto e : em.GetEntities())
	{
		if (em.GetComponent<CTransform>(e) && em.GetComponent<CPhysics>(e))
		{
			auto *t = em.GetComponent<CTransform>(e);
			auto* p = em.GetComponent<CPhysics>(e);
			//adding
			t->velocity += sf::Vector2f(0.f, 0.f) * dt;
			//applying drag
			t->velocity -= t->velocity * p->drag * dt;
			//integrate position
			t->position += t->velocity * dt;
		}
	}
}