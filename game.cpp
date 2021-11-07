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
    p_gun = new Pistol(window);
    
    balls.push_back(new Ball_large());
}

const bool Game::is_running() const
{
    return window->isOpen();
}

// chgane the logic - thread waiting for event to happen instead of cheking it in a while loop

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
                    balls[0]->double_ball(balls, 0);
                }
                break;
            case sf::Event::MouseButtonPressed:
                if (e.mouseButton.button == sf::Mouse::Left)
                {
                    p_gun->shoot(p->get_player_sprite().getPosition(),
                                 (sf::Vector2f)sf::Mouse::getPosition(*window)
                                 );
                }
                
            default:
                break;
        }
    }
}

void Game::update()
{
    poll_events();
    
    for (auto &it : balls)
    {
        it->ball_dispalcement(window);
    }
    
    p_gun->move_bullets();
    
    for (auto &it : balls)
    {
        if (util::is_colliding(it->get_ball_sprite(), p->get_player_sprite()))
        {
            //
        }
    }
    
    int g = 0;
    int h = 0;
    
    if (util::is_colliding(&balls, p_gun->magazine_pointer(), g, h))
    {
        balls.at(g)->double_ball(balls, g);
    }
}

void Game::render()
{
    window->clear();
    
    window->draw(p->get_player_sprite());
    
    p_gun->render_bullets();
    
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
