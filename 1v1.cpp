#include<iostream>
#include<SFML/Graphics.hpp>
#include "Sprites.h"
#include "Physics.h"
#include "Levels.h"
#include "Menus.h"
#include "Events.h"
#include "win-lose-logic.h"
#include "Sounds.h"
#include <ctime>



using namespace std;
using namespace sf;

bool collided = true;

Character playerOne;
Character playerTwo;


RectangleShape back(Vector2f(471.0f, 103.0f));
RectangleShape victory_menu(Vector2f(508.0f, 674.0f));
RectangleShape victory_menu_2(Vector2f(508.0f, 674.0f));
RectangleShape restart(Vector2f(100.0f, 100.0f)); 
RectangleShape hundred_health(Vector2f(282.0f, 73.0f));
RectangleShape seventy_health(Vector2f(282.0f, 73.0f));
RectangleShape forty_health(Vector2f(282.0f, 73.0f));
RectangleShape ten_health(Vector2f(282.0f, 73.0f));
RectangleShape zero_health(Vector2f(282.0f, 73.0f));
RectangleShape hundred_health_2(Vector2f(282.0f, 73.0f));
RectangleShape seventy_health_2(Vector2f(282.0f, 73.0f));
RectangleShape forty_health_2(Vector2f(282.0f, 73.0f));
RectangleShape ten_health_2(Vector2f(282.0f, 73.0f));
RectangleShape zero_health_2(Vector2f(282.0f, 73.0f));

Texture victory_texture;
Texture victory_texture_2;
Texture restart_texture;
Texture back_texture;
Texture hundred_health_texture;
Texture seventy_health_texture;
Texture forty_health_texture;
Texture ten_health_texture;
Texture zero_health_texture;
Texture hundred_health_texture_2;
Texture seventy_health_texture_2;
Texture forty_health_texture_2;
Texture ten_health_texture_2;
Texture zero_health_texture_2;

void duelsPauseMenu()
{
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

    duelsPauseMenu_eventLoop();

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

void duelsOptionMenu()
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

    duelsOptionMenu_eventLoop();

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

void healthBar(Character playerOneHealth,Character playerTwoHealth)
{
    if (playerOneHealth.health == 100)
    {
        hundred_health.setPosition(0.0f, 1007.0f);
        window.draw(hundred_health);
    }
    if (playerOneHealth.health == 70)
    {
        seventy_health.setPosition(0.0f, 1007.0f);
        window.draw(seventy_health);
    }
    if (playerOneHealth.health == 40)
    {
        forty_health.setPosition(0.0f, 1007.0f);
        window.draw(forty_health);
    }
    if (playerOneHealth.health == 10)
    {
        ten_health.setPosition(0.0f, 1007.0f);
        window.draw(ten_health);
    }
    if (playerOneHealth.health == 0)
    {
        zero_health.setPosition(0.0f, 1007.0f);
        window.draw(zero_health);
    }
    if (playerTwoHealth.health == 100)
    {
        hundred_health_2.setPosition(1638.0f, 1007.0f);
        window.draw(hundred_health_2);
    }
    if (playerTwoHealth.health == 70)
    {
        seventy_health_2.setPosition(1638.0f, 1007.0f);
        window.draw(seventy_health_2);
    }
    if (playerTwoHealth.health == 40)
    {
        forty_health_2.setPosition(1638.0f, 1007.0f);
        window.draw(forty_health_2);
    }
    if (playerTwoHealth.health == 10)
    {
        ten_health_2.setPosition(1638.0f, 1007.0f);
        window.draw(ten_health_2);
    }
    if (playerTwoHealth.health == 0)
    {
        zero_health_2.setPosition(1638.0f, 1007.0f);
        window.draw(zero_health_2);
    }
}

void resetDuels()
{

    playerOne.health = 100;
    playerTwo.health = 100;

    playerOne.dead = false;
    playerTwo.dead = false;
    playerOne.alive = true;
    playerTwo.alive = true;


    window.draw(lev[0].bg);
    window.draw(lev[0].ground);
    
    character_set_scale(playerOne, 0.4);
    character_set_position(playerOne, Vector2f(lev[16].block[1].getPosition().x + 50, lev[16].block[1].getPosition().y - 200));

    character_set_scale(playerTwo, 0.4);
    character_set_position(playerTwo, Vector2f(lev[16].block[0].getPosition().x + 20, lev[16].block[0].getPosition().y - 200));
    
}

void collision (Bullet& b, Character& shotPlayer)
{
    if (b.b.getGlobalBounds().intersects(shotPlayer.body.getGlobalBounds())) {
        shotPlayer.health -= 30;
        collided = false;
        if (shotPlayer.health <= 0) 
        {
            shotPlayer.health = 0;
            shotPlayer.dead = true;
            shotPlayer.alive = false;
            character_dead(shotPlayer);
            srand(std::time(nullptr));
            screams[rand() % 10].play();
        }
        //Death Animation                                                   /* helmy */
    }
    else if (b.b.getGlobalBounds().intersects(shotPlayer.head.getGlobalBounds())) {
        shotPlayer.health -= 60;
        collided = false;
        if (shotPlayer.health <= 0)
        {
            shotPlayer.health = 0;
            shotPlayer.dead = true;
            shotPlayer.alive = false;
            character_dead(shotPlayer);
            srand(std::time(nullptr));
            screams[rand() % 10].play();
        }
        //Death Animation                                                   /* helmy */
    }
    else if (b.b.getGlobalBounds().intersects(shotPlayer.left_arm1.getGlobalBounds())) {
        shotPlayer.health -= 30;
        collided = false;
        if (shotPlayer.health <= 0)
        {
            shotPlayer.health = 0;
            shotPlayer.dead = true;
            shotPlayer.alive = false;
            character_dead(shotPlayer);
            srand(std::time(nullptr));
            screams[rand() % 10].play();
        }
        //Death Animation                                                   /* helmy */
    }
    else if (b.b.getGlobalBounds().intersects(shotPlayer.left_arm2.getGlobalBounds())) {
        shotPlayer.health -= 30;
        collided = false;
        if (shotPlayer.health <= 0)
        {
            shotPlayer.health = 0;
            shotPlayer.dead = true;
            shotPlayer.alive = false;
            character_dead(shotPlayer);
            srand(std::time(nullptr));
            screams[rand() % 10].play();
        }
        //Death Animation                                                   /* helmy */
    }
    else if (b.b.getGlobalBounds().intersects(shotPlayer.right_arm1.getGlobalBounds())) {
        shotPlayer.health -= 30;
        collided = false;
        if (shotPlayer.health <= 0)
        {
            shotPlayer.health = 0;
            shotPlayer.dead = true;
            shotPlayer.alive = false;
            character_dead(shotPlayer);
            srand(std::time(nullptr));
            screams[rand() % 10].play();
        }
        //Death Animation                                                   /* helmy */
    }
    else if (b.b.getGlobalBounds().intersects(shotPlayer.right_arm2.getGlobalBounds())) {
        shotPlayer.health -= 30;
        collided = false;
        if (shotPlayer.health <= 0)
        {
            shotPlayer.health = 0;
            shotPlayer.dead = true;
            shotPlayer.alive = false;
            character_dead(shotPlayer);
            srand(std::time(nullptr));
            screams[rand() % 10].play();
        }
        //Death Animation                                                   /* helmy */
    }
    else if (b.b.getGlobalBounds().intersects(shotPlayer.left_leg1.getGlobalBounds())) {
        shotPlayer.health -= 30;
        collided = false;
        if (shotPlayer.health <= 0)
        {
            shotPlayer.health = 0;
            shotPlayer.dead = true;
            shotPlayer.alive = false;
            character_dead(shotPlayer);
            srand(std::time(nullptr));
            screams[rand() % 10].play();
        }
        //Death Animation                                                   /* helmy */
    }
    else if (b.b.getGlobalBounds().intersects(shotPlayer.left_leg2.getGlobalBounds())) {
        shotPlayer.health -= 30;
        collided = false;
        if (shotPlayer.health <= 0)
        {
            shotPlayer.health = 0;
            shotPlayer.dead = true;
            shotPlayer.alive = false;
            character_dead(shotPlayer);
            srand(std::time(nullptr));
            screams[rand() % 10].play();
        }
        //Death Animation                                                   /* helmy */
    }
    else if (b.b.getGlobalBounds().intersects(shotPlayer.right_leg1.getGlobalBounds())) {
        shotPlayer.health -= 30;
        collided = false;
        if (shotPlayer.health <= 0)
        {
            shotPlayer.health = 0;
            shotPlayer.dead = true;
            shotPlayer.alive = false;
            character_dead(shotPlayer);
            srand(std::time(nullptr));
            screams[rand() % 10].play();
        }
        //Death Animation                                                   /* helmy */
    }
    else  if (b.b.getGlobalBounds().intersects(shotPlayer.right_leg2.getGlobalBounds())) {
        shotPlayer.health -= 30;
        collided = false;
        if (shotPlayer.health <= 0)
        {
            shotPlayer.health = 0;
            shotPlayer.dead = true;
           shotPlayer.alive = false;
           character_dead(shotPlayer);
           srand(std::time(nullptr));
           screams[rand() % 10].play();
        }
        
        //Death Animation                                                   /* helmy */
    }
    
}

void duels()
{
    playerOne.has_gun = true;
    playerTwo.has_gun = true;
    victory_menu.setOrigin(254.0f, 337.0f);
    victory_menu.setPosition(960.0f, 540.0f);

    victory_menu_2.setOrigin(254.0f, 337.0f);
    victory_menu_2.setPosition(960.0f, 540.0f);

    restart.setOrigin(50.0f, 50.0f);
    restart.setPosition(960.0f, 650.0f);

    back.setOrigin(235.5f, 51.f);
    back.setPosition(960.0f, 770.0f);

    character_set_scale(playerOne, 0.4);

    character_set_scale(playerTwo, 0.4);



   

    if (playerTwo.dead)
    {
        window.draw(victory_menu);
        window.draw(restart);
        window.draw(back);
    }
    if (playerOne.dead)
    {
        window.draw(victory_menu_2);
        window.draw(restart);
        window.draw(back);
    }
    if (playerOne.health <= 0)
    {
        playerOne.health = 0;
        playerOne.dead = true;
        playerOne.alive = false;
    }
    if (playerTwo.health <= 0)
    {
        playerTwo.health = 0;
        playerTwo.dead = true;
        playerOne.alive = false;
    }
    
}