#pragma once
//gravity strength and acceleration

struct CGravity
{
	float value = 900.f;
	CGravity() {};
	CGravity(float g) : value(g) {}
};