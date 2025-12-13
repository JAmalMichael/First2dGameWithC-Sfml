#pragma once
#include "Scene.h"
#include "Assetsmanager.h"

class SceneGame : public Scene
{
private:
	sf::Font m_font;
	sf::Text m_label;
	AssetsManager m_assets;

public:
	SceneGame(Game* game);
	void update() override;
	void sInput() override;
	void sRender() override;
	void onEnd() override {};
};