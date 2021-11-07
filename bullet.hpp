//
//  bullet.hpp
//  sfmll
//
//  Created by Mikolaj Brozek on 06/11/2021.
//  Copyright © 2021 Mikolaj Brozek. All rights reserved.
//


#pragma once

#include "game.hpp"

class Bullet
{
public:
    Bullet(sf::Vector2f origin, sf::Vector2f mouse_pos);
    Bullet(sf::Vector2f origin, sf::Vector2f mouse_pos, const float &s);
    const sf::Sprite get_bullet_sprite() const;
    sf::Sprite get_bullet_sprite();
    const float get_pos_x() const;
    const float get_pos_y() const;
    float get_speed() const;
    void move(sf::RenderWindow* window, std::vector<Bullet*> &v, const int bullet_index);
private:
    sf::Texture bullet_tex;
    sf::Sprite bullet;
    float speed;
    sf::Vector2f direction;
};

