#pragma once

#include "includes.hpp"
#include "ball.hpp"

class Level 
{
public:
	static void load_level(const std::string& path, std::vector<Ball*>& balls, float& time, int& level_label);
};
