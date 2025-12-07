#pragma once
#include <memory>
#include <map>
#include "Typesdef.h"
#include "string"


class EntityManager;


class Entity
{
	friend class EntityManager;

	std::string m_tag;
	size_t m_id;
	bool m_active = true;
	ComponentMask m_mask;

public:
	Entity(const std::string& t, size_t id) : m_tag(t), m_id(id) {}

	bool isActive() const { return m_active; }
	void Destroy() { m_active = false; }

	const std::string GetTag() const { return m_tag; }
	size_t GetID() const { return m_id; }
	const ComponentMask& GetMask() const { return m_mask; }
};