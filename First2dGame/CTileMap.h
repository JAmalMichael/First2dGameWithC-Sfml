#pragma once
#include <vector>
#include "SFML//Graphics.hpp"


struct CTileMap
{
	sf::VertexArray vertices;
	const sf::Texture* texture = nullptr;
	unsigned width = 0;
	unsigned height = 0;
	unsigned tileSize = 32;

	CTileMap() = default;
};