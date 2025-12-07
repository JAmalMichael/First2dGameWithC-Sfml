#pragma once
#include <vector>
#include <map>
#include <memory>
#include <string>
#include "Entity.h"
#include "ComponentPool.h"
#include "CAnimation.h"
#include "CBoxCollider.h"
#include "CGravity.h"
#include "CHealth.h"
#include "CHitBox.h"
#include "CInput.h"
#include "CLifeSpan.h"
#include "CPhysiscs.h"
#include "CScore.h"
#include "CShape.h"
#include "CSound.h"
#include "CSprite.h"
#include "CState.h"
#include "CTag.h"
#include "CTransform.h"


class EntityManager
{
	std::vector<std::shared_ptr<Entity>> m_entities;
	std::map<std::string, std::vector<std::shared_ptr<Entity>>> m_entityMap;

	size_t m_nextID = 0;

	//component pools of all components
	ComponentPool<CTransform> m_transform;
	ComponentPool<CTag> m_tag;
	ComponentPool<CState> m_state;
	ComponentPool<CSprite> m_sprite;
	ComponentPool<CSound> m_sound;
	ComponentPool<CShape> m_shape;
	ComponentPool<CScore> m_score;
	ComponentPool<CPhysics> m_physics;
	ComponentPool<CLifeSpan> m_lifespan;
	ComponentPool<CInput> m_input;
	ComponentPool<CHitBox> m_hitbox;
	ComponentPool<CHealth> m_health;
	ComponentPool<CGravity> m_gravity;
	ComponentPool<CBoxCollider> m_boxcollider;
	ComponentPool<CAnimation> m_animation;
	
public:
	std::shared_ptr<Entity> AddEntity(const std::string& tag);

	void update();
	std::vector<std::shared_ptr<Entity>>& GetEntities();
	std::vector<std::shared_ptr<Entity>>& GetEntities(const std::string& tag);

	template<class T, class ...Args>
	T* AddComponent(std::shared_ptr<Entity> e, Args&&...args);

	template<class T>
	T* GetComponent(std::shared_ptr<Entity> e);
};