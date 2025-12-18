#include "Tilemap.h"

bool Tilemap::load(const sf::Texture& landTex,
	const sf::Texture& waterTex,
	unsigned int tileSize,
	unsigned int width,
	unsigned int height)
{
	m_landtexture = &landTex;
	m_watertexture = &waterTex;

	m_vertices.setPrimitiveType(sf::Quads);
	m_vertices.resize(width * height * 4);

	for (unsigned int x = 0; x < width; ++x)
	{
		for (unsigned int y = 0; y < height; ++y)
		{
			bool isLand = (x < 20);

			sf::Vertex* quad = &m_vertices[(x + y * width) * 4];

			quad[0].position = { x * float(tileSize), y * float(tileSize) };
			quad[1].position = { (x + 1) * float(tileSize), y * float(tileSize) };
			quad[2].position = { (x + 1) * float(tileSize), (y + 1) * float(tileSize) };
			quad[3].position = { x * float(tileSize), (y + 1) * float(tileSize) };

			quad[0].texCoords = { 0,0 };
			quad[1].texCoords = { float(tileSize), 0 };
			quad[2].texCoords = { float(tileSize), float(tileSize)};
			quad[3].texCoords = { 0, float(tileSize)};

			sf::Color tint = isLand ? sf::Color::White : sf::Color(150, 150, 255);
			quad[0].color = quad[1].color = quad[2].color = quad[3].color = tint;
		}
	}

	return true;
}

void Tilemap::draw(sf::RenderTarget& target, sf::RenderStates state) const
{
	state.transform *= getTransform();

	//land
	state.texture = m_landtexture;
	target.draw(m_vertices, state);

	//water
	state.texture = m_watertexture;
	target.draw(m_vertices, state);

}