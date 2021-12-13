#pragma once

#include "includes.hpp"
#include "entity.hpp"

class My_font
{
public:
    My_font(const std::string& font_path, const unsigned int &font_size, const sf::Color font_color);
    void set_text(const std::string& new_text);
    void set_color(const sf::Color& new_color);
    void set_position(const float &x_cor, const float &y_cor);
    void set_font_size(const unsigned int& s);
    
    void draw(sf::RenderWindow* window);
    const sf::Text get_text() const; 
private:
    sf::Font font;
    sf::Text text;
    
    unsigned int font_size;
    sf::Color font_color;
};
