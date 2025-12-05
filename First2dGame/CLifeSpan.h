#pragma once
//time until some entities are destroyed
#include "SFML/Graphics.hpp"

struct CLifeSpan
{
	float total = 1.f;
	float remaining = 1.f;
	bool destroyOnEnd = true;

	CLifeSpan() {}
	CLifeSpan (float seconds, bool destroy = true )
		: total(seconds), remaining(seconds), destroyOnEnd(destroy) {}
};