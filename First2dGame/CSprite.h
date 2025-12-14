#pragma once
//texture, spritesheet, origin
#include "SFML/Graphics.hpp"

struct CSprite
{
	sf::Sprite sprite;

	CSprite() = default;
	CSprite(const sf::Texture& tex) {
		sprite.setTexture(tex);
		sprite.setOrigin(
			tex.getSize().x / 2.f,
			tex.getSize().y / 2.f
		);
	}
};