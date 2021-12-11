#pragma once

#include "includes.hpp"
#include "entity.hpp"
#include "my_font.hpp"

class Scoreboard : public Entity
{
public:
    Scoreboard();
    void update_points(const std::string &p);
    void update_lives(const std::string &ls);
    void draw(sf::RenderWindow *window);
private:
    My_font* lives;
    My_font* points;
};
