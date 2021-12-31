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
	Game, Menu, Pause, Level, Count_down,
    Settings
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

    void count_down_level();
    void run_level(const int index);
    void resume_level();
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

    static const unsigned int count_down_seconds = 3;
    std::array<Button*, count_down_seconds> buttons_count_down_numbers;

    static const unsigned int level_count = 8;
    std::array<const std::string, level_count> level_paths = {
        "levels/level1.txt",
        "levels/level2.txt",
        "levels/level3.txt",
        "levels/level4.txt",
        "levels/level5.txt",
        "levels/level6.txt",
        "levels/level7.txt",
        "levels/level8.txt",
    };
    std::array<Button*, level_count> buttons_for_levels;
    
	sf::RenderWindow* window;
	sf::Event e;
    sf::Clock clock;
	std::vector<Ball*> balls;
	Player* p;
	std::vector<Bullet*> bullets;
    Scoreboard* sc;
    Timer* timer;
    
    unsigned int points;
    unsigned int lives;
    unsigned int current_level_index;
    unsigned int selected_level_index;
};
