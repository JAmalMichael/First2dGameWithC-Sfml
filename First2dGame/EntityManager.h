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
#include "CPhysiscs.h"  //cphysiscs
#include "CScore.h"
#include "CShape.h"
#include "CSound.h"
#include "CSprite.h"
#include "CState.h"
#include "CTag.h"
#include "CTransform.h"
#include "CTileMap.h"


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
	ComponentPool<CTileMap> m_tilemap;
	
public:
	//add entities
	std::shared_ptr<Entity> AddEntity(const std::string& tag)
	{
		auto e = std::make_shared<Entity>(tag, m_nextID++);
		m_entities.push_back(e);
		m_entityMap[tag].push_back(e);
		return e;
	};

	//update
	void update()
	{
		m_entities.erase(
			std::remove_if(m_entities.begin(), m_entities.end(),
				[](auto& e) {return !e->isActive(); }),
			m_entities.end()
		);
	};

	//Getentities
	std::vector<std::shared_ptr<Entity>>& GetEntities()
	{
		return m_entities;
	};

	//get entities with a tag
	std::vector<std::shared_ptr<Entity>>& GetEntities(const std::string& tag)
	{
		return m_entityMap[tag];
	};


	//Add components
	template<class T, class ...Args>
	T* AddComponent(std::shared_ptr<Entity> e, Args&&...args)
	{
		const ComponentTypeID typeID = GetUniqueComponentTypeID();
		e->m_mask.set(typeID);

		if constexpr (std::is_same<T, CTransform>::value)
			return new (m_transform.Add(e->m_id)) T(std::forward<Args>(args)...);
		if constexpr (std::is_same<T, CTag>::value)
			return new (m_tag.Add(e->m_id)) T(std::forward<Args>(args)...);
		if constexpr (std::is_same<T, CState>::value)
			return new (m_state.Add(e->m_id)) T(std::forward<Args>(args)...);
		if constexpr (std::is_same<T, CSprite>::value)
			return new (m_sprite.Add(e->m_id)) T(std::forward<Args>(args)...);
		if constexpr (std::is_same<T, CSound>::value)
			return new (m_sound.Add(e->m_id)) T(std::forward<Args>(args)...);
		if constexpr (std::is_same<T, CShape>::value)
			return new (m_shape.Add(e->m_id)) T(std::forward<Args>(args)...);
		if constexpr (std::is_same<T, CScore>::value)
			return new (m_score.Add(e->m_id)) T(std::forward<Args>(args)...);
		if constexpr (std::is_same<T, CPhysics>::value)
			return new (m_physics.Add(e->m_id)) T(std::forward<Args>(args)...);
		if constexpr (std::is_same<T, CLifeSpan>::value)
			return new (m_lifespan.Add(e->m_id)) T(std::forward<Args>(args)...);
		if constexpr (std::is_same<T, CInput>::value)
			return new (m_input.Add(e->m_id)) T(std::forward<Args>(args)...);
		if constexpr (std::is_same<T, CHitBox>::value)
			return new (m_hitbox.Add(e->m_id)) T(std::forward<Args>(args)...);
		if constexpr (std::is_same<T, CHealth>::value)
			return new (m_health.Add(e->m_id)) T(std::forward<Args>(args)...);
		if constexpr (std::is_same<T, CGravity>::value)
			return new (m_gravity.Add(e->m_id)) T(std::forward<Args>(args)...);
		if constexpr (std::is_same<T, CBoxCollider>::value)
			return new (m_boxcollider.Add(e->m_id)) T(std::forward<Args>(args)...);
		if constexpr (std::is_same<T, CAnimation>::value)
			return new (m_animation.Add(e->m_id)) T(std::forward<Args>(args)...);
		if constexpr (std::is_same<T, CTileMap>::value)
			return new (m_animation.Add(e->m_id)) T(std::forward<Args>(args)...);
		return nullptr;
	};

	//get components
	template<class T>
	T* GetComponent(std::shared_ptr<Entity> e)
	{
		if constexpr (std::is_same<T, CAnimation>::value)
			return m_animation.Get(e->m_id);
		if constexpr (std::is_same<T, CBoxCollider>::value)
			return m_boxcollider.Get(e->m_id);
		if constexpr (std::is_same<T, CGravity>::value)
			return m_gravity.Get(e->m_id);
		if constexpr (std::is_same<T, CHealth>::value)
			return m_health.Get(e->m_id);
		if constexpr (std::is_same<T, CHitBox>::value)
			return m_hitbox.Get(e->m_id);
		if constexpr (std::is_same<T, CInput>::value)
			return m_input.Get(e->m_id);
		if constexpr (std::is_same<T, CLifeSpan>::value)
			return m_lifespan.Get(e->m_id);
		if constexpr (std::is_same<T, CPhysics>::value)
			return m_physics.Get(e->m_id);
		if constexpr (std::is_same<T, CScore>::value)
			return m_score.Get(e->m_id);
		if constexpr (std::is_same<T, CShape>::value)
			return m_shape.Get(e->m_id);
		if constexpr (std::is_same<T, CSound>::value)
			return m_sound.Get(e->m_id);
		if constexpr (std::is_same<T, CSprite>::value)
			return m_sprite.Get(e->m_id);
		if constexpr (std::is_same<T, CState>::value)
			return m_state.Get(e->m_id);
		if constexpr (std::is_same<T, CTag>::value)
			return m_tag.Get(e->m_id);
		if constexpr (std::is_same<T, CTransform>::value)
			return m_transform.Get(e->m_id);
		if constexpr (std::is_same<T, CTileMap>::value)
			return m_tilemap.Get(e->m_id);
		return nullptr;
	};
};