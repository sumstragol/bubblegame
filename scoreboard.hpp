#pragma once

#include "includes.hpp"
#include "entity.hpp"
#include "button.hpp"

class Button;

enum class Value_type
{
  lives, points, level
};

class Scoreboard : public Entity
{
public:
    Scoreboard();
    ~Scoreboard();
    void draw(sf::RenderWindow *window);
    void set_value(const Value_type& val_type, const unsigned int& val);
private:
    struct Values {
        Button* lives;
        Button* points;
        Button* level;
    };
    
    Values sc_values;
};
