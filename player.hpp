#pragma once

#include "includes.hpp"
#include "entity.hpp"

enum class Move_direction
{
    up, down, left, right
};

class Player : public Entity
{
public:
    Player();
    void move(sf::RenderWindow* window, const Move_direction &d);
};