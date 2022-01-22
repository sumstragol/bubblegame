#include "menu_state.hpp"

Menu_State::Menu_State()
{
    this->init_buttons();
}

void Menu_State::init_buttons()
{
    const int mid = 500;
    this->logo = new Button(mid, 100, settings::BUTTON_TEX_PATH, settings::BUTTON_HOVER_TEX_PATH, "BUBBLE");
    this->button_play = new Button(mid, 400, settings::BUTTON_TEX_PATH, settings::BUTTON_HOVER_TEX_PATH, "PLAY");
    //this->button_settings = new Button(mid, 600, settings::BUTTON_TEX_PATH, settings::BUTTON_HOVER_TEX_PATH, "SETTINGS");
    this->button_exit = new Button(mid, 800, settings::BUTTON_TEX_PATH, settings::BUTTON_HOVER_TEX_PATH, "EXIT");
}

void Menu_State::clear()
{
    delete logo;
    delete button_play;
    //delete button_settings;
    delete button_exit;
}

void Menu_State::update(sf::RenderWindow* window, sf::Clock& c)
{
    sf::Vector2f mouse_pos = (sf::Vector2f)sf::Mouse::getPosition(*window);
    this->button_play->hover(mouse_pos);
    //this->button_settings->hover(mouse_pos);
    this->button_exit->hover(mouse_pos);
}

void Menu_State::render(sf::RenderWindow *window)
{
    window->clear(settings::MENU_COLOR_BACKGROUND);
    
    this->logo->draw(window);
    this->button_play->draw(window);
    //this->button_settings->draw(window);
    this->button_exit->draw(window);
}

void Menu_State::handle_input(sf::RenderWindow* window, sf::Event& e, sf::Clock& c)
{
    while (window->pollEvent(e))
    {
        switch (e.type)
        {
        case sf::Event::MouseButtonPressed:
        {
            if (e.mouseButton.button == sf::Mouse::Left)
            {
                if (button_play->is_hovering())
                {
                    other_requested_state = new Level_State();
                    quit();
                }
                
                /*
                if (button_settings->is_hovering())
                {
                    
                }
                */
                 
                if (button_exit->is_hovering())
                {
                    quit();
                }
            }
        }
        default:
            break;
        }
    }
}
