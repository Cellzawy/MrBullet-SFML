#ifndef MENUS
#define MENUS
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>

using namespace sf;
using namespace std;

enum menu_type {
    level_1, level_2, level_3, level_4, level_5,Level_6, Level_7, Level_8, Level_9, Level_10,
    main_menu, play_menu, options_menu, classic_Mode, achievements_menu
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
extern Texture back_ground, checkbox_close, checkbox_open, volume_increase, volume_decrease;

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
extern sf::Sprite achievements_button;

extern sf::RenderWindow window;


void Main_menu();
void Play_menu();
void Options_menu();
void Classic_menu();
void Achievements_menu();

void Texture_loading();

void Level_Evaluation(Level level[]);

void volume_manage(sf::Text&, sf::Sprite, sf::Sprite, int&, Font&, string);

void hoverEffect(sf::Sprite&); // for buttons
void hoverEffect(sf::Sprite&, sf::Texture&, sf::Texture&, sf::Text&); // for menu selection in play menu
void hoverEffect(Level level[]); // for levels selection in classic menu
void hoverEffect(sf::Sprite&, sf::Texture&); // for achievement button in main menu

#endif
