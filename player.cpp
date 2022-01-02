#include "player.hpp"

Player::Player()
{
    sprite_rect_right = sf::IntRect(0, 0, rect_cor.width, rect_cor.height);
    sprite_rect_left = sf::IntRect(rect_cor.width * 3, 0, rect_cor.width, rect_cor.height);

    set_tex(settings::PLAYER_TEX_PATH);

    sprite = sf::Sprite(tex, sprite_rect_left);

    set_speed_x(settings::PLAYER_SPEED);
    set_speed_y(settings::PLAYER_SPEED);
   
    set_pos_x(0);
    set_pos_y((float)(settings::SCREEN_HEIGHT - get_tex().getSize().y));
}

void Player::move(sf::RenderWindow *window, const Move_direction &d, sf::Clock& c)
{
    update(d, c);
    
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

void Player::refresh(const Move_direction& d)
{
    switch (d)
    {
    case Move_direction::left:
    {
        sprite_rect_left.left = rect_cor.width * 3;
        sprite.setTextureRect(sprite_rect_left);
        break;
    }
    case Move_direction::right:
    {
        sprite_rect_right.left = 0;
        sprite.setTextureRect(sprite_rect_right);
        break;
    }
    }
}

sprite_rect_cor Player::get_rect_cor() const
{
    return rect_cor;
}

void Player::update(const Move_direction& d, sf::Clock& c)
{
    if (c.getElapsedTime().asSeconds() > 0.3f)
    {
        switch (d)
        {
        case Move_direction::left:
        {
            if (sprite_rect_left.left == rect_cor.width * 5)
            {
                sprite_rect_left.left = rect_cor.width * 4;
            }
            else
            {
                sprite_rect_left.left += rect_cor.width;
            }

            sprite.setTextureRect(sprite_rect_left);
            break;
        }
        case Move_direction::right:
        {
            if (sprite_rect_right.left == rect_cor.width * 2)
            {
                sprite_rect_right.left = rect_cor.width;
            }
            else
            {
                sprite_rect_right.left += rect_cor.width;
            }

            sprite.setTextureRect(sprite_rect_right);
            break;
        }
        }

        c.restart();
    }
}