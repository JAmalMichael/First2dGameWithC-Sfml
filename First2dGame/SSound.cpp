#include "SSound.h"

void SSound::update(float dt, EntityManager& em, Tilemap*)
{
	for (auto e : em.GetEntities())
	{
		if (em.GetComponent<CSound>(e))
		{
			auto* sd = em.GetComponent<CSound>(e);
			sf::Sound sound;
			sound.setBuffer(m_assets.GetSound("slash"));
			sound.play();
		}
	}
}