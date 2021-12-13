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
    text.setFillColor(new_color);
}

void My_font::set_position(const float &x_cor, const float &y_cor)
{
    text.setPosition(x_cor, y_cor);
}

void My_font::set_font_size(const unsigned int &s)
{
    text.setCharacterSize(s);
}

void My_font::draw(sf::RenderWindow* window)
{
    window->draw(text);
}

const sf::Text My_font::get_text() const
{
    return text;
}
