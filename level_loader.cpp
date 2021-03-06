#include "level_loader.hpp"

void Level::load_level(const std::string& path, std::vector<Ball*>& balls, float& time, int& level_label)
{
	enum class Key_word
	{
		large, medium, small, time, end
	};

	std::ifstream input_file(path);
	if (!input_file.is_open())
	{
		std::cout << "Unable to open the file " << path << "\n";
        input_file.close();
        return;
	}

	// if file is loaded then it reads the content of it 
	// to assign level data

	std::string single_line;
    // looking up the key in lines
    auto look_for_keys = [&single_line]()
    {
        if      (single_line.find("large")  != std::string::npos) return Key_word::large;
        else if (single_line.find("medium") != std::string::npos) return Key_word::medium;
        else if (single_line.find("small")  != std::string::npos) return Key_word::small;
        else if (single_line.find("time")   != std::string::npos) return Key_word::time;
        else if (single_line.find("end")    != std::string::npos) return Key_word::end;
    };
                
    // if the known key was found, next line of the file sholud be represting
    // the count of a earlier specifed object
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

    auto float_conversion = [&input_file, &single_line]()
    {
        try
        {
            std::getline(input_file, single_line);

            return (float)std::atof(single_line.c_str());
        }
        catch (...)
        {
            std::cout << "Bad attempt converting line: " << single_line <<
                " into a float\n";

            return 0.8f;
        }
    };

    // if the count read was successful it will convert all the lines with
    // postions to floats
    auto position_conversion = [&input_file, &single_line]()
    {
        try
        {
            std::getline(input_file, single_line);
            std::stringstream line_stream(single_line);
            
            std::vector<std::string> tokens;
            std::string single_token;
            while (line_stream >> single_token)
            {
                tokens.push_back(single_token);
            }

            if (tokens.size() != 2)
            {
                std::cout << "Wrong number of coordinates provided on line: " <<
                    single_line << "\n";

                return sf::Vector2f(0, 0);
            }

            return sf::Vector2f(std::stof(tokens[0]), std::stof(tokens[1]));
        }
        catch (...)
        {
            std::cout << "Unable to convert line: " << single_line <<
                "into to separate float cooridantes\n";

            return sf::Vector2f(0, 0);
        }

    };
    
    // first line is level number
    level_label = int_conversion();
    
	while (std::getline(input_file, single_line))
	{
		Key_word current = look_for_keys();

		switch (current)
		{
		case Key_word::large:
		case Key_word::medium:
		case Key_word::small:
		{
			unsigned int count = int_conversion();
			
			for (unsigned int i = 0; i < count; i++)
			{
				sf::Vector2f temp = position_conversion();
				switch (current)
				{
				case Key_word::large:
				{
					balls.push_back(new Ball_large(temp.x, temp.y));

					break;
				}
				case Key_word::medium:
				{
					balls.push_back(new Ball_medium(temp.x, temp.y));
					break;
				}
				case Key_word::small:
				{
					balls.push_back(new Ball_small(temp.x, temp.y));
					break;
				}
				}
			}

			break;
		}
        case Key_word::end:
        {
            return;
            break;
        }
		case Key_word::time:
		{
			time = float_conversion();
			break;
		}
		default:
		{
			std::cout << "Undefined key " << single_line << "\n";
			break;
		}
		}
	}
    
    input_file.close();
}
