#include "pause_state.hpp"

Pause_State::Pause_State()
{
    this->init_buttons();
}

void Pause_State::init_buttons()
{
    const int mid = 500;
    this->logo = new Button(mid, 100, settings::BUTTON_TEX_PATH, settings::BUTTON_HOVER_TEX_PATH, "BUBBLE");
    this->button_resume = new Button(mid, 400, settings::BUTTON_TEX_PATH, settings::BUTTON_HOVER_TEX_PATH, "RESUME");
    //this->button_settings = new Button(mid, 600, settings::BUTTON_TEX_PATH, settings::BUTTON_HOVER_TEX_PATH, "SETTINGS");
    this->button_menu = new Button(mid, 800, settings::BUTTON_TEX_PATH, settings::BUTTON_HOVER_TEX_PATH, "MENU");
}

void Pause_State::clear()
{
    delete this->logo;
    delete this->button_resume;
    //delete this->button_settings;
    delete this->button_menu;
}

void Pause_State::update(sf::RenderWindow* window, sf::Clock& c)
{
    sf::Vector2f mouse_pos = (sf::Vector2f)sf::Mouse::getPosition(*window);
    this->button_resume->hover(mouse_pos);
    //this->button_settings->hover(mouse_pos);
    this->button_menu->hover(mouse_pos);
}

void Pause_State::render(sf::RenderWindow *window)
{
    window->clear(settings::MENU_COLOR_BACKGROUND);
    
    this->logo->draw(window);
    this->button_resume->draw(window);
    //this->button_settings->draw(window);
    this->button_menu->draw(window);
}

void Pause_State::handle_input(sf::RenderWindow* window, sf::Event& e, sf::Clock& c)
{
    while (window->pollEvent(e))
    {
        switch (e.type)
        {
        case sf::Event::MouseButtonPressed:
        {
            if (e.mouseButton.button == sf::Mouse::Left)
            {
                if (button_resume->is_hovering())
                {
                    quit();
                }
                /*
                if (button_settings->is_hovering())
                {
                    
                }
                */
                if (button_menu->is_hovering())
                {
                    other_requested_state = new Menu_State();
                    quit();
                }
            }
        }
        default:
            break;
        }
    }
}
