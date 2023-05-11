#include <SFML/Graphics.hpp>
#include "Sprites.h"
#include "Levels.h"
#include "Physics.h"
#include "Menus.h"
#include <cmath>

using namespace sf;

int dead_enemies = 0;
int level_index;
float bulletSpeed = 25.f;
int blockDirection[4] = { 0,1,2,3 };  // direction of the block movement (0 = right, 1 = down, 2 = left, 3 = up)
float blockSpeed = 3.0f;
float angle = 0.0f;   //used in level (16)
float radius = 290.0f;
float speed = 0.02f;

void constructlev1(RenderWindow& window)
{
    // background
    lev[0].BG.loadFromFile("assets/Backgrounds/background_city.png");
    lev[0].bg.setTexture(lev[0].BG);
    lev[0].bg.setScale(4, 1.2);

    // Rectangular ground
    lev[0].GROUND[0].loadFromFile("assets/Textures/ground.png");
    lev[0].ground.setTexture(&lev[0].GROUND[0]);
    lev[0].ground.setSize(Vector2f(window.getSize().x, window.getSize().y / 4));
    lev[0].ground.setOrigin(lev[0].ground.getLocalBounds().width / 2, lev[0].ground.getLocalBounds().height / 2);
    lev[0].ground.setPosition(window.getSize().x / 2.0, window.getSize().y);

    // Charachters

    //killer
    lev[0].killer.has_gun = true;
    character_init(lev[0].killer, "assets/Characters/Killer/killer_head.png", "assets/Characters/blue_suit_body.png", false);
    character_set_scale(lev[0].killer, 0.4);
    character_set_position(lev[0].killer, Vector2f(200, lev[0].ground.getPosition().y - (lev[0].ground.getLocalBounds().height) * 1.41));

    //enemy
    character_init(lev[0].target[0], "assets/Characters/gangster_head.png", "assets/Characters/black_suit_body.png", true);
    character_set_scale(lev[0].target[0], 0.4);
    character_set_position(lev[0].target[0], Vector2f(1720, lev[0].ground.getPosition().y - (lev[0].ground.getLocalBounds().height) * 1.4));

    // bullets
    lev[0].Bullets[0].setTexture(Bullet_texture);
    lev[0].Bullets[1].setTexture(Bullet_texture);
    lev[0].Bullets[2].setTexture(Bullet_texture);
    lev[0].Bullets[3].setTexture(Bullet_texture);
    lev[0].Bullets[4].setTexture(Bullet_texture);


    lev[0].Bullets[0].setPosition(Vector2f(850, 55));
    lev[0].Bullets[0].setOrigin(lev[0].Bullets[0].getLocalBounds().width / 2, lev[0].Bullets[0].getLocalBounds().height / 2);
    lev[0].Bullets[0].setScale(.25, .25);
    lev[0].Bullets[0].setColor(Color::Black);

    lev[0].Bullets[1].setPosition(Vector2f(900, 55));
    lev[0].Bullets[1].setOrigin(lev[0].Bullets[1].getLocalBounds().width / 2, lev[0].Bullets[1].getLocalBounds().height / 2);
    lev[0].Bullets[1].setScale(.25, .25);
    lev[0].Bullets[1].setColor(Color::Black);

    lev[0].Bullets[2].setPosition(Vector2f(950, 55));
    lev[0].Bullets[2].setOrigin(lev[0].Bullets[2].getLocalBounds().width / 2, lev[0].Bullets[2].getLocalBounds().height / 2);
    lev[0].Bullets[2].setScale(.25, .25);
    lev[0].Bullets[2].setColor(Color::Black);

    lev[0].Bullets[3].setPosition(Vector2f(1000, 55));
    lev[0].Bullets[3].setOrigin(lev[0].Bullets[3].getLocalBounds().width / 2, lev[0].Bullets[3].getLocalBounds().height / 2);
    lev[0].Bullets[3].setScale(.25, .25);
    lev[0].Bullets[3].setColor(Color(240, 150, 25));


    lev[0].Return_num = 4;
    lev[0].num_of_bullets = 4;
}

void constructlev2(RenderWindow& window)
{
    // background
    lev[1].BG.loadFromFile("assets/Backgrounds/background_city.png");
    lev[1].bg.setTexture(lev[1].BG);
    lev[1].bg.setScale(4, 1.2);

    // Blocks
    for (int i = 0; i < 9; i++)
    {
        lev[1].BLOCK[i].loadFromFile("assets/Textures/block.png");
        lev[1].block[i].setTexture(&lev[1].BLOCK[i]);
        if (i == 0)
        {
            lev[1].block[i].setSize(Vector2f(130, 130));
        }
        else
        {
            lev[1].block[i].setSize(Vector2f(100, 100));
        }
        lev[1].block[i].setOrigin(lev[1].block[i].getLocalBounds().width / 2, lev[1].block[i].getLocalBounds().height / 2);
    }

    // set positions for BLlocks
    lev[1].block[0].setPosition(window.getSize().x / static_cast<float>(2), window.getSize().y / static_cast<float>(2) + 150);
    lev[1].block[1].setPosition(lev[1].block[0].getPosition().x + 400, lev[1].block[0].getPosition().y + 250);
    lev[1].block[2].setPosition(lev[1].block[1].getPosition().x + 150, lev[1].block[1].getPosition().y + 100);
    lev[1].block[3].setPosition(lev[1].block[0].getPosition().x - 400, lev[1].block[0].getPosition().y + 250);
    lev[1].block[4].setPosition(lev[1].block[3].getPosition().x - 150, lev[1].block[3].getPosition().y + 100);
    lev[1].block[5].setPosition(lev[1].block[0].getPosition().x - 400, lev[1].block[0].getPosition().y - 250);
    lev[1].block[6].setPosition(lev[1].block[5].getPosition().x - 150, lev[1].block[5].getPosition().y - 100);
    lev[1].block[7].setPosition(lev[1].block[0].getPosition().x + 400, lev[1].block[0].getPosition().y - 250);
    lev[1].block[8].setPosition(lev[1].block[7].getPosition().x + 150, lev[1].block[7].getPosition().y - 100);

    //Characters

    //killer
    character_init(lev[1].killer, "assets/Characters/Killer/killer_head.png", "assets/Characters/blue_suit_body.png", false);
    character_set_scale(lev[1].killer, 0.4);
    character_set_position(lev[1].killer, Vector2f(lev[1].block[0].getPosition().x - 50, lev[1].block[0].getPosition().y - 300));

    //Targets
    for (int i = 0; i < 8; i++)
    {
        character_init(lev[1].target[i], "assets/Characters/gangster_head.png", "assets/Characters/black_suit_body.png", false);
        character_set_scale(lev[1].target[i], 0.4);
        character_set_position(lev[1].target[i], Vector2f(lev[1].block[i + 1].getPosition().x - 50, lev[1].block[i + 1].getPosition().y - 295));
    }

    // bullets
    lev[1].Bullets[0].setTexture(Bullet_texture);
    lev[1].Bullets[1].setTexture(Bullet_texture);
    lev[1].Bullets[2].setTexture(Bullet_texture);
    lev[1].Bullets[3].setTexture(Bullet_texture);
    lev[1].Bullets[4].setTexture(Bullet_texture);
    lev[1].Bullets[5].setTexture(Bullet_texture);
    lev[1].Bullets[6].setTexture(Bullet_texture);


    lev[1].Bullets[0].setPosition(Vector2f(850, 55));
    lev[1].Bullets[0].setOrigin(lev[1].Bullets[0].getLocalBounds().width / 2, lev[1].Bullets[0].getLocalBounds().height / 2);
    lev[1].Bullets[0].setScale(.25, .25);
    lev[1].Bullets[0].setColor(Color::Black);

    lev[1].Bullets[1].setPosition(Vector2f(900, 55));
    lev[1].Bullets[1].setOrigin(lev[1].Bullets[1].getLocalBounds().width / 2, lev[1].Bullets[1].getLocalBounds().height / 2);
    lev[1].Bullets[1].setScale(.25, .25);
    lev[1].Bullets[1].setColor(Color::Black);

    lev[1].Bullets[2].setPosition(Vector2f(950, 55));
    lev[1].Bullets[2].setOrigin(lev[1].Bullets[2].getLocalBounds().width / 2, lev[1].Bullets[2].getLocalBounds().height / 2);
    lev[1].Bullets[2].setScale(.25, .25);
    lev[1].Bullets[2].setColor(Color::Black);

    lev[1].Bullets[3].setPosition(Vector2f(1000, 55));
    lev[1].Bullets[3].setOrigin(lev[1].Bullets[3].getLocalBounds().width / 2, lev[1].Bullets[3].getLocalBounds().height / 2);
    lev[1].Bullets[3].setScale(.25, .25);
    lev[1].Bullets[3].setColor(Color(240, 150, 25));

    lev[1].Bullets[4].setPosition(Vector2f(1050, 55));
    lev[1].Bullets[4].setOrigin(lev[1].Bullets[4].getLocalBounds().width / 2, lev[1].Bullets[4].getLocalBounds().height / 2);
    lev[1].Bullets[4].setScale(.25, .25);
    lev[1].Bullets[4].setColor(Color(240, 150, 25));

    lev[1].Bullets[5].setPosition(Vector2f(1100, 55));
    lev[1].Bullets[5].setOrigin(lev[1].Bullets[5].getLocalBounds().width / 2, lev[1].Bullets[5].getLocalBounds().height / 2);
    lev[1].Bullets[5].setScale(.25, .25);
    lev[1].Bullets[5].setColor(Color(240, 150, 25));

    lev[1].Bullets[6].setPosition(Vector2f(1150, 55));
    lev[1].Bullets[6].setOrigin(lev[1].Bullets[6].getLocalBounds().width / 2, lev[1].Bullets[6].getLocalBounds().height / 2);
    lev[1].Bullets[6].setScale(.25, .25);
    lev[1].Bullets[6].setColor(Color(240, 150, 25));

    lev[1].Return_num = 7;
    lev[1].num_of_bullets = 7;
}

void constructlev3(RenderWindow& window)
{
    //backround
    lev[2].BG.loadFromFile("assets/Backgrounds/background_city.png");
    lev[2].bg.setTexture(lev[2].BG);
    lev[2].bg.setScale(4, 1.2);

    //ground
    lev[2].GROUND[0].loadFromFile("assets/Textures/ground.png");
    lev[2].ground.setTexture(&lev[2].GROUND[0]);
    lev[2].ground.setSize(Vector2f(window.getSize().x, window.getSize().y / 4));
    lev[2].ground.setOrigin(lev[2].ground.getLocalBounds().width / 2, lev[2].ground.getLocalBounds().height / 2);
    lev[2].ground.setPosition(window.getSize().x / 2.0, window.getSize().y);

    //shape1
    lev[2].SHAPES[0].loadFromFile("assets/Textures/rectangle1.png");
    lev[2].shape[0].setTexture(&lev[2].SHAPES[0]);
    lev[2].shape[0].setSize(Vector2f(450, 80));
    lev[2].shape[0].setOrigin(lev[2].shape[0].getLocalBounds().width / 2, lev[2].shape[0].getLocalBounds().height / 2);
    lev[2].shape[0].setPosition(window.getSize().x - lev[2].shape[1].getSize().x / 2, 350);

    //shape2
    lev[2].SHAPES[1].loadFromFile("assets/Textures/rectangle2.png");
    lev[2].shape[1].setTexture(&lev[2].SHAPES[1]);
    lev[2].shape[1].setSize(Vector2f(200, 400));
    //lev[2].shape2.setOrigin(lev[2].shape2.getLocalBounds().width / 2, lev[2].shape2.getLocalBounds().height / 2);
    lev[2].shape[1].setPosition(0, 400);

    //killer
    character_init(lev[2].killer, "assets/Characters/Killer/killer_head.png", "assets/Characters/blue_suit_body.png", true);
    character_set_scale(lev[2].killer, 0.34);
    character_set_position(lev[2].killer, Vector2f(window.getSize().x - 200, lev[2].ground.getPosition().y - (lev[2].ground.getLocalBounds().height) * 1.3));

    //enemy
    character_init(lev[2].target[0], "assets/Characters/gangster_head.png", "assets/Characters/black_suit_body.png", true);
    character_set_scale(lev[2].target[0], 0.34);
    character_set_position(lev[2].target[0], Vector2f(lev[2].shape[0].getPosition().x - (lev[2].shape[0].getSize().x / 2), lev[2].shape[0].getPosition().y - 235));

    // bullets
    lev[2].Bullets[0].setTexture(Bullet_texture);
    lev[2].Bullets[1].setTexture(Bullet_texture);
    lev[2].Bullets[2].setTexture(Bullet_texture);
    lev[2].Bullets[3].setTexture(Bullet_texture);
    lev[2].Bullets[4].setTexture(Bullet_texture);


    lev[2].Bullets[0].setPosition(Vector2f(850, 55));
    lev[2].Bullets[0].setOrigin(lev[2].Bullets[0].getLocalBounds().width / 2, lev[2].Bullets[0].getLocalBounds().height / 2);
    lev[2].Bullets[0].setScale(.25, .25);
    lev[2].Bullets[0].setColor(Color::Black);

    lev[2].Bullets[1].setPosition(Vector2f(900, 55));
    lev[2].Bullets[1].setOrigin(lev[2].Bullets[1].getLocalBounds().width / 2, lev[2].Bullets[1].getLocalBounds().height / 2);
    lev[2].Bullets[1].setScale(.25, .25);
    lev[2].Bullets[1].setColor(Color::Black);

    lev[2].Bullets[2].setPosition(Vector2f(950, 55));
    lev[2].Bullets[2].setOrigin(lev[2].Bullets[2].getLocalBounds().width / 2, lev[2].Bullets[2].getLocalBounds().height / 2);
    lev[2].Bullets[2].setScale(.25, .25);
    lev[2].Bullets[2].setColor(Color::Black);

    lev[2].Bullets[3].setPosition(Vector2f(1000, 55));
    lev[2].Bullets[3].setOrigin(lev[2].Bullets[3].getLocalBounds().width / 2, lev[2].Bullets[3].getLocalBounds().height / 2);
    lev[2].Bullets[3].setScale(.25, .25);
    lev[2].Bullets[3].setColor(Color(240, 150, 25));


    lev[2].Return_num = 4;
    lev[2].num_of_bullets = 4;
}

void constructlev4(RenderWindow& window)
{
    //background
    lev[3].BG.loadFromFile("assets/Backgrounds/background_city.png");
    lev[3].bg.setTexture(lev[3].BG);
    lev[3].bg.setScale(4, 1.2);

    //rectangle area
    lev[3].SHAPES[0].loadFromFile("assets/Textures/box.png");
    lev[3].shape[0].setTexture(&lev[3].SHAPES[0]);
    lev[3].shape[0].setSize(Vector2f(1000, 1200));
    lev[3].shape[0].setOrigin(lev[3].shape[0].getSize().x / 2, lev[3].shape[0].getSize().y / 2);
    lev[3].shape[0].setPosition(window.getSize().x / 2, window.getSize().y / 2 + 75);
    lev[3].shape[1].setSize(Vector2f(140, 1064));
    lev[3].shape[1].setPosition(Vector2f(460, 15));
    lev[3].shape[2].setSize(Vector2f(720, 180));
    lev[3].shape[2].setPosition(Vector2f(600, 15));
    lev[3].shape[3].setSize(Vector2f(140, 1064));
    lev[3].shape[3].setPosition(Vector2f(1320, 15));
    lev[3].shape[4].setSize(Vector2f(720, 180));
    lev[3].shape[4].setPosition(Vector2f(600, 950));
    lev[3].shape[5].setSize(Vector2f(460, 332));
    lev[3].shape[5].setPosition(Vector2f(600, 408));

    //killer
    character_init(lev[3].killer, "assets/Characters/Killer/killer_head.png", "assets/Characters/blue_suit_body.png", false);
    character_set_scale(lev[3].killer, 0.3);
    character_set_position(lev[3].killer, Vector2f(lev[3].shape[0].getPosition().x - 300, lev[3].shape[0].getPosition().y + 160));

    //targets
    character_init(lev[3].target[0], "assets/Characters/gangster_head.png", "assets/Characters/black_suit_body.png", true);
    character_set_scale(lev[3].target[0], 0.3);
    character_set_position(lev[3].target[0], Vector2f(lev[3].shape[0].getPosition().x + 250, lev[3].shape[0].getPosition().y + 160));

    character_init(lev[3].target[1], "assets/Characters/gangster_head.png", "assets/Characters/black_suit_body.png", false);
    character_set_scale(lev[3].target[1], 0.3);
    character_set_position(lev[3].target[1], Vector2f(lev[3].shape[0].getPosition().x - 300, lev[3].shape[0].getPosition().y - 390));

    character_init(lev[3].target[2], "assets/Characters/gangster_head.png", "assets/Characters/black_suit_body.png", false);
    character_set_scale(lev[3].target[2], 0.3);
    character_set_position(lev[3].target[2], Vector2f(lev[3].shape[0].getPosition().x - 100, lev[3].shape[0].getPosition().y - 390));

    // bullets
    lev[3].Bullets[0].setTexture(Bullet_texture);
    lev[3].Bullets[1].setTexture(Bullet_texture);
    lev[3].Bullets[2].setTexture(Bullet_texture);
    lev[3].Bullets[3].setTexture(Bullet_texture);
    lev[3].Bullets[4].setTexture(Bullet_texture);


    lev[3].Bullets[0].setPosition(Vector2f(850, 55));
    lev[3].Bullets[0].setOrigin(lev[3].Bullets[0].getLocalBounds().width / 2, lev[3].Bullets[0].getLocalBounds().height / 2);
    lev[3].Bullets[0].setScale(.25, .25);
    lev[3].Bullets[0].setColor(Color::Black);

    lev[3].Bullets[1].setPosition(Vector2f(900, 55));
    lev[3].Bullets[1].setOrigin(lev[3].Bullets[1].getLocalBounds().width / 2, lev[3].Bullets[1].getLocalBounds().height / 2);
    lev[3].Bullets[1].setScale(.25, .25);
    lev[3].Bullets[1].setColor(Color::Black);

    lev[3].Bullets[2].setPosition(Vector2f(950, 55));
    lev[3].Bullets[2].setOrigin(lev[3].Bullets[2].getLocalBounds().width / 2, lev[3].Bullets[2].getLocalBounds().height / 2);
    lev[3].Bullets[2].setScale(.25, .25);
    lev[3].Bullets[2].setColor(Color::Black);

    lev[3].Bullets[3].setPosition(Vector2f(1000, 55));
    lev[3].Bullets[3].setOrigin(lev[3].Bullets[3].getLocalBounds().width / 2, lev[3].Bullets[3].getLocalBounds().height / 2);
    lev[3].Bullets[3].setScale(.25, .25);
    lev[3].Bullets[3].setColor(Color(240, 150, 25));


    lev[3].Return_num = 4;
    lev[3].num_of_bullets = 4;
}

// New Levels 

void constructlev5(RenderWindow& window)
{
    // Background
    lev[4].BG.loadFromFile("assets/Backgrounds/background_city.png");
    lev[4].bg.setTexture(lev[4].BG);
    lev[4].bg.setScale(4, 1.2);

    // ground
    lev[4].GROUND[0].loadFromFile("assets/Textures/ground2.png");
    lev[4].ground.setTexture(&lev[4].GROUND[0]);
    lev[4].ground.setSize(Vector2f(window.getSize().x, window.getSize().y));
    lev[4].ground.setOrigin(lev[4].ground.getSize().x / 2, lev[4].ground.getSize().y / 2);
    lev[4].ground.setPosition(window.getSize().x / static_cast<float>(2), window.getSize().y / 1.85);

    // blocks 
    lev[4].BLOCK[0].loadFromFile("assets/Textures/Rectangle.png");
    lev[4].block[0].setTexture(&lev[4].BLOCK[0]);
    lev[4].block[0].setSize(Vector2f(500, 75));
    lev[4].block[0].setOrigin(lev[4].block[0].getSize().x / 2, lev[4].block[0].getSize().y / 2);
    lev[4].block[0].setPosition(lev[4].ground.getSize().x / 2, lev[4].ground.getSize().y - 850);

    //killer
    character_init(lev[4].killer, "assets/Characters/Killer/killer_head.png", "assets/Characters/blue_suit_body.png", false);
    character_set_scale(lev[4].killer, 0.4);
    character_set_position(lev[4].killer, Vector2f(lev[4].ground.getSize().x / 8, lev[4].ground.getPosition().y + 30));

    //targets
    for (int i = 0; i < 2; i++)
    {
        character_init(lev[4].target[i], "assets/Characters/gangster_head.png", "assets/Characters/black_suit_body.png", true);
        character_set_scale(lev[4].target[i], 0.35);
        character_set_position(lev[4].target[i], Vector2f(lev[4].ground.getPosition().x + (i * 250), lev[4].ground.getPosition().y + 60));
    }
    // bullets
    lev[4].Bullets[0].setTexture(Bullet_texture);
    lev[4].Bullets[1].setTexture(Bullet_texture);
    lev[4].Bullets[2].setTexture(Bullet_texture);
    lev[4].Bullets[3].setTexture(Bullet_texture);
    lev[4].Bullets[4].setTexture(Bullet_texture);


    lev[4].Bullets[0].setPosition(Vector2f(850, 55));
    lev[4].Bullets[0].setOrigin(lev[4].Bullets[0].getLocalBounds().width / 2, lev[4].Bullets[0].getLocalBounds().height / 2);
    lev[4].Bullets[0].setScale(.25, .25);
    lev[4].Bullets[0].setColor(Color::Black);

    lev[4].Bullets[1].setPosition(Vector2f(900, 55));
    lev[4].Bullets[1].setOrigin(lev[4].Bullets[1].getLocalBounds().width / 2, lev[4].Bullets[1].getLocalBounds().height / 2);
    lev[4].Bullets[1].setScale(.25, .25);
    lev[4].Bullets[1].setColor(Color::Black);

    lev[4].Bullets[2].setPosition(Vector2f(950, 55));
    lev[4].Bullets[2].setOrigin(lev[4].Bullets[2].getLocalBounds().width / 2, lev[4].Bullets[2].getLocalBounds().height / 2);
    lev[4].Bullets[2].setScale(.25, .25);
    lev[4].Bullets[2].setColor(Color::Black);

    lev[4].Bullets[3].setPosition(Vector2f(1000, 55));
    lev[4].Bullets[3].setOrigin(lev[4].Bullets[3].getLocalBounds().width / 2, lev[4].Bullets[3].getLocalBounds().height / 2);
    lev[4].Bullets[3].setScale(.25, .25);
    lev[4].Bullets[3].setColor(Color(240, 150, 25));


    lev[4].Return_num = 4;
    lev[4].num_of_bullets = 4;

}

void constructlev6(RenderWindow& window)
{
    //background
    lev[5].BG.loadFromFile("assets/Backgrounds/background_graveyard.png");
    lev[5].bg.setTexture(lev[5].BG);
    lev[5].bg.setScale(4, 1.2);

    //ground
    lev[5].GROUND[1].loadFromFile("assets/Textures/ZIGZAG_ground(2).png");
    lev[5].ground.setTexture(&lev[5].GROUND[1]);
    lev[5].ground.setSize(Vector2f(window.getSize().x, window.getSize().y));
    lev[5].ground.setOrigin(lev[5].ground.getSize().x / 2, lev[5].ground.getSize().y / 2);
    lev[5].ground.setPosition(lev[5].ground.getSize().x / 2, window.getSize().y - 200);

    //killer
    character_init(lev[5].killer, "assets/Characters/Killer/killer_head.png", "assets/Characters/blue_suit_body.png", false);
    character_set_scale(lev[5].killer, 0.3);
    character_set_position(lev[5].killer, Vector2f(25, lev[5].ground.getPosition().y - lev[5].ground.getSize().y / 1.5));

    //targets
    for (int i = 0; i < 7; i++)
    {
        character_init(lev[5].target[i], "assets/Characters/zombie_head.png", "assets/Characters/zombie_body.png", true);
        character_set_scale(lev[5].target[i], 0.27);
        character_set_position(lev[5].target[i], Vector2f(120 + (110 * i), lev[5].ground.getPosition().y - lev[5].ground.getSize().y / 1.7 + (i * 70)));
    }
    for (int i = 7; i < 15; i++)
    {
        character_init(lev[5].target[i], "assets/Characters/zombie_head.png", "assets/Characters/zombie_body.png", true);
        character_set_scale(lev[5].target[i], 0.27);
        character_set_position(lev[5].target[i], Vector2f(lev[5].ground.getOrigin().x + 135 + (110 * (i - 7)), lev[5].ground.getPosition().y - (215) - ((i - 7) * 70)));
    }
    // bullets
    for (int i = 0; i < 4; i++) {
        lev[5].Bullets[i].setTexture(Bullet_texture);
    }


    lev[5].Bullets[0].setPosition(Vector2f(850, 55));
    lev[5].Bullets[0].setOrigin(lev[5].Bullets[0].getLocalBounds().width / 2, lev[5].Bullets[0].getLocalBounds().height / 2);
    lev[5].Bullets[0].setScale(.25, .25);
    lev[5].Bullets[0].setColor(Color::Black);

    lev[5].Bullets[1].setPosition(Vector2f(900, 55));
    lev[5].Bullets[1].setOrigin(lev[5].Bullets[1].getLocalBounds().width / 2, lev[5].Bullets[1].getLocalBounds().height / 2);
    lev[5].Bullets[1].setScale(.25, .25);
    lev[5].Bullets[1].setColor(Color::Black);

    lev[5].Bullets[2].setPosition(Vector2f(950, 55));
    lev[5].Bullets[2].setOrigin(lev[5].Bullets[2].getLocalBounds().width / 2, lev[5].Bullets[2].getLocalBounds().height / 2);
    lev[5].Bullets[2].setScale(.25, .25);
    lev[5].Bullets[2].setColor(Color::Black);

    lev[5].Bullets[3].setPosition(Vector2f(1000, 55));
    lev[5].Bullets[3].setOrigin(lev[5].Bullets[3].getLocalBounds().width / 2, lev[5].Bullets[3].getLocalBounds().height / 2);
    lev[5].Bullets[3].setScale(.25, .25);
    lev[5].Bullets[3].setColor(Color(240, 150, 25));


    lev[5].Return_num = 4;
    lev[5].num_of_bullets = 4;

}

void constructlev7(RenderWindow& window)
{
    //background
    lev[6].BG.loadFromFile("assets/Backgrounds/background_graveyard.png");
    lev[6].bg.setTexture(lev[6].BG);
    lev[6].bg.setScale(4, 1.2);

    //box
    lev[6].SHAPES[0].loadFromFile("assets/Textures/box2.png");
    lev[6].shape[0].setTexture(&lev[6].SHAPES[0]);
    lev[6].shape[0].setSize(Vector2f(window.getSize().x / 2, window.getSize().y));
    lev[6].shape[0].setPosition(window.getSize().x - (0.75 * window.getSize().x), 1);

    //killer
    character_init(lev[6].killer, "assets/Characters/Killer/killer_head.png", "assets/Characters/blue_suit_body.png", false);
    character_set_scale(lev[6].killer, 0.3);
    character_set_position(lev[6].killer, Vector2f(window.getSize().x - (0.75 * window.getSize().x) + 150, lev[6].shape[0].getSize().y - 310));

    //target
    character_init(lev[6].target[0], "assets/Characters/zombie_head.png", "assets/Characters/zombie_body.png", false);
    character_set_scale(lev[6].target[0], 0.3);
    character_set_position(lev[6].target[0], Vector2f(window.getSize().x - (0.75 * window.getSize().x) + 150, lev[6].shape[0].getSize().y - 810));

    // bullets
    for (int i = 0; i < 4; i++) {
        lev[6].Bullets[i].setTexture(Bullet_texture);
    }


    lev[6].Bullets[0].setPosition(Vector2f(850, 55));
    lev[6].Bullets[0].setOrigin(lev[6].Bullets[0].getLocalBounds().width / 2, lev[6].Bullets[0].getLocalBounds().height / 2);
    lev[6].Bullets[0].setScale(.25, .25);
    lev[6].Bullets[0].setColor(Color::Black);

    lev[6].Bullets[1].setPosition(Vector2f(900, 55));
    lev[6].Bullets[1].setOrigin(lev[6].Bullets[1].getLocalBounds().width / 2, lev[6].Bullets[1].getLocalBounds().height / 2);
    lev[6].Bullets[1].setScale(.25, .25);
    lev[6].Bullets[1].setColor(Color::Black);

    lev[6].Bullets[2].setPosition(Vector2f(950, 55));
    lev[6].Bullets[2].setOrigin(lev[6].Bullets[2].getLocalBounds().width / 2, lev[6].Bullets[2].getLocalBounds().height / 2);
    lev[6].Bullets[2].setScale(.25, .25);
    lev[6].Bullets[2].setColor(Color::Black);

    lev[6].Bullets[3].setPosition(Vector2f(1000, 55));
    lev[6].Bullets[3].setOrigin(lev[6].Bullets[3].getLocalBounds().width / 2, lev[6].Bullets[3].getLocalBounds().height / 2);
    lev[6].Bullets[3].setScale(.25, .25);
    lev[6].Bullets[3].setColor(Color(240, 150, 25));


    lev[6].Return_num = 4;
    lev[6].num_of_bullets = 4;

}

void constructlev8(RenderWindow& window)
{
    //background
    lev[7].BG.loadFromFile("assets/Backgrounds/background_graveyard.png");
    lev[7].bg.setTexture(lev[7].BG);
    lev[7].bg.setScale(4, 1.2);

    //ground
    lev[7].GROUND[1].loadFromFile("assets/Textures/ZIGZAG_ground(2).png");
    lev[7].ground.setTexture(&lev[7].GROUND[1]);
    lev[7].ground.setSize(Vector2f(window.getSize().x, window.getSize().y));
    lev[7].ground.setOrigin(lev[7].ground.getSize().x / 2, lev[7].ground.getSize().y / 2);
    lev[7].ground.setPosition(lev[7].ground.getSize().x / 2, window.getSize().y - 200);

    //killer
    character_init(lev[7].killer, "assets/Characters/Killer/killer_head.png", "assets/Characters/blue_suit_body.png", false);
    character_set_scale(lev[7].killer, 0.3);
    character_set_position(lev[7].killer, Vector2f(25, lev[7].ground.getPosition().y - lev[7].ground.getSize().y / 1.5));

    //targets
    for (int i = 0; i < 7; i++)
    {
        character_init(lev[7].target[i], "assets/Characters/zombie_head.png", "assets/Characters/zombie_body.png", true);
        character_set_scale(lev[7].target[i], 0.27);
        character_set_position(lev[7].target[i], Vector2f(120 + (110 * i), lev[7].ground.getPosition().y - lev[7].ground.getSize().y / 1.7 + (i * 70)));
    }
    for (int i = 7; i < 15; i++)
    {
        character_init(lev[7].target[i], "assets/Characters/zombie_head.png", "assets/Characters/zombie_body.png", true);
        character_set_scale(lev[7].target[i], 0.27);
        character_set_position(lev[7].target[i], Vector2f(lev[7].ground.getOrigin().x + 135 + (110 * (i - 7)), lev[7].ground.getPosition().y - (215) - ((i - 7) * 70)));
    }
    //moving rect
    lev[7].SHAPES[0].loadFromFile("assets/Textures/rect3.png");
    lev[7].shape[0].setTexture(&lev[7].SHAPES[0]);
    lev[7].shape[0].setSize(Vector2f(100, 300));
    lev[7].shape[0].setPosition(Vector2f(window.getSize().x / 2 - 50, window.getSize().y / 2));

    // bullets
    for (int i = 0; i < 4; i++) {
        lev[7].Bullets[i].setTexture(Bullet_texture);
    }


    lev[7].Bullets[0].setPosition(Vector2f(850, 55));
    lev[7].Bullets[0].setOrigin(lev[7].Bullets[0].getLocalBounds().width / 2, lev[7].Bullets[0].getLocalBounds().height / 2);
    lev[7].Bullets[0].setScale(.25, .25);
    lev[7].Bullets[0].setColor(Color::Black);

    lev[7].Bullets[1].setPosition(Vector2f(900, 55));
    lev[7].Bullets[1].setOrigin(lev[7].Bullets[1].getLocalBounds().width / 2, lev[7].Bullets[1].getLocalBounds().height / 2);
    lev[7].Bullets[1].setScale(.25, .25);
    lev[7].Bullets[1].setColor(Color::Black);

    lev[7].Bullets[2].setPosition(Vector2f(950, 55));
    lev[7].Bullets[2].setOrigin(lev[7].Bullets[2].getLocalBounds().width / 2, lev[7].Bullets[2].getLocalBounds().height / 2);
    lev[7].Bullets[2].setScale(.25, .25);
    lev[7].Bullets[2].setColor(Color::Black);

    lev[7].Bullets[3].setPosition(Vector2f(1000, 55));
    lev[7].Bullets[3].setOrigin(lev[7].Bullets[3].getLocalBounds().width / 2, lev[7].Bullets[3].getLocalBounds().height / 2);
    lev[7].Bullets[3].setScale(.25, .25);
    lev[7].Bullets[3].setColor(Color(240, 150, 25));


    lev[7].Return_num = 4;
    lev[7].num_of_bullets = 4;
}

void constructlev9(RenderWindow& window)
{
    //background
    lev[8].BG.loadFromFile("assets/Backgrounds/background_graveyard.png");
    lev[8].bg.setTexture(lev[8].BG);
    lev[8].bg.setScale(4, 1.2);

    //box
    lev[8].SHAPES[0].loadFromFile("assets/Textures/box&ground.png");
    lev[8].shape[0].setTexture(&lev[8].SHAPES[0]);
    lev[8].shape[0].setSize(Vector2f(window.getSize().x, window.getSize().y));
    lev[8].shape[0].setOrigin(lev[8].shape[0].getSize().x / 2, lev[8].shape[0].getSize().y / 2);
    lev[8].shape[0].setPosition(Vector2f(1920 / 2, 1080 / 2));

    //killer
    character_init(lev[8].killer, "assets/Characters/Killer/killer_head.png", "assets/Characters/blue_suit_body.png", false);
    character_set_scale(lev[8].killer, 0.35);
    character_set_position(lev[8].killer, Vector2f(lev[8].shape[0].getPosition().x - 785, lev[8].shape[0].getPosition().y + 180));

    //target1
    character_init(lev[8].target[0], "assets/Characters/zombie_head.png", "assets/Characters/zombie_body.png", true);
    character_set_scale(lev[8].target[0], 0.3);
    character_set_position(lev[8].target[0], Vector2f(lev[8].shape[0].getPosition().x - 160, lev[8].shape[0].getPosition().y - 30));

    //target2
    character_init(lev[8].target[1], "assets/Characters/zombie_head.png", "assets/Characters/zombie_body.png", true);
    character_set_scale(lev[8].target[1], 1.3);
    character_set_position(lev[8].target[1], Vector2f(lev[8].shape[0].getPosition().x + 400, lev[9].shape[0].getPosition().y - 500));
    // bullets
    for (int i = 0; i < 4; i++) {
        lev[8].Bullets[i].setTexture(Bullet_texture);
    }


    lev[8].Bullets[0].setPosition(Vector2f(850, 55));
    lev[8].Bullets[0].setOrigin(lev[8].Bullets[0].getLocalBounds().width / 2, lev[8].Bullets[0].getLocalBounds().height / 2);
    lev[8].Bullets[0].setScale(.25, .25);
    lev[8].Bullets[0].setColor(Color::Black);

    lev[8].Bullets[1].setPosition(Vector2f(900, 55));
    lev[8].Bullets[1].setOrigin(lev[8].Bullets[1].getLocalBounds().width / 2, lev[8].Bullets[1].getLocalBounds().height / 2);
    lev[8].Bullets[1].setScale(.25, .25);
    lev[8].Bullets[1].setColor(Color::Black);

    lev[8].Bullets[2].setPosition(Vector2f(950, 55));
    lev[8].Bullets[2].setOrigin(lev[8].Bullets[2].getLocalBounds().width / 2, lev[8].Bullets[2].getLocalBounds().height / 2);
    lev[8].Bullets[2].setScale(.25, .25);
    lev[8].Bullets[2].setColor(Color::Black);

    lev[8].Bullets[3].setPosition(Vector2f(1000, 55));
    lev[8].Bullets[3].setOrigin(lev[8].Bullets[3].getLocalBounds().width / 2, lev[8].Bullets[3].getLocalBounds().height / 2);
    lev[8].Bullets[3].setScale(.25, .25);
    lev[8].Bullets[3].setColor(Color(240, 150, 25));


    lev[8].Return_num = 4;
    lev[8].num_of_bullets = 4;
}

void constructlev10(RenderWindow& window)
{
    //background
    lev[9].BG.loadFromFile("assets/Backgrounds/background_graveyard.png");
    lev[9].bg.setTexture(lev[9].BG);
    lev[9].bg.setScale(4, 1.2);

    //ground
    lev[9].GROUND[0].loadFromFile("assets/Textures/groundlev10.png");
    lev[9].ground.setTexture(&lev[9].GROUND[0]);
    lev[9].ground.setSize(Vector2f(1920, 1080));

    //killer
    character_init(lev[9].killer, "assets/Characters/Killer/killer_head.png", "assets/Characters/blue_suit_body.png", false);
    character_set_scale(lev[9].killer, 0.35);
    character_set_position(lev[9].killer, Vector2f(200, 515));

    //target1
    character_init(lev[9].target[0], "assets/Characters/zombie_head.png", "assets/Characters/zombie_body.png", true);
    character_set_scale(lev[9].target[0], 0.4);
    character_set_position(lev[9].target[0], Vector2f(1720, 490));


    // bullets

    for (int i = 0; i < 4; i++) {
        lev[9].Bullets[i].setTexture(Bullet_texture);
    }


    lev[9].Bullets[0].setPosition(Vector2f(850, 55));
    lev[9].Bullets[0].setOrigin(lev[9].Bullets[0].getLocalBounds().width / 2, lev[9].Bullets[0].getLocalBounds().height / 2);
    lev[9].Bullets[0].setScale(.25, .25);
    lev[9].Bullets[0].setColor(Color::Black);

    lev[9].Bullets[1].setPosition(Vector2f(900, 55));
    lev[9].Bullets[1].setOrigin(lev[9].Bullets[1].getLocalBounds().width / 2, lev[9].Bullets[1].getLocalBounds().height / 2);
    lev[9].Bullets[1].setScale(.25, .25);
    lev[9].Bullets[1].setColor(Color::Black);

    lev[9].Bullets[2].setPosition(Vector2f(950, 55));
    lev[9].Bullets[2].setOrigin(lev[9].Bullets[2].getLocalBounds().width / 2, lev[9].Bullets[2].getLocalBounds().height / 2);
    lev[9].Bullets[2].setScale(.25, .25);
    lev[9].Bullets[2].setColor(Color::Black);

    lev[9].Bullets[3].setPosition(Vector2f(1000, 55));
    lev[9].Bullets[3].setOrigin(lev[9].Bullets[3].getLocalBounds().width / 2, lev[9].Bullets[3].getLocalBounds().height / 2);
    lev[9].Bullets[3].setScale(.25, .25);
    lev[9].Bullets[3].setColor(Color(240, 150, 25));


    lev[9].Return_num = 4;
    lev[9].num_of_bullets = 4;


}

void constructlev11(RenderWindow& window) {
    //background
    lev[10].BG.loadFromFile("assets/Backgrounds/background_japan.png");
    lev[10].bg.setTexture(lev[10].BG);
    lev[10].bg.setScale(4, 1.2);

    //ground
    lev[10].BLOCK[0].loadFromFile("assets/Textures/block.png");
    lev[10].block[0].setTexture(&lev[10].BLOCK[0]);
    lev[10].block[0].setSize(Vector2f(100, 50));
    lev[10].block[0].setPosition(Vector2f(860, 540));

    //killer
    character_init(lev[10].killer, "assets/Characters/Killer/killer_chinese_head.png", "assets/Characters/chinese_body.png", true);
    character_set_scale(lev[10].killer, 0.25);
    character_set_position(lev[10].killer, Vector2f(lev[10].block[0].getPosition().x + 20, lev[10].block[0].getPosition().y - 150));

    //blocks
    for (int i = 1; i <= 3; i++) {
        lev[10].BLOCK[i].loadFromFile("assets/Textures/pyr_block.png");
        lev[10].block[i].setTexture(&lev[10].BLOCK[i]);
        lev[10].block[i].setSize(Vector2f(100, 50));
        //lev[10].block[1].setPosition(Vector2f(860, 540));
    }

    //targets
    for (int i = 0; i <= 2; i++) {
        character_init(lev[10].target[i], "assets/Characters/ninja_head.png", "assets/Characters/ninja_body.png", false);
        character_set_scale(lev[10].target[i], 0.25);
        //character_set_position(lev[11].target[0], Vector2f(lev[11].block[1].getPosition().x + 20, lev[11].block[1].getPosition().y - 150));
    }
    for (int i = 0; i < 6; i++) {
        lev[10].Bullets[i].setTexture(Bullet_texture);
    }


    lev[10].Bullets[0].setPosition(Vector2f(850, 55));
    lev[10].Bullets[0].setOrigin(lev[10].Bullets[0].getLocalBounds().width / 2, lev[10].Bullets[0].getLocalBounds().height / 2);
    lev[10].Bullets[0].setScale(.25, .25);
    lev[10].Bullets[0].setColor(Color::Black);

    lev[10].Bullets[1].setPosition(Vector2f(900, 55));
    lev[10].Bullets[1].setOrigin(lev[10].Bullets[1].getLocalBounds().width / 2, lev[10].Bullets[1].getLocalBounds().height / 2);
    lev[10].Bullets[1].setScale(.25, .25);
    lev[10].Bullets[1].setColor(Color::Black);

    lev[10].Bullets[2].setPosition(Vector2f(950, 55));
    lev[10].Bullets[2].setOrigin(lev[10].Bullets[2].getLocalBounds().width / 2, lev[10].Bullets[2].getLocalBounds().height / 2);
    lev[10].Bullets[2].setScale(.25, .25);
    lev[10].Bullets[2].setColor(Color::Black);

    lev[10].Bullets[3].setPosition(Vector2f(1000, 55));
    lev[10].Bullets[3].setOrigin(lev[10].Bullets[3].getLocalBounds().width / 2, lev[10].Bullets[3].getLocalBounds().height / 2);
    lev[10].Bullets[3].setScale(.25, .25);
    lev[10].Bullets[3].setColor(Color(240, 150, 25));

    lev[10].Bullets[4].setPosition(Vector2f(1050, 55));
    lev[10].Bullets[4].setOrigin(lev[10].Bullets[4].getLocalBounds().width / 2, lev[10].Bullets[4].getLocalBounds().height / 2);
    lev[10].Bullets[4].setScale(.25, .25);
    lev[10].Bullets[4].setColor(Color(240, 150, 25));

    lev[10].Bullets[5].setPosition(Vector2f(1100, 55));
    lev[10].Bullets[5].setOrigin(lev[10].Bullets[5].getLocalBounds().width / 2, lev[10].Bullets[5].getLocalBounds().height / 2);
    lev[10].Bullets[5].setScale(.25, .25);
    lev[10].Bullets[5].setColor(Color(240, 150, 25));



    lev[10].Return_num = 6;
    lev[10].num_of_bullets = 6;

}

void constructlev12(RenderWindow& window) {
    //background
    lev[11].BG.loadFromFile("assets/Backgrounds/background_japan.png");
    lev[11].bg.setTexture(lev[11].BG);
    lev[11].bg.setScale(4, 1.2);

    // Load and set properties for blocks
    for (int i = 0; i < 5; i++) {
        lev[11].BLOCK[i].loadFromFile("assets/Textures/rect1.png");
        lev[11].block[i].setTexture(&lev[11].BLOCK[i]);
        lev[11].block[i].setSize(Vector2f(80, 30));

        if (i == 0) {
            lev[11].block[i].setPosition(Vector2f(1700, 200));
        }

        else if (i == 1) {
            lev[11].block[i].setPosition(Vector2f(100, 900));
        }

        else if (i == 2) {
            lev[11].block[i].setPosition(Vector2f(1000, 400));
        }

        else if (i == 3) {
            lev[11].block[i].setPosition(Vector2f(800, 400));
        }

        else if (i == 4) {
            lev[11].block[i].setPosition(Vector2f(910, 540));
        }

    }

    // killer
    character_init(lev[11].killer, "assets/Characters/Killer/killer_chinese_head.png", "assets/Characters/chinese_body.png", true);
    character_set_scale(lev[11].killer, 0.22);
    character_set_position(lev[11].killer, Vector2f(lev[11].block[4].getPosition().x + 20, lev[11].block[4].getPosition().y - 130));

    // Initialize and set properties for target characters
    for (int i = 0; i < 4; i++) {
        character_init(lev[11].target[i], "assets/Characters/ninja_head.png", "assets/Characters/ninja_body.png", false);
        character_set_scale(lev[11].target[i], 0.22);
        //character_set_position(lev[12].target[i], Vector2f(lev[12].block[i].getPosition().x + 20, lev[12].block[i].getPosition().y - 150));
    }
    // bullets
    for (int i = 0; i < 6; i++) {
        lev[11].Bullets[i].setTexture(Bullet_texture);
    }


    lev[11].Bullets[0].setPosition(Vector2f(850, 55));
    lev[11].Bullets[0].setOrigin(lev[11].Bullets[0].getLocalBounds().width / 2, lev[11].Bullets[0].getLocalBounds().height / 2);
    lev[11].Bullets[0].setScale(.25, .25);
    lev[11].Bullets[0].setColor(Color::Black);

    lev[11].Bullets[1].setPosition(Vector2f(900, 55));
    lev[11].Bullets[1].setOrigin(lev[11].Bullets[1].getLocalBounds().width / 2, lev[11].Bullets[1].getLocalBounds().height / 2);
    lev[11].Bullets[1].setScale(.25, .25);
    lev[11].Bullets[1].setColor(Color::Black);

    lev[11].Bullets[2].setPosition(Vector2f(950, 55));
    lev[11].Bullets[2].setOrigin(lev[11].Bullets[2].getLocalBounds().width / 2, lev[11].Bullets[2].getLocalBounds().height / 2);
    lev[11].Bullets[2].setScale(.25, .25);
    lev[11].Bullets[2].setColor(Color::Black);

    lev[11].Bullets[3].setPosition(Vector2f(1000, 55));
    lev[11].Bullets[3].setOrigin(lev[11].Bullets[3].getLocalBounds().width / 2, lev[11].Bullets[3].getLocalBounds().height / 2);
    lev[11].Bullets[3].setScale(.25, .25);
    lev[11].Bullets[3].setColor(Color(240, 150, 25));

    lev[11].Bullets[4].setPosition(Vector2f(1050, 55));
    lev[11].Bullets[4].setOrigin(lev[11].Bullets[4].getLocalBounds().width / 2, lev[11].Bullets[4].getLocalBounds().height / 2);
    lev[11].Bullets[4].setScale(.25, .25);
    lev[11].Bullets[4].setColor(Color(240, 150, 25));

    lev[11].Bullets[5].setPosition(Vector2f(1100, 55));
    lev[11].Bullets[5].setOrigin(lev[11].Bullets[5].getLocalBounds().width / 2, lev[11].Bullets[5].getLocalBounds().height / 2);
    lev[11].Bullets[5].setScale(.25, .25);
    lev[11].Bullets[5].setColor(Color(240, 150, 25));



    lev[11].Return_num = 6;
    lev[11].num_of_bullets = 6;
}

void constructlev13(RenderWindow& window) {

    //background
    lev[12].BG.loadFromFile("assets/Backgrounds/background_japan.png");
    lev[12].bg.setTexture(lev[12].BG);
    lev[12].bg.setScale(4, 1.2);

    //blocks
    lev[12].BLOCK[0].loadFromFile("assets/Textures/block.png");
    lev[12].block[0].setTexture(&lev[12].BLOCK[0]);
    lev[12].block[0].setSize(Vector2f(100, 50));
    lev[12].block[0].setPosition(Vector2f(860, 540));

    for (int i = 1; i <= 4; i++) {
        lev[12].BLOCK[i].loadFromFile("assets/Textures/pyr_block.png");
        lev[12].block[i].setTexture(&lev[12].BLOCK[i]);
        lev[12].block[i].setSize(Vector2f(100, 50));
    }

    lev[12].block[3].setPosition(Vector2f(1520, 280));
    lev[12].block[4].setPosition(Vector2f(200, 800));

    //killer
    character_init(lev[12].killer, "assets/Characters/Killer/killer_chinese_head.png", "assets/Characters/chinese_body.png", true);
    character_set_scale(lev[12].killer, 0.25);
    character_set_position(lev[12].killer, Vector2f(lev[12].block[0].getPosition().x + 20, lev[12].block[0].getPosition().y - 150));

    // targets
    for (int i = 0; i <= 3; i++) {
        character_init(lev[12].target[i], "assets/Characters/ninja_head.png", "assets/Characters/ninja_body.png", false);
        character_set_scale(lev[12].target[i], 0.25);
    }

    character_set_position(lev[12].target[0], Vector2f(lev[12].block[1].getPosition().x + 20, lev[12].block[1].getPosition().y - 150));
    character_set_position(lev[12].target[1], Vector2f(lev[12].block[2].getPosition().x + 20, lev[12].block[2].getPosition().y - 150));
    character_set_position(lev[12].target[2], Vector2f(lev[12].block[3].getPosition().x + 20, lev[12].block[3].getPosition().y - 150));
    character_set_position(lev[12].target[3], Vector2f(lev[12].block[4].getPosition().x + 20, lev[12].block[4].getPosition().y - 150));

    // bullets
    for (int i = 0; i < 5; i++) {
        lev[12].Bullets[i].setTexture(Bullet_texture);
    }


    lev[12].Bullets[0].setPosition(Vector2f(850, 55));
    lev[12].Bullets[0].setOrigin(lev[12].Bullets[0].getLocalBounds().width / 2, lev[12].Bullets[0].getLocalBounds().height / 2);
    lev[12].Bullets[0].setScale(.25, .25);
    lev[12].Bullets[0].setColor(Color::Black);

    lev[12].Bullets[1].setPosition(Vector2f(900, 55));
    lev[12].Bullets[1].setOrigin(lev[12].Bullets[1].getLocalBounds().width / 2, lev[12].Bullets[1].getLocalBounds().height / 2);
    lev[12].Bullets[1].setScale(.25, .25);
    lev[12].Bullets[1].setColor(Color::Black);

    lev[12].Bullets[2].setPosition(Vector2f(950, 55));
    lev[12].Bullets[2].setOrigin(lev[12].Bullets[2].getLocalBounds().width / 2, lev[12].Bullets[2].getLocalBounds().height / 2);
    lev[12].Bullets[2].setScale(.25, .25);
    lev[12].Bullets[2].setColor(Color::Black);

    lev[12].Bullets[3].setPosition(Vector2f(1000, 55));
    lev[12].Bullets[3].setOrigin(lev[12].Bullets[3].getLocalBounds().width / 2, lev[12].Bullets[3].getLocalBounds().height / 2);
    lev[12].Bullets[3].setScale(.25, .25);
    lev[12].Bullets[3].setColor(Color(240, 150, 25));

    lev[12].Bullets[4].setPosition(Vector2f(1050, 55));
    lev[12].Bullets[4].setOrigin(lev[12].Bullets[4].getLocalBounds().width / 2, lev[12].Bullets[4].getLocalBounds().height / 2);
    lev[12].Bullets[4].setScale(.25, .25);
    lev[12].Bullets[4].setColor(Color(240, 150, 25));

    lev[12].Return_num = 5;
    lev[12].num_of_bullets = 5;
}

void constructlev14(RenderWindow& window) {

    //background
    lev[13].BG.loadFromFile("assets/Backgrounds/background_japan.png");
    lev[13].bg.setTexture(lev[13].BG);
    lev[13].bg.setScale(4, 1.2);

    // Load and set properties for ground
    lev[13].GROUND[0].loadFromFile("assets/Textures/ground_tokyo_1.png");
    lev[13].ground.setTexture(&lev[13].GROUND[0]);
    lev[13].ground.setSize(Vector2f(window.getSize().x, window.getSize().y / 3));
    lev[13].ground.setOrigin(lev[13].ground.getLocalBounds().width / 2, lev[13].ground.getLocalBounds().height / 2);
    lev[13].ground.setPosition(window.getSize().x / 2.0, window.getSize().y);

    // Load and set properties for shapes
    for (int i = 0; i <= 1; i++) {
        lev[13].SHAPES[i].loadFromFile("assets/Textures/rect1.png");
        lev[13].shape[i].setTexture(&lev[13].SHAPES[i]);
    }

    lev[13].shape[0].setSize(Vector2f(100, 600));
    lev[13].shape[0].setPosition(Vector2f(600, 300));
    lev[13].shape[1].setSize(Vector2f(100, 200));
    lev[13].shape[1].setPosition(Vector2f(600, 0));

    // Load and set properties for blocks
    lev[13].BLOCK[0].loadFromFile("assets/Textures/square.png");
    lev[13].block[0].setTexture(&lev[13].BLOCK[0]);
    lev[13].block[0].setSize(Vector2f(100, 50));
    lev[13].block[0].setPosition(Vector2f(300, 750));

    // Initialize and set properties for killer character
    character_init(lev[13].killer, "assets/Characters/Killer/killer_chinese_head.png", "assets/Characters/chinese_body.png", true);
    character_set_scale(lev[13].killer, 0.25);
    character_set_position(lev[13].killer, Vector2f(1500, 750));

    // Initialize and set properties for target character
    character_init(lev[13].target[0], "assets/Characters/ninja_head.png", "assets/Characters/ninja_body.png", false);
    character_set_scale(lev[13].target[0], 0.25);
    
    // bullets

    for (int i = 0; i < 4; i++) {
        lev[13].Bullets[i].setTexture(Bullet_texture);
    }


    lev[13].Bullets[0].setPosition(Vector2f(850, 55));
    lev[13].Bullets[0].setOrigin(lev[13].Bullets[0].getLocalBounds().width / 2, lev[13].Bullets[0].getLocalBounds().height / 2);
    lev[13].Bullets[0].setScale(.25, .25);
    lev[13].Bullets[0].setColor(Color::Black);

    lev[13].Bullets[1].setPosition(Vector2f(900, 55));
    lev[13].Bullets[1].setOrigin(lev[13].Bullets[1].getLocalBounds().width / 2, lev[13].Bullets[1].getLocalBounds().height / 2);
    lev[13].Bullets[1].setScale(.25, .25);
    lev[13].Bullets[1].setColor(Color::Black);

    lev[13].Bullets[2].setPosition(Vector2f(950, 55));
    lev[13].Bullets[2].setOrigin(lev[13].Bullets[2].getLocalBounds().width / 2, lev[13].Bullets[2].getLocalBounds().height / 2);
    lev[13].Bullets[2].setScale(.25, .25);
    lev[13].Bullets[2].setColor(Color::Black);

    lev[13].Bullets[3].setPosition(Vector2f(1000, 55));
    lev[13].Bullets[3].setOrigin(lev[13].Bullets[3].getLocalBounds().width / 2, lev[13].Bullets[3].getLocalBounds().height / 2);
    lev[13].Bullets[3].setScale(.25, .25);
    lev[13].Bullets[3].setColor(Color(240, 150, 25));


    lev[13].Return_num = 4;
    lev[13].num_of_bullets = 4;
}

void constructlev15(RenderWindow& window) {

    //background
    lev[14].BG.loadFromFile("assets/Backgrounds/background_japan.png");
    lev[14].bg.setTexture(lev[14].BG);
    lev[14].bg.setScale(4, 1.2);

    //blocks
    for (int i = 0; i <= 1; i++) {
        lev[14].BLOCK[i].loadFromFile("assets/Textures/square.png");
        lev[14].block[i].setTexture(&lev[14].BLOCK[i]);
    }

    lev[14].block[0].setSize(Vector2f(100, 50));
    //lev[15].block[0].setPosition(Vector2f(600, 750));

    lev[14].block[1].setSize(Vector2f(150, 320));
    lev[14].block[1].setPosition(Vector2f(1500, 750));

    // Initialize and set properties for killer character
    character_init(lev[14].killer, "assets/Characters/Killer/killer_chinese_head.png", "assets/Characters/chinese_body.png", true);
    character_set_scale(lev[14].killer, 0.25);
    character_set_position(lev[14].killer, Vector2f(lev[14].block[1].getPosition().x + 50, lev[14].block[1].getPosition().y - 150));

    // Initialize and set properties for target character
    character_init(lev[14].target[0], "assets/Characters/ninja_head.png", "assets/Characters/ninja_body.png", false);
    character_set_scale(lev[14].target[0], 0.25);
    //character_set_position(lev[15].target[0], Vector2f(lev[15].block[0].getPosition().x + 20, lev[15].block[0].getPosition().y - 150));
    // bullets
    lev[14].Bullets[0].setTexture(Bullet_texture);
    lev[14].Bullets[1].setTexture(Bullet_texture);
    lev[14].Bullets[2].setTexture(Bullet_texture);
    lev[14].Bullets[3].setTexture(Bullet_texture);
    lev[14].Bullets[4].setTexture(Bullet_texture);


    lev[14].Bullets[0].setPosition(Vector2f(850, 55));
    lev[14].Bullets[0].setOrigin(lev[14].Bullets[0].getLocalBounds().width / 2, lev[14].Bullets[0].getLocalBounds().height / 2);
    lev[14].Bullets[0].setScale(.25, .25);
    lev[14].Bullets[0].setColor(Color::Black);

    lev[14].Bullets[1].setPosition(Vector2f(900, 55));
    lev[14].Bullets[1].setOrigin(lev[14].Bullets[1].getLocalBounds().width / 2, lev[14].Bullets[1].getLocalBounds().height / 2);
    lev[14].Bullets[1].setScale(.25, .25);
    lev[14].Bullets[1].setColor(Color::Black);

    lev[14].Bullets[2].setPosition(Vector2f(950, 55));
    lev[14].Bullets[2].setOrigin(lev[14].Bullets[2].getLocalBounds().width / 2, lev[14].Bullets[2].getLocalBounds().height / 2);
    lev[14].Bullets[2].setScale(.25, .25);
    lev[14].Bullets[2].setColor(Color::Black);

    lev[14].Bullets[3].setPosition(Vector2f(1000, 55));
    lev[14].Bullets[3].setOrigin(lev[14].Bullets[3].getLocalBounds().width / 2, lev[14].Bullets[3].getLocalBounds().height / 2);
    lev[14].Bullets[3].setScale(.25, .25);
    lev[14].Bullets[3].setColor(Color(240, 150, 25));


    lev[14].Return_num = 4;
    lev[14].num_of_bullets = 4;
}

void constructOneVSone(RenderWindow& window) {

    //background
    lev[16].BG.loadFromFile("assets/Backgrounds/background_egypt.png");
    lev[16].bg.setTexture(lev[16].BG);
    lev[16].bg.setScale(4, 1.2);

    //blocks
    for (int i = 0; i < 4; i++) {
        lev[16].BLOCK[i].loadFromFile("assets/Textures/square.png");
        lev[16].block[i].setTexture(&lev[16].BLOCK[i]);
        lev[16].block[i].setSize(Vector2f(150, 50));
    }
    lev[16].block[0].setPosition(Vector2f(400, 750));
    lev[16].block[1].setPosition(Vector2f(1420, 750));
    lev[16].block[2].setPosition(Vector2f(960, 300));
    lev[16].block[2].setRotation(90.f);
    lev[16].block[3].setPosition(Vector2f(960, 700));
    lev[16].block[3].setRotation(90.f);


    character_init(lev[16].killer, "assets/Characters/Killer/killer_caveman_head.png", "assets/Characters/Killer/pulp_fiction_body.png", true);
    character_set_scale(lev[16].killer, 0.34);
    // character_set_position(lev[16].killer, Vector2f(lev[16].block[1].getPosition().x + 50, lev[16].block[1].getPosition().y - 200));

    character_init(lev[16].target[0], "assets/Characters/Killer/killer_nicky_larson_head.png", "assets/Characters/Killer/pulp_fiction_body.png", false);
    character_set_scale(lev[16].target[0], 0.34);
    //character_set_position(lev[16].target[0], Vector2f(lev[16].block[0].getPosition().x + 20, lev[16].block[0].getPosition().y - 200));

}


void DrawingLevels(int num, RenderWindow& window)
{
    if (num == 0) // ==> constructing Level 1
    {

        window.draw(lev[0].bg);
        window.draw(lev[0].ground);
        character_draw(lev[0].killer, window);
        character_draw(lev[0].target[0], window);
        for (int i = 0; i < lev[level_index].num_of_bullets; i++)
        {
            window.draw(lev[level_index].Bullets[i]);
        }
        for (int i = 0; i < bullets.size(); i++) {
            bullets[i].bulletBody.setPosition(bullets[i].bulletBody.getPosition() - bullets[i].bulletDirection * bulletSpeed);
        }
        for (int i = 0; i < bullets.size(); i++) {
            window.draw(bullets[i].b);
        }
        for (int i = 0; i < bullets.size(); i++) {
            HandlePhysics(lev[0], bullets[i]);
        }
        for (int i = 0; i < bullets.size(); i++) {
            CollideEnemies(lev[0], bullets[i]);
        }
        levels_background();
    }


    else if (num == 1) // ==> constructing Level 2
    {
        window.draw(lev[1].bg);
        for (int i = 0; i < lev[level_index].num_of_bullets; i++)
        {
            window.draw(lev[level_index].Bullets[i]);
        }
        for (int i = 0; i < 10; i++)
        {
            window.draw(lev[1].block[i]);
        }
        character_draw(lev[1].killer, window);
        for (int i = 0; i < bullets.size(); i++) {
            bullets[i].bulletBody.setPosition(bullets[i].bulletBody.getPosition() - bullets[i].bulletDirection * bulletSpeed);
        }
        for (int i = 0; i < 8; i++)
        {
            character_draw(lev[1].target[i], window);
        }
        for (int i = 0; i < bullets.size(); i++) {
            window.draw(bullets[i].bulletBody);
        }

        for (int i = 0; i < bullets.size(); i++) {
            HandlePhysics(lev[1], bullets[i]);
        }
        for (int i = 0; i < bullets.size(); i++) {
            CollideEnemies(lev[1], bullets[i]);
        }
        levels_background();
    }


    else if (num == 2) // ==> constructing Level 3
    {
        window.draw(lev[2].bg);
        window.draw(lev[2].ground);
        window.draw(lev[2].shape[0]);
        window.draw(lev[2].shape[1]);
        character_draw(lev[2].killer, window);
        for (int i = 0; i < bullets.size(); i++) {
            bullets[i].bulletBody.setPosition(bullets[i].bulletBody.getPosition() - bullets[i].bulletDirection * bulletSpeed);
        }
        character_draw(lev[2].target[0], window);
        for (int i = 0; i < lev[level_index].num_of_bullets; i++)
        {
            window.draw(lev[level_index].Bullets[i]);
        }
        for (int i = 0; i < bullets.size(); i++) {
            window.draw(bullets[i].bulletBody);
        }

        for (int i = 0; i < bullets.size(); i++) {
            HandlePhysics(lev[2], bullets[i]);
        }
        for (int i = 0; i < bullets.size(); i++) {
            CollideEnemies(lev[2], bullets[i]);
        }
        levels_background();

    }


    else if (num == 3)   // ==> constructing Level 4
    {
        window.draw(lev[3].bg);
        window.draw(lev[3].shape[0]);
        character_draw(lev[3].killer, window);
        for (int i = 0; i < lev[level_index].num_of_bullets; i++)
        {
            window.draw(lev[level_index].Bullets[i]);
        }
        for (int i = 0; i < 3; i++)
        {
            character_draw(lev[3].target[i], window);
        }
        for (int i = 0; i < bullets.size(); i++) {
            bullets[i].bulletBody.setPosition(bullets[i].bulletBody.getPosition() - bullets[i].bulletDirection * bulletSpeed);
        }
        for (int i = 0; i < bullets.size(); i++) {
            window.draw(bullets[i].bulletBody);
        }

        for (int i = 0; i < bullets.size(); i++) {
            HandlePhysics(lev[3], bullets[i]);
        }
        for (int i = 0; i < bullets.size(); i++) {
            CollideEnemies(lev[3], bullets[i]);
        }
        levels_background();

    }


    else if (num == 4) // ==> constructing level 5
    {
        lev[4].block[0].move(blockSpeed, 0.0f);
       
        if (lev[4].block[0].getPosition().x < 150 || lev[4].block[0].getPosition().x > 1100)
        {
            // Reverse the vertical movement direction
            blockSpeed *= -1;
        }



        window.draw(lev[4].bg);
        window.draw(lev[4].ground);
        window.draw(lev[4].block[0]);

        character_draw(lev[4].killer, window);

        for (int i = 0; i < bullets.size(); i++) {
            bullets[i].bulletBody.setPosition(bullets[i].bulletBody.getPosition() - bullets[i].bulletDirection * bulletSpeed);
        }
        for (int i = 0; i < lev[level_index].num_of_bullets; i++)
        {
            window.draw(lev[level_index].Bullets[i]);
        }
        for (int i = 0; i < 2; i++)
        {
            character_draw(lev[4].target[i], window);
        }
    }


    else if (num == 5) // ==> constructing level 6
    {
        window.draw(lev[5].bg);
        window.draw(lev[5].ground);
      
        character_draw(lev[5].killer, window);
        for (int i = 0; i < bullets.size(); i++) {
            bullets[i].bulletBody.setPosition(bullets[i].bulletBody.getPosition() - bullets[i].bulletDirection * bulletSpeed);
        }
        for (int i = 0; i < 15; i++)
        {
            character_draw(lev[5].target[i], window);
        }
        for (int i = 0; i < lev[level_index].num_of_bullets; i++)
        {
            window.draw(lev[level_index].Bullets[i]);
        }
    }


    else if (num == 6) // ==> constructing level 7
    {
    
        window.draw(lev[6].bg);
        window.draw(lev[6].shape[0]);
        character_draw(lev[6].killer, window);
        character_draw(lev[6].target[0], window);
        for (int i = 0; i < bullets.size(); i++) {
            bullets[i].bulletBody.setPosition(bullets[i].bulletBody.getPosition() - bullets[i].bulletDirection * bulletSpeed);
        }
        for (int i = 0; i < lev[level_index].num_of_bullets; i++)
        {
            window.draw(lev[level_index].Bullets[i]);
        }
    }


    else if (num == 7) // ==> constructing level 8
    {
    for (int i = 0; i < lev[level_index].num_of_bullets; i++)
    {
        window.draw(lev[level_index].Bullets[i]);
    }
        lev[7].shape[0].move(0.f, blockSpeed);
        if (lev[7].shape[0].getPosition().y < 100 || lev[7].shape[0].getPosition().y + lev[7].shape[0].getSize().y > window.getSize().y - 170)
        {
            // Reverse the vertical movement direction
            blockSpeed *= -1;
        }

        window.draw(lev[7].bg);
        window.draw(lev[7].ground);
        character_draw(lev[7].killer, window);
       
        window.draw(lev[7].shape[0]);

        for (int i = 0; i < 15; i++)
        {
            character_draw(lev[7].target[i], window);
        }
        for (int i = 0; i < bullets.size(); i++) {
            bullets[i].bulletBody.setPosition(bullets[i].bulletBody.getPosition() - bullets[i].bulletDirection * bulletSpeed);
        }
        for (int i = 0; i < lev[level_index].num_of_bullets; i++)
        {
            window.draw(lev[level_index].Bullets[i]);
        }

    }


    else if (num == 8) // ==> constructing level 9
    {
   
        window.draw(lev[8].bg);
        window.draw(lev[8].shape[0]);
        character_draw(lev[8].killer, window);
        for (int i = 0; i < 2; i++)
        {
            character_draw(lev[8].target[i], window);
        }
        for (int i = 0; i < bullets.size(); i++) {
            bullets[i].bulletBody.setPosition(bullets[i].bulletBody.getPosition() - bullets[i].bulletDirection * bulletSpeed);
        }
        for (int i = 0; i < lev[level_index].num_of_bullets; i++)
        {
            window.draw(lev[level_index].Bullets[i]);
        }
    }


    else if (num == 9) // ==> constructing level 10
    {
    
        window.draw(lev[9].bg);
        window.draw(lev[9].ground);
        character_draw(lev[9].killer, window);
        character_draw(lev[9].target[0], window);
        for (int i = 0; i < bullets.size(); i++) {
            bullets[i].bulletBody.setPosition(bullets[i].bulletBody.getPosition() - bullets[i].bulletDirection * bulletSpeed);
        }
        for (int i = 0; i < lev[level_index].num_of_bullets; i++)
        {
            window.draw(lev[level_index].Bullets[i]);
        }
    }


    else if (num == 10) // ==> constructing level 11
    {

        window.draw(lev[10].bg);
        
        // Calculate the positions of the blocks and targets using a loop
        for (int i = 1; i <= 3; i++) {
            float x = radius * cos(angle + (i - 1) * 90);
            float y = radius * sin(angle + (i - 1) * 90);
            lev[10].block[i].setPosition(860 + x, 540 + y);
            character_set_position(lev[10].target[i - 1], Vector2f(890 + x, 390 + y));
        }

        // Increment the angle
        angle += speed;

        // Draw the blocks and characters using loops
        for (int i = 0; i <= 3; i++) {
            window.draw(lev[10].block[i]);
        }

        for (int i = 0; i <= 2; i++) {
            character_draw(lev[10].target[i], window);
        }

        character_draw(lev[10].killer, window);
        for (int i = 0; i < lev[level_index].num_of_bullets; i++)
        {
            window.draw(lev[level_index].Bullets[i]);
        }
        for (int i = 0; i < bullets.size(); i++) {
            bullets[i].bulletBody.setPosition(bullets[i].bulletBody.getPosition() - bullets[i].bulletDirection * bulletSpeed);
        }
       
    }


    else if (num == 11) // ==> constructing level 12
    {
        // Loop through each block

        
        for (int i = 0; i < 4; i++) {

            // Move blocks according to their direction
            if (i < 2) {

                if (blockDirection[i] == 0) { // move right

                    Vector2f pos = lev[11].block[i].getPosition();
                    pos.x += (blockSpeed * 2);
                    lev[11].block[i].setPosition(pos);
                    if (pos.x > 1700) {
                        blockDirection[i] = 1; // change direction to down
                    }
                }

                else if (blockDirection[i] == 1) { // move down

                    Vector2f pos = lev[11].block[i].getPosition();
                    pos.y += (blockSpeed * 2);
                    lev[11].block[i].setPosition(pos);
                    if (pos.y > 970) {
                        blockDirection[i] = 2; // change direction to left
                    }
                }

                else if (blockDirection[i] == 2) { // move left
                    Vector2f pos = lev[11].block[i].getPosition();
                    pos.x -= (blockSpeed * 2);
                    lev[11].block[i].setPosition(pos);
                    if (pos.x < 100) {
                        blockDirection[i] = 3; // change direction to up
                    }
                }

                else if (blockDirection[i] == 3) { // move up
                    Vector2f pos = lev[11].block[i].getPosition();
                    pos.y -= (blockSpeed * 2);
                    lev[11].block[i].setPosition(pos);
                    if (pos.y < 150) {
                        blockDirection[i] = 0; // change direction to right
                    }
                }
            }

            else {
                if (blockDirection[i] == 0) { // move right
                    Vector2f pos = lev[11].block[i].getPosition();
                    pos.x += (blockSpeed * 2);
                    lev[11].block[i].setPosition(pos);
                    if (pos.x > 1500) {
                        blockDirection[i] = 1; // change direction to up
                    }
                }
                else if (blockDirection[i] == 1) { // move up
                    Vector2f pos = lev[11].block[i].getPosition();
                    pos.y -= (blockSpeed * 2);
                    lev[11].block[i].setPosition(pos);
                    if (pos.y < 350) {
                        blockDirection[i] = 2; // change direction to left
                    }
                }
                else if (blockDirection[i] == 2) { // move left
                    Vector2f pos = lev[11].block[i].getPosition();
                    pos.x -= (blockSpeed * 2);
                    lev[11].block[i].setPosition(pos);
                    if (pos.x < 400) {
                        blockDirection[i] = 3; // change direction to down
                    }
                }
                else if (blockDirection[i] == 3) { // move down
                    Vector2f pos = lev[11].block[i].getPosition();
                    pos.y += (blockSpeed * 2);
                    lev[11].block[i].setPosition(pos);
                    if (pos.y > 750) {
                        blockDirection[i] = 0; // change direction to right
                    }
                }
            }

            // Set the position of targets above the blocks
            for (int i = 0; i <= 3; i++) {
                character_set_position(lev[11].target[i], Vector2f(lev[11].block[i].getPosition().x + 20, lev[11].block[i].getPosition().y - 130));
            }
        }


        window.draw(lev[11].bg);
        for (int i = 0; i < 4; i++) {
            window.draw(lev[11].block[i]);
            character_draw(lev[11].target[i], window);
        }
        window.draw(lev[11].block[4]);
        character_draw(lev[11].killer, window);
        for (int i = 0; i < bullets.size(); i++) {
            bullets[i].bulletBody.setPosition(bullets[i].bulletBody.getPosition() - bullets[i].bulletDirection * bulletSpeed);
        }
        for (int i = 0; i < lev[level_index].num_of_bullets; i++)
        {
            window.draw(lev[level_index].Bullets[i]);
        }
    }


    else if (num == 12) // ==> constructing level 13
    {
        window.draw(lev[12].bg);
        float x = radius * cos(angle);
        float y = radius * sin(angle);
        float x2 = radius * cos(angle + 90);
        float y2 = radius * sin(angle + 90);

        

        lev[12].block[1].setPosition(860 + x, 540 + y);
        character_set_position(lev[12].target[0], Vector2f(890 + x, 390 + y));

        lev[12].block[2].setPosition(860 + x2, 540 + y2);
        character_set_position(lev[12].target[1], Vector2f(890 + x2, 390 + y2));


        angle += speed;
        for (int i = 0; i <= 4; i++) {
            window.draw(lev[12].block[i]);

        }
        for (int i = 0; i <= 3; i++) {
            character_draw(lev[12].target[i], window);

        }

        character_draw(lev[12].killer, window);
        for (int i = 0; i < bullets.size(); i++) {
            bullets[i].bulletBody.setPosition(bullets[i].bulletBody.getPosition() - bullets[i].bulletDirection * bulletSpeed);
        }
        for (int i = 0; i < lev[level_index].num_of_bullets; i++)
        {
            window.draw(lev[level_index].Bullets[i]);
        }
    }


    else if (num == 13) // ==> constructing level 14
    {

        lev[13].block[0].move(0.f, blockSpeed);
        if (lev[13].block[0].getPosition().y < 200 || lev[13].block[0].getPosition().y > 800)
        {
            // Reverse the vertical movement direction
            blockSpeed *= -1;
        }
       
        character_set_position(lev[13].target[0], Vector2f(lev[13].block[0].getPosition().x + 20, lev[13].block[0].getPosition().y - 150));
        window.draw(lev[13].bg);
        window.draw(lev[13].ground);
        window.draw(lev[13].shape[0]);
        window.draw(lev[13].shape[1]);
        window.draw(lev[13].block[0]);
        character_draw(lev[13].killer, window);
        character_draw(lev[13].target[0], window);

        for (int i = 0; i < bullets.size(); i++) {
            bullets[i].bulletBody.setPosition(bullets[i].bulletBody.getPosition() - bullets[i].bulletDirection * bulletSpeed);
        }
        for (int i = 0; i < lev[level_index].num_of_bullets; i++)
        {
            window.draw(lev[level_index].Bullets[i]);
        }
    }


    else if (num == 14) // ==> constructing level 15
    {
        // Update the block position
        static int x = 0;
        static int y = 300;
        static int speed = 14;
        static string direction = "down";

       

        if (direction == "down")
        {
            y += speed;
            x += speed;
            if (y >= 900)
            {
                direction = "up";
            }
            else if (x >= 1800)
            {
                direction = "up_reverse";
            }
        }
        else if (direction == "up")
        {
            y -= speed;
            x += speed;
            if (y <= 200)
            {
                direction = "down";
            }
            else if (x >= 1800)
            {
                direction = "down_reverse";
            }
        }
        else if (direction == "up_reverse")
        {
            y -= speed;
            x -= speed;
            if (y <= 200)
            {
                direction = "down_reverse";
            }
            else if (x <= 0)
            {
                direction = "down";
            }
        }
        else if (direction == "down_reverse")
        {
            y += speed;
            x -= speed;
            if (y >= 900)
            {
                direction = "up_reverse";
            }
            else if (x <= 0)
            {
                direction = "up";
            }

            for (int i = 0; i < bullets.size(); i++) {
                bullets[i].bulletBody.setPosition(bullets[i].bulletBody.getPosition() - bullets[i].bulletDirection * bulletSpeed);
            }
            for (int i = 0; i < lev[level_index].num_of_bullets; i++)
            {
                window.draw(lev[level_index].Bullets[i]);
            }
        }

        lev[14].block[0].setPosition(x, y);
        character_set_position(lev[14].target[0], Vector2f(lev[14].block[0].getPosition().x + 20, lev[14].block[0].getPosition().y - 150));
        window.draw(lev[14].bg);
        // Draw the block to the window
        window.draw(lev[14].block[0]);
        window.draw(lev[14].block[1]);
        character_draw(lev[14].target[0], window);
        character_draw(lev[14].killer, window);
        for (int i = 0; i < bullets.size(); i++) {
            bullets[i].bulletBody.setPosition(bullets[i].bulletBody.getPosition() - bullets[i].bulletDirection * bulletSpeed);
        }
        for (int i = 0; i < lev[level_index].num_of_bullets; i++)
        {
            window.draw(lev[level_index].Bullets[i]);
        }
    }


    else if (num == 16) // ==> one V one level
    {
        static int x1 = 400;
        static int y1 = 220;
        static int x2 = 1400;
        static int y2 = 900;
        static int speed = 10;
        static string direction1 = "down";
        static string direction2 = "up";

        // Move block1
        if (direction1 == "down")
        {
            y1 += speed;
            if (y1 >= 900)
            {
                direction1 = "up";
            }
        }
        else if (direction1 == "up")
        {
            y1 -= speed;
            if (y1 <= 220)
            {
                direction1 = "down";
            }
        }
        lev[16].block[0].setPosition(x1, y1);

        // Move block2
        if (direction2 == "up")
        {
            y2 -= speed;
            if (y2 <= 220)
            {
                direction2 = "down";
            }
        }
        else if (direction2 == "down")
        {
            y2 += speed;
            if (y2 >= 900)
            {
                direction2 = "up";
            }
        }
        lev[16].block[1].setPosition(x2, y2);

        character_set_position(lev[16].killer, Vector2f(lev[16].block[1].getPosition().x + 50, lev[16].block[1].getPosition().y - 200));
        character_set_position(lev[16].target[0], Vector2f(lev[16].block[0].getPosition().x + 20, lev[16].block[0].getPosition().y - 200));
        // Draw the blocks and background to the window
        window.draw(lev[16].bg);
        for (int i = 0; i < 4; i++)
        {
            window.draw(lev[16].block[i]);
        }
        character_draw(lev[16].killer, window);
        character_draw(lev[16].target[0], window);

    }

}