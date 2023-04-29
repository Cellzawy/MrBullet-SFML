#include <SFML/Graphics.hpp>
#include "Sprites.h"
#include "Levels.h"

using namespace sf;

level lev[10];

void constructlev1(RenderWindow& window)
{
    // background
    lev[1].BG.loadFromFile("assets/Backgrounds/background_city.png");
    lev[1].bg.setTexture(lev[1].BG);
    lev[1].bg.setScale(4, 1.2);

    // Rectangular ground
    lev[1].GROUND[0].loadFromFile("assets/Textures/ground.png");
    lev[1].ground.setTexture(&lev[1].GROUND[0]);
    lev[1].ground.setSize(Vector2f(window.getSize().x, window.getSize().y / 4));
    lev[1].ground.setOrigin(lev[1].ground.getLocalBounds().width / 2, lev[1].ground.getLocalBounds().height / 2);
    lev[1].ground.setPosition(window.getSize().x / 2.0, window.getSize().y);

    // Charachters

    //killer
    character_init(lev[1].killer, "assets/Characters/Killer/killer_head.png", "assets/Characters/blue_suit_body.png", false);
    character_set_scale(lev[1].killer, 0.4);
    character_set_position(lev[1].killer, Vector2f(200, lev[1].ground.getPosition().y - (lev[1].ground.getLocalBounds().height) * 1.41));

    //enemy
    character_init(lev[1].target[0], "assets/Characters/gangster_head.png", "assets/Characters/black_suit_body.png", true);
    character_set_scale(lev[1].target[0], 0.4);
    character_set_position(lev[1].target[0], Vector2f(1720, lev[1].ground.getPosition().y - (lev[1].ground.getLocalBounds().height) * 1.4));
}

void constructlev2(RenderWindow& window)
{
    // background
    lev[2].BG.loadFromFile("assets/Backgrounds/background_city.png");
    lev[2].bg.setTexture(lev[2].BG);
    lev[2].bg.setScale(4, 1.2);

    // Blocks
    for (int i = 0; i < 9; i++)
    {
        lev[2].BLOCK[i].loadFromFile("assets/Textures/block.png");
        lev[2].block[i].setTexture(&lev[2].BLOCK[i]);
        if (i == 0)
        {
            lev[2].block[i].setSize(Vector2f(130, 130));
        }
        else
        {
            lev[2].block[i].setSize(Vector2f(100, 100));
        }
        lev[2].block[i].setOrigin(lev[2].block[i].getLocalBounds().width / 2, lev[2].block[i].getLocalBounds().height / 2);
    }

    // set positions for BLlocks
    lev[2].block[0].setPosition(window.getSize().x / static_cast<float>(2), window.getSize().y / static_cast<float>(2) + 150);
    lev[2].block[1].setPosition(lev[2].block[0].getPosition().x + 400, lev[2].block[0].getPosition().y + 250);
    lev[2].block[2].setPosition(lev[2].block[1].getPosition().x + 150, lev[2].block[1].getPosition().y + 100);
    lev[2].block[3].setPosition(lev[2].block[0].getPosition().x - 400, lev[2].block[0].getPosition().y + 250);
    lev[2].block[4].setPosition(lev[2].block[3].getPosition().x - 150, lev[2].block[3].getPosition().y + 100);
    lev[2].block[5].setPosition(lev[2].block[0].getPosition().x - 400, lev[2].block[0].getPosition().y - 250);
    lev[2].block[6].setPosition(lev[2].block[5].getPosition().x - 150, lev[2].block[5].getPosition().y - 100);
    lev[2].block[7].setPosition(lev[2].block[0].getPosition().x + 400, lev[2].block[0].getPosition().y - 250);
    lev[2].block[8].setPosition(lev[2].block[7].getPosition().x + 150, lev[2].block[7].getPosition().y - 100);

    //Characters

    //killer
    character_init(lev[2].killer, "assets/Characters/Killer/killer_head.png", "assets/Characters/blue_suit_body.png", false);
    character_set_scale(lev[2].killer, 0.4);
    character_set_position(lev[2].killer, Vector2f(lev[2].block[0].getPosition().x - 50, lev[2].block[0].getPosition().y - 300));

    //Targets
    for (int i = 0; i < 8; i++)
    {
        character_init(lev[2].target[i], "assets/Characters/gangster_head.png", "assets/Characters/black_suit_body.png", false);
        character_set_scale(lev[2].target[i], 0.4);
        character_set_position(lev[2].target[i], Vector2f(lev[2].block[i + 1].getPosition().x - 50, lev[2].block[i + 1].getPosition().y - 295));
    }
}

void constructlev3(RenderWindow& window)
{
    //backround
    lev[3].BG.loadFromFile("assets/Backgrounds/background_city.png");
    lev[3].bg.setTexture(lev[3].BG);
    lev[3].bg.setScale(4, 1.2);

    //ground
    lev[3].GROUND[0].loadFromFile("assets/Textures/ground.png");
    lev[3].ground.setTexture(&lev[3].GROUND[0]);
    lev[3].ground.setSize(Vector2f(window.getSize().x, window.getSize().y / 4));
    lev[3].ground.setOrigin(lev[3].ground.getLocalBounds().width / 2, lev[3].ground.getLocalBounds().height / 2);
    lev[3].ground.setPosition(window.getSize().x / 2.0, window.getSize().y);

    //shape1
    lev[3].SHAPES[0].loadFromFile("assets/Textures/rectangle1.png");
    lev[3].shape[0].setTexture(&lev[3].SHAPES[0]);
    lev[3].shape[0].setSize(Vector2f(450, 80));
    lev[3].shape[0].setOrigin(lev[3].shape[0].getLocalBounds().width / 2, lev[3].shape[0].getLocalBounds().height / 2);
    lev[3].shape[0].setPosition(window.getSize().x - lev[3].shape[1].getSize().x / 2, 350);

    //shape2
    lev[3].SHAPES[1].loadFromFile("assets/Textures/rectangle2.png");
    lev[3].shape[1].setTexture(&lev[3].SHAPES[1]);
    lev[3].shape[1].setSize(Vector2f(200, 400));
    //lev[3].shape2.setOrigin(lev[3].shape2.getLocalBounds().width / 2, lev[3].shape2.getLocalBounds().height / 2);
    lev[3].shape[1].setPosition(0, 400);

    //killer
    character_init(lev[3].killer, "assets/Characters/Killer/killer_head.png", "assets/Characters/blue_suit_body.png", true);
    character_set_scale(lev[3].killer, 0.34);
    character_set_position(lev[3].killer, Vector2f(window.getSize().x - 200, lev[3].ground.getPosition().y - (lev[3].ground.getLocalBounds().height) * 1.3));

    //enemy
    character_init(lev[3].target[0], "assets/Characters/gangster_head.png", "assets/Characters/black_suit_body.png", true);
    character_set_scale(lev[3].target[0], 0.34);
    character_set_position(lev[3].target[0], Vector2f(lev[3].shape[0].getPosition().x - (lev[3].shape[0].getSize().x / 2), lev[3].shape[0].getPosition().y - 235));
}

void constructlev4(RenderWindow& window)
{
    //background
    lev[4].BG.loadFromFile("assets/Backgrounds/background_city.png");
    lev[4].bg.setTexture(lev[4].BG);
    lev[4].bg.setScale(4, 1.2);

    //rectangle area
    lev[4].SHAPES[0].loadFromFile("assets/Textures/box.png");
    lev[4].shape[0].setTexture(&lev[4].SHAPES[0]);
    lev[4].shape[0].setSize(Vector2f(1000, 1200));
    lev[4].shape[0].setOrigin(lev[4].shape[0].getSize().x / 2, lev[4].shape[0].getSize().y / 2);
    lev[4].shape[0].setPosition(window.getSize().x / 2, window.getSize().y / 2 + 75);

    //killer
    character_init(lev[4].killer, "assets/Characters/Killer/killer_head.png", "assets/Characters/blue_suit_body.png", false);
    character_set_scale(lev[4].killer, 0.3);
    character_set_position(lev[4].killer, Vector2f(lev[4].shape[0].getPosition().x - 300, lev[4].shape[0].getPosition().y + 160));

    //targets
    character_init(lev[4].target[0], "assets/Characters/gangster_head.png", "assets/Characters/black_suit_body.png", true);
    character_set_scale(lev[4].target[0], 0.3);
    character_set_position(lev[4].target[0], Vector2f(lev[4].shape[0].getPosition().x + 250, lev[4].shape[0].getPosition().y + 160));

    character_init(lev[4].target[1], "assets/Characters/gangster_head.png", "assets/Characters/black_suit_body.png", false);
    character_set_scale(lev[4].target[1], 0.3);
    character_set_position(lev[4].target[1], Vector2f(lev[4].shape[0].getPosition().x - 300, lev[4].shape[0].getPosition().y - 390));

    character_init(lev[4].target[2], "assets/Characters/gangster_head.png", "assets/Characters/black_suit_body.png", false);
    character_set_scale(lev[4].target[2], 0.3);
    character_set_position(lev[4].target[2], Vector2f(lev[4].shape[0].getPosition().x - 100, lev[4].shape[0].getPosition().y - 390));
}

void constructlev5(RenderWindow& window)
{
    // Background
    lev[5].BG.loadFromFile("assets/Textures/background_city.png");
    lev[5].bg.setTexture(lev[5].BG);
    lev[5].bg.setScale(4, 1.2);

    // ground
    lev[5].GROUND[0].loadFromFile("assets/Textures/ground2.png");
    lev[5].ground.setTexture(&lev[5].GROUND[0]);
    lev[5].ground.setSize(Vector2f(window.getSize().x, window.getSize().y));
    lev[5].ground.setOrigin(lev[5].ground.getSize().x / 2, lev[5].ground.getSize().y / 2);
    lev[5].ground.setPosition(window.getSize().x / 2, window.getSize().y / 1.85);

    // blocks 
    lev[5].BLOCK[0].loadFromFile("assets/Textures/rect2.png");
    lev[5].block[0].setTexture(&lev[5].BLOCK[0]);
    lev[5].block[0].setSize(Vector2f(200, 380));
    lev[5].block[0].setOrigin(lev[5].block[0].getSize().x / 2, lev[5].block[0].getSize().y / 2);
    lev[5].block[0].setPosition(lev[5].ground.getSize().x / 2 + 540, lev[5].ground.getSize().y - 853);

    //killer
    character_init(lev[5].killer, "assets/Characters/Killer/killer_head.png", "assets/Characters/blue_suit_body.png", false);
    character_set_scale(lev[5].killer, 0.4);
    character_set_position(lev[5].killer, Vector2f(lev[5].ground.getSize().x / 8, lev[5].ground.getPosition().y + 30));

    //targets
    for (int i = 0; i < 2; i++)
    {
        character_init(lev[5].target[i], "assets/Characters/gangster_head.png", "assets/Characters/black_suit_body.png", true);
        character_set_scale(lev[5].target[i], 0.35);
        character_set_position(lev[5].target[i], Vector2f(lev[5].ground.getPosition().x + (i * 250), lev[5].ground.getPosition().y + 50));
    }


}


void DrawingLevels(int num, RenderWindow& window)
{
    if (num == 1) // ==> constructing level 1
    {

        constructlev1(window);
        window.draw(lev[1].bg);
        window.draw(lev[1].ground);
        character_draw(lev[1].killer, window);
        character_draw(lev[1].target[0], window);


    }


    else if (num == 2) // ==> constructing level 2
    {
        constructlev2(window);
        window.draw(lev[2].bg);
        for (int i = 0; i < 10; i++)
        {
            window.draw(lev[2].block[i]);
        }
        character_draw(lev[2].killer, window);
        for (int i = 0; i < 8; i++)
        {
            character_draw(lev[2].target[i], window);
        }
    }


    else if (num == 3) // ==> constructing level 3
    {
        constructlev3(window);
        window.draw(lev[3].bg);
        window.draw(lev[3].ground);
        window.draw(lev[3].shape[0]);
        window.draw(lev[3].shape[1]);
        character_draw(lev[3].killer, window);
        character_draw(lev[3].target[0], window);
    }


    else if (num == 4)   // ==> constructing level 4
    {
        constructlev4(window);
        window.draw(lev[4].bg);
        window.draw(lev[4].shape[0]);
        character_draw(lev[4].killer, window);
        for (int i = 0; i < 3; i++)
        {
            character_draw(lev[4].target[i], window);
        }

    }


    else if (num == 5) // ==> constructing level 5
    {
        constructlev5(window);
        window.draw(lev[5].bg);
        window.draw(lev[5].ground);
        window.draw(lev[5].block[0]);

        character_draw(lev[5].killer, window);
        for (int i = 0; i < 2; i++)
        {
            character_draw(lev[5].target[i], window);
        }
    }

    else if (num == 11)
    {
        constructlev11(window);
        window.draw(lev[11].bg);
    }

}