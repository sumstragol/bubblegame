#include "player.hpp"

Player::Player()
{
    set_tex(settings::PLAYER_STAND_TEX_PATH);
    attach_tex();

    set_speed_x(settings::PLAYER_SPEED);
    set_speed_y(settings::PLAYER_SPEED);
   
    set_pos_x(settings::SCREEN_WIDTH / 2 - get_tex().getSize().x / 2);
    set_pos_y(settings::SCREEN_HEIGHT - get_tex().getSize().y);
}

void Player::move(sf::RenderWindow *window, const Move_direction &d)
{
    switch (d)
    {
        case Move_direction::left:
            sprite.move(-speed_x, 0.f);
            if (get_pos_x() < 0)
            {
                set_pos_x(0.f);
            }

            break;
        case Move_direction::right:
            sprite.move(speed_x, 0.f);
            if (get_pos_x() > window->getSize().x - sprite.getGlobalBounds().width)
            {
                set_pos_x(window->getSize().x - sprite.getGlobalBounds().width);
            }

            break;
    }
}

