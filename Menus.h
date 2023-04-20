#ifndef MENUS
#define MENUS
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

using namespace sf;
using namespace std;

enum menu_type {
    main_menu, play_menu, options_menu, classic_Mode, achievements_menu,
    level_1, level_2, level_3, level_4, level_5, level_6, level_7, level_8, level_9, level_10
};

struct Button{
    sf::Texture Default_texture;
    sf::Texture Pressed_texture;
    sf::Sprite sprite;
};

struct Menu{
    sf::Texture Default_texture;
    sf::Texture Hovered_texture;
    sf::Sprite sprite;
};

struct Achievment
{
  bool is_open = false;
  sf::Texture locked_texture;
  sf::Texture unlocked_texture;
  sf::Sprite sprite;
};

struct Enemy
{
    Texture enemytexture;
    Sprite enemysprite;
    Vector2f enemyposition;
    //float speed;
    bool isAlive;
};

struct Levels_view {
    short Level_evaluation = -1;  // from -1 to 3
    Texture Level_closed_texture;  // Level_evaluation = -1
    Texture Level_none_stared; // Leve_evaluation = 0
    Texture Level_one_stared;   // Level_evaluation = 1
    Texture Level_two_stared;  // Level_evaluation = 2
    Texture Leve_three_stared; // Level_evaluation = 3
    Sprite Level_selection;
};

struct Level
{
    RectangleShape block[4];
    Texture backgroundTexture;
    Sprite backgroundSprite;
    Texture playerTexture;
    Sprite playerSprite;
    Vector2f playerPosition;
    Levels_view view;
};

extern menu_type current_menu;

// general
extern sf::Font game_font;
extern Button back_button;
extern Music mainmenu_music;
extern SoundBuffer SFX_click_soundbuffer;
extern Sound SFX_click;

// main menu
extern sf::Texture main_menu_background_texture, mr_bullet_logo_texture;
extern Button play_button, options_button, quit_button;

// options menu
extern Texture back_ground, checkbox_close, checkbox_open, Back_button_Red, Back_button_Yellow, volume_increase, volume_decrease;

// play menu

extern sf::Texture play_menu_background_texture;
extern Menu classic_menu, duels_menu;

// classic menu
extern sf::Texture classic_menu_background_texture;
extern sf::Texture Border_hover_effect;
extern Level level[20];

// achievements menu
extern sf::Texture achievements_menu_background;
extern sf::Texture achievement_texture, achievement_hovered_texture;
extern Achievment achievements[5];



void Main_menu(sf::RenderWindow&);
void Play_menu(sf::RenderWindow&);
void Options_menu(sf::RenderWindow&);
void Classic_menu(sf::RenderWindow&);
void Achievements_menu(sf::RenderWindow&);

void Texture_loading();

void Level_Evaluation(Level level[]);

void volume_manage(sf::RenderWindow&, sf::Text&, sf::Sprite, sf::Sprite, int&, Font&, string);
void MUSIC(Music& music_name, String music_file_name, int& volume_num);
void FONT(Font& font_name, string font_file_name);

void hoverEffect(sf::Sprite&, sf::RenderWindow&); // for buttons
void hoverEffect(sf::Sprite&, sf::Texture&, sf::Texture&, sf::Text&, sf::RenderWindow&); // for menu selection in play menu
void hoverEffect(Level level[], sf::RenderWindow&); // for levels selection in classic menu
void hoverEffect(sf::Sprite&, sf::Texture&, sf::RenderWindow&); // for achievement button in main menu

#endif
