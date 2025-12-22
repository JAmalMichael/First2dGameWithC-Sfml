#pragma once
//frame index, frame loop, speed
#include "SFML/Graphics.hpp"
#include <vector>

struct CAnimation
{
	sf::Texture* texture = nullptr;
	std::vector<sf::IntRect> m_frames;
	int frameCount = 1;
	int currentFrame = 0;
	float frameTime = 0.12f;
	float elapsed = 0.f;
	bool repeat = true;

	CAnimation() {};
	CAnimation(sf::Texture *tex, int frames, float speed, bool loop = true )
		: frameCount(frames), frameTime(speed), texture(tex), repeat(loop) {}
};