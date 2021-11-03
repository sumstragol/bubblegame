//
//  player.hpp
//  sfmll
//
//  Created by Mikolaj Brozek on 01/11/2021.
//  Copyright © 2021 Mikolaj Brozek. All rights reserved.
//
#pragma once

#include "game.hpp"

enum class Move_direction;

class Player
{
public:
    Player();
    const sf::Sprite get_player_sprite() const;
    void move_player(sf::RenderWindow* window, const Move_direction &d);
private:
    sf::Texture player_stand_tex;
    sf::Texture player_move_1_tex;
    sf::Texture player_move_2_tex;
    sf::Sprite player;
    float speed;
};
