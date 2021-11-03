//
//  player.cpp
//  sfmll
//
//  Created by Mikolaj Brozek on 01/11/2021.
//  Copyright © 2021 Mikolaj Brozek. All rights reserved.
//
#include "player.hpp"

Player::Player()
:speed(settings::PLAYER_SPEED)
{
    util::load_tex(player_stand_tex, settings::PLAYER_STAND_TEX_PATH);
    util::load_tex(player_move_1_tex, settings::PLAYER_MOVE_1_TEX_PATH);
    util::load_tex(player_move_2_tex, settings::PLAYER_MOVE_2_TEX_PATH);
    
    player.setTexture(player_stand_tex);
    
    player.setPosition(settings::SCREEN_WIDTH / 2 - player.getTexture()->getSize().x / 2,
                       settings::SCREEN_HEIGHT - player.getTexture()->getSize().y);
}

const sf::Sprite Player::get_player_sprite() const
{
    return player;
}

void Player::move_player(sf::RenderWindow *window, const Move_direction &d)
{
    switch (d)
    {
        case Move_direction::left:
            player.move(-speed, 0.f);
            if (player.getPosition().x < 0)
            {
                player.setPosition(0, player.getPosition().y);
            }
            
            break;
        case Move_direction::right:
            player.move(speed, 0.f);
            if (player.getPosition().x > window->getSize().x - player.getGlobalBounds().width)
            {
                player.setPosition(window->getSize().x - player.getGlobalBounds().width,
                                   player.getPosition().y);
            }
            
            break;
    }
}
