#pragma once

#include "includes.hpp"
#include "states_includes.hpp"
#include "button.hpp"
#include "game_data.hpp"

class Level_State : public State
{
public:
    Level_State();
    void init_levels_paths();
    void init_buttons() override;
    void clear() override;
    void update(sf::RenderWindow* window, sf::Clock& c) override;
    void render(sf::RenderWindow* window) override;
    void handle_input(sf::RenderWindow* window, sf::Event& e, sf::Clock& c) override;
private:
    Button* logo;
    Button* button_menu;
    Button* left_arrow;
    Button* right_arrow;
    std::vector<Button*> buttons_levels;
    std::vector<std::string> levels_paths;
    
    unsigned int current_page;
    unsigned int max_pages;
    unsigned int max_level;
};

