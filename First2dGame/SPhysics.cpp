#include "SPhysics.h"

void SPhysics::update(float dt, EntityManager& em, Tilemap*)
{
    const float gravity = 980.f; 

    for (auto e : em.GetEntities())
    {
        auto phs = em.GetComponent<CPhysics>(e);
        auto trs = em.GetComponent<CTransform>(e);
        if (!phs || !trs) continue;

        // Apply gravity
        if (phs->affectedByGravity && !phs->grounded)
        {
            phs->velocity.y += gravity * dt;
        }

        // Apply drag
        phs->velocity.x *= (1.f - phs->drag);

        // Update position
        trs->position += phs->velocity * dt;

        // Simple ground collision check
        if (trs->position.y >= 670.f) // ground level
        {
            trs->position.y = 670.f;
            phs->velocity.y = 0.f;
            phs->grounded = true;
        }
    }
}
