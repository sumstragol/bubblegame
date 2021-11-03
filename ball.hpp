//
//  ball.hpp
//  sfmll
//
//  Created by Mikolaj Brozek on 01/11/2021.
//  Copyright © 2021 Mikolaj Brozek. All rights reserved.
//

#pragma once

#include "game.hpp"

enum class Ball_size { large, medium, small };

class Ball
{
public:
    Ball(const Ball_size &bs);
    Ball(const Ball_size &bs, float x, float y, float sx, float sy);
    const sf::Sprite get_ball_sprite() const;
    const Ball_size get_ball_size() const;
    float get_speed_x() const;
    float get_speed_y() const;
    const float get_pos_x() const;
    const float get_pos_y() const;
    void ball_dispalcement(sf::RenderWindow* window);
    static void double_ball(std::vector<Ball*>& v, const int to_double_index);
private:
    static void set_scale(sf::Sprite &b, const Ball_size &bs);
    static void set_color(sf::Sprite &b, const Ball_size &bs);
    float get_max_speed_y() const;
    
    sf::Texture ball_tex;
    sf::Sprite ball;
    Ball_size size;
    float speed_x;
    float speed_y;
    float gravity;
    bool after_create;
};

