#pragma once
#include "Scene.h"

class SceneGameOver : public Scene

{
private:
	sf::Font m_font;
	sf::Text m_label;
public:

	SceneGameOver(Game* game);
	void sInput() override;
	void update() override;
	void sRender() override;
	void onEnd() override {}

};