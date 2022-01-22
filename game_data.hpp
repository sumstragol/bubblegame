#pragma once

#include "includes.hpp"

struct Container
{
    int lives;
    int points;
    int level;
    
    friend bool operator==(const Container& lhs, const Container& rhs)
    {
        return (lhs.lives == rhs.lives && lhs.points == rhs.points &&
            lhs.level == rhs.level);
    }
};


class Game_Data
{
public:
    static void read_stats(Container& data);
    static void load_stats(Container& data);
private:
    enum class Key_Word { lives, points, level };
    inline static const std::string data_file_path = "game_data/temp.txt";
};

