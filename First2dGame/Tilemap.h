#pragma once


class Tilemap
{
	virtual bool isSolid(float worldX, float worldY) const = 0;
	virtual int tileSize() const = 0;
	virtual ~Tilemap() = default;
};