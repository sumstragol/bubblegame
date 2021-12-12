#pragma once

#include "includes.hpp"


namespace settings
{
    //window
    const std::string TITLE = "Bubble";
    const int SCREEN_WIDTH = 1600;
    const int SCREEN_HEIGHT = 1200;
    const unsigned int FPS = 60;
    //state menu
    const sf::Color MENU_COLOR_BACKGROUND = sf::Color::Color(112, 156, 122, 0);
    const std::string LOGO_TEX = "textures/logo.png";
    const std::string BUTTON_MENU = "textures/button_menu.png";
    const std::string BUTTON_MENU_HOVER = "textures/button_menu_hover.png";
    const std::string BUTTON_PLAY = "textures/button_play.png";
    const std::string BUTTON_PLAY_HOVER = "textures/button_play_hover.png";
    const std::string BUTTON_RESUME = "textures/button_resume.png";
    const std::string BUTTON_RESUME_HOVER = "textures/button_resume_hover.png";
    const std::string BUTTON_SETTINGS = "textures/button_settings.png";
    const std::string BUTTON_SETTINGS_HOVER = "textures/button_settings_hover.png";
    const std::string BUTTON = "textures/button.png";
    const std::string BUTTON_HOVER = "textures/button_hover.png";
    //state pause

    //player
    const std::string PLAYER_STAND_TEX_PATH = "textures/player_stand.png";
    const std::string PLAYER_MOVE_1_TEX_PATH = "textures/player_move_1.png";
    const std::string PLAYER_MOVE_2_TEX_PATH = "textures/player_move_2.png";
    const float PLAYER_SPEED = 20.f;
    //ball
    const std::string BALL_TEX_PATH = "textures/ball.png";
    const float BALL_SCALE_LARGE = 3.f;
    const float BALL_SCALE_MEDIUM = 2.f;
    const float BALL_SCALE_SMALL = 1.f;
    const sf::Color BALL_COLOR_LARGE = sf::Color::Red;
    const sf::Color BALL_COLOR_MEDIUM = sf::Color::Yellow;
    const sf::Color BALL_COLOR_SMALL = sf::Color::Green;
    const float BALL_VERTICAL_SPEED = 0.f;
    const float BALL_HORIZONTAL_SPEED = 4.f;
    const float BALL_GRAVITY = 0.5f;
    const float BALL_MAX_GRAVITY_LARGE = 30.f;
    const float BALL_MAX_GRAVITY_MEDIUM = 25.f;
    const float BALL_MAX_GRAVITY_SMALL = 20.f;
    //bullet
    const std::string BULLET_TEX_PATH = "textures/ball.png";
    const float BULLET_SPEED_LOW = 25.f;
    //scoreboard
    const std::string SCOREBOARD_TEX_PATH = "textures/scoreboard.png";
    const std::string FONT_PATH = "textures/uni0553-webfont.ttf";
    const unsigned int FONT_SIZE = 40;
    const sf::Color FONT_COLOR = sf::Color::Red;
    //timer
    const std::string TIMER_TEX_PATH = "textures/timer.png";
}
