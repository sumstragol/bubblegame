//
//  game.hpp
//  sfmll
//
//  Created by Mikolaj Brozek on 01/11/2021.
//  Copyright © 2021 Mikolaj Brozek. All rights reserved.
//
#pragma once

#include <vector>
#include <thread>
#include <chrono>
#include <future>
#include <mutex>


#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include "settings.hpp"
#include "util.hpp"
#include "player.hpp"
#include "bullet.hpp"
#include "pistol.hpp"
#include "ball.hpp"

class Player;
class Bullet;
class Pistol;
class Ball;

enum class Move_direction
{
    left, right
};

class Game
{
public:
    Game();
    void run();
private:
    const bool is_running() const;
    void poll_events();
    void update();
    void render();
    
    sf::RenderWindow* window;
    sf::Event e;
    
    Player* p;
    Pistol* p_gun;
    std::vector<Ball*> balls;
};
