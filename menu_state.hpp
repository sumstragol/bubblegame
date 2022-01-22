#pragma once

#include "includes.hpp"
#include "state.hpp"
#include "levels_state.hpp"
#include "button.hpp"

class Menu_State : public State
{
public:
    Menu_State();
    void init_buttons() override;
    void clear() override;
    void update(sf::RenderWindow* window, sf::Clock& c) override;
    void render(sf::RenderWindow* window) override;
    void handle_input(sf::RenderWindow* window, sf::Event& e, sf::Clock& c) override;
private:
    Button* logo;
    Button* button_play;
    Button* button_exit;
};
