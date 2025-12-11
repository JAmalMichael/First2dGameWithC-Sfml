#pragma once


class Tilemap
{
public:
	virtual bool isSolid(float worldX, float worldY) const = 0;
	virtual int tileSize() const = 0;
	virtual ~Tilemap() = default;
};