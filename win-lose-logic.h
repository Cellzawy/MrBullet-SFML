#ifndef WIN_LOSE_LOGIC_H_INCLUDED
#define WIN_LOSE_LOGIC_H_INCLUDED

extern sf::Texture win_panel_texture, lose_panel_texture;
extern sf::Texture star_texture, empty_star_texture, forward_texture, backward_texture, reset_texture;
extern sf::Texture quit_to_main_menu_texture;

extern sf::Sprite Forward, backward, first_star, second_star, third_star, reset;
extern sf::Sprite win_panel, lose_panel;
extern sf::Sprite quit_to_main_menu;
extern sf::Text result_text;

extern sf::Text out_of_bullets, Try_again;

extern bool animation;

void Win_panel(int score);
void Winning_level_results(int score);
void Zero_stars();
void One_star();
void Two_stars();
void Three_stars();
void DissolveEffect_three_stars(float dissolveTime);
void DissolveEffect_won_options(float dissolveTime);
void DissolveEffect_won_Quit(float);

void Lose_panel();
void DissolveEffect_first_Text(sf::Text, float);
void DissolveEffect_second_Text(sf::Text, float);
void DissolveEffect_lost_options(float dissolveTime);
void DissolveEffect_lost_Quit(sf::Sprite&, float);

void Moving_down_animation(sf::Sprite&);
void Reset();

#endif
