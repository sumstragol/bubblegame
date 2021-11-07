//
//  util.cpp
//  sfmll
//
//  Created by Mikolaj Brozek on 01/11/2021.
//  Copyright © 2021 Mikolaj Brozek. All rights reserved.
//

#include <math.h>

#include "util.hpp"

void util::load_tex(sf::Texture &tex, const std::string& path)
{
    tex.loadFromFile(path);
}

sf::Texture util::get_tex(const std::string& path)
{
    sf::Texture temp;
    temp.loadFromFile(path);
    return temp;
}

const float util::get_vector_length(sf::Vector2f &v)
{
    return sqrt(pow(v.x, 2) + pow(v.y, 2));
}

sf::Vector2f util::normalize_vector(sf::Vector2f &v)
{
    const float len = get_vector_length(v);
    v.x /= len;
    v.y /= len;
}

void util::direction_vector(sf::Vector2f &t, const sf::Vector2f &f, const sf::Vector2f &s)
{
    t = f - s;
}

bool util::is_colliding(const sf::Sprite &first, const sf::Sprite &second)
{
    return first.getGlobalBounds().intersects(second.getGlobalBounds());
}

bool util::is_colliding(std::vector<Ball*>* balls, std::vector<Bullet*>* bullets, int &bullet_index, int &ball_index)
{
    for (int i = 0; i < balls->size(); i++)
    {
        for (int j = 0; j < bullets->size(); j++)
        {
            if (is_colliding(balls->at(i)->get_ball_sprite(), bullets->at(j)->get_bullet_sprite()))
            {
                ball_index = i;
                bullet_index = j;
                return true;
            }
        }
    }
}
