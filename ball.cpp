//
//  ball.cpp
//  sfmll
//
//  Created by Mikolaj Brozek on 01/11/2021.
//  Copyright © 2021 Mikolaj Brozek. All rights reserved.
//
#include "ball.hpp"

Ball::Ball(const Ball_size &bs)
:size(bs),
    speed_x(settings::BALL_HORIZONTAL_SPEED),
    speed_y(settings::BALL_VERTICAL_SPEED),
    gravity(settings::BALL_GRAVITY),
    after_create(true)
{
    util::load_tex(ball_tex, settings::BALL_TEX_PATH);
    
    ball.setTexture(ball_tex);
    set_scale(ball, bs);
    set_color(ball, bs);
    ball.setPosition(0, 0);
}

Ball::Ball(const Ball_size &bs, float x, float y, float sx, float sy)
:size(bs),
    speed_x(sx),
    speed_y(sy),
    gravity(settings::BALL_GRAVITY),
    after_create(true)
{
    util::load_tex(ball_tex, settings::BALL_TEX_PATH);
    
    ball.setTexture(ball_tex);
    set_scale(ball, bs);
    set_color(ball, bs);
    
    ball.setPosition(x, y);
}

const sf::Sprite Ball::get_ball_sprite() const
{
    return ball;
}

const Ball_size Ball::get_ball_size() const
{
    return size;
}

float Ball::get_speed_x() const
{
    return speed_x;
}

float Ball::get_speed_y() const
{
    return speed_y;
}

const float Ball::get_pos_x() const
{
    return get_ball_sprite().getPosition().x;
}

const float Ball::get_pos_y() const
{
    return get_ball_sprite().getPosition().y;
}

void Ball::ball_dispalcement(sf::RenderWindow* window)
{
    speed_y += gravity;
    ball.move(speed_x, speed_y);
    if (ball.getPosition().y + ball.getGlobalBounds().height + 0.5f >= window->getSize().y)
    {
        ball.setPosition(ball.getPosition().x,
                            window->getSize().y - ball.getGlobalBounds().height
                         );
        
        if (after_create)
        {
            speed_y = get_max_speed_y();
            after_create = false;
        }
        
        speed_y = -speed_y - gravity;
    }
    
    if (ball.getPosition().x + ball.getGlobalBounds().width >= window->getSize().x ||
            ball.getPosition().x <= 0
        )
    {
        speed_x = -speed_x;
    }
}

void Ball::double_ball(std::vector<Ball*>& v, const int to_double_index)
{
    Ball_size new_size;
    
    switch (v.at(to_double_index)->size)
    {
        case Ball_size::large:
            new_size = Ball_size::medium;
            break;
        case Ball_size::medium:
            new_size = Ball_size::small;
            break;
        case Ball_size::small:
            delete v.at(to_double_index);
            v.erase(v.begin() + to_double_index);
            return;
            break;
    }
    
    v.push_back(new Ball(new_size,
                         v.at(to_double_index)->get_pos_x(),
                         v.at(to_double_index)->get_pos_y(),
                         v.at(to_double_index)->get_speed_x(),
                         v.at(to_double_index)->get_speed_y()
                ));
    
    v.push_back(new Ball(new_size,
                         v.at(to_double_index)->get_pos_x(),
                         v.at(to_double_index)->get_pos_y(),
                         -v.at(to_double_index)->get_speed_x(),
                         v.at(to_double_index)->get_speed_y()
                ));
    
    delete v.at(to_double_index);
    v.erase(v.begin() + to_double_index);
}

void Ball::set_scale(sf::Sprite &b, const Ball_size &bs)
{
    switch (bs)
    {
        case Ball_size::large:
            b.setScale(settings::BALL_SCALE_LARGE, settings::BALL_SCALE_LARGE);
            return;
            break;
        case Ball_size::medium:
            b.setScale(settings::BALL_SCALE_MEDIUM, settings::BALL_SCALE_MEDIUM);
            return;
            break;
        case Ball_size::small:
            b.setScale(settings::BALL_SCALE_SMALL, settings::BALL_SCALE_SMALL);
            return;
    }
}

void Ball::set_color(sf::Sprite &b, const Ball_size &bs)
{
    switch (bs)
    {
        case Ball_size::large:
            b.setColor(settings::BALL_COLOR_LARGE);
            return;
            break;
        case Ball_size::medium:
            b.setColor(settings::BALL_COLOR_MEDIUM);
            return;
            break;
        case Ball_size::small:
            b.setColor(settings::BALL_COLOR_SMALL);
            return;
    }
}

float Ball::get_max_speed_y() const
{
    switch (size)
    {
        case Ball_size::large:
            return settings::BALL_MAX_GRAVITY_LARGE;
            break;
        case Ball_size::medium:
            return settings::BALL_MAX_GRAVITY_MEDIUM;
            break;
        case Ball_size::small:
            return settings::BALL_MAX_GRAVITY_SMALL;
            break;
    }
}
