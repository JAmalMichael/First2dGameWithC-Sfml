#include "SHitbox.h"

void SHitbox::update(float dt, EntityManager& em, Tilemap*)
{
	auto& vec = em.GetEntities();

	for (size_t i = 0; i < vec.size(); ++i)
	{
		auto a = vec[i];
		if (!(em.GetComponent<CHitBox>(a) && em.GetComponent<CTransform>(a))) continue;
		{
			auto* hbox = em.GetComponent<CHitBox>(a);
			auto* trans = em.GetComponent<CTransform>(a);
			sf::FloatRect rectA(trans->position + hbox->offset, hbox->size);

			for (size_t j = i + 1; j < vec.size(); ++j) {
				auto b = vec[j];
				if (!(em.GetComponent<CHitBox>(b) && em.GetComponent<CTransform>(b))) continue;
				auto* hbox = em.GetComponent<CHitBox>(b);
				auto* trans = em.GetComponent<CTransform>(b);
				sf::FloatRect rectB(trans->position + hbox->offset, hbox->size);


				if (rectA.intersects(rectB))
				{
					//trigger events like damage, bounce, etc
					if (em.GetComponent<CHealth>(a) && em.GetComponent<CHealth>(b))
					{
						auto* hp = em.GetComponent<CHealth>(a);
						hp->hp -= 1;
					}
				}
		}
	}
}