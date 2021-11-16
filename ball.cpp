#include "ball.hpp"

Ball::Ball()
	:gravity(settings::BALL_GRAVITY),
	after_create(true)
{
	set_tex(settings::BALL_TEX_PATH);
    attach_tex();

	set_speed_x(settings::BALL_HORIZONTAL_SPEED);
	set_speed_y(settings::BALL_VERTICAL_SPEED);
}

Ball::Ball(const Ball* b)
	:gravity(b->gravity),
	after_create(true)
{
    set_tex(settings::BALL_TEX_PATH);
    attach_tex();

    set_pos_x(b->get_pos_x());
    set_pos_y(b->get_pos_y());

	set_speed_x(b->get_speed_x());
	set_speed_y(b->get_speed_y());
}

Ball::~Ball() = default;

void Ball::move(sf::RenderWindow* window)
{
	speed_y += gravity;
	sprite.move(speed_x, speed_y);
    if (get_pos_y() + sprite.getGlobalBounds().height + 0.5f >= window->getSize().y)
    {
        sprite.setPosition(get_pos_x(),
            window->getSize().y - sprite.getGlobalBounds().height
        );

        if (after_create)
        {
            speed_y = get_max_speed_y();
            after_create = false;
        }

        speed_y = -speed_y - gravity;
    }

    if (get_pos_x() + sprite.getGlobalBounds().width >= window->getSize().x ||
        get_pos_x() <= 0
        )
    {
        speed_x = -speed_x;
    }
}

void Ball::neg_speed_x()
{
    speed_x *= -1;
}

Ball_small::Ball_small()
    :Ball()
{
    sprite.setColor(settings::BALL_COLOR_SMALL);
    sprite.setScale(settings::BALL_SCALE_SMALL, settings::BALL_SCALE_SMALL);
}

Ball_small::Ball_small(const Ball* b)
    :Ball(b)
{
    sprite.setColor(settings::BALL_COLOR_SMALL);
    sprite.setScale(settings::BALL_SCALE_SMALL, settings::BALL_SCALE_SMALL);
}

void Ball_small::double_ball(std::vector<Ball*> &vec)
{
    int ball_index = std::find(vec.begin(), vec.end(), this) - vec.begin();
    vec.erase(vec.begin() + ball_index);

    delete this;
}

float Ball_small::get_max_speed_y() const
{
    return settings::BALL_MAX_GRAVITY_SMALL;
}

Ball_medium::Ball_medium()
    :Ball()
{
    sprite.setColor(settings::BALL_COLOR_MEDIUM);
    sprite.setScale(settings::BALL_SCALE_MEDIUM, settings::BALL_SCALE_MEDIUM);
}

Ball_medium::Ball_medium(const Ball* b)
    :Ball(b)
{
    sprite.setColor(settings::BALL_COLOR_MEDIUM);
    sprite.setScale(settings::BALL_SCALE_MEDIUM, settings::BALL_SCALE_MEDIUM);
}

void Ball_medium::double_ball(std::vector<Ball*>& vec)
{
    int ball_index = std::find(vec.begin(), vec.end(), this) - vec.begin();
    vec.erase(vec.begin() + ball_index);

    vec.push_back(new Ball_small(this));
    neg_speed_x();
    vec.push_back(new Ball_small(this));
    
    delete this;
}

float Ball_medium::get_max_speed_y() const
{
    return settings::BALL_MAX_GRAVITY_MEDIUM;
}

Ball_large::Ball_large()
    :Ball()
{
    sprite.setColor(settings::BALL_COLOR_LARGE);
    sprite.setScale(settings::BALL_SCALE_LARGE, settings::BALL_SCALE_LARGE);
}

Ball_large::Ball_large(const Ball* b)
    :Ball(b)
{
    sprite.setColor(settings::BALL_COLOR_LARGE);
    sprite.setScale(settings::BALL_SCALE_LARGE, settings::BALL_SCALE_LARGE);
}

void Ball_large::double_ball(std::vector<Ball*>& vec)
{
    int ball_index = std::find(vec.begin(), vec.end(), this) - vec.begin();
    vec.erase(vec.begin() + ball_index);

    vec.push_back(new Ball_medium(this));
    neg_speed_x();
    vec.push_back(new Ball_medium(this));

    delete this;
}

float Ball_large::get_max_speed_y() const
{
    return settings::BALL_MAX_GRAVITY_LARGE;
}