//
//  util.hpp
//  sfmll
//
//  Created by Mikolaj Brozek on 01/11/2021.
//  Copyright © 2021 Mikolaj Brozek. All rights reserved.
//
#pragma once

#include "game.hpp"

class Bullet;
class Ball;

namespace util {
    // texture related functions
    void load_tex(sf::Texture &tex, const std::string& path);
    sf::Texture get_tex(const std::string& path);
    // vector related functions
    const float get_vector_length(sf::Vector2f &v);
    sf::Vector2f normalize_vector(sf::Vector2f &v);
    void direction_vector(sf::Vector2f &t, const sf::Vector2f &f, const sf::Vector2f &s);
    //collision
    bool is_colliding(const sf::Sprite &first, const sf::Sprite &second);
    bool is_colliding(std::vector<Ball*>* balls, std::vector<Bullet*>* bullets, int &bullet_index, int &ball_index);
}
