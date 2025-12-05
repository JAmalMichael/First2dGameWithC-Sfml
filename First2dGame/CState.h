#pragma once
//idle, runnin, jumping
#include <string>

struct CState
{
	std::string state = "idle";

	CState() {}
	CState(std::string &s) : state(s) {}
};