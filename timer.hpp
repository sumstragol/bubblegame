#pragma once

#include "includes.hpp"
#include "entity.hpp"

class Timer : public Entity
{
public:
    Timer(const float &t);
    bool is_running() const;
    void update(sf::RenderWindow *window);
    void set_time(const float& t);
    void reset();
private:
    bool is_active;
};

