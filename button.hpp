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
	Button(const float& cor_x, const float& cor_y,
		const std::string& tex_reg_path, const bool &adjust_x
	);
	Button(const float& cor_x, const float& cor_y, 
		const std::string& tex_reg_path, const std::string& tex_hover_path,
		const bool& adjust_x
	);

	Button(const float& cor_x, const float& cor_y, const std::string& button_text);

	const sf::Texture get_tex(const Button_tex_type& type) const;
	void hover(const sf::Vector2f& pos);
	bool is_hovering() const;
private:
	void set_tex(const std::string& path, const Button_tex_type& type);
	void set_tex(const sf::Texture& t, const Button_tex_type& type);
	void attach_tex(const Button_tex_type& type);

	struct Button_tex
	{
		sf::Texture regular;
		sf::Texture hover;
	};
	Button_tex tex;
	bool is_on_hover;
};