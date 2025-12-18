#pragma once
#include "Scene.h"
#include "Assetsmanager.h"
#include "EntityManager.h"
#include "SRender.h"
#include "STileRender.h"
#include "Tilemap.h"

class SceneGame : public Scene
{
private:
	sf::Font m_font;
	sf::Text m_label;
	AssetsManager m_assets;
	EntityManager m_entities;
	SRender m_render;
	STileRender t_render;
	Tilemap tileMap;
	

public:
	SceneGame(Game* game);
	void update() override;
	void sInput() override;
	void sRender() override;
	void onEnd() override {};
	void onEnter() override;
	void SpawnPlayer();
	void SpawnEnemy();
	void AddbackGround();
	void AddTileMap();
};