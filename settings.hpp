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
    const sf::Color MENU_COLOR_BACKGROUND = sf::Color(132, 186, 154);
    const std::string LOGO_TEX = "/Users/mikolajbrozek/xcode projects/bubblef/bubblef/textures/logo.png";
    //state game
    const sf::Color GAME_COLOR_BACKGROUND = sf::Color(211, 240, 222);
    //state pause
    //button
    const std::string BUTTON_TEX_PATH = "/Users/mikolajbrozek/xcode projects/bubblef/bubblef/textures/button.png";
    const std::string BUTTON_HOVER_TEX_PATH = "/Users/mikolajbrozek/xcode projects/bubblef/bubblef/textures/button_hover.png";
    const std::string BUTTON_L_TEX_PATH = "/Users/mikolajbrozek/xcode projects/bubblef/bubblef/textures/button_l.png";
    const std::string BUTTON_HOVER_L_TEX_PATH = "/Users/mikolajbrozek/xcode projects/bubblef/bubblef/textures/button_hover_l.png";
    const unsigned int BUTTON_FONT_SIZE = 100;
    const sf::Color BUTTON_FONT_COLOR = sf::Color::Black;
    const sf::Color BUTTON_HOVER_FONT_COLOR = sf::Color::White;
    //player
    const std::string PLAYER_TEX_PATH = "/Users/mikolajbrozek/xcode projects/bubblef/bubblef/textures/player.png";
    const int PLAYER_TEX_SIZE_WIDTH = 90;
    const int PLAYER_TEX_SIZE_HEIGHT = 140;
    const float PLAYER_SPEED = 15.f;
    //ball
    const std::string BALL_TEX_PATH = "/Users/mikolajbrozek/xcode projects/bubblef/bubblef/textures/ball.png";
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
    const std::string BULLET_TEX_PATH = "/Users/mikolajbrozek/xcode projects/bubblef/bubblef/textures/ball.png";
    const float BULLET_SPEED = 25.f;
    //scoreboard
    const std::string SCOREBOARD_TEX_PATH = "/Users/mikolajbrozek/xcode projects/bubblef/bubblef/textures/scoreboard.png";
    const std::string FONT_PATH = "/Users/mikolajbrozek/xcode projects/bubblef/bubblef/textures/uni0553-webfont.ttf";
    const unsigned int FONT_SIZE = 40;
    const sf::Color FONT_COLOR = sf::Color::Black;
    //timer
    const std::string TIMER_TEX_PATH = "/Users/mikolajbrozek/xcode projects/bubblef/bubblef/textures/timer.png";
}
