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

void My_font::update_text(const std::string &new_text, const float &y_cor)
{
    text.setString(new_text);
    text.setPosition(settings::SCREEN_WIDTH / 2 - text.getGlobalBounds().width / 2, y_cor);
}

void My_font::draw(sf::RenderWindow* window)
{
    window->draw(text);
}
