#include "button.hpp"

Button::Button(
               const float& cor_x, const float& cor_y,
               const std::string &tex_path, const std::string& hover_tex_path,
               const std::string& button_text
)
	:is_on_hover(false)
{
	// prepare button
    // textures
    set_tex(tex_path, Button_tex_type::regular);
    set_tex(hover_tex_path, Button_tex_type::hover);
    
    attach_tex(Button_tex_type::regular);

    // captions
    cap.regular = new My_font(settings::FONT_PATH, settings::BUTTON_FONT_SIZE, settings::BUTTON_FONT_COLOR);
    cap.regular->set_text(button_text);
    
    cap.hover = new My_font(settings::FONT_PATH, settings::BUTTON_FONT_SIZE, settings::BUTTON_HOVER_FONT_COLOR);
    cap.hover->set_text(button_text);
    
    // pos of captions
    
    const float right_cor_x =
        cor_x + (get_tex(Button_tex_type::regular).getSize().x / 2 - cap.regular->get_text().getGlobalBounds().width / 2);
    cap.regular->set_position(right_cor_x, cor_y);
    cap.hover->set_position(right_cor_x, cor_y);
    
    // pos of button
    
    set_pos_x(cor_x);
    set_pos_y(cor_y);
}

void Button::draw(sf::RenderWindow *window) const
{
    window->draw(sprite);
    
    if (!is_hovering())
    {
        cap.regular->draw(window);
    }
    else
    {
        cap.hover->draw(window);
    }
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

void Button::update_text_cor(const Button_tex_type& type)
{
    const float cor_x =
        get_pos_x() + (get_tex(Button_tex_type::regular).getSize().x / 2 - cap.regular->get_text().getGlobalBounds().width / 2);
    
    const float cor_y =
        get_pos_y() + (get_tex(Button_tex_type::regular).getSize().y / 2 - cap.regular->get_text().getGlobalBounds().height / 2);
    
    if (type == Button_tex_type::regular)
    {
        cap.regular->set_position(cor_x, cor_y);
    }
    else if (type == Button_tex_type::hover)
    {
        cap.hover->set_position(cor_x, cor_y);
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

My_font* Button::get_caption_text(const Button_tex_type& type)
{
    if (type == Button_tex_type::regular)
    {
        return cap.regular;
    }
    else if (type == Button_tex_type::hover)
    {
        return cap.hover;
    }
}

