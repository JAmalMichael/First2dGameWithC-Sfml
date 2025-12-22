#include "Tilemap.h"

bool Tilemap::load(
    const sf::Texture& landTex,
    const sf::Texture& waterTex,
    unsigned int tileSize,
    unsigned int width,
    unsigned int height)
{
    m_landtexture = &landTex;
    m_watertexture = &waterTex;

    m_landVertices.setPrimitiveType(sf::Quads);
    m_waterVertices.setPrimitiveType(sf::Quads);

    for (unsigned int y = 0; y < height; ++y)
    {
        for (unsigned int x = 0; x < width; ++x)
        {
            bool isLand = (x < 20);

            sf::VertexArray& verts = isLand ? m_landVertices : m_waterVertices;
            verts.resize(verts.getVertexCount() + 4);

            sf::Vertex* quad = &verts[verts.getVertexCount() - 4];

            float tx = static_cast<float>(x * tileSize);
            float ty = static_cast<float>(y * tileSize);
            float ts = static_cast<float>(tileSize);

            sf::Vector2u texSize = landTex.getSize(); //400 X 400

            quad[0].position = { tx, ty };
            quad[1].position = { tx + ts, ty };
            quad[2].position = { tx + ts, ty + ts };
            quad[3].position = { tx, ty + ts };

            quad[0].texCoords = { 0.f, 0.f };
            quad[1].texCoords = { ts, 0.f };
            quad[2].texCoords = { ts, ts };
            quad[3].texCoords = { 0.f, ts };
        }
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