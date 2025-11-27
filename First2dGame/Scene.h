#pragma once
#include <SFML/Graphics.hpp>

class Game;

class Scene
{
protected:
	bool m_paused = false;
	Game* m_game;

public:
	Scene(Game* game) : m_game(game) {}
	virtual ~Scene() {}

	virtual void update() = 0;
	virtual void sInput() = 0;
	virtual void sRender() = 0;
	virtual void onEnd() = 0;


	void setPaused(bool paused) { m_paused = paused; }
};