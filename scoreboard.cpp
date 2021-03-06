#include "scoreboard.hpp"

Scoreboard::Scoreboard()
{
    sc_values.lives = new Button(600, 0,
        settings::SCOREBOARD_TEX_PATH, settings::SCOREBOARD_TEX_PATH,
        "Lives: 0"
    );
    sc_values.lives->get_caption_text()->set_font_size(30);
    sc_values.lives->get_caption_text()->set_color(settings::FONT_COLOR);
    sc_values.lives->update_text_cor();
    
    sc_values.points = new Button(600, 34,
        settings::SCOREBOARD_TEX_PATH, settings::SCOREBOARD_TEX_PATH,
        "Points: 0"
    );
    sc_values.points->get_caption_text()->set_font_size(30);
    sc_values.points->get_caption_text()->set_color(settings::FONT_COLOR);
    sc_values.points->update_text_cor();
    
    sc_values.level = new Button(600, 68,
        settings::SCOREBOARD_TEX_PATH, settings::SCOREBOARD_TEX_PATH,
        "Level: 0"
    );
    sc_values.level->get_caption_text()->set_font_size(30);
    sc_values.level->get_caption_text()->set_color(settings::FONT_COLOR);
    sc_values.level->update_text_cor();
}

Scoreboard::~Scoreboard()
{
    delete sc_values.lives;
    delete sc_values.points;
    delete sc_values.level;
}

void Scoreboard::draw(sf::RenderWindow *window)
{
    sc_values.lives->draw(window);
    sc_values.points->draw(window);
    sc_values.level->draw(window);
}

void Scoreboard::set_value(const Value_type& val_type, const unsigned int& val)
{
    if (val_type == Value_type::lives)
    {
        sc_values.lives->get_caption_text()->set_text("Lives: " + std::to_string(val));
        sc_values.lives->update_text_cor();
    }
    else if (val_type == Value_type::points)
    {
        sc_values.points->get_caption_text()->set_text("Poitns: " + std::to_string(val));
        sc_values.points->update_text_cor();
    }
    else if (val_type == Value_type::level)
    {
        sc_values.level->get_caption_text()->set_text("Level: " + std::to_string(val));
        sc_values.level->update_text_cor();
    }
}
