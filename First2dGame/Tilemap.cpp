#include "Tilemap.h"

bool Tilemap::load(
	const sf::Texture& landTex,
	const sf::Texture& waterTex,
	unsigned int tileSize,
	unsigned int width)
{
	m_landtexture = &landTex;
	m_watertexture = &waterTex;

	m_landVertices.setPrimitiveType(sf::Quads);
	m_waterVertices.setPrimitiveType(sf::Quads);


		for (unsigned int x = 0; x < width; ++x)
		{
			bool isLand = (x < 20);

			sf::VertexArray& verts = isLand ? m_landVertices : m_waterVertices;
			verts.resize(verts.getVertexCount() + 4);

			sf::Vertex* quad = &verts[verts.getVertexCount() - 4];

			float tx = static_cast<float>(x * tileSize);
			float ts = static_cast<float>(tileSize);

			quad[0].position = { tx, 0.f };
			quad[1].position = { tx + ts, 0.f };
			quad[2].position = { tx + ts, ts };
			quad[3].position = { tx, ts };


			quad[0].texCoords = { 0, 0 };
			quad[1].texCoords = { (float)tileSize, 0 };
			quad[2].texCoords = { (float)tileSize, (float)tileSize };
			quad[3].texCoords = { 0, (float)tileSize };

		}

		return true;
	}

void Tilemap::draw(sf::RenderTarget& target, sf::RenderStates state) const
{
	state.transform *= getTransform();

	//land
	state.texture = m_landtexture;
	target.draw(m_landVertices, state);

	//water
	state.texture = m_watertexture;
	target.draw(m_waterVertices, state);

}