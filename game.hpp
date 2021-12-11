#include "includes.hpp"

#include "entity.hpp"
#include "ball.hpp"
#include "player.hpp"
#include "bullet.hpp"
#include "scoreboard.hpp"
#include "timer.hpp"

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
