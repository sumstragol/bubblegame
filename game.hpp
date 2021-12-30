#include "includes.hpp"

#include "entity.hpp"
#include "ball.hpp"
#include "player.hpp"
#include "bullet.hpp"
#include "scoreboard.hpp"
#include "timer.hpp"
#include "button.hpp"
#include "level.hpp"

enum class Game_state 
{
	Game, Menu, Pause, Level, Count_down
};

enum class Move_direction;

class Game
{
public:
	Game();
	void run();
private:
	bool is_running() const;
	void poll_events();
	void update();
	void render();

    void run_level(const int index);
    void clear_level();
    void check_for_win();
    void level_fail();
    
	Game_state state;
    
	Button* logo;
	Button* button_menu;
	Button* button_play;
	Button* button_resume;
	Button* button_settings;
	Button* button_exit;
    
    static const unsigned int level_count = 8;
    std::array<const std::string, level_count> level_paths = {
        "/Users/mikolajbrozek/xcode projects/bubblef/bubblef/levels/level1.txt",
        "/Users/mikolajbrozek/xcode projects/bubblef/bubblef/levels/level2.txt",
        "/Users/mikolajbrozek/xcode projects/bubblef/bubblef/levels/level3.txt",
        "/Users/mikolajbrozek/xcode projects/bubblef/bubblef/levels/level4.txt",
        "/Users/mikolajbrozek/xcode projects/bubblef/bubblef/levels/level5.txt",
        "/Users/mikolajbrozek/xcode projects/bubblef/bubblef/levels/level6.txt",
        "/Users/mikolajbrozek/xcode projects/bubblef/bubblef/levels/level7.txt",
        "/Users/mikolajbrozek/xcode projects/bubblef/bubblef/levels/level8.txt",
    };
    std::array<Button*, level_count> buttons_for_levels;
    
	sf::RenderWindow* window;
	sf::Event e;
	std::vector<Ball*> balls;
	Player* p;
	std::vector<Bullet*> bullets;
    Scoreboard* sc;
    Timer* timer;
    
    unsigned int points;
    unsigned int lives;
    unsigned int current_level_index;
};
