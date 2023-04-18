#include <SFML/Graphics.hpp>
#include "Sprites.h"
#include "Levels.h"

using namespace sf;

level lev1, lev2, lev3, lev4, lev5;

void constructlev1(RenderWindow& window)
{
	// background
	lev1.BG.loadFromFile("assets/Backgrounds/background_city.png");
	lev1.bg.setTexture(lev1.BG);
	lev1.bg.setScale(4, 1.2);

	// Rectangular ground
	lev1.FLOOR[0].loadFromFile("assets/Textures/ground.png");
	lev1.ground.setTexture(&lev1.FLOOR[0]);
	lev1.ground.setSize(Vector2f(window.getSize().x, window.getSize().y / 4));
	lev1.ground.setOrigin(lev1.ground.getLocalBounds().width / 2, lev1.ground.getLocalBounds().height / 2);
	lev1.ground.setPosition(window.getSize().x /2.0, window.getSize().y);

	// Charachters
    
    //killer
    character_init(lev1.killer, "assets/Characters/Killer/killer_head.png", "assets/Characters/blue_suit_body.png", false);
    character_set_scale(lev1.killer, 0.4);
    character_set_position(lev1.killer, Vector2f(200, lev1.ground.getPosition().y - (lev1.ground.getLocalBounds().height)*1.41));

    //enemy
    character_init(lev1.target[0], "assets/Characters/gangster_head.png", "assets/Characters/punk_body.png", true);
    character_set_scale(lev1.target[0], 0.4);
    character_set_position(lev1.target[0], Vector2f(1720, lev1.ground.getPosition().y - (lev1.ground.getLocalBounds().height) * 1.4));
}

void constructlev2(RenderWindow& window)
{
    // background
    lev2.BG.loadFromFile("assets/Backgrounds/background_city.png");
    lev2.bg.setTexture(lev2.BG);
    lev2.bg.setScale(4, 1.2);

    // Blocks
    for (int i = 0; i < 9; i++)
    {
        lev2.BLOCK[i].loadFromFile("assets/Textures/block.png");
        lev2.blocks[i].setTexture(&lev2.BLOCK[i]);
        if (i == 0)
        {
            lev2.blocks[i].setSize(Vector2f(130, 130));
        }
        else
        {
            lev2.blocks[i].setSize(Vector2f(100, 100));
        }
        lev2.blocks[i].setOrigin(lev2.blocks[i].getLocalBounds().width / 2, lev2.blocks[i].getLocalBounds().height / 2);
    }

    // set positions for BLlocks
    lev2.blocks[0].setPosition(window.getSize().x / static_cast<float>(2), window.getSize().y / static_cast<float>(2) + 150);
    lev2.blocks[1].setPosition(lev2.blocks[0].getPosition().x + 400, lev2.blocks[0].getPosition().y + 250);
    lev2.blocks[2].setPosition(lev2.blocks[1].getPosition().x + 150, lev2.blocks[1].getPosition().y + 100);
    lev2.blocks[3].setPosition(lev2.blocks[0].getPosition().x - 400, lev2.blocks[0].getPosition().y + 250);
    lev2.blocks[4].setPosition(lev2.blocks[3].getPosition().x - 150, lev2.blocks[3].getPosition().y + 100);
    lev2.blocks[5].setPosition(lev2.blocks[0].getPosition().x - 400, lev2.blocks[0].getPosition().y - 250);
    lev2.blocks[6].setPosition(lev2.blocks[5].getPosition().x - 150, lev2.blocks[5].getPosition().y - 100);
    lev2.blocks[7].setPosition(lev2.blocks[0].getPosition().x + 400, lev2.blocks[0].getPosition().y - 250);
    lev2.blocks[8].setPosition(lev2.blocks[7].getPosition().x + 150, lev2.blocks[7].getPosition().y - 100);

    //Characters

    //killer
    character_init(lev2.killer, "assets/Characters/Killer/killer_head.png", "assets/Characters/blue_suit_body.png", false);
    character_set_scale(lev2.killer, 0.4);
    character_set_position(lev2.killer, Vector2f(lev2.blocks[0].getPosition().x - 50, lev2.blocks[0].getPosition().y - 300));

    //Targets
    for (int i = 0; i < 8; i++)
    {
        character_init(lev2.target[i], "assets/Characters/gangster_head.png", "assets/Characters/punk_body.png", false);
        character_set_scale(lev2.target[i], 0.4);
        character_set_position(lev2.target[i], Vector2f(lev2.blocks[i + 1].getPosition().x - 50, lev2.blocks[i + 1].getPosition().y - 295));
    }
}

void constructlev3(RenderWindow& window)
{
    // lev3.bg, lev3.killer, lev3.target[0], lev3.ground, lev3.shape1, lev3.shape2, 
    // Sprite& a3, Character& killer3, Character& target3, RectangleShape& ground, RectangleShape& sh1, RectangleShape& sh2, 
    //backround
    lev3.BG.loadFromFile("assets/Backgrounds/background_city.png");
    lev3.bg.setTexture(lev3.BG);
    lev3.bg.setScale(4, 1.2);

    //ground
    lev3.FLOOR[0].loadFromFile("assets/Textures/ground.png");
    lev3.ground.setTexture(&lev3.FLOOR[0]);
    lev3.ground.setSize(Vector2f(window.getSize().x, window.getSize().y / 4));
    lev3.ground.setOrigin(lev3.ground.getLocalBounds().width / 2, lev3.ground.getLocalBounds().height / 2);
    lev3.ground.setPosition(window.getSize().x / 2.0, window.getSize().y);

    //shape1
    lev3.SHAPES[0].loadFromFile("assets/Textures/rectangle1.png");
    lev3.shape1.setTexture(&lev3.SHAPES[0]);
    lev3.shape1.setSize(Vector2f(450,80));
    lev3.shape1.setOrigin(lev3.shape1.getLocalBounds().width / 2, lev3.shape1.getLocalBounds().height / 2);
    lev3.shape1.setPosition(window.getSize().x - lev3.shape1.getSize().x/2, 350);

    //shape2
    lev3.SHAPES[1].loadFromFile("assets/Textures/rectangle2.png");
    lev3.shape2.setTexture(&lev3.SHAPES[1]);
    lev3.shape2.setSize(Vector2f(200, 400));
    //lev3.shape2.setOrigin(lev3.shape2.getLocalBounds().width / 2, lev3.shape2.getLocalBounds().height / 2);
    lev3.shape2.setPosition(0, 400);

    //killer
    character_init(lev3.killer, "assets/Characters/Killer/killer_head.png", "assets/Characters/blue_suit_body.png", true);
    character_set_scale(lev3.killer, 0.34);
    character_set_position(lev3.killer, Vector2f(window.getSize().x-200, lev3.ground.getPosition().y - (lev3.ground.getLocalBounds().height) * 1.3));

    //enemy
    character_init(lev3.target[0], "assets/Characters/gangster_head.png", "assets/Characters/punk_body.png", true);
    character_set_scale(lev3.target[0], 0.34);
    character_set_position(lev3.target[0], Vector2f(lev3.shape1.getPosition().x - (lev3.shape1.getSize().x / 2), lev3.shape1.getPosition().y-235));
}

void constructlev4(RenderWindow& window)
{
    // Sprite& a4, Character& killer4, Character target[3], RectangleShape& area, 
    // lev4.bg, lev4.killer, lev4.target, lev4.shape1, 
    //background
    lev4.BG.loadFromFile("assets/Backgrounds/background_city.png");
    lev4.bg.setTexture(lev4.BG);
    lev4.bg.setScale(4, 1.2);

    //rectangle area
    lev4.SHAPES[0].loadFromFile("assets/Textures/box.png");
    lev4.shape1.setTexture(&lev4.SHAPES[0]);
    lev4.shape1.setSize(Vector2f(1000, 1200));
    lev4.shape1.setOrigin(lev4.shape1.getSize().x / 2, lev4.shape1.getSize().y / 2);
    lev4.shape1.setPosition(window.getSize().x / 2, window.getSize().y / 2 + 75);

    //killer
    character_init(lev4.killer, "assets/Characters/Killer/killer_head.png", "assets/Characters/blue_suit_body.png", false);
    character_set_scale(lev4.killer, 0.3);
    character_set_position(lev4.killer, Vector2f(lev4.shape1.getPosition().x-300, lev4.shape1.getPosition().y+160));

    //targets
    character_init(lev4.target[0], "assets/Characters/gangster_head.png", "assets/Characters/punk_body.png", true);
    character_set_scale(lev4.target[0], 0.3);
    character_set_position(lev4.target[0], Vector2f(lev4.shape1.getPosition().x + 250, lev4.shape1.getPosition().y + 160));

    character_init(lev4.target[1], "assets/Characters/gangster_head.png", "assets/Characters/punk_body.png", false);
    character_set_scale(lev4.target[1], 0.3);
    character_set_position(lev4.target[1], Vector2f(lev4.shape1.getPosition().x - 300, lev4.shape1.getPosition().y - 390));

    character_init(lev4.target[2], "assets/Characters/gangster_head.png", "assets/Characters/punk_body.png", false);
    character_set_scale(lev4.target[2], 0.3);
    character_set_position(lev4.target[2], Vector2f(lev4.shape1.getPosition().x - 100, lev4.shape1.getPosition().y -390));
}
