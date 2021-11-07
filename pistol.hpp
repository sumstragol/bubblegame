//
//  pistol.hpp
//  sfmll
//
//  Created by Mikolaj Brozek on 07/11/2021.
//  Copyright © 2021 Mikolaj Brozek. All rights reserved.
//

#pragma once

#include "game.hpp"

class Bullet;

class Pistol
{
public:
    Pistol(sf::RenderWindow *window);
    void shoot(const sf::Vector2f &origin, const sf::Vector2f &direction);
    void render_bullets();
    void move_bullets();
    bool got_hit(const sf::Sprite& b);
private:
    void reload();
    void freeze();
    
    const unsigned int max_capacity;
    const unsigned int reload_time;
    const unsigned int freeze_time_between_shots;
    int current_bullet_count;
    bool is_reloaded;
    bool is_able_to_shoot;
    std::vector<Bullet*> magazine;

    sf::RenderWindow* window_to_render_on;
};
