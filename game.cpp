#include "game.hpp"

using namespace settings;

Game::Game()
    :points(0),
    lives(3),
    current_level_index(1),
    selected_level_index(0)
{
    window = new sf::RenderWindow(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), TITLE, sf::Style::Titlebar | sf::Style::Close);
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
    
    // buttons for count down before any level 
    for (int i = 0; i < count_down_seconds; i++)
    {
        buttons_count_down_numbers.at(i) = new Button(
            585 + i * 150,
            400,
            BUTTON_L_TEX_PATH,
            BUTTON_HOVER_L_TEX_PATH,
            std::to_string(count_down_seconds - i)
        );
    }

    // buttons for levels
    for (int i = 0; i < level_paths.size(); i++)
    {
        buttons_for_levels.at(i) = new Button(
            200 + i * 150,
            400,
            BUTTON_L_TEX_PATH,
            BUTTON_HOVER_L_TEX_PATH,
            std::to_string(i + 1)
        );
    }
    
    p = new Player();
    
    sc = new Scoreboard();
    sc->set_value(Value_type::lives, lives);
    sc->set_value(Value_type::points, points);
    sc->set_value(Value_type::level, current_level_index);

    timer = new Timer(0.f);
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
                return;
            }
            else if (state == Game_state::Count_down)
            {
                return;
            }
            else if (state == Game_state::Game)
            {
                if (e.key.code == sf::Keyboard::A)
                {
                    p->move(window, Move_direction::left, clock);
                }
                if (e.key.code == sf::Keyboard::D)
                {
                    p->move(window, Move_direction::right, clock);
                }
                if (e.key.code == sf::Keyboard::Escape)
                {
                    state = Game_state::Pause;
                }

                return;
            }
            else if (state == Game_state::Pause)
            {
                if (e.key.code == sf::Keyboard::Escape)
                {
                    state = Game_state::Count_down;
                    count_down_level();
                }

                return;
            }
            
        }
        case sf::Event::KeyReleased:
        {
            if (e.key.code == sf::Keyboard::A)
            {
                p->refresh(Move_direction::left);
            }
            if (e.key.code == sf::Keyboard::D)
            {
                p->refresh(Move_direction::right);
            }

            return;
        }
        case sf::Event::MouseButtonPressed:
        {
            if (state == Game_state::Menu)
            {
                if (e.mouseButton.button == sf::Mouse::Left)
                {
                    if (button_play->is_hovering())
                    {
                        state = Game_state::Level;
                    }
                    if (button_exit->is_hovering())
                    {
                        window->close();
                    }
                    /*
                    if (button_settings->is_hovering())
                    {

                    }
                    */
                }

                return;
            }
            else if (state == Game_state::Count_down)
            {
                return;
            }
            else if (state == Game_state::Game)
            {
                if (e.mouseButton.button == sf::Mouse::Left)
                {
                    if (bullets.size() < 1)
                    {
                        bullets.push_back(
                            new Bullet(sf::Vector2f(
                                p->get_sprite().getPosition().x + p->get_sprite().getGlobalBounds().width / 4,
                                p->get_sprite().getPosition().y + p->get_sprite().getGlobalBounds().height / 4
                            ),
                            (sf::Vector2f)sf::Mouse::getPosition(*window))
                        );
                    }
                }

                return;
            }
            else if (state == Game_state::Pause)
            {
                if (e.mouseButton.button == sf::Mouse::Left)
                {
                    if (button_resume->is_hovering())
                    {
                        state = Game_state::Count_down;
                        count_down_level();
                    }
                    /*
                    if (button_settings->is_hovering())
                    {

                    }
                    */
                    if (button_menu->is_hovering())
                    {
                        state = Game_state::Menu;
                        clear_level();
                    }

                    return;
                }
            }
            else if (state == Game_state::Level)
            {
                if (e.mouseButton.button == sf::Mouse::Left)
                {
                    if (button_menu->is_hovering())
                    {
                        state = Game_state::Menu;
                        return;
                    }
                    
                    std::for_each_n(buttons_for_levels.begin(), current_level_index,
                        [this, indx = 0](auto& single_button) mutable
                        {
                            if (single_button->is_hovering())
                            {
                                run_level(indx);

                                return;
                            }
                        
                            indx++;
                        }
                    );
                }
            }
            /*
            else if (state == Game_state::Settings)
            {
             
            }
            */
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

        // checks for balls collision with a bullets
        for (auto& it : balls)
        {
            for (auto& single_bullet : bullets)
            {
                if (it->got_hit(single_bullet->get_sprite()))
                {
                    it->double_ball(balls);
                    single_bullet->remove(bullets);
                    points += 15;
                    sc->set_value(Value_type::points, points);
                    
                    check_for_win();
                    break;
                }
            }
        }

        // checks for balls collision with a player
        for (auto& single_ball : balls)
        {
            if (p->got_hit(single_ball->get_sprite()))
            {
                level_fail();
            }
        }
        
        if (timer->is_running())
        {
            timer->update(window);
        }
        else
        {
            level_fail();
        }
    }
    else 
    {
        sf::Vector2f mouse_pos = (sf::Vector2f)sf::Mouse::getPosition(*window);

        button_menu->hover(mouse_pos);
        //button_settings->hover(mouse_pos);

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
        else if (state == Game_state::Level)
        {       
            // level buttons
            std::for_each_n(buttons_for_levels.begin(), current_level_index,
                [&mouse_pos](auto& single_button)
                {
                    single_button->hover(mouse_pos);
                }
            );
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
    else if (state == Game_state::Level)
    {
        window->clear(MENU_COLOR_BACKGROUND);
        logo->draw(window);
        
        button_menu->draw(window);
        
        for (const auto& single_button : buttons_for_levels)
        {
            single_button->draw(window);
        }
    }
    /*
    else if (state == Game_state::Settings)
    {

    }
    */
    else if (state == Game_state::Game || state == Game_state::Count_down)
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

        if (state == Game_state::Count_down)
        {
            for (const auto& single_button : buttons_count_down_numbers)
            {
                single_button->draw(window);
            }
        }
    }
    
    window->display();
}

void Game::count_down_level()
{
    for (int i = 0; i < count_down_seconds; i++)
    {
        for (int j = 0; j < count_down_seconds; j++)
        {
            if (i == j)
            {
                buttons_count_down_numbers.at(j)->get_caption_text()->set_color(sf::Color::Red);
            }
            else
            {
                buttons_count_down_numbers.at(j)->get_caption_text()->set_color(sf::Color::Black);
            }
        }

        render();
        util::my_sleep(1000);
    }

    // empty queque of events happend in count down state
    while (window->pollEvent(e)) {}

    state = Game_state::Game;
}

void Game::run_level(const int index)
{
    clear_level();
    selected_level_index = index;

    float temp;
    Level::load_level(level_paths.at(selected_level_index), balls, temp);
    timer->set_time(temp);
    sc->set_value(Value_type::level, selected_level_index + 1);
    
    state = Game_state::Count_down;
    count_down_level();
}

void Game::resume_level()
{
    state = Game_state::Count_down;
    count_down_level();
}

void Game::clear_level()
{
    // reset player position
    p->set_pos_x(settings::SCREEN_WIDTH / 2 - p->get_tex().getSize().x / 2);
    p->set_pos_y(settings::SCREEN_HEIGHT - p->get_tex().getSize().y);

    // clear balls content
    std::for_each(balls.begin(), balls.end(),
        [](auto& it)
        {
            delete it;
        }
    );
    balls.clear();

    // clear bullets content
    std::for_each(bullets.begin(), bullets.end(),
        [](auto& it)
        {
            delete it;
        }
    );
    bullets.clear();

    // reset timer
    timer->reset();
}

void Game::check_for_win()
{
    if (balls.empty())
    {
        state = Game_state::Level;
        if (current_level_index < level_count &&
            current_level_index - 1 == selected_level_index
            )
        {
            current_level_index++;
        }
    }
}

void Game::level_fail()
{
    util::my_sleep(1000);
    
    if (lives == 1)
    {
        // refresh last selected level button
        buttons_for_levels.at(current_level_index - 1)->hover(sf::Vector2f(0.f, 0.f));

        clear_level();
        current_level_index = 1;
        lives = 3;
        points = 0;
        sc->set_value(Value_type::level, current_level_index);
        sc->set_value(Value_type::lives, lives);
        sc->set_value(Value_type::points, points);
        state = Game_state::Menu;
        return;
    }
    
    lives--;
    sc->set_value(Value_type::lives, lives);
    run_level(current_level_index - 1);
}
