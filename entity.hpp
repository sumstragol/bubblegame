#pragma once

#include "includes.hpp"

class Entity
{
public:
    virtual ~Entity();
    const sf::Texture get_tex() const;
    const sf::Sprite get_sprite() const;
    sf::Sprite get_sprite();
    float get_speed_x() const;
    float get_speed_y() const;
    const float get_pos_x() const;
    const float get_pos_y() const;
    void draw(sf::RenderWindow* window) const;
    bool got_hit(const sf::Sprite &other) const;
protected:
    void set_tex(const std::string& path);
    void set_tex(const sf::Texture& t);
    void attach_tex();
    void set_pos_x(const float& value);
    void set_pos_y(const float& value);
    void set_speed_x(const float& value);
    void set_speed_y(const float& value);

    sf::Texture tex;
    sf::Sprite sprite;
    float speed_x;
    float speed_y;
};