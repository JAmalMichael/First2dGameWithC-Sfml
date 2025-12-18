#pragma once
#include "SFML/Graphics.hpp"
#include <vector>


class Tilemap : public sf::Drawable, sf::Transformable
{
private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates state) const override;

	sf::VertexArray m_vertices;
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
};