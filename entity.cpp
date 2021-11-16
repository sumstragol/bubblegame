#include "entity.hpp"

Entity::~Entity() = default;

const sf::Sprite Entity::get_sprite() const
{
    return sprite;
}

sf::Sprite Entity::get_sprite()
{
    return sprite;
}

const sf::Texture Entity::get_tex() const
{
    return tex;
}

float Entity::get_speed_x() const
{
    return speed_x;
}

float Entity::get_speed_y() const
{
    return speed_y;
}

const float Entity::get_pos_x() const
{
    return get_sprite().getPosition().x;
}

const float Entity::get_pos_y() const
{
    return get_sprite().getPosition().y;
}

void Entity::draw(sf::RenderWindow* window) const
{
    window->draw(sprite);
}

bool Entity::got_hit(const sf::Sprite& other) const
{
    return sprite.getGlobalBounds().intersects(other.getGlobalBounds());
}

void Entity::set_tex(const std::string &path)
{
    tex = util::get_tex(path);
}

void Entity::set_tex(const sf::Texture& t)
{
    tex = t;
}

void Entity::attach_tex()
{
    sprite.setTexture(tex);
}

void Entity::set_pos_x(const float &value)
{
     sprite.setPosition(value, get_sprite().getPosition().y);
}

void Entity::set_pos_y(const float &value)
{
    sprite.setPosition(get_sprite().getPosition().x, value);
}

void Entity::set_speed_x(const float &value)
{
    speed_x = value;
}

void Entity::set_speed_y(const float &value)
{
    speed_y = value;
}
