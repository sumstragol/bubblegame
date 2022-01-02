#pragma once

#include "includes.hpp"
#include "entity.hpp"

enum class Move_direction
{
    up, down, left, right
};

struct sprite_rect_cor
{
    int width;
    int height;
};

class Player : public Entity
{
public:
    Player();
    using Entity::set_pos_x;
    using Entity::set_pos_y;
    void move(sf::RenderWindow* window, const Move_direction &d, sf::Clock& c);
    void refresh(const Move_direction& d);
    sprite_rect_cor get_rect_cor() const;
private:
    void update(const Move_direction& d, sf::Clock& c);

    sf::IntRect sprite_rect_right;
    sf::IntRect sprite_rect_left;

    sprite_rect_cor rect_cor{ settings::PLAYER_TEX_SIZE_WIDTH, settings::PLAYER_TEX_SIZE_HEIGHT };
};
