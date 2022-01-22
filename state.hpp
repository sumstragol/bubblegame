#pragma once

#include "includes.hpp"

class State
{
public:
    virtual ~State() = default;
    virtual void init_buttons() = 0;
    virtual void clear() = 0;
    virtual void update(sf::RenderWindow* window, sf::Clock& c) = 0;
    virtual void render(sf::RenderWindow* window) = 0;
    virtual void handle_input(sf::RenderWindow* window, sf::Event& e, sf::Clock& c) = 0;
    
    const bool is_active() const { return this->active; }
    const bool is_paused() const { return this->paused; }
    virtual void quit() { this->active = false; }
    void pause() { this->paused = true; }
    void resume() { this->paused = false; }
    
    const bool is_other_state_request_valid() { return other_requested_state; }
    State* other_state_request() { if (is_other_state_request_valid()) return other_requested_state; }
    void free_other_state_request() { delete other_requested_state; other_requested_state = nullptr; }
protected:
    

    State* other_requested_state = nullptr;
    bool active = true;
    bool paused = false;
};
