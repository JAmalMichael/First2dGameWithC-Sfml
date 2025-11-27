#pragma once
#include "Scene.h"

class SceneGame : public Scene
{
private:
	sf::Font m_font;
	sf::Text m_label;

public:
	SceneGame(Game* game);
	void update() override;
	void sInput() override;
	void sRender() override;
	void onEnd() override {};
};