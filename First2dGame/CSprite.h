#pragma once
//texture, spritesheet, origin
#include "SFML/Graphics.hpp"

struct CSprite
{
	sf::Sprite sprite;
	sf::Texture *texture = nullptr;

	CSprite() {};
	CSprite(sf::Texture *tex) : texture(tex) {
		sprite.setTexture(*tex);
	}
};