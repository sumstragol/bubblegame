#include "game_data.hpp"

void Game_Data::read_stats(Container& data)
{
    std::ifstream input_file(Game_Data::data_file_path);
    
    if (!input_file.is_open())
    {
        std::cout << "Unable to open the file " << Game_Data::data_file_path << "\n";
        input_file.close();
        return;
    }
    
    std::string single_line;
    while (std::getline(input_file, single_line))
    {
        auto look_for_keys = [&single_line]()
        {
            if      (single_line.find("lives")  != std::string::npos) return Key_Word::lives;
            else if (single_line.find("points") != std::string::npos) return Key_Word::points;
            else if (single_line.find("level")  != std::string::npos) return Key_Word::level;
        };
        
        auto int_conversion = [&input_file, &single_line]()
        {
            try
            {
                std::getline(input_file, single_line);
        
                return std::stoi(single_line);
            }
            catch (...)
            {
                std::cout << "Bad attempt converting line: " << single_line <<
                    " into a int\n";
                    
                    return int{ 0 };
            }
        };
        
        Key_Word current = look_for_keys();
        switch (current)
        {
            case Key_Word::lives:
            {
                data.lives = int_conversion();
                break;
            }
            case Key_Word::points:
            {
                data.points = int_conversion();
                break;
            }
            case Key_Word::level:
            {
                data.level = int_conversion();
                break;
            }
            default:
                break;
        }
    }
    
    input_file.close();
    return;
}

void Game_Data::load_stats(Container& data)
{
    std::ofstream output_file(Game_Data::data_file_path);
    if (!output_file.is_open())
    {
        std::cout << "Unable to open the file " << Game_Data::data_file_path << "\n";
        output_file.close();
        return;
    }
    
    output_file << "lives\n";
    output_file << data.lives << "\n";
    output_file << "points\n";
    output_file << data.points << "\n";
    output_file << "level\n";
    output_file << data.level << "\n";
    
    output_file.close();
}
