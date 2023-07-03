#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include "Levels.h"
#include "Menus.h"
#include "Events.h"
#include "win-lose-logic.h"
#include "1v1.h"



using namespace sf;
using namespace std;

//menu initialization
menu_type current_menu = main_menu;

// general
sf::Font game_font;
Button back_button;
Music mainmenu_music;
SoundBuffer SFX_click_soundbuffer;
Sound SFX_click;
SoundBuffer shoot_soundbuffer;
Sound shoot;
SoundBuffer Restart_soundbuffer;
Sound Restart_sound;

Lev lev[17];

//1v1
//Texture victory_texture;
//Texture victory_texture_2;
//Texture restart_texture;
//Texture back_texture;
//Texture hundred_health_texture;
//Texture seventy_health_texture;
//Texture forty_health_texture;
//Texture ten_health_texture;
//Texture zero_health_texture;
//Texture hundred_health_texture_2;
//Texture seventy_health_texture_2;
//Texture forty_health_texture_2;
//Texture ten_health_texture_2;
//Texture zero_health_texture_2;

// main menu
sf::Texture main_menu_background_texture, mr_bullet_logo_texture;
Button play_button, options_button, quit_button;
sf::Sprite main_menu_background, mr_bullet_logo;
sf::Sprite achievements_button;

// options menu
Texture back_ground, checkbox_close, checkbox_open, volume_increase, volume_decrease;
int volume_value[2] = { 0,50 };
Text volume_presentage[2];
bool fullscreen_close = false;
Sprite check_box_close, check_box_open, Volume_increase[2], Volume_decrease[2];

// Pause menu
Texture pause_back_ground, Rec_background, pause;
Button Resume, optionts, QUIT;

// options menu pause
sf::Texture options_menu_background;


// play menu
sf::Texture play_menu_background_texture;
Menu classic_menu, duels_menu;

// levels_background
Texture pause_menu_button;
Texture Bullet_texture;
Sprite Replay;
Sprite Pause_menu_button;
Sprite Bullet_Sprite;

// classic menu
sf::Texture classic_menu_background_texture;
sf::Texture Border_hover_effect;

// choose_player_menu
bool chosen = false;
Hovered_button
character_one, character_two, character_three, character_four, character_five, character_six, character_seven, character_eight;
Hovered_button
Character_ONE, Character_TWO, Character_THREE, Character_FOUR, Character_FIVE, Character_SIX, Character_SEVEN, Character_EIGHT;
Sprite Choose_Player_Back_Ground;
Texture choose_player_back_ground;


//1v1_maps

Texture   maps_1v1_player_back_ground, maps_one_1v1_back_ground, maps_two_1v1_back_ground, maps_three_1v1_back_ground, maps_four_1v1_back_ground;
Hovered_button MAP_1, MAP_2, MAP_3, MAP_4;
Sprite MAPS_1v1_player_back_ground;
bool chose_dules_1=false, 
chose_dules_2 = false,
chose_dules_3 = false,
chose_dules_4 = false;

// achievements menu
sf::Texture achievements_menu_background;
sf::Texture achievement_texture, achievement_hovered_texture;
Achievment achievements[5];

void Main_menu();
void Play_menu();
void Options_menu();
void Classic_menu();
void Achievements_menu();

void Texture_loading();

void Level_Evaluation(Lev lev[]);

void volume_manage(sf::Text&, sf::Sprite, sf::Sprite, int&);

void hoverEffect(sf::Sprite&); // for buttons
void hoverEffect(sf::Sprite&, sf::Texture&, sf::Texture&, sf::Text&); // for menu selection in play menu
void hoverEffect(Lev lev[]); // for levels selection in classic menu
void hoverEffect(sf::Sprite&, sf::Texture&); // for achievement button in main menu




void Main_menu()
{

    // main menu background and logo


	main_menu_background.setTexture(main_menu_background_texture);
	main_menu_background.setScale(
		window.getSize().x / main_menu_background.getLocalBounds().width, // to make the background fit into the screen size
		window.getSize().y / main_menu_background.getLocalBounds().height
    );


    mr_bullet_logo.setTexture(mr_bullet_logo_texture);
    mr_bullet_logo.setOrigin(mr_bullet_logo.getLocalBounds().width / 2, mr_bullet_logo.getLocalBounds().height / 2);
	mr_bullet_logo.setPosition(window.getSize().x / 2, window.getSize().y / 9);


	// Buttons


	play_button.sprite.setTexture(play_button.Default_texture);
    play_button.sprite.setOrigin(play_button.sprite.getLocalBounds().width / 2, play_button.sprite.getLocalBounds().height / 2);
	play_button.sprite.setPosition(window.getSize().x / 2, window.getSize().y / 3);



	options_button.sprite.setTexture(options_button.Default_texture);
    options_button.sprite.setOrigin(options_button.sprite.getLocalBounds().width / 2, options_button.sprite.getLocalBounds().height / 2);
	options_button.sprite.setPosition(window.getSize().x / 2, window.getSize().y / 2);



	quit_button.sprite.setTexture(quit_button.Default_texture);
    quit_button.sprite.setOrigin(quit_button.sprite.getLocalBounds().width / 2, quit_button.sprite.getLocalBounds().height / 2);
	quit_button.sprite.setPosition(window.getSize().x / 2, window.getSize().y * 2/3);


	// achievements menu


	achievements_button.setTexture(achievement_texture);

	achievements_button.setOrigin(achievements_button.getLocalBounds().width / 2, achievements_button.getLocalBounds().height / 2);
	achievements_button.setPosition(window.getSize().x / 1.059, window.getSize().y / 1.097);


    //hovereffect checking

    hoverEffect(quit_button.sprite);
    hoverEffect(options_button.sprite);
    hoverEffect(play_button.sprite);
    hoverEffect(achievements_button, achievement_hovered_texture);

    // pollEvent loop

    main_menu_eventloop();

    //drawing
    window.draw(main_menu_background);
    window.draw(mr_bullet_logo);
    window.draw(play_button.sprite);
    window.draw(options_button.sprite);
    window.draw(quit_button.sprite);
    window.draw(achievements_button);
}

void Play_menu()
{
    sf::Sprite play_menu_background;
    sf::Text classic_mode("Classic", game_font, 40), duels_mode("Duels", game_font, 40), choose("Choose your mode", game_font, 50);
    // Background


    play_menu_background.setTexture(play_menu_background_texture);
    play_menu_background.setScale(
        window.getSize().x / play_menu_background.getLocalBounds().width,
        window.getSize().y / play_menu_background.getLocalBounds().height);


    // classic menu    and     duels menu

    classic_menu.sprite.setTexture(classic_menu.Default_texture);
    classic_menu.sprite.setOrigin(classic_menu.sprite.getLocalBounds().width / 2, classic_menu.sprite.getLocalBounds().height / 2);
    classic_menu.sprite.setPosition(window.getSize().x / 5.529, window.getSize().y / 2);


    duels_menu.sprite.setTexture(duels_menu.Default_texture);
    duels_menu.sprite.setOrigin(duels_menu.sprite.getLocalBounds().width / 2, duels_menu.sprite.getLocalBounds().height / 2);
    duels_menu.sprite.setPosition(window.getSize().x / 1.235,window.getSize().y / 2);

    // Text



    choose.setFillColor(sf::Color::Black);
    choose.setOrigin(choose.getLocalBounds().width / 2, choose.getLocalBounds().height / 2);
    choose.setPosition(window.getSize().x / 2, window.getSize().y / 9);


    classic_mode.setFillColor(sf::Color::Black);
    classic_mode.setOrigin(classic_mode.getLocalBounds().width / 2, classic_mode.getLocalBounds().height / 2);
    classic_mode.setPosition(window.getSize().x / 5.529, window.getSize().y / 3.342);


    duels_mode.setFillColor(sf::Color::Black);
    duels_mode.setOrigin(duels_mode.getLocalBounds().width / 2, duels_mode.getLocalBounds().height / 2);
    duels_mode.setPosition(window.getSize().x / 1.235, window.getSize().y / 3.342);


    // back button


    back_button.sprite.setTexture(back_button.Default_texture);
    back_button.sprite.setOrigin(back_button.sprite.getLocalBounds().width / 2, back_button.sprite.getLocalBounds().height / 2);
    back_button.sprite.setPosition(window.getSize().x / 12.061, window.getSize().y / 1.099);


    // hovereffect checking

    hoverEffect(back_button.sprite);
    hoverEffect(classic_menu.sprite, classic_menu.Default_texture, classic_menu.Hovered_texture, classic_mode);
    hoverEffect(duels_menu.sprite, duels_menu.Default_texture, duels_menu.Hovered_texture, duels_mode);

    // pollEvent loop

    play_menu_eventloop();

    // drawing

    window.draw(play_menu_background);
    window.draw(choose);
    window.draw(classic_mode);
    window.draw(classic_menu.sprite);
    window.draw(duels_mode);
    window.draw(duels_menu.sprite);
    window.draw(back_button.sprite);

}

void Options_menu()
{
    //Text
    sf::Text Audio_text("Audio", game_font, 50);
    Audio_text.setPosition(window.getSize().x / 10.666, window.getSize().y / 27);
    Audio_text.setOrigin(Audio_text.getLocalBounds().width / 2, Audio_text.getLocalBounds().height / 2);
    Audio_text.setFillColor(Color(190, 95, 14));




    sf::Text volume_presentage[2];
    volume_presentage[0].setFont(game_font);
    volume_presentage[0].setString(to_string(volume_value[0]));
    volume_presentage[0].setCharacterSize(50);
    volume_presentage[0].setOrigin(volume_presentage[0].getLocalBounds().width / 2, volume_presentage[0].getLocalBounds().height / 2);
    volume_presentage[0].setScale(Vector2f(1.2, 1.2));
    volume_presentage[0].setPosition(window.getSize().x / 5.052, window.getSize().y / 7.448);

    volume_presentage[1].setFont(game_font);
    volume_presentage[1].setString(to_string(volume_value[1]));
    volume_presentage[1].setCharacterSize(50);
    volume_presentage[1].setOrigin(volume_presentage[1].getLocalBounds().width / 2, volume_presentage[1].getLocalBounds().height / 2);
    volume_presentage[1].setScale(Vector2f(1.2, 1.2));
    volume_presentage[1].setPosition(window.getSize().x / 5.052, window.getSize().y / 4.102);

    sf::Text Music_Text("Music", game_font, 50);
    Music_Text.setOrigin(Music_Text.getLocalBounds().width / 2, Music_Text.getLocalBounds().height / 2);
    Music_Text.setPosition(window.getSize().x / 19.2, window.getSize().y / 7.75);

    sf::Text SFX_Text("SFX", game_font, 50);
    SFX_Text.setOrigin(SFX_Text.getLocalBounds().width / 2, SFX_Text.getLocalBounds().height); //to center the text
    SFX_Text.setPosition(window.getSize().x / 19.2, window.getSize().y / 3.75);

    sf::Text video_text("Video", game_font, 50);
    video_text.setOrigin(video_text.getLocalBounds().width / 2, video_text.getLocalBounds().height / 2);
    video_text.setPosition(window.getSize().x / 1.828, window.getSize().y / 21.6);
    video_text.setFillColor(Color(190, 95, 14));

    sf::Text Fullscreen_text("Fullscreen", game_font, 50);
    Fullscreen_text.setOrigin(Fullscreen_text.getLocalBounds().width / 2, Fullscreen_text.getLocalBounds().height / 2);
    Fullscreen_text.setPosition(window.getSize().x / 1.828, window.getSize().y / 5.45);


    //sprite
    Sprite  Back_ground;

    Back_ground.setTexture(back_ground);
    Back_ground.setScale(window.getSize().x / Back_ground.getLocalBounds().width, window.getSize().y / Back_ground.getLocalBounds().height);


    check_box_close.setTexture(checkbox_close);
    check_box_close.setScale(Vector2f(0.5, .5));
    check_box_close.setPosition(window.getSize().x / 1.6, window.getSize().y / 5.837);


    check_box_open.setTexture(checkbox_open);
    check_box_open.setScale(Vector2f(0.5, .5));
    check_box_open.setPosition(window.getSize().x / 1.6, window.getSize().y / 5.837);



    Volume_increase[0].setTexture(volume_increase);
    Volume_increase[0].setPosition(window.getSize().x / 3.918, window.getSize().y / 6);
    Volume_increase[0].setColor(Color::White);
    Volume_increase[0].setOrigin(Volume_increase[0].getLocalBounds().width / 2, Volume_increase[0].getLocalBounds().height);


    Volume_decrease[0].setTexture(volume_decrease);
    Volume_decrease[0].setPosition(window.getSize().x / 6.4, window.getSize().y / 6.353);
    Volume_decrease[0].setColor(Color::White);
    Volume_decrease[0].setOrigin(Volume_decrease[0].getLocalBounds().width / 2, Volume_decrease[0].getLocalBounds().height);




    Volume_increase[1].setTexture(volume_increase);
    Volume_increase[1].setPosition(window.getSize().x / 3.918, window.getSize().y / 3.6);
    Volume_increase[1].setColor(Color::White);
    Volume_increase[1].setOrigin(Volume_increase[1].getLocalBounds().width / 2, Volume_increase[1].getLocalBounds().height);




    Volume_decrease[1].setTexture(volume_decrease);
    Volume_decrease[1].setPosition(window.getSize().x / 6.4, window.getSize().y / 3.724);
    Volume_decrease[1].setColor(Color::White);
    Volume_decrease[1].setOrigin(Volume_decrease[1].getLocalBounds().width / 2, Volume_decrease[1].getLocalBounds().height);


    back_button.sprite.setTexture(back_button.Default_texture);
    back_button.sprite.setOrigin(back_button.sprite.getLocalBounds().width / 2, back_button.sprite.getLocalBounds().height / 2);
    back_button.sprite.setPosition(window.getSize().x / 12.061, window.getSize().y / 1.099);


    hoverEffect(back_button.sprite);

    options_menu_eventloop();


    window.draw(Back_ground);
    window.draw(Audio_text);
    window.draw(Music_Text);
    window.draw(SFX_Text);
    window.draw(video_text);
    window.draw(Fullscreen_text);
    window.draw(Volume_increase[0]);
    window.draw(Volume_decrease[0]);
    window.draw(volume_presentage[0]);
    window.draw(Volume_increase[1]);
    window.draw(Volume_decrease[1]);
    window.draw(volume_presentage[1]);
    window.draw(back_button.sprite);
    if (fullscreen_close == false)
        window.draw(check_box_open);
    else
        window.draw(check_box_close);
}

void Options_menu_Pause()
{
    //Text

    sf::Text Audio_text("Audio", game_font, 50);
    Audio_text.setPosition(window.getSize().x / 10.666, window.getSize().y / 27);
    Audio_text.setOrigin(Audio_text.getLocalBounds().width / 2, Audio_text.getLocalBounds().height / 2);
    Audio_text.setFillColor(Color(235, 50, 35));




    sf::Text volume_presentage[2];
    volume_presentage[0].setFont(game_font);
    volume_presentage[0].setString(to_string(volume_value[0]));
    volume_presentage[0].setCharacterSize(50);
    volume_presentage[0].setOrigin(volume_presentage[0].getLocalBounds().width / 2, volume_presentage[0].getLocalBounds().height / 2);
    volume_presentage[0].setScale(Vector2f(1.2, 1.2));
    volume_presentage[0].setPosition(window.getSize().x / 5.052, window.getSize().y / 7.448);

    volume_presentage[1].setFont(game_font);
    volume_presentage[1].setString(to_string(volume_value[1]));
    volume_presentage[1].setCharacterSize(50);
    volume_presentage[1].setOrigin(volume_presentage[1].getLocalBounds().width / 2, volume_presentage[1].getLocalBounds().height / 2);
    volume_presentage[1].setScale(Vector2f(1.2, 1.2));
    volume_presentage[1].setPosition(window.getSize().x / 5.052, window.getSize().y / 4.102);

    sf::Text Music_Text("Music", game_font, 50);
    Music_Text.setOrigin(Music_Text.getLocalBounds().width / 2, Music_Text.getLocalBounds().height / 2);
    Music_Text.setPosition(window.getSize().x / 19.2, window.getSize().y / 7.75);

    sf::Text SFX_Text("SFX", game_font, 50);
    SFX_Text.setOrigin(SFX_Text.getLocalBounds().width / 2, SFX_Text.getLocalBounds().height); //to center the text
    SFX_Text.setPosition(window.getSize().x / 19.2, window.getSize().y / 3.75);

    sf::Text video_text("Video", game_font, 50);
    video_text.setOrigin(video_text.getLocalBounds().width / 2, video_text.getLocalBounds().height / 2);
    video_text.setPosition(window.getSize().x / 1.828, window.getSize().y / 21.6);
    video_text.setFillColor(Color(235, 50, 35));

    sf::Text Fullscreen_text("Fullscreen", game_font, 50);
    Fullscreen_text.setOrigin(Fullscreen_text.getLocalBounds().width / 2, Fullscreen_text.getLocalBounds().height / 2);
    Fullscreen_text.setPosition(window.getSize().x / 1.828, window.getSize().y / 5.45);


    //sprite
    Sprite  Back_ground;

    Back_ground.setTexture(options_menu_background);
    Back_ground.setScale(window.getSize().x / Back_ground.getLocalBounds().width, window.getSize().y / Back_ground.getLocalBounds().height);


    check_box_close.setTexture(checkbox_close);
    check_box_close.setScale(Vector2f(0.5, .5));
    check_box_close.setPosition(window.getSize().x / 1.6, window.getSize().y / 5.837);


    check_box_open.setTexture(checkbox_open);
    check_box_open.setScale(Vector2f(0.5, .5));
    check_box_open.setPosition(window.getSize().x / 1.6, window.getSize().y / 5.837);



    Volume_increase[0].setTexture(volume_increase);
    Volume_increase[0].setPosition(window.getSize().x / 3.918, window.getSize().y / 6);
    Volume_increase[0].setOrigin(Volume_increase[0].getLocalBounds().width / 2, Volume_increase[0].getLocalBounds().height);


    Volume_decrease[0].setTexture(volume_decrease);
    Volume_decrease[0].setPosition(window.getSize().x / 6.4, window.getSize().y / 6.353);
    Volume_decrease[0].setOrigin(Volume_decrease[0].getLocalBounds().width / 2, Volume_decrease[0].getLocalBounds().height);




    Volume_increase[1].setTexture(volume_increase);
    Volume_increase[1].setPosition(window.getSize().x / 3.918, window.getSize().y / 3.6);
    Volume_increase[1].setOrigin(Volume_increase[1].getLocalBounds().width / 2, Volume_increase[1].getLocalBounds().height);




    Volume_decrease[1].setTexture(volume_decrease);
    Volume_decrease[1].setPosition(window.getSize().x / 6.4, window.getSize().y / 3.724);
    Volume_decrease[1].setOrigin(Volume_decrease[1].getLocalBounds().width / 2, Volume_decrease[1].getLocalBounds().height);


    back_button.sprite.setTexture(back_button.Default_texture);
    back_button.sprite.setOrigin(back_button.sprite.getLocalBounds().width / 2, back_button.sprite.getLocalBounds().height / 2);
    back_button.sprite.setPosition(window.getSize().x / 12.061, window.getSize().y / 1.099);


    hoverEffect(back_button.sprite);

    options_menu_pause_eventloop();

    window.draw(Back_ground);
    window.draw(Audio_text);
    window.draw(Music_Text);
    window.draw(SFX_Text);
    window.draw(video_text);
    window.draw(Fullscreen_text);
    window.draw(Volume_increase[0]);
    window.draw(Volume_decrease[0]);
    window.draw(volume_presentage[0]);
    window.draw(Volume_increase[1]);
    window.draw(Volume_decrease[1]);
    window.draw(volume_presentage[1]);
    window.draw(back_button.sprite);
    if (fullscreen_close == false)
        window.draw(check_box_open);
    else
        window.draw(check_box_close);
}


void PAUSE_MENU()
{

    //Text
    Text PAUSE_Word("Pause", game_font, 50);
    PAUSE_Word.setOrigin(PAUSE_Word.getLocalBounds().width / 2, PAUSE_Word.getLocalBounds().height / 2);
    PAUSE_Word.setScale(1.5, 1.5);
    PAUSE_Word.setPosition(window.getSize().x / 2.021, window.getSize().y / 8.307);

    //Sprite
    Sprite  Back_ground, Rec_Background;

    Resume.sprite.setTexture(Resume.Default_texture);
    optionts.sprite.setTexture(optionts.Default_texture);
    QUIT.sprite.setTexture(QUIT.Default_texture);

    Back_ground.setTexture(pause_back_ground);
    Rec_Background.setTexture(Rec_background);

    Back_ground.setScale(window.getSize().x / Back_ground.getLocalBounds().width, window.getSize().y / Back_ground.getLocalBounds().height);

    Resume.sprite.setPosition(window.getSize().x / 2, window.getSize().y / 3);
    Resume.sprite.setOrigin(Resume.sprite.getLocalBounds().width / 2, Resume.sprite.getLocalBounds().height / 2);

    optionts.sprite.setPosition(window.getSize().x / 2, window.getSize().y / 2);
    optionts.sprite.setOrigin(optionts.sprite.getLocalBounds().width / 2, optionts.sprite.getLocalBounds().height / 2);

    QUIT.sprite.setPosition(window.getSize().x / 2, window.getSize().y / 1.5);
    QUIT.sprite.setOrigin(QUIT.sprite.getLocalBounds().width / 2, QUIT.sprite.getLocalBounds().height / 2);


    Rec_Background.setPosition(window.getSize().x / 2, window.getSize().y / 2);
    Rec_Background.setOrigin(Rec_Background.getLocalBounds().width / 2, Rec_Background.getLocalBounds().height / 2);
    Rec_Background.setScale(.6, 0.5);


    pause_eventloop();

    hoverEffect(Resume.sprite);
    hoverEffect(optionts.sprite);
    hoverEffect(QUIT.sprite);




    window.draw(Back_ground);
    window.draw(Rec_Background);
    window.draw(Resume.sprite);
    window.draw(optionts.sprite);
    window.draw(QUIT.sprite);
    window.draw(PAUSE_Word);


}

void levels_background()
{
    crosshair.setTexture(crosshairTx);
    crosshair.setOrigin(crosshair.getLocalBounds().width / 2, crosshair.getLocalBounds().height / 2);
    crosshair.setPosition(Mouse::getPosition().x, Mouse::getPosition().y);
    crosshair.setScale(0.5, 0.5);
    Replay.setTexture(reset_texture);
    Replay.setOrigin(Replay.getLocalBounds().width / 2, Replay.getLocalBounds().height / 2);
    Replay.setPosition(Vector2f(1800, 75));
    Replay.setScale(0.5, 0.5);

    Pause_menu_button.setTexture(pause_menu_button);
    Pause_menu_button.setOrigin(Pause_menu_button.getLocalBounds().width / 2, Pause_menu_button.getLocalBounds().height / 2);
    Pause_menu_button.setPosition(Vector2f(80, 70));
    Pause_menu_button.setScale(0.22, 0.22);
    // poll event
    window.draw(crosshair);
    window.draw(Replay);
    window.draw(Pause_menu_button);
}


void Classic_menu()
{
    // background


    sf::Sprite classic_menu_background;

   classic_menu_background.setTexture(classic_menu_background_texture);
    classic_menu_background.setScale(
        window.getSize().x / classic_menu_background.getLocalBounds().width,
        window.getSize().y / classic_menu_background.getLocalBounds().height);

    // levels


    const int width = 150;
    const int height = 150;
    const int gap = 30;
    const int num_rows = 3;
    const int num_cols = 5;

    const int grid_width = (num_cols * width) + ((num_cols - 1) * gap);
    const int grid_height = (num_rows * height) + ((num_rows - 1) * gap);

    const int start_x = (window.getSize().x - grid_width) / 2;
    const int start_y = (window.getSize().y - grid_height) / 2;


    Level_Evaluation(lev);


    for (int i = 0; i < num_rows * num_cols; ++i)
    {


        lev[i].view.Level_selection.setPosition(
            start_x + (i % num_cols) * (width + gap),
            start_y + (i / num_cols) * (height + gap)
        );
    }


    // back button

    back_button.sprite.setTexture(back_button.Default_texture);
    back_button.sprite.setOrigin(back_button.sprite.getLocalBounds().width / 2, back_button.sprite.getLocalBounds().height / 2);
    back_button.sprite.setPosition(window.getSize().x / 12.061, window.getSize().y / 1.099);

    // hoverEffect checking

    hoverEffect(back_button.sprite);

    // pollEvent loop

    classic_menu_eventloop();

    // drawing

    window.draw(classic_menu_background);
    window.draw(back_button.sprite);
    for (int i = 0; i < 15; i++)
    {
        window.draw(lev[i].view.Level_selection);
    }
    hoverEffect(lev);
}

void Achievements_menu()
{

    // backgroound

    sf::Sprite background;
    background.setTexture(achievements_menu_background);

    background.setScale(
        window.getSize().x / background.getLocalBounds().width,
        window.getSize().y / background.getLocalBounds().height);

    // achievements

    for (int i = 0; i < 5; i++)
    {
        achievements[i].sprite.setOrigin(achievements[i].sprite.getLocalBounds().width / 2, achievements[i].sprite.getLocalBounds().height /2);
        achievements[i].sprite.setScale(0.5f, 0.5f);
    }

    achievements[0].sprite.setPosition(window.getSize().x / 2, window.getSize().y / 7);
    achievements[1].sprite.setPosition(window.getSize().x / 2, window.getSize().y / 3.186);
    achievements[2].sprite.setPosition(window.getSize().x / 2, window.getSize().y / 2.065);
    achievements[3].sprite.setPosition(window.getSize().x / 2, window.getSize().y / 1.531);
    achievements[4].sprite.setPosition(window.getSize().x / 2, window.getSize().y / 1.211);

    // back button

    back_button.sprite.setTexture(back_button.Default_texture);
    back_button.sprite.setOrigin(back_button.sprite.getLocalBounds().width / 2, back_button.sprite.getLocalBounds().height / 2);
    back_button.sprite.setPosition(window.getSize().x / 12.061, window.getSize().y / 1.099);

    hoverEffect(back_button.sprite);

    // pollEvent loop

    achievements_menu_eventloop();

    // drawing
    Achievements_texture(achievements);

    window.draw(background);
    for (int i = 0; i < 5; i++)
    {
        window.draw(achievements[i].sprite);
    }
    window.draw(back_button.sprite);
}



void player_one_menu()
{


    window.setFramerateLimit(60);


    //Text

    Text player_one("player one", game_font, 50);
    player_one.setOrigin(player_one.getLocalBounds().width / 2, player_one.getLocalBounds().height / 2);
    player_one.setScale(1.5, 1.5);
    player_one.setPosition(Vector2f(930, 130));


    //Sprite

    Character_ONE.sprite.setTexture(character_one.original);
    Character_ONE.sprite.setOrigin(Character_ONE.sprite.getLocalBounds().width / 2, Character_ONE.sprite.getLocalBounds().height / 2);
    Character_ONE.sprite.setScale(1.25, 1.25);
    Character_ONE.sprite.setPosition(Vector2f(400, 400));

    Character_TWO.sprite.setTexture(character_two.original);
    Character_TWO.sprite.setOrigin(Character_TWO.sprite.getLocalBounds().width / 2, Character_TWO.sprite.getLocalBounds().height / 2);
    Character_TWO.sprite.setScale(1.25, 1.25);
    Character_TWO.sprite.setPosition(Vector2f(760, 400));

    Character_THREE.sprite.setTexture(character_three.original);
    Character_THREE.sprite.setOrigin(Character_THREE.sprite.getLocalBounds().width / 2, Character_THREE.sprite.getLocalBounds().height / 2);
    Character_THREE.sprite.setScale(1.25, 1.25);
    Character_THREE.sprite.setPosition(Vector2f(1120, 400));

    Character_FOUR.sprite.setTexture(character_four.original);
    Character_FOUR.sprite.setOrigin(Character_FOUR.sprite.getLocalBounds().width / 2, Character_FOUR.sprite.getLocalBounds().height / 2);
    Character_FOUR.sprite.setScale(1.25, 1.25);
    Character_FOUR.sprite.setPosition(Vector2f(1480, 400));

    Character_FIVE.sprite.setTexture(character_five.original);
    Character_FIVE.sprite.setOrigin(Character_FIVE.sprite.getLocalBounds().width / 2, Character_FIVE.sprite.getLocalBounds().height / 2);
    Character_FIVE.sprite.setScale(1.25, 1.25);
    Character_FIVE.sprite.setPosition(Vector2f(400, 800));

    Character_SIX.sprite.setTexture(character_six.original);
    Character_SIX.sprite.setOrigin(Character_SIX.sprite.getLocalBounds().width / 2, Character_SIX.sprite.getLocalBounds().height / 2);
    Character_SIX.sprite.setScale(1.25, 1.25);
    Character_SIX.sprite.setPosition(Vector2f(760, 800));

    Character_SEVEN.sprite.setTexture(character_seven.original);
    Character_SEVEN.sprite.setOrigin(Character_SEVEN.sprite.getLocalBounds().width / 2, Character_SEVEN.sprite.getLocalBounds().height / 2);
    Character_SEVEN.sprite.setScale(1.25, 1.25);
    Character_SEVEN.sprite.setPosition(Vector2f(1120, 800));

    Character_EIGHT.sprite.setTexture(character_eight.original);
    Character_EIGHT.sprite.setOrigin(Character_EIGHT.sprite.getLocalBounds().width / 2, Character_EIGHT.sprite.getLocalBounds().height / 2);
    Character_EIGHT.sprite.setScale(1.25, 1.25);
    Character_EIGHT.sprite.setPosition(Vector2f(1480, 800));


    back_button.sprite.setTexture(back_button.Default_texture);
    back_button.sprite.setOrigin(back_button.sprite.getLocalBounds().width / 2, back_button.sprite.getLocalBounds().height / 2);
    back_button.sprite.setPosition(window.getSize().x / 12.061, window.getSize().y / 1.099);




    Choose_Player_Back_Ground.setTexture(choose_player_back_ground);
    Choose_Player_Back_Ground.setScale(4, 4);
    Choose_Player_Back_Ground.setPosition(1, 2);
    Choose_Player_Back_Ground.setColor(Color::Blue);



    player_one_menu_eventloop();

    Event event;

    hoverEffect(Character_ONE.sprite, character_one.original, character_one.hovered, character_one.chosen, event);
    hoverEffect(Character_TWO.sprite, character_two.original, character_two.hovered, character_two.chosen, event);
    hoverEffect(Character_THREE.sprite, character_three.original, character_three.hovered, character_three.chosen, event);
    hoverEffect(Character_FOUR.sprite, character_four.original, character_four.hovered, character_four.chosen, event);
    hoverEffect(Character_FIVE.sprite, character_five.original, character_five.hovered, character_five.chosen, event);
    hoverEffect(Character_SIX.sprite, character_six.original, character_six.hovered, character_six.chosen, event);
    hoverEffect(Character_EIGHT.sprite, character_eight.original, character_eight.hovered, character_eight.chosen, event);
    hoverEffect(Character_SEVEN.sprite, character_seven.original, character_seven.hovered, character_seven.chosen, event);

    hoverEffect(back_button.sprite);


    window.draw(Choose_Player_Back_Ground);
    if (chosen)
        player_one.setFillColor(Color::Blue);

    window.draw(back_button.sprite);
    window.draw(player_one);
    window.draw(Character_ONE.sprite);
    window.draw(Character_TWO.sprite);
    window.draw(Character_THREE.sprite);
    window.draw(Character_FOUR.sprite);
    window.draw(Character_FIVE.sprite);
    window.draw(Character_SIX.sprite);
    window.draw(Character_SEVEN.sprite);
    window.draw(Character_EIGHT.sprite);

}


void player_two_menu()
{

    window.setFramerateLimit(60);


    //Text

    Text player_two("player Two", game_font, 50);
    player_two.setOrigin(player_two.getLocalBounds().width / 2, player_two.getLocalBounds().height / 2);
    player_two.setScale(1.5, 1.5);
    player_two.setPosition(Vector2f(930, 130));



    //Sprite


    Character_ONE.sprite.setTexture(character_one.original);
    Character_ONE.sprite.setOrigin(Character_ONE.sprite.getLocalBounds().width / 2, Character_ONE.sprite.getLocalBounds().height / 2);
    Character_ONE.sprite.setScale(1.25, 1.25);
    Character_ONE.sprite.setPosition(Vector2f(400, 400));

    Character_TWO.sprite.setTexture(character_two.original);
    Character_TWO.sprite.setOrigin(Character_TWO.sprite.getLocalBounds().width / 2, Character_TWO.sprite.getLocalBounds().height / 2);
    Character_TWO.sprite.setScale(1.25, 1.25);
    Character_TWO.sprite.setPosition(Vector2f(760, 400));

    Character_THREE.sprite.setTexture(character_three.original);
    Character_THREE.sprite.setOrigin(Character_THREE.sprite.getLocalBounds().width / 2, Character_THREE.sprite.getLocalBounds().height / 2);
    Character_THREE.sprite.setScale(1.25, 1.25);
    Character_THREE.sprite.setPosition(Vector2f(1120, 400));

    Character_FOUR.sprite.setTexture(character_four.original);
    Character_FOUR.sprite.setOrigin(Character_FOUR.sprite.getLocalBounds().width / 2, Character_FOUR.sprite.getLocalBounds().height / 2);
    Character_FOUR.sprite.setScale(1.25, 1.25);
    Character_FOUR.sprite.setPosition(Vector2f(1480, 400));

    Character_FIVE.sprite.setTexture(character_five.original);
    Character_FIVE.sprite.setOrigin(Character_FIVE.sprite.getLocalBounds().width / 2, Character_FIVE.sprite.getLocalBounds().height / 2);
    Character_FIVE.sprite.setScale(1.25, 1.25);
    Character_FIVE.sprite.setPosition(Vector2f(400, 800));

    Character_SIX.sprite.setTexture(character_six.original);
    Character_SIX.sprite.setOrigin(Character_SIX.sprite.getLocalBounds().width / 2, Character_SIX.sprite.getLocalBounds().height / 2);
    Character_SIX.sprite.setScale(1.25, 1.25);
    Character_SIX.sprite.setPosition(Vector2f(760, 800));

    Character_SEVEN.sprite.setTexture(character_seven.original);
    Character_SEVEN.sprite.setOrigin(Character_SEVEN.sprite.getLocalBounds().width / 2, Character_SEVEN.sprite.getLocalBounds().height / 2);
    Character_SEVEN.sprite.setScale(1.25, 1.25);
    Character_SEVEN.sprite.setPosition(Vector2f(1120, 800));

    Character_EIGHT.sprite.setTexture(character_eight.original);
    Character_EIGHT.sprite.setOrigin(Character_EIGHT.sprite.getLocalBounds().width / 2, Character_EIGHT.sprite.getLocalBounds().height / 2);
    Character_EIGHT.sprite.setScale(1.25, 1.25);
    Character_EIGHT.sprite.setPosition(Vector2f(1480, 800));


    back_button.sprite.setTexture(back_button.Default_texture);
    back_button.sprite.setOrigin(back_button.sprite.getLocalBounds().width / 2, back_button.sprite.getLocalBounds().height / 2);
    back_button.sprite.setPosition(window.getSize().x / 12.061, window.getSize().y / 1.099);


    Choose_Player_Back_Ground.setTexture(choose_player_back_ground);
    Choose_Player_Back_Ground.setScale(4, 4);
    Choose_Player_Back_Ground.setPosition(1, 2);
    Choose_Player_Back_Ground.setColor(Color(225, 70, 13));



    sf::Event event;

    player_two_menu_eventloop();



    hoverEffect(Character_ONE.sprite, character_one.original, character_one.hovered, character_one.chosen, event);
    hoverEffect(Character_TWO.sprite, character_two.original, character_two.hovered, character_two.chosen, event);
    hoverEffect(Character_THREE.sprite, character_three.original, character_three.hovered, character_three.chosen, event);
    hoverEffect(Character_FOUR.sprite, character_four.original, character_four.hovered, character_four.chosen, event);
    hoverEffect(Character_FIVE.sprite, character_five.original, character_five.hovered, character_five.chosen, event);
    hoverEffect(Character_SIX.sprite, character_six.original, character_six.hovered, character_six.chosen, event);
    hoverEffect(Character_SEVEN.sprite, character_seven.original, character_seven.hovered, character_seven.chosen, event);
    hoverEffect(Character_EIGHT.sprite, character_eight.original, character_eight.hovered, character_eight.chosen, event);

    hoverEffect(back_button.sprite);


    window.draw(Choose_Player_Back_Ground);


    if (chosen)
        player_two.setFillColor(Color::Red);
    window.draw(back_button.sprite);
    window.draw(player_two);
    window.draw(Character_ONE.sprite);
    window.draw(Character_TWO.sprite);
    window.draw(Character_THREE.sprite);
    window.draw(Character_FOUR.sprite);
    window.draw(Character_FIVE.sprite);
    window.draw(Character_SIX.sprite);
    window.draw(Character_SEVEN.sprite);
    window.draw(Character_EIGHT.sprite);


}



void ReadFile() {
    string myText;
    // Read from the text file
    ifstream saveFile("save.txt");
    int levNum = 0;
    // Use a while loop together with the getline() function to read the file line by line
    while (getline(saveFile, myText)) {
        //if (levNum == 0 && myText == "-1") {
        //    lev[levNum].view.highest_score = 0;
        //}
        lev[levNum].view.highest_score = stoi(myText);
        levNum++;
    }

    // Close the file
    saveFile.close();

}

void WriteFile() {
        // Create and open a text file
        ofstream myfile("save.txt");
        int levNum = 0;
        if (myfile.is_open())
        {
            string str;
            while (str != "-1") {
                str = to_string(lev[levNum].view.highest_score);
                myfile << str << endl;
                levNum++;
            }
            myfile.close();
        }
        else cerr << "Unable to open file";

}

void Texture_loading()
{
// general
shoot_soundbuffer.loadFromFile("assets/sounds/shoot.ogg");
Restart_soundbuffer.loadFromFile("assets/sounds/restart.ogg");
game_font.loadFromFile("assets/HelveticaNeueCondensedBlack.ttf");

back_button.Default_texture.loadFromFile("assets/menus/Back_button.png");
back_button.Pressed_texture.loadFromFile("assets/menus/Back_button_pressed.png");

SFX_click_soundbuffer.loadFromFile("assets/sounds/SFX_click.ogg");

//choose_player

character_one.hovered.loadFromFile("assets/player_characters/default-hovered.png");
character_one.chosen.loadFromFile("assets/player_characters/default-chosen.png");
character_one.original.loadFromFile("assets/player_characters/default.png");

character_two.hovered.loadFromFile("assets/player_characters/RedSuit-hovered.png");
character_two.chosen.loadFromFile("assets/player_characters/RedSuit-chosen.png");
character_two.original.loadFromFile("assets/player_characters/RedSuit.png");

character_three.hovered.loadFromFile("assets/player_characters/Robot-hovered.png");
character_three.chosen.loadFromFile("assets/player_characters/Robot-chosen.png");
character_three.original.loadFromFile("assets/player_characters/Robot.png");

character_four.hovered.loadFromFile("assets/player_characters/wolf-hovered.png");
character_four.chosen.loadFromFile("assets/player_characters/wolf-chosen.png");
character_four.original.loadFromFile("assets/player_characters/wolf.png");


character_five.hovered.loadFromFile("assets/player_characters/vampire-hovered.png");
character_five.chosen.loadFromFile("assets/player_characters/vampire-chosen.png");
character_five.original.loadFromFile("assets/player_characters/vampire.png");

character_six.hovered.loadFromFile("assets/player_characters/pirate-hovered.png");
character_six.chosen.loadFromFile("assets/player_characters/pirate-chosen.png");
character_six.original.loadFromFile("assets/player_characters/pirate.png");

character_seven.hovered.loadFromFile("assets/player_characters/mummy-hovered.png");
character_seven.chosen.loadFromFile("assets/player_characters/mummy-chosen.png");
character_seven.original.loadFromFile("assets/player_characters/mummy.png");

character_eight.hovered.loadFromFile("assets/player_characters/ninja-hovered.png");
character_eight.chosen.loadFromFile("assets/player_characters/ninja-chosen.png");
character_eight.original.loadFromFile("assets/player_characters/ninja.png");


choose_player_back_ground.loadFromFile("assets/player_characters/background_circus.png");



//1v1_map

MAP_1.hovered.loadFromFile("assets/1v1_maps/SandMap-hovered.png");
MAP_1.original.loadFromFile("assets/1v1_maps/SandMap.png");

MAP_2.hovered.loadFromFile("assets/1v1_maps/mansion-hovered.png");
MAP_2.original.loadFromFile("assets/1v1_maps/mansion.png");

MAP_3.hovered.loadFromFile("assets/1v1_maps/WhiteWoods-hovered.png");
MAP_3.original.loadFromFile("assets/1v1_maps/WhiteWoods.png");

MAP_4.hovered.loadFromFile("assets/1v1_maps/wastelands-hovered.png");
MAP_4.original.loadFromFile("assets/1v1_maps/wastelands.png");



maps_1v1_player_back_ground.loadFromFile("assets/1v1_maps/desert-background.png");
maps_one_1v1_back_ground.loadFromFile("assets/1v1_maps/desert-background.png");
maps_two_1v1_back_ground.loadFromFile("assets/1v1_maps/scream-background.png");
maps_three_1v1_back_ground.loadFromFile("assets/1v1_maps/ice-background.png");
maps_four_1v1_back_ground.loadFromFile("assets/1v1_maps/sun_land-background.png");


//1v1
victory_texture.loadFromFile("assets/1v1/fotor_2023-5-6_21_25_1.png");
victory_menu.setTexture(&victory_texture);


victory_texture_2.loadFromFile("assets/1v1/fotor_2023-5-6_23_24_19.png");
victory_menu_2.setTexture(&victory_texture_2);


restart_texture.loadFromFile("assets/1v1/Reset_button.png");
restart.setTexture(&restart_texture);


back_texture.loadFromFile("assets/1v1/Quit_To_Main_Menu.png");
back.setTexture(&back_texture);

hundred_health_texture.loadFromFile("assets/1v1/100_health.png");
hundred_health.setTexture(&hundred_health_texture);

seventy_health_texture.loadFromFile("assets/1v1/75_health.png");
seventy_health.setTexture(&seventy_health_texture);

forty_health_texture.loadFromFile("assets/1v1/25_health.png");
forty_health.setTexture(&forty_health_texture);

ten_health_texture.loadFromFile("assets/1v1/15_health.png");
ten_health.setTexture(&ten_health_texture);

zero_health_texture.loadFromFile("assets/1v1/0_health.png");
zero_health.setTexture(&zero_health_texture);

hundred_health_texture_2.loadFromFile("assets/1v1/100_health.png");
hundred_health_2.setTexture(&hundred_health_texture_2);

seventy_health_texture_2.loadFromFile("assets/1v1/75_health.png");
seventy_health_2.setTexture(&seventy_health_texture_2);

forty_health_texture_2.loadFromFile("assets/1v1/25_health.png");
forty_health_2.setTexture(&forty_health_texture_2);

ten_health_texture_2.loadFromFile("assets/1v1/15_health.png");
ten_health_2.setTexture(&ten_health_texture_2);

zero_health_texture_2.loadFromFile("assets/1v1/0_health.png");
zero_health_2.setTexture(&zero_health_texture_2);



// win lose panels

win_panel_texture.loadFromFile("assets/win_lose_panels/win_panel.png");
lose_panel_texture.loadFromFile("assets/win_lose_panels/lose_panel.png");
star_texture.loadFromFile("assets/win_lose_panels/Star.png");
empty_star_texture.loadFromFile("assets/win_lose_panels/Empty_star.png");
backward_texture.loadFromFile("assets/win_lose_panels/Backward_texture.png");
forward_texture.loadFromFile("assets/win_lose_panels/Forward_texture.png");
backward_texture.loadFromFile("assets/win_lose_panels/Backward_texture.png");
reset_texture.loadFromFile("assets/win_lose_panels/Reset_button.png");
quit_to_main_menu_texture.loadFromFile("assets/win_lose_panels/Quit_To_Main_Menu.png");
blur_effect_texture.loadFromFile("assets/win_lose_panels/blur_effect.png");

// main menu


main_menu_background_texture.loadFromFile("assets/menus/main_menu/Screenshot_19.png");

mr_bullet_logo_texture.loadFromFile("assets/menus/main_menu/mr_logo_1.png");


play_button.Default_texture.loadFromFile("assets/menus/main_menu/Play_button.png");
play_button.Pressed_texture.loadFromFile("assets/menus/main_menu/Play_button_pressed.png");

options_button.Default_texture.loadFromFile("assets/menus/main_menu/Options_button.png");
options_button.Pressed_texture.loadFromFile("assets/menus/main_menu/Options_button_pressed.png");

quit_button.Default_texture.loadFromFile("assets/menus/main_menu/Quit_button.png");
quit_button.Pressed_texture.loadFromFile("assets/menus/main_menu/Quit_button_pressed.png");


// options menu

back_ground.loadFromFile("assets/menus/options_menu/background_western.png");
checkbox_close.loadFromFile("assets/menus/options_menu/switch_off.png");
checkbox_open.loadFromFile("assets/menus/options_menu/switch_on.png");
volume_increase.loadFromFile("assets/menus/options_menu/Volume_increase.png");
volume_decrease.loadFromFile("assets/menus/options_menu/Volume_decrease.png");


// options menu pause

options_menu_background.loadFromFile("assets/menus/pause_menu/background_vampire.png");

// Pause menu

Resume.Default_texture.loadFromFile("assets/menus/pause_menu/Resume_button.png");
Resume.Pressed_texture.loadFromFile("assets/menus/pause_menu/Resume_button_pressed.png");
optionts.Default_texture.loadFromFile("assets/menus/pause_menu/Options_button.png");
optionts.Pressed_texture.loadFromFile("assets/menus/pause_menu/Options_button_pressed.png");
QUIT.Default_texture.loadFromFile("assets/menus/pause_menu/Quit_button.png");
QUIT.Pressed_texture.loadFromFile("assets/menus/pause_menu/Quit_button_pressed.png");
Rec_background.loadFromFile("assets/menus/pause_menu/Transparent-screen.png");
pause_back_ground.loadFromFile("assets/menus/pause_menu/background_prison.png");


// play menu


play_menu_background_texture.loadFromFile("assets/menus/play_menu/Play_menu_background.png");


classic_menu.Default_texture.loadFromFile("assets/menus/play_menu/Classic_mode.png");
classic_menu.Hovered_texture.loadFromFile("assets/menus/play_menu/Classic_mode_hovered.png");

duels_menu.Default_texture.loadFromFile("assets/menus/play_menu/Duels.png");
duels_menu.Hovered_texture.loadFromFile("assets/menus/play_menu/Duels_hovered.png");

// Level
pause_menu_button.loadFromFile("assets/menus/Level/pause button.png");
Bullet_texture.loadFromFile("assets/menus/Level/bullet.png");


// classic menu

classic_menu_background_texture.loadFromFile("assets/menus/classic_menu/background_city_night.png");
Border_hover_effect.loadFromFile("assets/menus/classic_menu/Border_hover_effect.png");


lev[0].view.Level_evaluation = 0;
ReadFile();
//lev[0].view.highest_score = lev[0].view.Level_evaluation;
lev[0].view.Level_none_stared.loadFromFile("assets/menus/classic_menu/Lvl_1/Level_1_no_stars.png");
lev[0].view.Level_one_stared.loadFromFile("assets/menus/classic_menu/Lvl_1/Lvl_1_one_star.png");
lev[0].view.Level_two_stared.loadFromFile("assets/menus/classic_menu/Lvl_1/Lvl_1_two_stars.png");
lev[0].view.Leve_three_stared.loadFromFile("assets/menus/classic_menu/Lvl_1/Lvl_1_three_stars.png");

lev[1].view.Level_closed_texture.loadFromFile("assets/menus/classic_menu/Lvl_2/Lvl_2_closed.png");
lev[1].view.Level_none_stared.loadFromFile("assets/menus/classic_menu/Lvl_2/Lvl_2_no_stars.png");
lev[1].view.Level_one_stared.loadFromFile("assets/menus/classic_menu/Lvl_2/Lvl_2_one_star.png");
lev[1].view.Level_two_stared.loadFromFile("assets/menus/classic_menu/Lvl_2/Lvl_2_two_stars.png");
lev[1].view.Leve_three_stared.loadFromFile("assets/menus/classic_menu/Lvl_2/Lvl_3_three_stars.png");

lev[2].view.Level_closed_texture.loadFromFile("assets/menus/classic_menu/Lvl_3/Lvl_3_closed.png");
lev[2].view.Level_none_stared.loadFromFile("assets/menus/classic_menu/Lvl_3/Lvl_3_no_stars.png");
lev[2].view.Level_one_stared.loadFromFile("assets/menus/classic_menu/Lvl_3/Lvl_3_one_star.png");
lev[2].view.Level_two_stared.loadFromFile("assets/menus/classic_menu/Lvl_3/Lvl_3_two_stars.png");
lev[2].view.Leve_three_stared.loadFromFile("assets/menus/classic_menu/Lvl_3/Lvl_3_three_stars.png");

lev[3].view.Level_closed_texture.loadFromFile("assets/menus/classic_menu/Lvl_4/Lvl_4_closed.png");
lev[3].view.Level_none_stared.loadFromFile("assets/menus/classic_menu/Lvl_4/Lvl_4_no_stars.png");
lev[3].view.Level_one_stared.loadFromFile("assets/menus/classic_menu/Lvl_4/Lvl_4_one_star.png");
lev[3].view.Level_two_stared.loadFromFile("assets/menus/classic_menu/Lvl_4/Lvl_4_two_stars.png");
lev[3].view.Leve_three_stared.loadFromFile("assets/menus/classic_menu/Lvl_4/Lvl_4_three_stars.png");

lev[4].view.Level_closed_texture.loadFromFile("assets/menus/classic_menu/Lvl_5/Lvl_5_closed.png");
lev[4].view.Level_none_stared.loadFromFile("assets/menus/classic_menu/Lvl_5/Lvl_5_no_stars.png");
lev[4].view.Level_one_stared.loadFromFile("assets/menus/classic_menu/Lvl_5/Lvl_5_one_star.png");
lev[4].view.Level_two_stared.loadFromFile("assets/menus/classic_menu/Lvl_5/Lvl_5_two_stars.png");
lev[4].view.Leve_three_stared.loadFromFile("assets/menus/classic_menu/Lvl_5/Lvl_5_three_stars.png");

lev[5].view.Level_closed_texture.loadFromFile("assets/menus/classic_menu/Lvl_6/Lvl_6_closed.png");
lev[5].view.Level_none_stared.loadFromFile("assets/menus/classic_menu/Lvl_6/Lvl_6_none_stared.png");
lev[5].view.Level_one_stared.loadFromFile("assets/menus/classic_menu/Lvl_6/Lvl_6_one_stared.png");
lev[5].view.Level_two_stared.loadFromFile("assets/menus/classic_menu/Lvl_6/Lvl_6_two_stared.png");
lev[5].view.Leve_three_stared.loadFromFile("assets/menus/classic_menu/Lvl_6/Lvl_6_three_stars.png");

lev[6].view.Level_closed_texture.loadFromFile("assets/menus/classic_menu/Lvl_7/Lvl_7_closed.png");
lev[6].view.Level_none_stared.loadFromFile("assets/menus/classic_menu/Lvl_7/Lvl_7_none_stared.png");
lev[6].view.Level_one_stared.loadFromFile("assets/menus/classic_menu/Lvl_7/Lvl_7_one_stared.png");
lev[6].view.Level_two_stared.loadFromFile("assets/menus/classic_menu/Lvl_7/Lvl_7_two_stared.png");
lev[6].view.Leve_three_stared.loadFromFile("assets/menus/classic_menu/Lvl_7/Lvl_7_three_stared.png");

lev[7].view.Level_closed_texture.loadFromFile("assets/menus/classic_menu/Lvl_8/Lvl_8_closed.png");
lev[7].view.Level_none_stared.loadFromFile("assets/menus/classic_menu/Lvl_8/Lvl_8_none_stared.png");
lev[7].view.Level_one_stared.loadFromFile("assets/menus/classic_menu/Lvl_8/Lvl_8_one_stared.png");
lev[7].view.Level_two_stared.loadFromFile("assets/menus/classic_menu/Lvl_8/Lvl_8_two_stared.png");
lev[7].view.Leve_three_stared.loadFromFile("assets/menus/classic_menu/Lvl_8/Lvl_8_three_stars.png");

lev[8].view.Level_closed_texture.loadFromFile("assets/menus/classic_menu/Lvl_9/Lvl_9_closed.png");
lev[8].view.Level_none_stared.loadFromFile("assets/menus/classic_menu/Lvl_9/Lvl_9_none_stared.png");
lev[8].view.Level_one_stared.loadFromFile("assets/menus/classic_menu/Lvl_9/Lvl_9_one_stared.png");
lev[8].view.Level_two_stared.loadFromFile("assets/menus/classic_menu/Lvl_9/Lvl_9_two_stared.png");
lev[8].view.Leve_three_stared.loadFromFile("assets/menus/classic_menu/Lvl_9/Lvl_9_three_stared.png");

lev[9].view.Level_closed_texture.loadFromFile("assets/menus/classic_menu/Lvl_10/Lvl_10_closed.png");
lev[9].view.Level_none_stared.loadFromFile("assets/menus/classic_menu/Lvl_10/Lvl_10_none_stared.png");
lev[9].view.Level_one_stared.loadFromFile("assets/menus/classic_menu/Lvl_10/Lvl_10_one_stared.png");
lev[9].view.Level_two_stared.loadFromFile("assets/menus/classic_menu/Lvl_10/Lvl_10_two_stared.png");
lev[9].view.Leve_three_stared.loadFromFile("assets/menus/classic_menu/Lvl_10/Lvl_10_three_stared.png");

lev[10].view.Level_closed_texture.loadFromFile("assets/menus/classic_menu/Lvl_11/Lvl_11_closed.png");
lev[10].view.Level_none_stared.loadFromFile("assets/menus/classic_menu/Lvl_11/Lvl_11_none_stared.png");
lev[10].view.Level_one_stared.loadFromFile("assets/menus/classic_menu/Lvl_11/Lvl_11_one_stared.png");
lev[10].view.Level_two_stared.loadFromFile("assets/menus/classic_menu/Lvl_11/Lvl_11_two_stared.png");
lev[10].view.Leve_three_stared.loadFromFile("assets/menus/classic_menu/Lvl_11/Lvl_11_three_stared.png");

lev[11].view.Level_closed_texture.loadFromFile("assets/menus/classic_menu/Lvl_12/Lvl_12_closed.png");
lev[11].view.Level_none_stared.loadFromFile("assets/menus/classic_menu/Lvl_12/Lvl_12_none_stared.png");
lev[11].view.Level_one_stared.loadFromFile("assets/menus/classic_menu/Lvl_12/Lvl_12_one_stared.png");
lev[11].view.Level_two_stared.loadFromFile("assets/menus/classic_menu/Lvl_12/Lvl_12_two_stared.png");
lev[11].view.Leve_three_stared.loadFromFile("assets/menus/classic_menu/Lvl_12/Lvl_12_three_stared.png");

lev[12].view.Level_closed_texture.loadFromFile("assets/menus/classic_menu/Lvl_13/Lvl_13_closed.png");
lev[12].view.Level_none_stared.loadFromFile("assets/menus/classic_menu/Lvl_13/Lvl_13_none_stared.png");
lev[12].view.Level_one_stared.loadFromFile("assets/menus/classic_menu/Lvl_13/Lvl_13_one_stared.png");
lev[12].view.Level_two_stared.loadFromFile("assets/menus/classic_menu/Lvl_13/Lvl_13_two_stared.png");
lev[12].view.Leve_three_stared.loadFromFile("assets/menus/classic_menu/Lvl_13/Lvl_13_three_stared.png");

lev[13].view.Level_closed_texture.loadFromFile("assets/menus/classic_menu/Lvl_14/Lvl_14_closed.png");
lev[13].view.Level_none_stared.loadFromFile("assets/menus/classic_menu/Lvl_14/Lvl_14_none_stared.png");
lev[13].view.Level_one_stared.loadFromFile("assets/menus/classic_menu/Lvl_14/Lvl_14_one_stared.png");
lev[13].view.Level_two_stared.loadFromFile("assets/menus/classic_menu/Lvl_14/Lvl_14_two_stared.png");
lev[13].view.Leve_three_stared.loadFromFile("assets/menus/classic_menu/Lvl_14/Lvl_14_three_stared.png");

lev[14].view.Level_closed_texture.loadFromFile("assets/menus/classic_menu/Lvl_15/Lvl_15_closed.png");
lev[14].view.Level_none_stared.loadFromFile("assets/menus/classic_menu/Lvl_15/Lvl_15_none_stared.png");
lev[14].view.Level_one_stared.loadFromFile("assets/menus/classic_menu/Lvl_15/Lvl_15_one_stared.png");
lev[14].view.Level_two_stared.loadFromFile("assets/menus/classic_menu/Lvl_15/Lvl_15_two_stared.png");
lev[14].view.Leve_three_stared.loadFromFile("assets/menus/classic_menu/Lvl_15/Lvl_15_three_stared.png");

// achievements menu
achievements_menu_background.loadFromFile("assets/menus/achievements_menu/background_chinese.png");

achievement_texture.loadFromFile("assets/menus/achievements_menu/Achievement_cup_texture.png");
achievement_hovered_texture.loadFromFile("assets/menus/achievements_menu/Achievement_cup_hovered.png");

achievements[0].locked_texture.loadFromFile("assets/menus/achievements_menu/First_Kill_achievement_locked.png");
achievements[0].unlocked_texture.loadFromFile("assets/menus/achievements_menu/First_Kill_achievement_unlocked.png");

achievements[1].locked_texture.loadFromFile("assets/menus/achievements_menu/Finally_A_Challenge_locked.png");
achievements[1].unlocked_texture.loadFromFile("assets/menus/achievements_menu/Finally_A_Challenge_unlocked.png");

achievements[2].locked_texture.loadFromFile("assets/menus/achievements_menu/Halfway_There_achievement_locked.png");
achievements[2].unlocked_texture.loadFromFile("assets/menus/achievements_menu/Halfway_There_achievement_unlocked.png");

achievements[3].locked_texture.loadFromFile("assets/menus/achievements_menu/It_Ends_For_Now_locked.png");
achievements[3].unlocked_texture.loadFromFile("assets/menus/achievements_menu/It_Ends_For_Now_unlocked.png");

achievements[4].locked_texture.loadFromFile("assets/menus/achievements_menu/Assassin_locked.png");
achievements[4].unlocked_texture.loadFromFile("assets/menus/achievements_menu/Assassin_unlocked.png");

for (int i = 0; i < 5; i++)
{
    achievements[i].sprite.setTexture(achievements[i].locked_texture);
}

}

void volume_manage(sf::Text& text, sf::Sprite volume_up, sf::Sprite volume_down, int& volume_num)
{

            Vector2i mousePosition = Mouse::getPosition(window);


            if (volume_up.getGlobalBounds().contains(sf::Vector2f(mousePosition)) && volume_num < 100)
            {
                volume_num += 10;
                text.setString(to_string(volume_num));
                SFX_click.setVolume(volume_value[1]);
                SFX_click.play();
            }

            else if (volume_down.getGlobalBounds().contains(sf::Vector2f(mousePosition)) && volume_num > 0)
            {
                volume_num -= 10;
                text.setString(to_string(volume_num));
                SFX_click.setVolume(volume_value[1]);
                SFX_click.play();
            }


}

void MAPS_1v1()
{

window.setFramerateLimit(60);


//Text

Text choose_your_map("choose your map", game_font, 50);
choose_your_map.setOrigin(choose_your_map.getLocalBounds().width / 2, choose_your_map.getLocalBounds().height / 2);
choose_your_map.setScale(1.5, 1.5);
choose_your_map.setPosition(Vector2f(930, 130));


//sprite 


MAP_1.sprite.setTexture(MAP_1.original);
MAP_2.sprite.setTexture(MAP_2.original);
MAP_3.sprite.setTexture(MAP_3.original);
MAP_4.sprite.setTexture(MAP_4.original);


MAP_1.sprite.setTexture(MAP_1.original);
MAP_1.sprite.setOrigin(MAP_1.sprite.getLocalBounds().width / 2, MAP_1.sprite.getLocalBounds().height / 2);
MAP_1.sprite.setScale(0.35, 0.35);
MAP_1.sprite.setPosition(Vector2f(400, 350));


MAP_2.sprite.setTexture(MAP_2.original);
MAP_2.sprite.setOrigin(MAP_2.sprite.getLocalBounds().width / 2, MAP_2.sprite.getLocalBounds().height / 2);
MAP_2.sprite.setScale(0.35, 0.35);
MAP_2.sprite.setPosition(Vector2f(1600, 350));

MAP_3.sprite.setTexture(MAP_3.original);
MAP_3.sprite.setOrigin(MAP_3.sprite.getLocalBounds().width / 2, MAP_3.sprite.getLocalBounds().height / 2);
MAP_3.sprite.setScale(0.35, 0.35);
MAP_3.sprite.setPosition(Vector2f(400, 750));

MAP_4.sprite.setTexture(MAP_4.original);
MAP_4.sprite.setOrigin(MAP_4.sprite.getLocalBounds().width / 2, MAP_4.sprite.getLocalBounds().height / 2);
MAP_4.sprite.setScale(0.35, 0.35);
MAP_4.sprite.setPosition(Vector2f(1600, 750));



MAPS_1v1_player_back_ground.setTexture(maps_1v1_player_back_ground);


back_button.sprite.setTexture(back_button.Default_texture);
back_button.sprite.setOrigin(back_button.sprite.getLocalBounds().width / 2, back_button.sprite.getLocalBounds().height / 2);
back_button.sprite.setPosition(window.getSize().x / 12.061, window.getSize().y / 1.099);



  


    hoverEffect(MAP_1.sprite, MAP_1.original, MAP_1.hovered);
    hoverEffect(MAP_2.sprite, MAP_2.original, MAP_2.hovered);
    hoverEffect(MAP_3.sprite, MAP_3.original, MAP_3.hovered);
    hoverEffect(MAP_4.sprite, MAP_4.original, MAP_4.hovered);


    hoverEffect(back_button.sprite);

    MAPS_1v1_eventloop();

    window.draw(MAPS_1v1_player_back_ground);
    window.draw(back_button.sprite);
    window.draw(choose_your_map);
    window.draw(MAP_1.sprite);
    window.draw(MAP_2.sprite);
    window.draw(MAP_3.sprite);
    window.draw(MAP_4.sprite);
}





void Level_Evaluation(Lev lev[])
{
    for (int i = 0; i < 15; i++)
    {
        if (lev[i].view.highest_score == -1)
        {
            lev[i].view.Level_selection.setTexture(lev[i].view.Level_closed_texture);
        }

        else if (lev[i].view.highest_score == 0)
        {
            lev[i].view.Level_selection.setTexture(lev[i].view.Level_none_stared);
        }

        else if (lev[i].view.highest_score == 1)
        {
            lev[i].view.Level_selection.setTexture(lev[i].view.Level_one_stared);
        }

        else if (lev[i].view.highest_score == 2)
        {
            lev[i].view.Level_selection.setTexture(lev[i].view.Level_two_stared);
        }

        else if (lev[i].view.highest_score == 3)
        {
            lev[i].view.Level_selection.setTexture(lev[i].view.Leve_three_stared);
        }
    }
}

void Achievements_checking()
{
    // first kill
    if (lev[0].is_finished && achievements[0].is_open && achievements[0].is_closed)
    {
        achievements[0].sprite.setTexture(achievements[0].unlocked_texture);
        achievements[0].is_closed = false;
    }

    //duels


    //halfway there
    if (lev[7].is_finished && achievements[2].is_closed && achievements[2].is_open)
    {
        achievements[2].sprite.setTexture(achievements[2].unlocked_texture);
        achievements[2].is_closed = false;
    }

    // it ends for now
    if (lev[14].is_finished && achievements[3].is_closed && achievements[3].is_open)
    {
        achievements[3].sprite.setTexture(achievements[3].unlocked_texture);
        achievements[3].is_closed = false;
    }

    // asassin
    int ace_levels = 0;

    if (lev[14].view.Level_evaluation == 3)
    {
        for (int i = 0; i < 14; i++)
        {
            if (lev[i].view.Level_evaluation == 3)
            {
                ace_levels++;
            }
        }

        if (ace_levels == 15 && achievements[4].is_closed)
        {
            achievements[4].sprite.setTexture(achievements[4].unlocked_texture);
            achievements[4].is_closed = false;
        }
    }
}

void Achievements_texture(Achievment achieve[])
{
    for (int i = 0; i < 5; i++)
    {
        if (achieve[i].is_open)
        {
            achieve[i].sprite.setTexture(achieve[i].unlocked_texture);
        }
    }
}

void hoverEffect(sf::Sprite& button, sf::Texture& hovered)
{
    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

    if (button.getGlobalBounds().contains(mousePosition.x, mousePosition.y))
    {
        button.setTexture(hovered);
    }
}

void hoverEffect(sf::Sprite& button)
{
	// Get the local bounds of the button
	sf::FloatRect bounds = button.getLocalBounds();

	// Get the global bounds of the button
	sf::FloatRect globalBounds = button.getGlobalBounds();

	// Get the mouse position relative to the window
	sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

	// Check if the mouse is within the bounds of the button
	if (globalBounds.contains(mousePosition.x, mousePosition.y))
	{
		// Enlarge the button
		button.setScale(1.2, 1.2);
	}
	else
	{
		// Shrink the button back to its original size
		button.setScale(1.0, 1.0);
	}
}

void hoverEffect(Lev lev[])
{
    sf::Sprite Border;
    Border.setTexture(Border_hover_effect);
    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
    for (int i = 0; i < 15; i++)
    {
        if (lev[i].view.highest_score != -1 && lev[i].view.Level_selection.getGlobalBounds().contains(mousePosition.x, mousePosition.y))
        {
            sf::Vector2f Level_position = lev[i].view.Level_selection.getPosition();
            Border.setPosition(Level_position.x, Level_position.y);
            window.draw(Border);
        }
    }
}

void hoverEffect(sf::Sprite& option, sf::Texture& original, sf::Texture& hovered)
{
    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

    if (option.getGlobalBounds().contains(mousePosition.x, mousePosition.y))
    {
        option.setTexture(hovered);
    }

    else
    {
        option.setTexture(original);

    }
}

void hoverEffect(sf::Sprite& option, sf::Texture& original,sf::Texture& hovered, sf::Text& attached_text)
{
    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

    if(option.getGlobalBounds().contains(mousePosition.x, mousePosition.y))
    {
        option.setTexture(hovered);
        attached_text.setFillColor(sf::Color::Red);
    }

    else
        option.setTexture(original);
}

void hoverEffect(sf::Sprite& option, sf::Texture& original, sf::Texture& hovered, sf::Texture& clicked, sf::Event& event)
{
    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

    if (option.getGlobalBounds().contains(mousePosition.x, mousePosition.y))
    {
        option.setTexture(hovered);
    }

    else
    {
        option.setTexture(original);

    }

    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
    {
        if (option.getGlobalBounds().contains(mousePosition.x, mousePosition.y))
        {
            option.setTexture(clicked);
            chosen = true;

            // SFX_click.play(); // add after merge
        }
    }
}
