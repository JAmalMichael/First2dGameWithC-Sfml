#pragma once
#include <vector>
#include "SFML//Graphics.hpp"


struct CTileMap
{
	unsigned width = 0;
	unsigned height = 0;
	unsigned tileSize = 32;
	const sf::Texture* texture = nullptr;
	sf::VertexArray vertices;

	CTileMap()
	{
		vertices.setPrimitiveType(sf::Quads);
	}
};