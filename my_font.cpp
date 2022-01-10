#include "my_font.hpp"

My_font::My_font(const std::string& font_path, const unsigned int &font_size, const sf::Color font_color)
    :font_size(font_size),
    font_color(font_color)
{
    font.loadFromFile(font_path);
    text.setFont(font);
    text.setCharacterSize(font_size);
    text.setFillColor(font_color);
}

void My_font::set_text(const std::string& new_text)
{
    text.setString(new_text);
}

void My_font::set_color(const sf::Color& new_color)
{
    font_color = new_color;
    text.setFillColor(font_color);
}

void My_font::set_position(const int& cor_x, const int& cor_y)
{
    text.setPosition(cor_x, cor_y);
}

void My_font::set_font_size(const unsigned int &s)
{
    font_size = s;
    text.setCharacterSize(font_size);
}

unsigned int My_font::get_font_size() const
{
    return font_size;
}

void My_font::draw(sf::RenderWindow* window)
{
    window->draw(text);
}

const sf::Text My_font::get_text() const
{
    return text;
}
