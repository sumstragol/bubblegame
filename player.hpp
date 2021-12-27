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
    using Entity::set_pos_x;
    using Entity::set_pos_y;
    void move(sf::RenderWindow* window, const Move_direction &d);
};
