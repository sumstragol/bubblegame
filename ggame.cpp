#include "ggame.hpp"

using namespace settings;

GGame::GGame()
{
    this->window = new sf::RenderWindow(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), TITLE, sf::Style::Titlebar | sf::Style::Close);
    this->window->setFramerateLimit(FPS);
    this->window->clear();
    
    this->init_states();
}

void GGame::init_states()
{
    this->states.push(new Menu_State());
}

void GGame::push_new_state()
{
    State* temp = this->states.top()->other_state_request();
    this->states.push(temp);
}

void GGame::replace_current_state()
{
    State* temp = this->states.top()->other_state_request();
    
    while (this->states.size())
    {
        this->states.top()->quit();
        this->states.top()->clear();
        delete this->states.top();
        this->states.pop();
    }

    this->states.push(temp);
}

void GGame::delete_current_state()
{
    this->states.top()->clear();
    delete this->states.top();
    this->states.pop();
    
    if (this->states.size() == 1)
    {
        this->states.top()->resume();
    }
    
    if (this->states.size() == 0)
    {
        this->window->close();
    }
}

void GGame::run()
{
    while (this->window->isOpen())
    {
        this->update();
        this->render();
    }
}

void GGame::update()
{
    this->states.top()->update(window, clock);
    this->states.top()->handle_input(window, e, clock);
    
    if (!this->states.top()->is_active())
    {
        if (this->states.top()->is_other_state_request_valid())
        {
            this->replace_current_state();
        }
        else
        {
            this->delete_current_state();
        }

        return;
    }
    
    if (this->states.top()->is_paused())
    {
        this->push_new_state();
    }
        
}

void GGame::render()
{
    if (this->states.empty())
        return;
    
    this->states.top()->render(window);
    this->window->display();
}
