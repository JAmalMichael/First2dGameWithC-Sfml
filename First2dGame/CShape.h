#pragma once
#include "Typesdef.h"
#include "SFML/Graphics.hpp"


struct CShape
{
	sf::CircleShape shape;

	CShape() {};
	CShape(float radius, int points, sf::Color fill, sf::Color outline, float thickness)
		:shape(radius, points)
	{
		shape.setFillColor(fill);
		shape.setOutlineColor(outline);
		shape.setOutlineThickness(thickness);
		shape.setOrigin(radius, radius);
	};
};
