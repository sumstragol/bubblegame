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
    const sf::Color MENU_COLOR_BACKGROUND = sf::Color::Blue;
    const std::string LOGO_TEX = "textures/logo.png";
    //state pause
    //button
    const std::string BUTTON_TEX_PATH = "textures/button.png";
    const std::string BUTTON_HOVER_TEX_PATH = "textures/button_hover.png";
    const unsigned int BUTTON_FONT_SIZE = 100;
    const sf::Color BUTTON_FONT_COLOR = sf::Color::White;
    const sf::Color BUTTON_HOVER_FONT_COLOR = sf::Color::Yellow;
    //player
    const std::string PLAYER_STAND_TEX_PATH = "textures/player_stand.png";
    const std::string PLAYER_MOVE_1_TEX_PATH = "/Users/mikolajbrozek/xcode projects/bubblef/bubblef/textures/player_move_1.png";
    const std::string PLAYER_MOVE_2_TEX_PATH = "/Users/mikolajbrozek/xcode projects/bubblef/bubblef/textures/player_move_2.png";
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
