#pragma once

#include "includes.hpp"
#include "entity.hpp"


class Bullet : public Entity
{
public:
	Bullet(const Entity* origin, const sf::Vector2f& direction);
	void move(sf::RenderWindow* window, std::vector<Bullet*>& vec);
	void remove(std::vector<Bullet*>& vec);
};