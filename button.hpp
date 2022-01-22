#pragma once

#include "includes.hpp"
#include "entity.hpp"
#include "my_font.hpp"

class My_font;

enum class Button_tex_type
{
	regular, hover
};

class Button : public Entity
{
public:
	Button(
           const float& cor_x, const float& cor_y,
           const std::string& tex_path, const std::string& hover_tex_path,
           const std::string& button_text
    );
    ~Button();
    
    void draw(sf::RenderWindow* window) const;
	const sf::Texture get_tex(const Button_tex_type& type) const;
    
    // changing button properties if given positions is located in buttons sprite texture
	void hover(const sf::Vector2f& pos);
    // returns if the mouses cursor is placed on the button
	bool is_hovering() const;
    My_font* get_caption_text(const Button_tex_type& type = Button_tex_type::regular);
    void update_text_cor(const Button_tex_type& type = Button_tex_type::regular);
private:
	void set_tex(const std::string& path, const Button_tex_type& type);
	void set_tex(const sf::Texture& t, const Button_tex_type& type);
	void attach_tex(const Button_tex_type& type);
    
	struct Button_tex
	{
		sf::Texture regular;
		sf::Texture hover;
	};
    
    struct Button_caption
    {
        My_font* regular;
        My_font* hover;
    };
    
	Button_tex tex;
    Button_caption cap;
	bool is_on_hover;
};
