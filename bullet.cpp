//
//  bullet.cpp
//  sfmll
//
//  Created by Mikolaj Brozek on 06/11/2021.
//  Copyright © 2021 Mikolaj Brozek. All rights reserved.
//

#include "bullet.hpp"

Bullet::Bullet(sf::Vector2f origin, sf::Vector2f mouse_pos)
:bullet_tex(util::get_tex(settings::BULLET_TEX_PATH)),
    speed(settings::BULLET_SPEED_LOW)
{
    bullet.setTexture(bullet_tex);
    
    bullet.setPosition(origin);
    
    util::direction_vector(direction, origin, mouse_pos);
    util::normalize_vector(direction);
    direction.x *= -speed;
    direction.y *= -speed;
}

Bullet::Bullet(sf::Vector2f origin, sf::Vector2f mouse_pos, const float &s)
:bullet_tex(util::get_tex(settings::BULLET_TEX_PATH)),
    speed(s)

{
    bullet.setTexture(bullet_tex);
    
    bullet.setPosition(origin);
    
    util::direction_vector(direction, origin, mouse_pos);
    util::normalize_vector(direction);
    direction.x *= -speed;
    direction.y *= -speed;
}

const sf::Sprite Bullet::get_bullet_sprite() const
{
    return bullet;
}

sf::Sprite Bullet::get_bullet_sprite()
{
    return bullet;
}

const float Bullet::get_pos_x() const
{
    return bullet.getPosition().x;
}

const float Bullet::get_pos_y() const
{
    return bullet.getPosition().y;
}

float Bullet::get_speed() const
{
    return speed;
}

void Bullet::move(sf::RenderWindow* window, std::vector<Bullet*> &v, const int bullet_index)
{
    bullet.move(direction);
    
    if (get_pos_x() < -bullet.getGlobalBounds().width ||                        //right border
        get_pos_x() > window->getSize().x + bullet.getGlobalBounds().width ||   //left  border
        get_pos_y() < -get_bullet_sprite().getGlobalBounds().height ||          //top   border
        get_pos_y() + get_bullet_sprite().getGlobalBounds().height > window->getSize().y + bullet.getGlobalBounds().height
        )
    {
        v.erase(v.begin() + bullet_index);
    }
}
