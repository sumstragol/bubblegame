#include "timer.hpp"

Timer::Timer(const float &t)
    :is_active(true)
{
    set_tex(settings::TIMER_TEX_PATH);
    attach_tex();
    
    set_speed_x(-t);
    set_speed_y(0.f);
    
    set_pos_x(0.f);
    set_pos_y(0.f);
}

bool Timer::is_running() const
{
    return is_active;
}

void Timer::update(sf::RenderWindow *window)
{
    sprite.move(speed_x, speed_y);
    if (get_pos_x() + get_sprite().getGlobalBounds().width < 0)
    {
        is_active = false;
    }
}

void Timer::set_time(const float& t)
{
    set_speed_x(-t);
}

void Timer::reset()
{
    set_pos_x(0);
    is_active = true;
}
