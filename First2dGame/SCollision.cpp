#include "SCollision.h"
#include <iostream>
#include "Tilemap.h"

void SCollision::update(float dt, EntityManager& em, Tilemap* tilemap)
{
	Tilemap* tm = m_tilemap ? m_tilemap : tilemap;
	if (!tm) return;

	const int tileS = tm->tileSize();

	for (auto e : em.GetEntities())
	{
		if (em.GetComponent<CTransform>(e) && em.GetComponent<CBoxCollider>(e))
		{
			auto* trans = em.GetComponent<CTransform>(e);
			auto* cbox = em.GetComponent<CBoxCollider>(e);

			//setting AABB
			sf::FloatRect aabb(trans->position.x - cbox->size.x / 2.f, trans->position.y - cbox->size.y / 2.f, cbox->size.x, cbox->size.y);

			//checking surrounding tiles
			int minTx = static_cast<int>(std::floor(aabb.left / tileS));
			int maxTx = static_cast<int>(std::floor((aabb.left + aabb.width) / tileS));
			int minTy = static_cast<int>(std::floor(aabb.top / tileS));
			int maxTy = static_cast<int>(std::floor((aabb.top + aabb.height) / tileS));

			//basic separation resolution
			for (int ty = minTy; ty < maxTy; ty++)
			{
				for (int tx = minTx; tx < maxTx; tx++)
				{
					float wx = tx * tileS + tileS / 2.f;
					float wy = ty * tileS + tileS / 2.f;

					if (tm->isSolid(wx, wy))
					{
						//computing intersection
						sf::FloatRect tileRect(tx * tileS, ty * tileS, tileS, tileS);
						sf::FloatRect inter;
						if (aabb.intersects(tileRect, inter))
						{
							//pushing the entity out
							if (inter.width < inter.height)
							{
								//move horizontally
								if (aabb.left < tileRect.left) trans->position.x -= inter.width; else trans->position.x += inter.width;
							}
							else {
								//move vertically
								if (aabb.top < tileRect.top) trans->position.y -= inter.height; else trans->position.y += inter.height;

							}
							aabb.left = trans->position.x - cbox->size.x / 2.f;
							aabb.top = trans->position.y - cbox->size.y / 2.f;
						}

					}
				}
			}
		}
	}


}