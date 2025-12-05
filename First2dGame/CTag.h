#pragma once
//categorization of entities
#include <string>

struct CTag
{
	std::string tag = "";

	CTag()= default;
	CTag(std::string &t) : tag(t) {}
};