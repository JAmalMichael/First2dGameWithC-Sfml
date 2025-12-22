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
            bool isLand = (( x % 51) < 50);

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

bool Tilemap::isSolid(float wx, float wy) const
{
    int x = static_cast<int>(wx) / m_tileSize;
    int y = static_cast<int>(wy) / m_tileSize;

    if (x < 0 || y < 0) return false;

    // Bounds check using vertex count
    unsigned tilesWide = m_landVertices.getVertexCount() / 4;
    unsigned tilesHigh = tilesWide ? tilesWide : 0;

    unsigned index = (x + y * tilesWide) * 4;

    if (index + 3 >= m_landVertices.getVertexCount())
        return false;

    // If land quad exists here ? solid
    return m_landVertices[index].color.a != 0;
}
