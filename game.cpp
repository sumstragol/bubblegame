#include "game.hpp"

Game::Game()
{
    window = new sf::RenderWindow(sf::VideoMode(settings::SCREEN_WIDTH, settings::SCREEN_HEIGHT), settings::TITLE);
    window->setFramerateLimit(settings::FPS);
    window->clear();
    
    Ball* b = new Ball_large();

    balls.push_back(b);

    p = new Player();
}

void Game::run()
{
    while (window->isOpen())
    {
        poll_events();
        update();
        render();
    }
}

bool Game::is_running() const
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
                p->move(window, Move_direction::left);
            }
            if (e.key.code == sf::Keyboard::D)
            {
                p->move(window, Move_direction::right);
            }
        case sf::Event::MouseButtonPressed:
            if (e.mouseButton.button == sf::Mouse::Left)
            {
                if (bullets.size() < 1)
                {
                    bullets.push_back(new Bullet(p, (sf::Vector2f)sf::Mouse::getPosition(*window)));
                }
            }
        }
    }
}

void Game::update()
{
    for (auto& it : balls)
    {
        it->move(window);
    }

    for (auto& it : bullets)
    {
        it->move(window, bullets);
    }

    for (auto& it : balls)
    {
        for (auto& single_bullet : bullets)
        {
            if (it->got_hit(single_bullet->get_sprite()))
            {
                it->double_ball(balls);
                single_bullet->remove(bullets);
                break;
            }   
        }
    }
}

void Game::render()
{
    window->clear();

    for (auto& it : balls)
    {
        it->draw(window);
    }

    for (auto& it : bullets)
    {
        it->draw(window);
    }

    p->draw(window);

    window->display();
}