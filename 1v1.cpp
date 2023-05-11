#include<iostream>
#include<SFML/Graphics.hpp>
#include "Sprites.h"
#include "Physics.h"
#include "Levels.h"
#include "Menus.h"
#include "Events.h"
#include "win-lose-logic.h"


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
    character_set_position(playerOne, Vector2f(200.0f, lev[0].ground.getPosition().y - (lev[0].ground.getLocalBounds().height) * 1.41));
    character_draw(playerOne, window);

    character_set_scale(playerTwo, 0.4);
    character_set_position(playerTwo, Vector2f(1800.0f, lev[0].ground.getPosition().y - (lev[0].ground.getLocalBounds().height) * 1.41));
    character_draw(playerTwo, window);
    
}

void collision (Bullet& b, Character& shotPlayer)
{
    if (b.bulletBody.getGlobalBounds().intersects(shotPlayer.body.getGlobalBounds())) {
        shotPlayer.health -= 30;
        collided = false;
        if (shotPlayer.health <= 0) 
        {
            shotPlayer.health = 0;
            shotPlayer.dead = true;
            shotPlayer.alive = false;
        }
        //Death Animation                                                   /* helmy */
    }
    else if (b.bulletBody.getGlobalBounds().intersects(shotPlayer.head.getGlobalBounds())) {
        shotPlayer.health -= 30;
        collided = false;
        if (shotPlayer.health <= 0)
        {
            shotPlayer.health = 0;
            shotPlayer.dead = true;
            shotPlayer.alive = false;
        }
        //Death Animation                                                   /* helmy */
    }
    else if (b.bulletBody.getGlobalBounds().intersects(shotPlayer.left_arm1.getGlobalBounds())) {
        shotPlayer.health -= 30;
        collided = false;
        if (shotPlayer.health <= 0)
        {
            shotPlayer.health = 0;
            shotPlayer.dead = true;
            shotPlayer.alive = false;
        }
        //Death Animation                                                   /* helmy */
    }
    else if (b.bulletBody.getGlobalBounds().intersects(shotPlayer.left_arm2.getGlobalBounds())) {
        shotPlayer.health -= 30;
        collided = false;
        if (shotPlayer.health <= 0)
        {
            shotPlayer.health = 0;
            shotPlayer.dead = true;
            shotPlayer.alive = false;
        }
        //Death Animation                                                   /* helmy */
    }
    else if (b.bulletBody.getGlobalBounds().intersects(shotPlayer.right_arm1.getGlobalBounds())) {
        shotPlayer.health -= 30;
        collided = false;
        if (shotPlayer.health <= 0)
        {
            shotPlayer.health = 0;
            shotPlayer.dead = true;
            shotPlayer.alive = false;
        }
        //Death Animation                                                   /* helmy */
    }
    else if (b.bulletBody.getGlobalBounds().intersects(shotPlayer.right_arm2.getGlobalBounds())) {
        shotPlayer.health -= 30;
        collided = false;
        if (shotPlayer.health <= 0)
        {
            shotPlayer.health = 0;
            shotPlayer.dead = true;
            shotPlayer.alive = false;
        }
        //Death Animation                                                   /* helmy */
    }
    else if (b.bulletBody.getGlobalBounds().intersects(shotPlayer.left_leg1.getGlobalBounds())) {
        shotPlayer.health -= 30;
        collided = false;
        if (shotPlayer.health <= 0)
        {
            shotPlayer.health = 0;
            shotPlayer.dead = true;
            shotPlayer.alive = false;
        }
        //Death Animation                                                   /* helmy */
    }
    else if (b.bulletBody.getGlobalBounds().intersects(shotPlayer.left_leg2.getGlobalBounds())) {
        shotPlayer.health -= 30;
        collided = false;
        if (shotPlayer.health <= 0)
        {
            shotPlayer.health = 0;
            shotPlayer.dead = true;
            shotPlayer.alive = false;
        }
        //Death Animation                                                   /* helmy */
    }
    else if (b.bulletBody.getGlobalBounds().intersects(shotPlayer.right_leg1.getGlobalBounds())) {
        shotPlayer.health -= 30;
        collided = false;
        if (shotPlayer.health <= 0)
        {
            shotPlayer.health = 0;
            shotPlayer.dead = true;
            shotPlayer.alive = false;
        }
        //Death Animation                                                   /* helmy */
    }
    else  if (b.bulletBody.getGlobalBounds().intersects(shotPlayer.right_leg2.getGlobalBounds())) {
        shotPlayer.health -= 30;
        collided = false;
        if (shotPlayer.health <= 0)
        {
            shotPlayer.health = 0;
            shotPlayer.dead = true;
           shotPlayer.alive = false;
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
    character_set_position(playerOne, Vector2f(200.0f, lev[0].ground.getPosition().y - (lev[0].ground.getLocalBounds().height) * 1.41));
    character_draw(playerOne, window);

    character_set_scale(playerTwo, 0.4);
    character_set_position(playerTwo, Vector2f(1800.0f, lev[0].ground.getPosition().y - (lev[0].ground.getLocalBounds().height) * 1.41));
    character_draw(playerTwo, window);




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