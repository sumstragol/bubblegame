//
//  game.cpp
//  sfmll
//
//  Created by Mikolaj Brozek on 01/11/2021.
//  Copyright © 2021 Mikolaj Brozek. All rights reserved.
//

#include "game.hpp"

Game::Game()
{
    window = new sf::RenderWindow(sf::VideoMode(settings::SCREEN_WIDTH, settings::SCREEN_HEIGHT), settings::TITLE);
    window->setFramerateLimit(settings::FPS);
    window->clear();
    p = new Player();
    
    balls.push_back(new Ball(Ball_size::large));
}

const bool Game::is_running() const
{
    return window->isOpen();
}

void Game::poll_events()
{
    while (window->pollEvent(e))
    {
        switch (e.type)
        {
            case sf::Event::Closed:
                window->close();
                break;
            case sf::Event::KeyPressed:
                if (e.key.code == sf::Keyboard::A)
                {
                    p->move_player(window, Move_direction::left);
                }
                else if (e.key.code == sf::Keyboard::D)
                {
                    p->move_player(window, Move_direction::right);
                }
                else if (e.key.code == sf::Keyboard::T)
                {
                    Ball::double_ball(balls, 0);
                }
                break;
            default:
                break;
        }
    }
}

void Game::update()
{
    poll_events();
    
    for (auto it : balls)
    {
        it->ball_dispalcement(window);
    }
}

void Game::render()
{
    window->clear();
    
    window->draw(p->get_player_sprite());
    
    for (auto it : balls)
    {
        window->draw(it->get_ball_sprite());
    }
    
    
    window->display();
}

void Game::run()
{
    while (is_running())
    {
        update();
        render();
    }
}
