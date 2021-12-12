#include "button.hpp"

Button::Button(const float& cor_x, const float& cor_y,
	const std::string& tex_reg_path, const bool& adjust_x
)
	:is_on_hover(false)
{
	set_tex(tex_reg_path, Button_tex_type::regular);

	attach_tex(Button_tex_type::regular);


	set_pos_x(cor_x);
	if (adjust_x)
	{
		set_pos_x(get_pos_x() - sprite.getTexture()->getSize().x / 2);
	}
	set_pos_y(cor_y);
}

Button::Button(const float& cor_x, const float& cor_y,
	const std::string &tex_reg_path, const std::string &tex_hover_path,
	const bool& adjust_x
)
	:is_on_hover(false)
{
	set_tex(tex_reg_path, Button_tex_type::regular);
	set_tex(tex_hover_path, Button_tex_type::hover);

	attach_tex(Button_tex_type::regular);

	set_pos_x(cor_x);
	if (adjust_x)
	{
		set_pos_x(get_pos_x() - sprite.getTexture()->getSize().x / 2);
	}
	set_pos_y(cor_y);
}

Button::Button(const float& cor_x, const float& cor_y, const std::string& button_text)
	:is_on_hover(false)
{
	// prepare button ingredients

	sf::RenderTexture* temp_rt = new sf::RenderTexture;
	sf::Sprite* temp_s = new sf::Sprite();
	My_font* temp_f = new My_font(settings::FONT_PATH, settings::FONT_SIZE, sf::Color::White);
	temp_f->update_textt(button_text);

	// regular button 

	temp_rt->clear();
	temp_s->setTexture(util::get_tex(settings::BUTTON));
	temp_rt->draw(*temp_s);
	temp_rt->draw(temp_f->get_text());
	temp_rt->display();

	tex.regular = temp_rt->getTexture();

	// hover button
	/*
	temp_f->change_color(sf::Color::Black);

	temp_rt->clear();
	temp_s->setTexture(util::get_tex(settings::BUTTON_HOVER));
	temp_rt->draw(*temp_s);
	temp_rt->draw(temp_f->get_text());
	temp_rt->display();

	tex.hover = temp_rt->getTexture();
	*/
	// rest

	attach_tex(Button_tex_type::regular);

	set_pos_x(cor_x);
	set_pos_x(cor_y);

	delete temp_rt;
	delete temp_s;
	delete temp_f;
}

const sf::Texture Button::get_tex(const Button_tex_type& type) const
{
	if (type == Button_tex_type::regular)
	{
		return tex.regular;
	}
	else if (type == Button_tex_type::hover)
	{
		return tex.hover;
	}
}

void Button::set_tex(const std::string& path, const Button_tex_type& type)
{
	if (type == Button_tex_type::regular)
	{
		tex.regular = util::get_tex(path);
	}
	else if (type == Button_tex_type::hover)
	{
		tex.hover = util::get_tex(path);
	}
}

void Button::set_tex(const sf::Texture& t, const Button_tex_type& type)
{
	if (type == Button_tex_type::regular)
	{
		tex.regular = t;
	}
	else if (type == Button_tex_type::hover)
	{
		tex.hover = t;
	}
}

void Button::attach_tex(const Button_tex_type& type)
{
	if (type == Button_tex_type::regular)
	{
		sprite.setTexture(tex.regular);
	}
	else if (type == Button_tex_type::hover)
	{
		sprite.setTexture(tex.hover);
	}
} 

void Button::hover(const sf::Vector2f& pos)
{
	if (sprite.getGlobalBounds().contains(pos))
	{
		is_on_hover = true;
		attach_tex(Button_tex_type::hover);
	}
	else
	{
		is_on_hover = false;
		attach_tex(Button_tex_type::regular);
	}
}

bool Button::is_hovering() const
{
	return is_on_hover;
}