//
//  ball.hpp
//  sfmll
//
//  Created by Mikolaj Brozek on 01/11/2021.
//  Copyright © 2021 Mikolaj Brozek. All rights reserved.
//

#pragma once

#include "game.hpp"

class Ball
{
public:
    Ball();
    Ball(const Ball* b);
    virtual ~Ball();
    const sf::Texture get_ball_tex() const;
    const sf::Sprite get_ball_sprite() const;
    float get_speed_x() const;
    float get_speed_y() const;
    void reverse_x();
    const float get_pos_x() const;
    const float get_pos_y() const;
    void ball_dispalcement(sf::RenderWindow* window);
    virtual void double_ball(std::vector<Ball*>& v, const int to_double_index) = 0;
protected:
    virtual float get_max_speed_y() const = 0;
    
    sf::Texture ball_tex;
    sf::Sprite ball;
    float speed_x;
    float speed_y;
    float gravity;
    bool after_create;
};

class Ball_small : public Ball
{
public:
    Ball_small();
    Ball_small(const Ball* b);
    void double_ball(std::vector<Ball*>& v, const int to_double_index);
private:
    float get_max_speed_y() const;
};

class Ball_medium : public Ball
{
public:
    Ball_medium();
    Ball_medium(const Ball* b);
    void double_ball(std::vector<Ball*>& v, const int to_double_index);
private:
    float get_max_speed_y() const;
};

class Ball_large : public Ball
{
public:
    Ball_large();
    Ball_large(const Ball* b);
    void double_ball(std::vector<Ball*>& v, const int to_double_index);
private:
    float get_max_speed_y() const;
};
