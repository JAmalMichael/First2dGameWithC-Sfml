#pragma once
//health and lives
#include "SFML/Graphics.hpp"

struct CHealth
{
	int hp = 1;
	int maxHp = 1;

	CHealth() {}
	CHealth(int max) : hp(max), maxHp(max) {}
};