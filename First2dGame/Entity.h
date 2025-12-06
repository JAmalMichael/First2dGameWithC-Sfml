#pragma once
#include "string"


class Entity
{
	std::string tag;
	size_t id;

public:
	Entity(const std::string& t, size_t i) : tag(t), id(i) {}
};