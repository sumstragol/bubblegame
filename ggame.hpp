#pragma once

#include "includes.hpp"
#include "states_includes.hpp"

class GGame
{
public:
    GGame();
    void run();
private:
    void init_states();
    void push_new_state();
    void replace_current_state();
    void delete_current_state();
    void update();
    void render();

    sf::RenderWindow* window;
    sf::Event e;
    sf::Clock clock;
    
    std::stack<State*> states;
};
