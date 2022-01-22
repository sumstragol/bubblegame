#include "game_state.hpp"

Game_State::Game_State(const std::string& level_path)
{
    this->init_level_path = level_path;
    this->init_buttons();
    this->init_game_objects(level_path);
}

void Game_State::init_buttons()
{
    
}

void Game_State::init_game_objects(const std::string& level_path)
{
    p = new Player();
    p->set_pos_x((float)(settings::SCREEN_WIDTH / 2 - p->get_rect_cor().width / 2));
    p->set_pos_y((float)(settings::SCREEN_HEIGHT - p->get_tex().getSize().y));
    
    sc = new Scoreboard();
    
    if (!this->init_data.lives)
    {
        Container temp;
        Game_Data::read_stats(temp);
        this->init_data = temp;
        this->data.lives = temp.lives;
        this->data.points = temp.points;
        this->data.level = temp.level;
    }
    
    sc->set_value(Value_type::lives, this->data.lives);
    sc->set_value(Value_type::points, this->data.points);
    
    timer = new Timer(0.f);
    float tempt;
    int temp_level_index;
    Level::load_level(level_path, balls, tempt, temp_level_index);
    
    this->sc->set_value(Value_type::level, temp_level_index);
    
    
    timer->set_time(tempt);
}

void Game_State::clear()
{
    delete p;
    delete sc;
    delete timer;
    
    for (auto& it : balls)
    {
        delete it;
    }
    balls.clear();
    
    for (auto &it : bullets)
    {
        delete it;
    }
    bullets.clear();
}

void Game_State::update(sf::RenderWindow* window, sf::Clock& c)
{
    for (auto& it : balls)
    {
        it->move(window);
    }
    
    for (auto& it : bullets)
    {
        it->move(window, bullets);
    }
    
    // if any ball got hit with the bullet
    for (auto& it : balls)
    {
        for (auto& single_bullet : bullets)
        {
            if (it->got_hit(single_bullet->get_sprite()))
            {
                it->double_ball(balls);
                single_bullet->remove(bullets);
                this->data.points += 15;
                sc->set_value(Value_type::points, this->data.points);
                
                if (balls.size() == 0)
                {
                    this->finish_level();
                }
                
                break;
            }
        }
    }
    
    // if any ball hit player
    for (auto& single_ball : balls)
    {
        if (p->got_hit(single_ball->get_sprite()))
        {
            this->restart_level();
        }
    }
    
    // timer update
    if (timer->is_running())
    {
        timer->update(window);
    }
    else
    {
        this->restart_level();
    }
}

void Game_State::render(sf::RenderWindow *window)
{
    window->clear(settings::GAME_COLOR_BACKGROUND);

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

void Game_State::handle_input(sf::RenderWindow* window, sf::Event& e, sf::Clock& c)
{
    while (window->pollEvent(e))
    {
        switch (e.type)
        {
        case sf::Event::MouseButtonPressed:
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
                
                return;
            }
        }
        case sf::Event::KeyPressed:
        {
            if (e.key.code == sf::Keyboard::A)
            {
                p->move(window, Move_direction::left, c);
            }
            if (e.key.code == sf::Keyboard::D)
            {
                p->move(window, Move_direction::right, c);
            }
            if (e.key.code == sf::Keyboard::Escape)
            {
                other_requested_state = new Pause_State();
                pause();
            }
            
            return;
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
        }
        default:
            break;
        }
    }
}

void Game_State::restart_level()
{
    this->data.lives--;
    if (!this->data.lives)
    {
        other_requested_state = new Menu_State();
        quit();
    }
    
    util::my_sleep(1000);
    clear();
    init_game_objects(this->init_level_path);
}

void Game_State::finish_level()
{
    util::my_sleep(1000);
    this->data.level++;
    Game_Data::load_stats(data);
    other_requested_state = new Level_State();
    quit();
}

void Game_State::quit()
{
    if (data.lives == 0)
    {
        this->data.lives = 10;
        this->data.points = 0;
        this->data.level = 1;
        Game_Data::load_stats(this->data);
    }
    else if (!(init_data == data))
    {
        Game_Data::load_stats(data);
    }
    
    
    this->active = false;
}
