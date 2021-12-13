#include "scoreboard.hpp"

Scoreboard::Scoreboard()
{
    sc_values.lives = new Button(450, 0,
        settings::SCOREBOARD_TEX_PATH, settings::SCOREBOARD_TEX_PATH,
        "Lives: 0"
    );
    sc_values.lives->get_caption_text()->set_font_size(30);
    sc_values.lives->get_caption_text()->set_color(sf::Color::Red);
    sc_values.lives->update_text_cor();
    
    sc_values.points = new Button(450, 45,
        settings::SCOREBOARD_TEX_PATH, settings::SCOREBOARD_TEX_PATH,
        "Points: 0"
    );
    sc_values.points->get_caption_text()->set_font_size(30);
    sc_values.points->get_caption_text()->set_color(sf::Color::Red);
    sc_values.points->update_text_cor();
    
    sc_values.level = new Button(450, 90,
        settings::SCOREBOARD_TEX_PATH, settings::SCOREBOARD_TEX_PATH,
        "Level: 0"
    );
    sc_values.level->get_caption_text()->set_font_size(30);
    sc_values.level->get_caption_text()->set_color(sf::Color::Red);
    sc_values.level->update_text_cor();
}

void Scoreboard::draw(sf::RenderWindow *window)
{
    sc_values.lives->draw(window);
    sc_values.points->draw(window);
    sc_values.level->draw(window);
}

void Scoreboard::set_value(const std::string& new_val, const Values_type& val_type)
{
    if (val_type == Values_type::lives)
    {
        sc_values.lives->get_caption_text()->set_text(new_val);
    }
    else if (val_type == Values_type::points)
    {
        sc_values.points->get_caption_text()->set_text(new_val);
    }
    else if (val_type == Values_type::level)
    {
        sc_values.level->get_caption_text()->set_text(new_val);
    }
}
