#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <vector>
#include <string>
#include <iostream>
#include "Menus.h"

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

// main menu
sf::Texture main_menu_background_texture, mr_bullet_logo_texture;
Button play_button, options_button, quit_button;

// options menu
Texture back_ground, checkbox_close, checkbox_open, Back_button_Red, Back_button_Yellow, volume_increase, volume_decrease;

// play menu
sf::Texture play_menu_background_texture;
Menu classic_menu, duels_menu;

// classic menu
sf::Texture classic_menu_background_texture;
sf::Texture Border_hover_effect;
Level level[20];

// achievements menu
sf::Texture achievements_menu_background;
sf::Texture achievement_texture, achievement_hovered_texture;
Achievment achievements[5];


void Main_menu(sf::RenderWindow& mainmenu)
{
    // main menu background and logo

	sf::Sprite main_menu_background, mr_bullet_logo;


	main_menu_background.setTexture(main_menu_background_texture);
	main_menu_background.setScale(
		mainmenu.getSize().x / main_menu_background.getLocalBounds().width, // to make the background fit into the screen size
		mainmenu.getSize().y / main_menu_background.getLocalBounds().height
    );


    mr_bullet_logo.setTexture(mr_bullet_logo_texture);
    mr_bullet_logo.setOrigin(mr_bullet_logo.getLocalBounds().width / 2, mr_bullet_logo.getLocalBounds().height / 2);
	mr_bullet_logo.setPosition(mainmenu.getSize().x / 2, mainmenu.getSize().y / 9);


	// Buttons


	play_button.sprite.setTexture(play_button.Default_texture);
    play_button.sprite.setOrigin(play_button.sprite.getLocalBounds().width / 2, play_button.sprite.getLocalBounds().height / 2);
	play_button.sprite.setPosition(mainmenu.getSize().x / 2, mainmenu.getSize().y / 3);



	options_button.sprite.setTexture(options_button.Default_texture);
    options_button.sprite.setOrigin(options_button.sprite.getLocalBounds().width / 2, options_button.sprite.getLocalBounds().height / 2);
	options_button.sprite.setPosition(mainmenu.getSize().x / 2, mainmenu.getSize().y / 2);



	quit_button.sprite.setTexture(quit_button.Default_texture);
    quit_button.sprite.setOrigin(quit_button.sprite.getLocalBounds().width / 2, quit_button.sprite.getLocalBounds().height / 2);
	quit_button.sprite.setPosition(mainmenu.getSize().x / 2, mainmenu.getSize().y * 2/3);


	// achievements menu

	sf::Sprite achievements_button;
	achievements_button.setTexture(achievement_texture);

	achievements_button.setOrigin(achievements_button.getLocalBounds().width / 2, achievements_button.getLocalBounds().height / 2);
	achievements_button.setPosition(mainmenu.getSize().x / 1.059, mainmenu.getSize().y / 1.097);


    //hovereffect checking

    hoverEffect(quit_button.sprite, mainmenu);
    hoverEffect(options_button.sprite, mainmenu);
    hoverEffect(play_button.sprite, mainmenu);
    hoverEffect(achievements_button, achievement_hovered_texture, mainmenu);

    // pollEvent loop

    sf::Event event;

    while(mainmenu.pollEvent(event))
    {
        if(event.type == sf::Event::Closed)
        {
            SFX_click.play();
            mainmenu.close();
        }

        else if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
        {

            // a variable to store the mouse position on the screen
            sf::Vector2i mousePosition = sf::Mouse::getPosition(mainmenu);

            if(quit_button.sprite.getGlobalBounds().contains(mousePosition.x, mousePosition.y))
            {
                SFX_click.play();
                quit_button.sprite.setTexture(quit_button.Pressed_texture);
                mainmenu.close();

            }

            else if (options_button.sprite.getGlobalBounds().contains(mousePosition.x, mousePosition.y))
            {
                SFX_click.play();
                options_button.sprite.setTexture(options_button.Pressed_texture);
                current_menu = options_menu;
            }


            else if (play_button.sprite.getGlobalBounds().contains(mousePosition.x, mousePosition.y))
            {
                SFX_click.play();
                play_button.sprite.setTexture(play_button.Pressed_texture);
                current_menu = play_menu;

            }

            else if (achievements_button.getGlobalBounds().contains(mousePosition.x, mousePosition.y))
            {
                SFX_click.play();
                current_menu = achievements_menu;
            }

        }
    }

    //drawing
    mainmenu.draw(main_menu_background);
    mainmenu.draw(mr_bullet_logo);
    mainmenu.draw(play_button.sprite);
    mainmenu.draw(options_button.sprite);
    mainmenu.draw(quit_button.sprite);
    mainmenu.draw(achievements_button);
}




void Play_menu(sf::RenderWindow& play_menu)
{
    // Background



    sf::Sprite play_menu_background;
    play_menu_background.setTexture(play_menu_background_texture);
    play_menu_background.setScale(
        play_menu.getSize().x / play_menu_background.getLocalBounds().width,
        play_menu.getSize().y / play_menu_background.getLocalBounds().height);


    // classic menu    and     duels menu



    classic_menu.sprite.setTexture(classic_menu.Default_texture);
    classic_menu.sprite.setOrigin(classic_menu.sprite.getLocalBounds().width / 2, classic_menu.sprite.getLocalBounds().height / 2);
    classic_menu.sprite.setPosition(play_menu.getSize().x / 5.529, play_menu.getSize().y / 2);





    duels_menu.sprite.setTexture(duels_menu.Default_texture);
    duels_menu.sprite.setOrigin(duels_menu.sprite.getLocalBounds().width / 2, duels_menu.sprite.getLocalBounds().height / 2);
    duels_menu.sprite.setPosition(play_menu.getSize().x / 1.235,play_menu.getSize().y / 2);

    // Text



    sf::Text classic_mode("Classic", game_font, 40), duels_mode("Duels", game_font, 40), choose("Choose your mode", game_font, 50);


    choose.setFillColor(sf::Color::Black);
    choose.setOrigin(choose.getLocalBounds().width / 2, choose.getLocalBounds().height / 2);
    choose.setPosition(play_menu.getSize().x / 2, play_menu.getSize().y / 9);


    classic_mode.setFillColor(sf::Color::Black);
    classic_mode.setOrigin(classic_mode.getLocalBounds().width / 2, classic_mode.getLocalBounds().height / 2);
    classic_mode.setPosition(play_menu.getSize().x / 5.529, play_menu.getSize().y / 3.342);


    duels_mode.setFillColor(sf::Color::Black);
    duels_mode.setOrigin(duels_mode.getLocalBounds().width / 2, duels_mode.getLocalBounds().height / 2);
    duels_mode.setPosition(play_menu.getSize().x / 1.235, play_menu.getSize().y / 3.342);


    // back button


    back_button.sprite.setTexture(back_button.Default_texture);
    back_button.sprite.setOrigin(back_button.sprite.getLocalBounds().width / 2, back_button.sprite.getLocalBounds().height / 2);
    back_button.sprite.setPosition(play_menu.getSize().x / 12.061, play_menu.getSize().y / 1.099);


    // hovereffect checking

    hoverEffect(back_button.sprite, play_menu);
    hoverEffect(classic_menu.sprite, classic_menu.Default_texture, classic_menu.Hovered_texture, classic_mode, play_menu);
    hoverEffect(duels_menu.sprite, duels_menu.Default_texture, duels_menu.Hovered_texture, duels_mode, play_menu);

    sf::Event event;
    while(play_menu.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            SFX_click.play();
            play_menu.close();
        }

        else if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
        {
            sf::Vector2i mousePosition = sf::Mouse::getPosition(play_menu);

            if (back_button.sprite.getGlobalBounds().contains(mousePosition.x, mousePosition.y))
            {
                SFX_click.play();
                back_button.sprite.setTexture(back_button.Pressed_texture);
                current_menu = main_menu;
            }

            else if (classic_menu.sprite.getGlobalBounds().contains(mousePosition.x, mousePosition.y))
            {
                SFX_click.play();
                current_menu = classic_Mode;
            }
        }
    }

    play_menu.draw(play_menu_background);
    play_menu.draw(choose);
    play_menu.draw(classic_mode);
    play_menu.draw(classic_menu.sprite);
    play_menu.draw(duels_mode);
    play_menu.draw(duels_menu.sprite);
    play_menu.draw(back_button.sprite);
}



void Options_menu(sf::RenderWindow& window )
{
    //Text
    sf::Text Audio_text("Audio", game_font, 50);
    Audio_text.setPosition(window.getSize().x / 10.666, window.getSize().y / 27);
    Audio_text.setOrigin(Audio_text.getLocalBounds().width / 2, Audio_text.getLocalBounds().height / 2);
    Audio_text.setFillColor(Color(190, 95, 14));

    sf::Text volume_presentage[2];
    int volumeVariable[2] = { 50,50 };

    volume_presentage[0].setCharacterSize(50);
    volume_presentage[0].setPosition(window.getSize().x / 5.052, window.getSize().y / 7.448);

    volume_presentage[1].setCharacterSize(50);
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
    Fullscreen_text.setFillColor(Color::White);


    //sprite
    Sprite armor_sprite, Back_ground, check_box_close, check_box_open, Rectangle_Background, Volume_increase[2], Volume_decrease[2];


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


    bool fullscreen = true;
    bool back = true;




    hoverEffect(back_button.sprite, window);

    Event event;
    while (window.pollEvent(event))
    {
        //Mouse Events

        if (Mouse::isButtonPressed(Mouse::Left))
        {

            Vector2i mousePosition = Mouse::getPosition(window);



            volume_manage(window, volume_presentage[0], Volume_increase[0], Volume_decrease[0], volumeVariable[0], game_font, "assets/HelveticaNeueCondensedBlack.ttf");



            volume_manage(window, volume_presentage[1], Volume_increase[1], Volume_decrease[1], volumeVariable[1], game_font, "assets/HelveticaNeueCondensedBlack.ttf");

            volume_presentage[0].setOrigin(volume_presentage[0].getLocalBounds().width / 2, volume_presentage[0].getLocalBounds().height / 2);
            volume_presentage[1].setOrigin(volume_presentage[1].getLocalBounds().width / 2, volume_presentage[0].getLocalBounds().height / 2);



            if (back_button.sprite.getGlobalBounds().contains(sf::Vector2f(mousePosition)))
            {
                back_button.sprite.setTexture(back_button.Pressed_texture);
                SFX_click.play();
                current_menu = main_menu;
            }

            if (check_box_close.getGlobalBounds().contains(sf::Vector2f(mousePosition)) && fullscreen)
            {
                SFX_click.play();
                fullscreen = false;
                Fullscreen_text.setFillColor(Color::White);
                window.create(VideoMode(1920, 1080), "window", Style::Fullscreen); //FUllscreen_mode
            }

            else if (check_box_open.getGlobalBounds().contains(sf::Vector2f(mousePosition)))
            {
                SFX_click.play();
                fullscreen = true;
                Fullscreen_text.setFillColor(Color::White);
                window.create(VideoMode(1920, 1080), "window", Style::Default); //Default_mode
            }
        }

            if (event.type == Event::Closed)
            {
                SFX_click.play();
                window.close();
            }

    }

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
        if (fullscreen == false)
            window.draw(check_box_open);
        else
            window.draw(check_box_close);
        window.draw(back_button.sprite);
}



void Classic_menu(sf::RenderWindow& classic_menu)
{
    // background


    sf::Sprite classic_menu_background;

   classic_menu_background.setTexture(classic_menu_background_texture);
    classic_menu_background.setScale(
        classic_menu.getSize().x / classic_menu_background.getLocalBounds().width,
        classic_menu.getSize().y / classic_menu_background.getLocalBounds().height);

    // levels


    const int width = 150;
    const int height = 150;
    const int gap = 30;
    const int num_rows = 2;
    const int num_cols = 5;

    const int grid_width = (num_cols * width) + ((num_cols - 1) * gap);
    const int grid_height = (num_rows * height) + ((num_rows - 1) * gap);

    const int start_x = (classic_menu.getSize().x - grid_width) / 2;
    const int start_y = (classic_menu.getSize().y - grid_height) / 2;


    Level_Evaluation(level);

    std::vector<sf::Sprite> levels;
    for (int i = 0; i < num_rows * num_cols; ++i)
    {


        level[i].view.Level_selection.setPosition(
            start_x + (i % num_cols) * (width + gap),
            start_y + (i / num_cols) * (height + gap)
        );
        levels.push_back(level[i].view.Level_selection);
    }


    // back button

    back_button.sprite.setTexture(back_button.Default_texture);
    back_button.sprite.setOrigin(back_button.sprite.getLocalBounds().width / 2, back_button.sprite.getLocalBounds().height / 2);
    back_button.sprite.setPosition(classic_menu.getSize().x / 12.061, classic_menu.getSize().y / 1.099);

    // hoverEffect checking

    hoverEffect(back_button.sprite, classic_menu);


    sf::Event event;
    while(classic_menu.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            SFX_click.play();
            classic_menu.close();
        }

        else if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
        {
            sf::Vector2i mousePosition = sf::Mouse::getPosition(classic_menu);

            if (back_button.sprite.getGlobalBounds().contains(mousePosition.x, mousePosition.y))
            {
                SFX_click.play();
                back_button.sprite.setTexture(back_button.Pressed_texture);
                current_menu = play_menu;
            }
        }
    }


    // drawing

    classic_menu.draw(classic_menu_background);
    classic_menu.draw(back_button.sprite);
    for (int i = 0; i < levels.size(); i++)
    {
        classic_menu.draw(level[i].view.Level_selection);
    }
    hoverEffect(level, classic_menu);
}


void Achievements_menu(sf::RenderWindow& achievements_menu)
{
    // backgroound

    sf::Sprite background;
    background.setTexture(achievements_menu_background);

    background.setScale(
        achievements_menu.getSize().x / background.getLocalBounds().width,
        achievements_menu.getSize().y / background.getLocalBounds().height);

    // achievements

    for (int i = 0; i < 5; i++)
    {
        achievements[i].sprite.setOrigin(achievements[i].sprite.getLocalBounds().width / 2, achievements[i].sprite.getLocalBounds().height /2);
        achievements[i].sprite.setScale(0.5f, 0.5f);
    }

    achievements[0].sprite.setPosition(achievements_menu.getSize().x / 2, achievements_menu.getSize().y / 7);
    achievements[1].sprite.setPosition(achievements_menu.getSize().x / 2, achievements_menu.getSize().y / 3.186);
    achievements[2].sprite.setPosition(achievements_menu.getSize().x / 2, achievements_menu.getSize().y / 2.065);
    achievements[3].sprite.setPosition(achievements_menu.getSize().x / 2, achievements_menu.getSize().y / 1.531);
    achievements[4].sprite.setPosition(achievements_menu.getSize().x / 2, achievements_menu.getSize().y / 1.211);

    // back button

    back_button.sprite.setTexture(back_button.Default_texture);
    back_button.sprite.setOrigin(back_button.sprite.getLocalBounds().width / 2, back_button.sprite.getLocalBounds().height / 2);
    back_button.sprite.setPosition(achievements_menu.getSize().x / 12.061, achievements_menu.getSize().y / 1.099);

    hoverEffect(back_button.sprite, achievements_menu);

    // pollEvent loop

    sf::Event event;
    while(achievements_menu.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            SFX_click.play();
            achievements_menu.close();
        }

        else if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
        {
            sf::Vector2i mousePosition = sf::Mouse::getPosition(achievements_menu);

            if (back_button.sprite.getGlobalBounds().contains(mousePosition.x, mousePosition.y))
            {
                SFX_click.play();
                back_button.sprite.setTexture(back_button.Pressed_texture);
                current_menu = main_menu;
            }
        }
    }

    // drawing

    achievements_menu.draw(background);
    for (int i = 0; i < 5; i++)
    {
        achievements_menu.draw(achievements[i].sprite);
    }
    achievements_menu.draw(back_button.sprite);
}


void Texture_loading()
{
// general

game_font.loadFromFile("assets/HelveticaNeueCondensedBlack.ttf");

back_button.Default_texture.loadFromFile("assets/menus/Back_button.png");
back_button.Pressed_texture.loadFromFile("assets/menus/Back_button_pressed.png");

SFX_click_soundbuffer.loadFromFile("assets/sounds/SFX_click.ogg");

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
Back_button_Red.loadFromFile("assets/menus/Back_button.png");
Back_button_Yellow.loadFromFile("assets/menus/Back_button_pressed.png");
volume_increase.loadFromFile("assets/menus/options_menu/Volume_increase.png");
volume_decrease.loadFromFile("assets/menus/options_menu/Volume_decrease.png");


// play menu


play_menu_background_texture.loadFromFile("assets/menus/play_menu/Play_menu_background.png");


classic_menu.Default_texture.loadFromFile("assets/menus/play_menu/Classic_mode.png");
classic_menu.Hovered_texture.loadFromFile("assets/menus/play_menu/Classic_mode_hovered.png");

duels_menu.Default_texture.loadFromFile("assets/menus/play_menu/Duels.png");
duels_menu.Hovered_texture.loadFromFile("assets/menus/play_menu/Duels_hovered.png");


// classic menu

classic_menu_background_texture.loadFromFile("assets/menus/classic_menu/background_city_night.png");
Border_hover_effect.loadFromFile("assets/menus/classic_menu/Border_hover_effect.png");


level[0].view.Level_evaluation = 0;
level[0].view.Level_none_stared.loadFromFile("assets/menus/classic_menu/Lvl_1/Level_1_no_stars.png");
level[0].view.Level_one_stared.loadFromFile("assets/menus/classic_menu/Lvl_1/Lvl_1_one_star.png");
level[0].view.Level_two_stared.loadFromFile("assets/menus/classic_menu/Lvl_1/Lvl_1_two_stars.png");
level[0].view.Leve_three_stared.loadFromFile("assets/menus/classic_menu/Lvl_1/Lvl_1_three_stars.png");

level[1].view.Level_closed_texture.loadFromFile("assets/menus/classic_menu/Lvl_2/Lvl_2_closed.png");
level[1].view.Level_none_stared.loadFromFile("assets/menus/classic_menu/Lvl_2/Lvl_2_no_stars.png");
level[1].view.Level_one_stared.loadFromFile("assets/menus/classic_menu/Lvl_2/Lvl_2_one_star.png");
level[1].view.Level_two_stared.loadFromFile("assets/menus/classic_menu/Lvl_2/Lvl_2_two_stars.png");
level[1].view.Leve_three_stared.loadFromFile("assets/menus/classic_menu/Lvl_2/Lvl_3_three_stars.png");

level[2].view.Level_closed_texture.loadFromFile("assets/menus/classic_menu/Lvl_3/Lvl_3_closed.png");
level[2].view.Level_none_stared.loadFromFile("assets/menus/classic_menu/Lvl_3/Lvl_3_no_stars.png");
level[2].view.Level_one_stared.loadFromFile("assets/menus/classic_menu/Lvl_3/Lvl_3_one_star.png");
level[2].view.Level_two_stared.loadFromFile("assets/menus/classic_menu/Lvl_3/Lvl_3_two_stars.png");
level[2].view.Leve_three_stared.loadFromFile("assets/menus/classic_menu/Lvl_3/Lvl_3_three_stars.png");

level[3].view.Level_closed_texture.loadFromFile("assets/menus/classic_menu/Lvl_4/Lvl_4_closed.png");
level[3].view.Level_none_stared.loadFromFile("assets/menus/classic_menu/Lvl_4/Lvl_4_no_stars.png");
level[3].view.Level_one_stared.loadFromFile("assets/menus/classic_menu/Lvl_4/Lvl_4_one_star.png");
level[3].view.Level_two_stared.loadFromFile("assets/menus/classic_menu/Lvl_4/Lvl_4_two_stars.png");
level[3].view.Leve_three_stared.loadFromFile("assets/menus/classic_menu/Lvl_4/Lvl_4_three_stars.png");

level[4].view.Level_closed_texture.loadFromFile("assets/menus/classic_menu/Lvl_5/Lvl_5_closed.png");
level[4].view.Level_none_stared.loadFromFile("assets/menus/classic_menu/Lvl_5/Lvl_5_no_stars.png");
level[4].view.Level_one_stared.loadFromFile("assets/menus/classic_menu/Lvl_5/Lvl_5_one_star.png");
level[4].view.Level_two_stared.loadFromFile("assets/menus/classic_menu/Lvl_5/Lvl_5_two_stars.png");
level[4].view.Leve_three_stared.loadFromFile("assets/menus/classic_menu/Lvl_5/Lvl_5_three_stars.png");

level[5].view.Level_closed_texture.loadFromFile("assets/menus/classic_menu/Lvl_6/Lvl_6_closed.png");
level[5].view.Level_none_stared.loadFromFile("assets/menus/classic_menu/Lvl_6/Lvl_6_none_stared.png");
level[5].view.Level_one_stared.loadFromFile("assets/menus/classic_menu/Lvl_6/Lvl_6_one_stared.png");
level[5].view.Level_two_stared.loadFromFile("assets/menus/classic_menu/Lvl_6/Lvl_6_two_stared.png");
level[5].view.Leve_three_stared.loadFromFile("assets/menus/classic_menu/Lvl_6/Lvl_6_three_stared.png");

level[6].view.Level_closed_texture.loadFromFile("assets/menus/classic_menu/Lvl_7/Lvl_7_closed.png");
level[6].view.Level_none_stared.loadFromFile("assets/menus/classic_menu/Lvl_7/Lvl_7_none_stared.png");
level[6].view.Level_one_stared.loadFromFile("assets/menus/classic_menu/Lvl_7/Lvl_7_one_stared.png");
level[6].view.Level_two_stared.loadFromFile("assets/menus/classic_menu/Lvl_7/Lvl_7_two_stared.png");
level[6].view.Leve_three_stared.loadFromFile("assets/menus/classic_menu/Lvl_7/Lvl_7_three_stared.png");

level[7].view.Level_closed_texture.loadFromFile("assets/menus/classic_menu/Lvl_8/Lvl_8_closed.png");
level[7].view.Level_none_stared.loadFromFile("assets/menus/classic_menu/Lvl_8/Lvl_8_none_stared.png");
level[7].view.Level_one_stared.loadFromFile("assets/menus/classic_menu/Lvl_8/Lvl_8_one_stared.png");
level[7].view.Level_two_stared.loadFromFile("assets/menus/classic_menu/Lvl_8/Lvl_8_two_stared.png");
level[7].view.Leve_three_stared.loadFromFile("assets/menus/classic_menu/Lvl_8/Lvl_8_three_stared.png");

level[8].view.Level_closed_texture.loadFromFile("assets/menus/classic_menu/Lvl_9/Lvl_9_closed.png");
level[8].view.Level_none_stared.loadFromFile("assets/menus/classic_menu/Lvl_9/Lvl_9_none_stared.png");
level[8].view.Level_one_stared.loadFromFile("assets/menus/classic_menu/Lvl_9/Lvl_9_one_stared.png");
level[8].view.Level_two_stared.loadFromFile("assets/menus/classic_menu/Lvl_9/Lvl_9_two_stared.png");
level[8].view.Leve_three_stared.loadFromFile("assets/menus/classic_menu/Lvl_9/Lvl_9_three_stared.png");

level[9].view.Level_closed_texture.loadFromFile("assets/menus/classic_menu/Lvl_10/Lvl_10_closed.png");
level[9].view.Level_none_stared.loadFromFile("assets/menus/classic_menu/Lvl_10/Lvl_10_none_stared.png");
level[9].view.Level_one_stared.loadFromFile("assets/menus/classic_menu/Lvl_10/Lvl_10_one_stared.png");
level[9].view.Level_two_stared.loadFromFile("assets/menus/classic_menu/Lvl_10/Lvl_10_two_stared.png");
level[9].view.Leve_three_stared.loadFromFile("assets/menus/classic_menu/Lvl_10/Lvl_10_three_stared.png");

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


void FONT(Font& font_name, string font_file_name)
{
    font_name.loadFromFile(font_file_name);
}


void volume_manage(sf::RenderWindow& window, sf::Text& text, sf::Sprite volume_up, sf::Sprite volume_down, int& volume_num, Font& font_name, string font_file_name)
{
    font_name.loadFromFile(font_file_name);
    text.setFont(font_name);
    text.setString(to_string(volume_num));          //to display the volume presentage
    text.setCharacterSize(50);
    text.setOrigin(text.getLocalBounds().width / 2, text.getLocalBounds().height / 2);
    text.setScale(Vector2f(1.2, 1.2));
    Vector2i mousePosition = Mouse::getPosition(window);

    if (volume_up.getGlobalBounds().contains(sf::Vector2f(mousePosition)) && volume_num < 100)
    {

        volume_num += 10;
        text.setString(to_string(volume_num));
    }

    else if (volume_down.getGlobalBounds().contains(sf::Vector2f(mousePosition)) && volume_num > 0)
    {

        volume_num -= 10;
        text.setString(to_string(volume_num));
    }
}

void Level_Evaluation(Level level[])
{
    for (int i = 0; i < 20; i++)
    {
        if (level[i].view.Level_evaluation == -1)
        {
            level[i].view.Level_selection.setTexture(level[i].view.Level_closed_texture);
        }

        else if (level[i].view.Level_evaluation == 0)
        {
            level[i].view.Level_selection.setTexture(level[i].view.Level_none_stared);
        }

        else if (level[i].view.Level_evaluation == 1)
        {
            level[i].view.Level_selection.setTexture(level[i].view.Level_one_stared);
        }

        else if (level[i].view.Level_evaluation == 2)
        {
            level[i].view.Level_selection.setTexture(level[i].view.Level_two_stared);
        }

        else if (level[i].view.Level_evaluation == 3)
        {
            level[i].view.Level_selection.setTexture(level[i].view.Leve_three_stared);
        }
    }
}


void hoverEffect(sf::Sprite& button, sf::Texture& hovered, sf::RenderWindow& window)
{
    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

    if (button.getGlobalBounds().contains(mousePosition.x, mousePosition.y))
    {
        button.setTexture(hovered);
    }
}

void hoverEffect(sf::Sprite& button, sf::RenderWindow& window)
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

void hoverEffect(Level level[], sf::RenderWindow& window)
{
    sf::Sprite Border;
    Border.setTexture(Border_hover_effect);
    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
    for (int i = 0; i < 20; i++)
    {
        if (level[i].view.Level_evaluation != -1 && level[i].view.Level_selection.getGlobalBounds().contains(mousePosition.x, mousePosition.y))
        {
            sf::Vector2f Level_position = level[i].view.Level_selection.getPosition();
            Border.setPosition(Level_position.x, Level_position.y);
            window.draw(Border);
        }
    }
}

void hoverEffect(sf::Sprite& option, sf::Texture& original,sf::Texture& hovered, sf::Text& attached_text, sf::RenderWindow& window)
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
