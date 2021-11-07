//
//  ball.cpp
//  sfmll
//
//  Created by Mikolaj Brozek on 01/11/2021.
//  Copyright © 2021 Mikolaj Brozek. All rights reserved.
//
#include "ball.hpp"

/*
 
    Base class implementation
 
 */

Ball::Ball()
:ball_tex(util::get_tex(settings::BALL_TEX_PATH)),
    speed_x(settings::BALL_HORIZONTAL_SPEED),
    speed_y(settings::BALL_VERTICAL_SPEED),
    gravity(settings::BALL_GRAVITY),
    after_create(true)
{
    ball.setTexture(ball_tex);
}

Ball::Ball(const Ball* b)
:ball_tex(b->get_ball_tex()),
    speed_x(b->get_speed_x()),
    speed_y(b->get_speed_y()),
    gravity(settings::BALL_GRAVITY),
    after_create(true)
{
    ball.setTexture(ball_tex);
    ball.setPosition(b->get_pos_x(), b->get_pos_y());
}

Ball::~Ball() = default;

const sf::Sprite Ball::get_ball_sprite() const
{
    return ball;
}

const sf::Texture Ball::get_ball_tex() const
{
    return ball_tex;
}

float Ball::get_speed_x() const
{
    return speed_x;
}

void Ball::reverse_x()
{
    speed_x *= -1;
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
    //
    //
    //
    // y axis
    //
    //
    //
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
    //
    //
    //
    // x axis
    //
    //
    //
    if (ball.getPosition().x + ball.getGlobalBounds().width >= window->getSize().x ||
            ball.getPosition().x <= 0
        )
    {
        speed_x = -speed_x;
    }
}

/*
 
    Derived classes implementation
 
 */

/*
 
    Ball_small
 
 */

Ball_small::Ball_small()
:Ball()
{
    ball.setColor(settings::BALL_COLOR_SMALL);
    ball.setScale(settings::BALL_SCALE_SMALL, settings::BALL_SCALE_SMALL);
}

Ball_small::Ball_small(const Ball* b)
:Ball(b)
{
    ball.setColor(settings::BALL_COLOR_SMALL);
    ball.setScale(settings::BALL_SCALE_SMALL, settings::BALL_SCALE_SMALL);
}

void Ball_small::double_ball(std::vector<Ball*>& v, const int to_double_index)
{
    delete v.at(to_double_index);
    v.erase(v.begin() + to_double_index);
}

float Ball_small::get_max_speed_y() const
{
    return settings::BALL_MAX_GRAVITY_MEDIUM;
}

/*
 
    Ball_medium
 
 */

Ball_medium::Ball_medium()
:Ball()
{
    ball.setColor(settings::BALL_COLOR_MEDIUM);
    ball.setScale(settings::BALL_SCALE_MEDIUM, settings::BALL_SCALE_MEDIUM);
}

Ball_medium::Ball_medium(const Ball* b)
:Ball(b)
{
    ball.setColor(settings::BALL_COLOR_MEDIUM);
    ball.setScale(settings::BALL_SCALE_MEDIUM, settings::BALL_SCALE_MEDIUM);
}

void Ball_medium::double_ball(std::vector<Ball*>& v, const int to_double_index)
{
    v.push_back(new Ball_small(v.at(to_double_index)));
    v.at(to_double_index)->reverse_x();
    v.push_back(new Ball_small(v.at(to_double_index)));
    
    delete v.at(to_double_index);
    v.erase(v.begin() + to_double_index);
}

float Ball_medium::get_max_speed_y() const
{
    return settings::BALL_MAX_GRAVITY_MEDIUM;
}

/*
 
    Ball_large
 
 */


Ball_large::Ball_large()
:Ball()
{
    ball.setColor(settings::BALL_COLOR_LARGE);
    ball.setScale(settings::BALL_SCALE_LARGE, settings::BALL_SCALE_LARGE);
}

Ball_large::Ball_large(const Ball* b)
:Ball(b)
{
    ball.setColor(settings::BALL_COLOR_LARGE);
    ball.setScale(settings::BALL_SCALE_LARGE, settings::BALL_SCALE_LARGE);
}

void Ball_large::double_ball(std::vector<Ball*>& v, const int to_double_index)
{
    v.push_back(new Ball_medium(v.at(to_double_index)));
    v.at(to_double_index)->reverse_x();
    v.push_back(new Ball_medium(v.at(to_double_index)));
   
    delete v.at(to_double_index);
    v.erase(v.begin() + to_double_index);
}

float Ball_large::get_max_speed_y() const
{
    return settings::BALL_MAX_GRAVITY_LARGE;
}
