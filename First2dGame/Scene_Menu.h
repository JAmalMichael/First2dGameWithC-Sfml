#pragma once
#include "Scene.h"

class SceneMenu : public Scene
{
private:
	sf::Text m_title;
	sf::Font m_font;

public:
	SceneMenu(Game* game);
	void update() override;
	void sInput() override;
	void sRender() override;
	void onEnd() override {};
};
