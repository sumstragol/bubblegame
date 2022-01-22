#include "levels_state.hpp"

Level_State::Level_State()
{
    Container temp;
    Game_Data::read_stats(temp);
    this->max_level = temp.level * 1;
    this->current_page = temp.level / 16;
    
    this->init_levels_paths();
    this->init_buttons();
    
    this->max_pages = ceil(this->levels_paths.size() / 16.0);
}

void Level_State::init_levels_paths()
{
    this->levels_paths.push_back("levels/level1.txt");
    this->levels_paths.push_back("levels/level2.txt");
    this->levels_paths.push_back("levels/level3.txt");
    this->levels_paths.push_back("levels/level4.txt");
    this->levels_paths.push_back("levels/level5.txt");
    this->levels_paths.push_back("levels/level6.txt");
    this->levels_paths.push_back("levels/level7.txt");
    this->levels_paths.push_back("levels/level8.txt");
    this->levels_paths.push_back("levels/level9.txt");
    this->levels_paths.push_back("levels/level10.txt");
    this->levels_paths.push_back("levels/level11.txt");
    this->levels_paths.push_back("levels/level12.txt");
    this->levels_paths.push_back("levels/level13.txt");
    this->levels_paths.push_back("levels/level14.txt");
    this->levels_paths.push_back("levels/level15.txt");
    this->levels_paths.push_back("levels/level16.txt");
    this->levels_paths.push_back("levels/level17.txt");
    this->levels_paths.push_back("levels/level18.txt");
    this->levels_paths.push_back("levels/level19.txt");
    this->levels_paths.push_back("levels/level20.txt");
}

void Level_State::init_buttons()
{
    const int mid = 500;
    this->logo = new Button(mid, 100, settings::BUTTON_TEX_PATH, settings::BUTTON_HOVER_TEX_PATH, "BUBBLE");
    this->button_menu = new Button(mid, 800, settings::BUTTON_TEX_PATH, settings::BUTTON_HOVER_TEX_PATH, "MENU");
    this->left_arrow = new Button(50, 480, settings::BUTTON_L_TEX_PATH, settings::BUTTON_HOVER_L_TEX_PATH, "<-");
    this->right_arrow = new Button(1400, 480, settings::BUTTON_L_TEX_PATH, settings::BUTTON_HOVER_L_TEX_PATH, "->");
    
    float temp_x = 0;
    float temp_y = 400.f;
    for (size_t i = 0; i < levels_paths.size(); i++)
    {
         buttons_levels.push_back(
            new Button(
                static_cast<float>(200 + temp_x * 150),
                temp_y,
                settings::BUTTON_L_TEX_PATH,
                settings::BUTTON_HOVER_L_TEX_PATH,
                std::to_string(i + 1)
            )
        );
        
        temp_x += 1;
        
        if (i != 0 && (i + 1) % 8 == 0)
        {
            temp_x = 0.f;
            temp_y += 150.f;
        }
        
        if (i != 0 && (i + 1) % 16 == 0)
        {
            temp_x = 0.f;
            temp_y = 400.0f;
        }
    }
    
    // twoja stara
    for (auto& it : buttons_levels)
    {
        it->get_caption_text(Button_tex_type::regular)->set_font_size(80);
        it->get_caption_text(Button_tex_type::hover)->set_font_size(80);
        it->update_text_cor(Button_tex_type::regular);
        it->update_text_cor(Button_tex_type::hover);
    }
    
    std::for_each_n(this->buttons_levels.begin(), this->max_level - 1,
        [this](auto& single_button)
        {
            single_button->get_caption_text()->set_color(sf::Color::Red);
        }
    );
}

void Level_State::clear()
{
    delete logo;
    delete button_menu;
    delete left_arrow;
    delete right_arrow;
    
    for (auto& it : this->buttons_levels)
    {
        delete it;
    }
    
    this->buttons_levels.clear();
}

void Level_State::update(sf::RenderWindow* window, sf::Clock& c)
{
    sf::Vector2f mouse_pos = (sf::Vector2f)sf::Mouse::getPosition(*window);
    this->button_menu->hover(mouse_pos);
    this->left_arrow->hover(mouse_pos);
    this->right_arrow->hover(mouse_pos);
    
    for (unsigned i = this->current_page * 16, j = 0; i < this->max_level; i++, j++)
    {
        this->buttons_levels.at(i)->hover(mouse_pos);
        
        if (j == 15)
        {
            break;
        }
    }
}

void Level_State::render(sf::RenderWindow *window)
{
    window->clear(settings::MENU_COLOR_BACKGROUND);
    
    this->logo->draw(window);
    this->button_menu->draw(window);
    this->left_arrow->draw(window);
    this->right_arrow->draw(window);
    
    for (unsigned i = current_page * 16, j = 0; i < buttons_levels.size(); i++, j++)
    {
        buttons_levels.at(i)->draw(window);
        
        if (j == 15)
        {
            break;
        }
    }
}

void Level_State::handle_input(sf::RenderWindow* window, sf::Event& e, sf::Clock& c)
{
    while (window->pollEvent(e))
    {
        switch (e.type)
        {
        case sf::Event::MouseButtonPressed:
        {
            if (e.mouseButton.button == sf::Mouse::Left)
            {
                if (button_menu->is_hovering())
                {
                    this->other_requested_state = new Menu_State();
                    this->quit();
                }
                
                if (right_arrow->is_hovering())
                {
                    this->current_page = (this->current_page + 1) % this->max_pages;
                }
                
                if (left_arrow->is_hovering())
                {
                    this->current_page = (this->current_page - 1) % this->max_pages;
                }
                
                for (unsigned i = this->current_page * 16, j = 0; i < this->buttons_levels.size(); i++, j++)
                {
                    if (this->buttons_levels.at(i)->is_hovering())
                    {
                        this->other_requested_state = new Game_State(this->levels_paths.at(i));
                        this->quit();
                    }
                    
                    if (j == 15)
                    {
                        break;
                    }
                }
            }
        }
        default:
            break;
        }
    }
}
