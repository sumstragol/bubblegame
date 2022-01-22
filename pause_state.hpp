#pragma once

#include "includes.hpp"
#include "states_includes.hpp"

#include "button.hpp"

class Pause_State : public State
{
public:
    Pause_State();
    void init_buttons() override;
    void clear() override;
    void update(sf::RenderWindow* window, sf::Clock& c) override;
    void render(sf::RenderWindow* window) override;
    void handle_input(sf::RenderWindow* window, sf::Event& e, sf::Clock& c) override;
private:
    Button* logo;
    Button* button_resume;
    //Button* button_settings;
    Button* button_menu;
};
