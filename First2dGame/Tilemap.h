#pragma once
#include "SFML/Graphics.hpp"
#include <vector>


class Tilemap : public sf::Drawable, public sf::Transformable
{
private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates state) const override;

	sf::VertexArray m_landVertices;
	sf::VertexArray m_waterVertices;

	const sf::Texture* m_landtexture = nullptr;
	const sf::Texture* m_watertexture = nullptr;

public:
	bool load(
		const sf::Texture& landTex,
		const sf::Texture& waterTex,
		unsigned int tileSize,
		unsigned int width
	);
};