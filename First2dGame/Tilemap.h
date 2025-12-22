#pragma once
#include "SFML/Graphics.hpp"
#include <vector>


class Tilemap : public sf::Drawable, public sf::Transformable
{
private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates state) const override;

	sf::VertexArray m_landVertices;
	sf::VertexArray m_waterVertices;

	const sf::Texture* m_landtexture;
	const sf::Texture* m_watertexture;

public:
	bool load(
		const sf::Texture& landTex,
		const sf::Texture& waterTex,
		unsigned int tileSize,
		unsigned int width,
		unsigned int height
	);

	//return tile size
	unsigned int tileSize() const { return m_tileSize; }

	//isSolid
	bool isSolid(float wx, float wy) const;

private:
	unsigned int m_tileSize = 32; // Add this member to store tile size
};