#include "SAnimation.h"

void SAnimation::update(float dt, EntityManager &em, Tilemap*)
{
	for ( auto e : em.GetEntities())
	{
		if (em.GetComponent<CAnimation>(e) && em.GetComponent<CSprite>(e) && em.GetComponent<CTransform>(e))
		{
			auto* anim = em.GetComponent<CAnimation>(e);
			auto* spr = em.GetComponent<CSprite>(e);
			if (!anim->texture) continue;
			anim->elapsed += dt;
			if (anim->elapsed > anim->frameTime)
			{
				anim->elapsed = 0.f;
				anim->currentFrame = (anim->currentFrame + 1) % anim->frameCount;
				int fw = anim->texture->getSize().x / anim->frameCount;
				int fh = anim->texture->getSize().y;
				sf::IntRect rect(anim->currentFrame * fw, 0, fw, fh);
				spr->sprite.setTexture(*anim->texture);
				spr->sprite.setTextureRect(rect);
			}
		}
	}
}