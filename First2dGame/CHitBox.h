#pragma once
//hit box for enemy damage
#include "SFML/Graphics.hpp"


struct CHitBox
{
	sf::Vector2f offset{ 0.f, 0.f };
	sf::Vector2f size{ 0.f, 0.f };

	CHitBox() {}
	CHitBox(sf::Vector2f off, sf::Vector2f s)
		: offset(off), size(s) {} ;
};