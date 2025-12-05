#pragma once
//frame index, frame loop, speed
#include "SFML/Graphics.hpp"

struct CAnimation
{
	sf::Texture* texture = nullptr;
	int frameCount = 1;
	int currentFrame = 0;
	float frameTime = 0.1f;
	float elapsed = 0.f;
	bool repeat = true;

	CAnimation() {};
	CAnimation(sf::Texture *tex, int frames, float speed, bool loop = true )
		: frameCount(frames), frameTime(speed), texture(tex), repeat(loop) {}
};