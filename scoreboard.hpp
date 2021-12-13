#pragma once

#include "includes.hpp"
#include "entity.hpp"
#include "button.hpp"

class Button;

enum class Values_type
{
  lives, points, level
};

class Scoreboard : public Entity
{
public:
    Scoreboard();
    void draw(sf::RenderWindow *window);
    void set_value(const std::string& new_val, const Values_type& val_type);
private:
    struct Values {
        Button* lives;
        Button* points;
        Button* level;
    };
    
    Values sc_values;
};
