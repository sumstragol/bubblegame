//
//  settings.hpp
//  sfmll
//
//  Created by Mikolaj Brozek on 01/11/2021.
//  Copyright © 2021 Mikolaj Brozek. All rights reserved.
//

#pragma once

#include <iostream>

namespace settings
{
    //window
    const std::string TITLE = "Bubble";
    const int SCREEN_WIDTH = 1600;
    const int SCREEN_HEIGHT = 1200;
    const unsigned int FPS = 60;
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
    const float BULLET_SPEED_LOW = 30.f;
    //pistol
    const unsigned int PISTOL_MAX_CAPACITY = 5;
    const unsigned int PISTOL_RELOAD_TIME = 3000;
    const unsigned int PISTOL_FREEZE_TIME_BETWEEN_SHOTS = 1000;
}
