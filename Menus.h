#ifndef MENUS
#define MENUS
#include "Levels.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>

using namespace sf;
using namespace std;

enum menu_type {
    level_1, level_2, level_3, level_4, level_5,level_6, level_7, level_8, level_9, level_10,
    main_menu, play_menu, options_menu, classic_Mode, achievements_menu, won_panel, lost_panel , pause_MENU, OPTIONS_MENU_PAUSE
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


struct Levels_view {
    int Level_evaluation = -1;  // from -1 to 3
    Texture Level_closed_texture;  // Level_evaluation = -1
    Texture Level_none_stared; // Leve_evaluation = 0
    Texture Level_one_stared;   // Level_evaluation = 1
    Texture Level_two_stared;  // Level_evaluation = 2
    Texture Leve_three_stared; // Level_evaluation = 3
    Sprite Level_selection;
};

struct Lev {
    Texture BG;

    Texture GROUND[10];

    Texture BLOCK[10];

    Texture SHAPES[10];

    Sprite bg;

    Sprite Bullets[5];

    RectangleShape ground, shape[10];

    RectangleShape block[10];

    int num_of_bullets;

    int Return_num;

    Character killer, target[100];

    Levels_view view;
};

extern Lev lev[10];

extern menu_type current_menu;

// general
extern sf::Font game_font;
extern Button back_button;
extern Music mainmenu_music;
extern SoundBuffer SFX_click_soundbuffer;
extern Sound SFX_click;
extern SoundBuffer shoot_soundbuffer;
extern Sound shoot;
extern SoundBuffer Restart_soundbuffer;
extern Sound Restart_sound;
extern Lev lev[10];

// main menu
extern sf::Texture main_menu_background_texture, mr_bullet_logo_texture;
extern Button play_button, options_button, quit_button;

// options menu
extern Texture back_ground, checkbox_close, checkbox_open, volume_increase, volume_decrease;
extern Text volume_presentage[2];
extern  int volume_value[2];
extern bool fullscreen_close;
extern Sprite check_box_close, check_box_open, Volume_increase[2], Volume_decrease[2];


// options menu pause 
extern Texture options_menu_background;

// Pause menu

extern Texture pause_back_ground, Rec_background, pause;
extern Button Resume, optionts, QUIT;

// play menu

extern sf::Texture play_menu_background_texture;
extern Menu classic_menu, duels_menu;

// levels_background
extern Texture pause_menu_button;
extern Texture Bullet_texture;
extern Sprite Replay;
extern Sprite Pause_menu_button;
extern Sprite Bullet_Sprite;


// classic menu
extern sf::Texture classic_menu_background_texture;
extern sf::Texture Border_hover_effect;  // the levels struct is in the Levels.h file


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

void Options_menu_Pause();

void PAUSE_MENU();

void Texture_loading();

void levels_background();

void Level_Evaluation(Lev lev[]);

void volume_manage(sf::Text&, sf::Sprite, sf::Sprite, int&);

void hoverEffect(sf::Sprite&); // for buttons

void hoverEffect(sf::Sprite&, sf::Texture&, sf::Texture&, sf::Text&); // for menu selection in play menu

void hoverEffect(Lev lev[]); // for levels selection in classic menu

void hoverEffect(sf::Sprite&, sf::Texture&); // for achievement button in main menu

#endif
