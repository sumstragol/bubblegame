//
//  pistol.cpp
//  sfmll
//
//  Created by Mikolaj Brozek on 07/11/2021.
//  Copyright © 2021 Mikolaj Brozek. All rights reserved.
//

#include "pistol.hpp"

Pistol::Pistol(sf::RenderWindow* window)
:max_capacity(settings::PISTOL_MAX_CAPACITY),
    reload_time(settings::PISTOL_RELOAD_TIME),
    freeze_time_between_shots(settings::PISTOL_FREEZE_TIME_BETWEEN_SHOTS),
    current_bullet_count(max_capacity),
    is_reloaded(true),
    is_able_to_shoot(true),
    window_to_render_on(window)
{}

void Pistol::shoot(const sf::Vector2f &origin, const sf::Vector2f &direction)
{
    
    
    if (is_able_to_shoot && is_reloaded)
    {
        magazine.push_back(new Bullet(origin, direction));
        
        //std::thread bullet_draw
        
        current_bullet_count--;
        //std::thread t;
        if (current_bullet_count == 0)
        {
            //t = std::thread(&Pistol::reload, Pistol());
            current_bullet_count = max_capacity;
        }
        else
        {
            //t = std::thread(&Pistol::freeze, Pistol());
        }
        
        //t.join();
    }
}

void Pistol::render_bullets()
{
    if (!magazine.empty())
    {
        for (auto it : magazine)
        {
            window_to_render_on->draw(it->get_bullet_sprite());
        }
    }
}

void Pistol::move_bullets()
{
    if (!magazine.empty())
    {
        for (int i = 0; i < magazine.size(); i++)
        {
            magazine[i]->move(window_to_render_on, magazine, i);
        }
    }
}

std::vector<Bullet*>* Pistol::magazine_pointer()
{
    return &magazine;
}

void Pistol::reload()
{
    is_reloaded = false;
    std::this_thread::sleep_for(std::chrono::milliseconds(reload_time));
    is_reloaded = true;
}

void Pistol::freeze()
{
    is_able_to_shoot = false;
    std::this_thread::sleep_for(std::chrono::milliseconds(freeze_time_between_shots));
    is_able_to_shoot = true;
}
