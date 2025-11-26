#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class GameObj
{
private:
	sf::RenderWindow renderer;

public:
	bool isrunning();
	void playerInit();
	void enemyInit();
};
