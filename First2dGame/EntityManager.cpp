//#include "EntityManager.h"

//std::shared_ptr<Entity> EntityManager::AddEntity(const std::string& tag)
//{
//	auto e = std::make_shared<Entity>(tag, m_nextID++);
//	m_entities.push_back(e);
//	m_entityMap[tag].push_back(e);
//	return e;
//}

//void EntityManager::update() {
//	m_entities.erase(
//		std::remove_if(m_entities.begin(), m_entities.end(),
//			[](auto& e) {return !e->isActive(); }),
//		m_entities.end()
//	);
//}

//std::vector<std::shared_ptr<Entity>>& EntityManager::GetEntities()
//{
//	return m_entities;
//}

//std::vector<std::shared_ptr<Entity>>& EntityManager::GetEntities(const std::string & tag)
//{
//	return m_entityMap[tag];
//}

//template<class T, class ...Args>
//T* EntityManager::AddComponent(std::shared_ptr<Entity> e, Args&&... args)
//{
//	const ComponentTypeID typeID = GetUniqueComponentTypeID();
//	e->m_mask.set(typeID);
//
//	if constexpr (std::is_same<T, CTransform>::value)
//		return new (m_transform.Add(e->m_id)) T(std::forward<Args>(args)...);
//	if constexpr (std::is_same<T, CTag>::value)
//		return new (m_tag.Add(e->m_id)) T(std::forward<Args>(args)...);
//	if constexpr (std::is_same<T, CState>::value)
//		return new (m_state.Add(e->m_id)) T(std::forward<Args>(args)...);
//	if constexpr (std::is_same<T, CSprite>::value)
//		return new (m_sprite.Add(e->m_id)) T(std::forward<Args>(args)...);
//	if constexpr (std::is_same<T, CSound>::value)
//		return new (m_sound.Add(e->m_id)) T(std::forward<Args>(args)...);
//	if constexpr (std::is_same<T, CShape>::value)
//		return new (m_shape.Add(e->m_id)) T(std::forward<Args>(args)...);
//	if constexpr (std::is_same<T, CScore>::value)
//		return new (m_score.Add(e->m_id)) T(std::forward<Args>(args)...);
//	if constexpr (std::is_same<T, CPhysics>::value)
//		return new (m_physics.Add(e->m_id)) T(std::forward<Args>(args)...);
//	if constexpr (std::is_same<T, CLifeSpan>::value)
//		return new (m_lifespan.Add(e->m_id)) T(std::forward<Args>(args)...);
//	if constexpr (std::is_same<T, CInput>::value)
//		return new (m_input.Add(e->m_id)) T(std::forward<Args>(args)...);
//	if constexpr (std::is_same<T, CHitBox>::value)
//		return new (m_hitbox.Add(e->m_id)) T(std::forward<Args>(args)...);
//	if constexpr (std::is_same<T, CHealth>::value)
//		return new (m_health.Add(e->m_id)) T(std::forward<Args>(args)...);
//	if constexpr (std::is_same<T, CGravity>::value)
//		return new (m_gravity.Add(e->m_id)) T(std::forward<Args>(args)...);
//	if constexpr (std::is_same<T, CBoxCollider>::value)
//		return new (m_boxcollider.Add(e->m_id)) T(std::forward<Args>(args)...);
//	if constexpr (std::is_same<T, CAnimation>::value)
//		return new (m_animation.Add(e->m_id)) T(std::forward<Args>(args)...);
//
//	return nullptr;
//}


//template<class T>
//T* EntityManager::GetComponent(std::shared_ptr<Entity> e)
//{
//	if constexpr (std::is_same<T, CAnimation>::Value)
//		return m_animation.Get(e->m_id);
//	if constexpr (std::is_same<T, CBoxCollider>::Value)
//		return m_boxcollider.Get(e->m_id);
//	if constexpr (std::is_same<T, CGravity>::Value)
//		return m_gravity.Get(e->m_id);
//	if constexpr (std::is_same<T, CHealth>::Value)
//		return m_health.Get(e->m_id);
//	if constexpr (std::is_same<T, CHitBox>::Value)
//		return m_hitbox.Get(e->m_id);
//	if constexpr (std::is_same<T, CInput>::Value)
//		return m_input.Get(e->m_id);
//	if constexpr (std::is_same<T, CAnimation>::Value)
//		return m_animation.Get(e->m_id);
//	if constexpr (std::is_same<T, CLifeSpan>::Value)
//		return m_lifespan.Get(e->m_id);
//	if constexpr (std::is_same<T, CPhysics>::Value)
//		return m_physics.Get(e->m_id);
//	if constexpr (std::is_same<T, CScore>::Value)
//		return m_score.Get(e->m_id);
//	if constexpr (std::is_same<T, CShape>::Value)
//		return m_shape.Get(e->m_id);
//	if constexpr (std::is_same<T, CAnimation>::Value)
//		return m_animation.Get(e->m_id);
//	if constexpr (std::is_same<T, CSound>::Value)
//		return m_sound.Get(e->m_id);
//	if constexpr (std::is_same<T, CSprite>::Value)
//		return m_sprite.Get(e->m_id);
//	if constexpr (std::is_same<T, CState>::Value)
//		return m_state.Get(e->m_id);
//	if constexpr (std::is_same<T, CTag>::Value)
//		return m_tag.Get(e->m_id);
//	if constexpr (std::is_same<T, CTransform>::Value)
//		return m_transform.Get(e->m_id);
//
//	return nullptr;
//}