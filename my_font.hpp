#pragma once

#include "includes.hpp"
#include "entity.hpp"

class My_font
{
public:
    My_font(const std::string& font_path, const unsigned int &font_size, const sf::Color font_color);
    void update_text(const std::string& new_text, const float &y_cor);
    void draw(sf::RenderWindow* window);
private:
    sf::Font font;
    sf::Text text;
    
    unsigned int font_size;
    sf::Color font_color;
};
