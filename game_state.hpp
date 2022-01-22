#pragma once

#include "includes.hpp"
#include "states_includes.hpp"

#include "button.hpp"
#include "ball.hpp"
#include "bullet.hpp"
#include "player.hpp"
#include "scoreboard.hpp"
#include "timer.hpp"
#include "level_loader.hpp"
#include "game_data.hpp"

class Game_State : public State
{
public:
    Game_State(const std::string& level_path);
    void init_buttons() override;
    void init_game_objects(const std::string& level_path);
    void clear() override;
    void update(sf::RenderWindow* window, sf::Clock& c) override;
    void render(sf::RenderWindow* window) override;
    void handle_input(sf::RenderWindow* window, sf::Event& e, sf::Clock& c) override;
private:
    void quit() override;
    void restart_level();
    void finish_level();
    
    Container data;
    Container init_data {0, 0, 0};
    std::string init_level_path;
    int current_level_index;
    
    Player* p;
    std::vector<Ball*> balls;
    std::vector<Bullet*> bullets;
    Scoreboard* sc;
    Timer* timer;
};
