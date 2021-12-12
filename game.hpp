#include "includes.hpp"

#include "entity.hpp"
#include "ball.hpp"
#include "player.hpp"
#include "bullet.hpp"
#include "scoreboard.hpp"
#include "timer.hpp"
#include "button.hpp"


enum class Game_state 
{
	Game, Menu, Pause
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

	Game_state state;
	Button* logo;
	Button* button_menu;
	Button* button_play;
	Button* button_resume;
	Button* button_settings;
	Button* button_exit;




	sf::RenderWindow* window;
	sf::Event e;
	std::vector<Ball*> balls;
	Player* p;
	std::vector<Bullet*> bullets;
    Scoreboard* sc;
    Timer* timer;
    
    unsigned int points;
    unsigned int lives;
};
