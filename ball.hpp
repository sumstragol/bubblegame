#pragma once

#include "includes.hpp"
#include "entity.hpp"

class Ball : public Entity
{
public:
	Ball();
	Ball(const Ball* b);
	virtual ~Ball();
	void move(sf::RenderWindow* window);
	virtual void double_ball(std::vector<Ball*>& vec) = 0;
protected:
	void neg_speed_x();
	virtual float get_max_speed_y() const = 0;

	float gravity;
	bool after_create;
};

class Ball_small : public Ball
{
public:
	Ball_small();
	Ball_small(const Ball* b);
	void double_ball(std::vector<Ball*>& vec) override;
private:
	float get_max_speed_y() const override;
};

class Ball_medium : public Ball
{
public:
	Ball_medium();
	Ball_medium(const Ball* b);
	void double_ball(std::vector<Ball*>& vec) override;
private:
	float get_max_speed_y() const override;
};

class Ball_large : public Ball
{
public:
	Ball_large();
	Ball_large(const Ball* b);
	void double_ball(std::vector<Ball*>& vec) override;
private:
	float get_max_speed_y() const override;
};
