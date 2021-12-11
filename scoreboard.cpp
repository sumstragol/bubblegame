#include "scoreboard.hpp"

Scoreboard::Scoreboard()
{
    set_tex(settings::SCOREBOARD_TEX_PATH);
    attach_tex();
    
    set_pos_x(settings::SCREEN_WIDTH / 2 - get_tex().getSize().x / 2);
    set_pos_y(0.f);
    
    points = new My_font(settings::FONT_PATH, settings::FONT_SIZE, settings::FONT_COLOR);
    points->update_text("Points: 0", settings::FONT_SIZE);
    
    lives = new My_font(settings::FONT_PATH, settings::FONT_SIZE, settings::FONT_COLOR);
    lives->update_text("Lives: 0", 0.f);
}

void Scoreboard::update_points(const std::string &p)
{
    points->update_text("Points: " + p, settings::FONT_SIZE);
}

void Scoreboard::update_lives(const std::string &ls)
{
    lives->update_text("Lives: " + ls, 0.f);
}

void Scoreboard::draw(sf::RenderWindow *window)
{
    window->draw(sprite);
    points->draw(window);
    lives->draw(window);
}
