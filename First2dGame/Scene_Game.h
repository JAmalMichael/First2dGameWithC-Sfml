#pragma once
#include "Scene.h"
#include "Assetsmanager.h"
#include "EntityManager.h"
#include "SRender.h"
#include "STileRender.h"
#include "Tilemap.h"
#include "SPhysics.h"
#include "SMovement.h"
#include "SAnimation.h"
#include "SCollision.h"

class SceneGame : public Scene
{
private:
	sf::Font m_font;
	sf::Text m_label;
	AssetsManager m_assets;
	EntityManager m_entities;
	SRender m_render;
	STileRender t_render;
	sf::Texture landTexture;
	sf::Texture waterTexture;
	Tilemap m_tileMap;
	SMovement m_movement;
	SPhysics m_physics;
	SAnimation m_animation;
	SCollision m_collison;
	

public:
	SceneGame(Game* game);
	void update(float dt) override;
	void sInput() override;
	void sRender() override;
	void onEnd() override {};
	void onEnter() override;
	void SpawnPlayer();
	void SpawnEnemy();
	void AddbackGround();
	void AddTileMap();
	void PlayerMovement();
};