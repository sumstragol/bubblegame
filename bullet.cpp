#include "bullet.hpp"

Bullet::Bullet(const sf::Vector2f& origin, const sf::Vector2f& direction)
{
	set_tex(settings::BALL_TEX_PATH);
	attach_tex();

	set_pos_x(origin.x);
	set_pos_y(origin.y);

	sf::Vector2f temp;
	util::direction_vector(temp, origin, direction);
	util::normalize_vector(temp);

	set_speed_x(-temp.x * settings::BULLET_SPEED);
	set_speed_y(-temp.y * settings::BULLET_SPEED);
}

void Bullet::move(sf::RenderWindow* window, std::vector<Bullet*>& vec)
{
	sprite.move(speed_x, speed_y);

	if (get_pos_x() < -sprite.getGlobalBounds().width ||                        
		get_pos_x() > window->getSize().x + sprite.getGlobalBounds().width ||  
		get_pos_y() < -sprite.getGlobalBounds().height ||
		get_pos_y() + sprite.getGlobalBounds().height > window->getSize().y + sprite.getGlobalBounds().height
		)
	{
		int bullet_index = std::find(vec.begin(), vec.end(), this) - vec.begin();
		vec.erase(vec.begin() + bullet_index);

		delete this;
	}
}

void Bullet::remove(std::vector<Bullet*>& vec)
{
	int bullet_index = std::find(vec.begin(), vec.end(), this) - vec.begin();
	vec.erase(vec.begin() + bullet_index);

	delete this;
}
