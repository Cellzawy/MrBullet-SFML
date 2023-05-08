#include <SFML/Graphics.hpp>
#include "Sprites.h"
#include "Levels.h"
#include "Physics.h"
#include "Menus.h"

using namespace sf;

int dead_enemies = 0;
int level_index;

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


    lev[1].Bullets[0].setPosition(Vector2f(850, 55));
    lev[1].Bullets[0].setOrigin(lev[1].Bullets[0].getLocalBounds().width / 2, lev[1].Bullets[0].getLocalBounds().height / 2);
    lev[1].Bullets[0].setScale(.25, .25);
    lev[1].Bullets[0].setColor(Color::Black);

    lev[1].Bullets[1].setPosition(Vector2f(900, 55));
    lev[1].Bullets[1].setOrigin(lev[1].Bullets[1].getLocalBounds().width / 2, lev[1].Bullets[1].getLocalBounds().height / 2);
    lev[1].Bullets[1].setScale(.25, .25);
    lev[1].Bullets[1].setColor(Color(240, 150, 25));

    lev[1].Bullets[2].setPosition(Vector2f(950, 55));
    lev[1].Bullets[2].setOrigin(lev[1].Bullets[2].getLocalBounds().width / 2, lev[1].Bullets[2].getLocalBounds().height / 2);
    lev[1].Bullets[2].setScale(.25, .25);
    lev[1].Bullets[2].setColor(Color(240, 150, 25));

    lev[1].Bullets[3].setPosition(Vector2f(1000, 55));
    lev[1].Bullets[3].setOrigin(lev[1].Bullets[3].getLocalBounds().width / 2, lev[1].Bullets[3].getLocalBounds().height / 2);
    lev[1].Bullets[3].setScale(.25, .25);
    lev[1].Bullets[3].setColor(Color(240, 150, 25));

    lev[1].Bullets[4].setPosition(Vector2f(1050, 55));
    lev[1].Bullets[4].setOrigin(lev[1].Bullets[4].getLocalBounds().width / 2, lev[1].Bullets[4].getLocalBounds().height / 2);
    lev[1].Bullets[4].setScale(.25, .25);
    lev[1].Bullets[4].setColor(Color(240, 150, 25));

    lev[1].Return_num = 5;
    lev[1].num_of_bullets = 5;
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

void constructlev5(RenderWindow& window)
{
    // Background
    lev[4].BG.loadFromFile("assets/Textures/background_city.png");
    lev[4].bg.setTexture(lev[4].BG);
    lev[4].bg.setScale(4, 1.2);

    // ground
    lev[4].GROUND[0].loadFromFile("assets/Textures/ground2.png");
    lev[4].ground.setTexture(&lev[4].GROUND[0]);
    lev[4].ground.setSize(Vector2f(window.getSize().x, window.getSize().y));
    lev[4].ground.setOrigin(lev[4].ground.getSize().x / 2, lev[4].ground.getSize().y / 2);
    lev[4].ground.setPosition(window.getSize().x / 2, window.getSize().y / 1.85);

    // blocks
    lev[4].BLOCK[0].loadFromFile("assets/Textures/rect2.png");
    lev[4].block[0].setTexture(&lev[4].BLOCK[0]);
    lev[4].block[0].setSize(Vector2f(200, 380));
    lev[4].block[0].setOrigin(lev[4].block[0].getSize().x / 2, lev[4].block[0].getSize().y / 2);
    lev[4].block[0].setPosition(lev[4].ground.getSize().x / 2 + 540, lev[4].ground.getSize().y - 853);

    //killer
    character_init(lev[4].killer, "assets/Characters/Killer/killer_head.png", "assets/Characters/blue_suit_body.png", false);
    character_set_scale(lev[4].killer, 0.4);
    character_set_position(lev[4].killer, Vector2f(lev[4].ground.getSize().x / 8, lev[4].ground.getPosition().y + 30));

    //targets
    for (int i = 0; i < 2; i++)
    {
        character_init(lev[4].target[i], "assets/Characters/gangster_head.png", "assets/Characters/black_suit_body.png", true);
        character_set_scale(lev[4].target[i], 0.35);
        character_set_position(lev[4].target[i], Vector2f(lev[4].ground.getPosition().x + (i * 250), lev[4].ground.getPosition().y + 50));
    }


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
            bullets[i].bulletBody.setPosition(bullets[i].bulletBody.getPosition() - bullets[i].bulletDirection * 20.f);
        }
        for (int i = 0; i < bullets.size(); i++) {
            window.draw(bullets[i].bulletBody);
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
            bullets[i].bulletBody.setPosition(bullets[i].bulletBody.getPosition() - bullets[i].bulletDirection * 20.f);
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

        for (int i = 0; i < lev[level_index].num_of_bullets; i++)
        {
            window.draw(lev[level_index].Bullets[i]);
        }

        for (int i = 0; i < bullets.size(); i++) {
            bullets[i].bulletBody.setPosition(bullets[i].bulletBody.getPosition() - bullets[i].bulletDirection * 20.f);
        }
        character_draw(lev[2].target[0], window);
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
            bullets[i].bulletBody.setPosition(bullets[i].bulletBody.getPosition() - bullets[i].bulletDirection * 20.f);
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


    else if (num == 4) // ==> constructing Level 5
    {
        window.draw(lev[4].bg);
        window.draw(lev[4].ground);
        window.draw(lev[4].block[0]);
         for (int i = 0; i < lev[level_index].num_of_bullets; i++)
        {
            window.draw(lev[level_index].Bullets[i]);
        }

        character_draw(lev[4].killer, window);
        for (int i = 0; i < 2; i++)
        {
            character_draw(lev[4].target[i], window);
        }
        for (int i = 0; i < bullets.size(); i++) {
            bullets[i].bulletBody.setPosition(bullets[i].bulletBody.getPosition() - bullets[i].bulletDirection * 20.f);
        }
        for (int i = 0; i < bullets.size(); i++) {
            window.draw(bullets[i].bulletBody);
        }

        for (int i = 0; i < bullets.size(); i++) {
            HandlePhysics(lev[4], bullets[i]);
        }
        for (int i = 0; i < bullets.size(); i++) {
            CollideEnemies(lev[4], bullets[i]);
        }

        levels_background();
    }
}
