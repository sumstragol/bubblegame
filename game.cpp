#include "game.hpp"

using namespace settings;

Game::Game()
    :points(0),
    lives(1)
{
    window = new sf::RenderWindow(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), TITLE);
    window->setFramerateLimit(FPS);
    window->clear();
    
    state = Game_state::Menu;

    const int temp_x = 500;

    logo = new Button(temp_x, 100, BUTTON_TEX_PATH, BUTTON_HOVER_TEX_PATH, "BUBBLE");
    button_menu = new Button(temp_x, 800, BUTTON_TEX_PATH, BUTTON_HOVER_TEX_PATH, "MENU");
    button_play = new Button(temp_x, 400, BUTTON_TEX_PATH, BUTTON_HOVER_TEX_PATH, "PLAY");
    button_resume = new Button(temp_x, 400, BUTTON_TEX_PATH, BUTTON_HOVER_TEX_PATH, "RESUME");
    button_settings = new Button(temp_x, 600, BUTTON_TEX_PATH, BUTTON_HOVER_TEX_PATH, "SETTINGS");
    button_exit = new Button(temp_x, 800, BUTTON_TEX_PATH, BUTTON_HOVER_TEX_PATH, "EXIT");


    Ball* b = new Ball_large();

    balls.push_back(b);

    p = new Player();
    
    sc = new Scoreboard();
    sc->set_value("Lives: " + std::to_string(1), Values_type::lives);
    sc->set_value("Points: " + std::to_string(0), Values_type::points);
    sc->set_value("Level: " + std::to_string(0) , Values_type::level);
    
    timer = new Timer(0.8f);
}

void Game::run()
{
    while (is_running())
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
        {
            window->close();
            break;
        }
        case sf::Event::KeyPressed:
        {
            if (state == Game_state::Menu)
            {

            }
            else if (state == Game_state::Game)
            {
                if (e.key.code == sf::Keyboard::S)
                {
                    p->move(window, Move_direction::left);
                }
                if (e.key.code == sf::Keyboard::D)
                {
                    p->move(window, Move_direction::right);
                }
                if (e.key.code == sf::Keyboard::Escape)
                {
                    state = Game_state::Pause;
                }
            }
            else if (state == Game_state::Pause)
            {
                if (e.key.code == sf::Keyboard::Escape)
                {
                    state = Game_state::Game;
                }
            }
        }
        case sf::Event::MouseButtonPressed:
        {
            if (state == Game_state::Menu)
            {
                if (e.mouseButton.button == sf::Mouse::Left)
                {
                    if (button_play->is_hovering())
                    {
                        state = Game_state::Game;
                    }
                    if (button_exit->is_hovering())
                    {
                        window->close();
                    }
                }
            }
            else if (state == Game_state::Game)
            {
                if (e.mouseButton.button == sf::Mouse::Left)
                {
                    if (bullets.size() < 1)
                    {
                        bullets.push_back(new Bullet(
                            sf::Vector2f(
                                p->get_sprite().getPosition().x + p->get_sprite().getGlobalBounds().width / 4,
                                p->get_sprite().getPosition().y + p->get_sprite().getGlobalBounds().height / 4
                            ),
                            (sf::Vector2f)sf::Mouse::getPosition(*window))
                        );
                    }
                }
            }
            else if (state == Game_state::Pause)
            {
                if (e.mouseButton.button == sf::Mouse::Left)
                {
                    if (button_resume->is_hovering())
                    {
                        state = Game_state::Game;
                    }
                    if (button_settings->is_hovering())
                    {

                    }
                    if (button_menu->is_hovering())
                    {
                        state = Game_state::Menu;
                    }
                }
            }
        }
        }
    }
}

void Game::update()
{
    if (state == Game_state::Game)
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
                    points += 15;
                    sc->set_value("Points: " + std::to_string(points), Values_type::points);
                    break;
                }
            }
        }

        if (timer->is_running())
        {
            timer->update(window);
        }
    }
    else 
    {
        sf::Vector2f mouse_pos = (sf::Vector2f)sf::Mouse::getPosition(*window);

        button_menu->hover(mouse_pos);
        button_settings->hover(mouse_pos);

        if (state == Game_state::Pause)
        {
            button_resume->hover(mouse_pos);

            button_exit->hover(mouse_pos);
        }
        else if (state == Game_state::Menu)
        {
            button_play->hover(mouse_pos);
            button_exit->hover(mouse_pos);
        }
    }

}

void Game::render()
{
    window->clear();

    if (state == Game_state::Menu || state == Game_state::Pause)
    {
        window->clear(MENU_COLOR_BACKGROUND);
        logo->draw(window);
        button_settings->draw(window);
        
        if (state == Game_state::Menu)
        {
            button_play->draw(window);
            button_exit->draw(window);
        }
        else if (state == Game_state::Pause)
        {
            button_resume->draw(window);
            button_menu->draw(window);
        }
    }
    else if (state == Game_state::Game)
    {
        for (auto& it : balls)
        {
            it->draw(window);
        }

        for (auto& it : bullets)
        {
            it->draw(window);
        }

        p->draw(window);

        timer->draw(window);

        sc->draw(window);
    }
    
    window->display();
}
