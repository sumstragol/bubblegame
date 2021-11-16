#pragma once

#include "includes.hpp"

namespace util {
    // texture related functions
    void load_tex(sf::Texture &tex, const std::string& path);
    sf::Texture get_tex(const std::string& path);
    // vector related functions
    const float get_vector_length(sf::Vector2f &v);
    void normalize_vector(sf::Vector2f &v);
    void direction_vector(sf::Vector2f &t, const sf::Vector2f &f, const sf::Vector2f &s);
    //collision
    bool is_colliding(const sf::Sprite &first, const sf::Sprite &second);
}
