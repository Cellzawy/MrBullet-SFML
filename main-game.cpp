#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "Sprites.h"
#include "Physics.h"
#include "Levels.h"
#include "1v1.h"
#include "Menus.h"
#include "Events.h"
#include "Sounds.h"
#include "1v1.h"
//#include "Levels.cpp"
#include "win-lose-logic.h"

sf::RenderWindow window(sf::VideoMode(1920, 1080), "Mr bullet", sf::Style::Fullscreen);
bool in_level;
bool shot;
int currentLvl = 0;


// Menus test
int main() {
    sprites();
    BufferSounds();
    SetSounds();
    window.setFramerateLimit(60);
    crosshairTx.loadFromFile("assets/Textures/crosshair.png");

    Texture_loading();
    SFX_click.setBuffer(SFX_click_soundbuffer);
    shoot.setBuffer(shoot_soundbuffer);
    Restart_sound.setBuffer(Restart_soundbuffer);

    mainmenu_music.openFromFile("assets/sounds/main_music.ogg");
    mainmenu_music.setVolume(volume_value[0]);
    mainmenu_music.play();
    mainmenu_music.setLoop(true);
    for (int i = 0; i < 15; i++) {
        lev[i].killer.has_gun = true;
    }
    constructlev1(window);
    constructlev2(window);
    constructlev3(window);
    constructlev4(window);
    constructlev5(window);
    constructlev11(window);
    constructlev12(window);
    constructlev13(window);
    constructlev14(window);
    constructlev15(window);
    constructOneVSone(window);
    //constructlev6(window);
    //constructlev7(window);
    //constructlev8(window);
    //constructlev9(window);
    //constructlev10(window);
    //constructlev11(window);
    //constructlev12(window);
    //constructlev13(window);
    //constructlev14(window);
    //constructlev15(window);
    //constructlev6(window);
    //constructlev7(window);
    //constructlev8(window);
    bool level_complete = false;
    int currentLvl;
    bool drawLine = true;
    character_init(playerOne, "assets/Characters/Killer/killer_head.png", "assets/Characters/blue_suit_body.png", false);
    character_init(playerTwo, "assets/Characters/Killer/killer_head.png", "assets/Characters/blue_suit_body.png", true);

    while (window.isOpen())
    {
        sf::Vector2i mouse_position = sf::Mouse::getPosition(window);

        line[0].position = lev[level_index].killer.bullet_pos;
        line[1].position = sf::Vector2f(mouse_position.x, mouse_position.y);

        //gunPos = lev[level_index].killer.bullet_pos;
        if (current_menu >= static_cast<menu_type>(0) && current_menu <= static_cast<menu_type>(14) || current_menu == Duels)
        {
            if (bullets.size() != 0)
            {
                //if (current_menu == Duels)
                //{
                //    lev[level_index].num_of_bullets = 1;
                //}
                if (playerOne.turn) {
                    line[0].position = playerOne.bullet_pos;
                    line[1].position = sf::Vector2f(mouse_position.x, mouse_position.y);
                }
                else {
                    line[0].position = playerTwo.bullet_pos;
                    line[1].position = sf::Vector2f(mouse_position.x, mouse_position.y);
                }
                for (int i = bullets.size() - 1; i > 0; i--)
                {
                    Time elapsed = bullets[i].clock.getElapsedTime();
                    level_complete = false;
                    if (elapsed >= seconds(5.f))
                    {
                        bullets[i].clock.restart();
                        bullets.erase(bullets.begin() + i);
                        std::cout << "erased";

                        level_complete = true;
                        if (current_menu == Duels)
                        {
                            playerOne.turn = !playerOne.turn;
                            shot = false;
                            collided = true;
                        }
                    }
                }
            }

            for (int i = 0; i < bullets.size(); i++) {
                //bullets[i].bulletBody.setPosition(bullets[i].bulletBody.getPosition() - bullets[i].bulletDirection * 20.f);
                bullets[i].b.setPosition(bullets[i].bulletBody.getPosition());

            }
        }

        // drawing

        window.clear();

        if (current_menu == main_menu)
        {
            in_level = false;
            Main_menu();

        }

        else if (current_menu == play_menu)
        {
            in_level = false;
            Play_menu();
            lev[level_index].num_of_bullets = 1;

        }


        else if (current_menu == options_menu)
        {
            in_level = false;
            Options_menu();
        }

        else if (current_menu == pause_MENU)
        {
            in_level = false;
            PAUSE_MENU();
        }

        else if (current_menu == OPTIONS_MENU_PAUSE)
        {
            in_level = false;
            Options_menu_Pause();
        }

        else if (current_menu == classic_Mode)
        {
            in_level = false;
            Classic_menu();
        }

        else if (current_menu == achievements_menu)
        {
            in_level = false;
            Achievements_menu();
        }

        else if (current_menu == won_panel)
        {
            for (int i = bullets.size() - 1; i >= 0; i--)
            {
                bullets[i].clock.restart();
                bullets.erase(bullets.begin() + i);
                std::cout << "erased";

                level_complete = true;

            }
            Win_panel(lev[level_index].view.Level_evaluation);
        }

        else if (current_menu == lost_panel)
        {
            Lose_panel(currentLvl);
        }


        else if (current_menu == level_1)
        {
            drawLine = true;
            character_rotate_arm(lev[0].killer, sf::Mouse::getPosition());
            int enemies_num = 1;
            levels_eventloop(enemies_num);
            if (current_menu >= static_cast<menu_type>(0) && current_menu <= static_cast<menu_type>(4))
            {
                DrawingLevels(0, window);
                in_level = true;
                currentLvl = 0;

                for (int i = 0; i < bullets.size(); i++) {
                    HandlePhysics(lev[0], bullets[i]);
                }
                for (int i = 0; i < bullets.size(); i++) {
                    CollideEnemies(lev[0], bullets[i]);
                }




                for (int i = 0; i < enemies_num; i++)
                {
                    if (lev[level_index].target[i].alive && lev[level_index].target[i].dead)
                    {
                        dead_enemies++;
                        lev[level_index].target[i].alive = false;
                    }
                }




                if (dead_enemies == enemies_num)
                {
                    lev[0].is_finished = true;
                    achievements[0].is_open = true;
                    Achievements_checking();
                    stars_system(3, 2, 1, 0);
                    current_menu = won_panel;
                    drawLine = false;

                }

                else if (lev[level_index].num_of_bullets == 0 && level_complete && bullets.size() == 0)  ///32131563
                {
                    current_menu = lost_panel;
                }

            }
        }

        else if (current_menu == level_2)
        {
            drawLine = true;
            int enemies_num = 8;
            levels_eventloop(enemies_num);
            if (current_menu >= static_cast<menu_type>(0) && current_menu <= static_cast<menu_type>(4))
            {
                DrawingLevels(1, window);
                in_level = true;
                currentLvl = 2;

                for (int i = 0; i < bullets.size(); i++) {
                    HandlePhysics(lev[1], bullets[i]);
                }
                for (int i = 0; i < bullets.size(); i++) {
                    CollideEnemies(lev[1], bullets[i]);
                }




                for (int i = 0; i < enemies_num; i++)
                {
                    if (lev[level_index].target[i].alive && lev[level_index].target[i].dead)
                    {
                        dead_enemies++;
                        lev[level_index].target[i].alive = false;
                    }
                }




                if (dead_enemies == enemies_num)
                {
                    stars_system(3, 2, 1, 0);
                    current_menu = won_panel;
                    drawLine = false;

                }

                else if (lev[level_index].num_of_bullets == 0 && level_complete && bullets.size() == 0)  ///32131563
                {
                    current_menu = lost_panel;
                }

            }
        }
        else if (current_menu == level_3)
        {
            drawLine = true;
            int enemies_num = 1;
            levels_eventloop(enemies_num);
            if (current_menu >= static_cast<menu_type>(0) && current_menu <= static_cast<menu_type>(4))
            {
                DrawingLevels(2, window);
                in_level = true;
                currentLvl = 2;

                for (int i = 0; i < bullets.size(); i++) {
                    HandlePhysics(lev[2], bullets[i]);
                }
                for (int i = 0; i < bullets.size(); i++) {
                    CollideEnemies(lev[2], bullets[i]);
                }




                for (int i = 0; i < enemies_num; i++)
                {
                    if (lev[level_index].target[i].alive && lev[level_index].target[i].dead)
                    {
                        dead_enemies++;
                        lev[level_index].target[i].alive = false;
                    }
                }




                if (dead_enemies == enemies_num)
                {
                    stars_system(3, 2, 1, 0);
                    current_menu = won_panel;
                    drawLine = false;

                }

                else if (lev[level_index].num_of_bullets == 0 && level_complete && bullets.size() == 0)  ///32131563
                {
                    current_menu = lost_panel;
                }

            }
        }
        else if (current_menu == level_4)
        {
            drawLine = true;
            int enemies_num = 3;
            levels_eventloop(enemies_num);
            if (current_menu >= static_cast<menu_type>(0) && current_menu <= static_cast<menu_type>(4))
            {
                DrawingLevels(3, window);
                in_level = true;
                currentLvl = 3;

                for (int i = 0; i < bullets.size(); i++) {
                    HandlePhysics(lev[3], bullets[i]);
                }
                for (int i = 0; i < bullets.size(); i++) {
                    CollideEnemies(lev[3], bullets[i]);
                }




                for (int i = 0; i < enemies_num; i++)
                {
                    if (lev[level_index].target[i].alive && lev[level_index].target[i].dead)
                    {
                        dead_enemies++;
                        lev[level_index].target[i].alive = false;
                    }
                }




                if (dead_enemies == enemies_num)
                {
                    stars_system(3, 2, 1, 0);
                    current_menu = won_panel;
                    //for (int i = bullets.size() - 1; i > 0; i--)
                    //{
                    //        bullets[i].clock.restart();
                    //        bullets.erase(bullets.begin() + i);
                    //        std::cout << "erased";

                    //        level_complete = true;
                    //        if (current_menu == Duels)
                    //        {
                    //            playerOne.turn = !playerOne.turn;
                    //            shot = false;
                    //            collided = true;
                    //        }
    
                    //}
                    drawLine = false;
                }

                else if (lev[level_index].num_of_bullets == 0 && level_complete && bullets.size() == 0)  ///32131563
                {
                    current_menu = lost_panel;
                }

            }
        }

        else if (current_menu == level_11)
        {
            drawLine = true;
            int enemies_num = 3;
            character_rotate_arm(lev[10].killer, sf::Mouse::getPosition());

            levels_eventloop(enemies_num);
            if (current_menu >= static_cast<menu_type>(0) && current_menu <= static_cast<menu_type>(4))
            {
                DrawingLevels(10, window);
                in_level = true;
                currentLvl = 11;

                for (int i = 0; i < bullets.size(); i++) {
                    HandlePhysics(lev[10], bullets[i]);
                }
                for (int i = 0; i < bullets.size(); i++) {
                    CollideEnemies(lev[10], bullets[i]);
                }


                for (int i = 0; i < enemies_num; i++)
                {
                    if (lev[level_index].target[i].alive && lev[level_index].target[i].dead)
                    {
                        dead_enemies++;
                        lev[level_index].target[i].alive = false;
                    }
                }




                if (dead_enemies == enemies_num)
                {
                    stars_system(3, 2, 1, 0);
                    current_menu = won_panel;
                    drawLine = false;
                }

                else if (lev[level_index].num_of_bullets == 0 && level_complete && bullets.size() == 0)  ///32131563
                {
                    current_menu = lost_panel;
                }

            }

        }

        else if (current_menu == level_12)
        {
            drawLine = true;
            int enemies_num = 4;
            character_rotate_arm(lev[11].killer, sf::Mouse::getPosition());

            levels_eventloop(enemies_num);
            if (current_menu >= static_cast<menu_type>(0) && current_menu <= static_cast<menu_type>(4))
            {
                DrawingLevels(11, window);
                in_level = true;
                currentLvl = 12;

                for (int i = 0; i < bullets.size(); i++) {
                    HandlePhysics(lev[12], bullets[i]);
                }
                for (int i = 0; i < bullets.size(); i++) {
                    CollideEnemies(lev[12], bullets[i]);
                }


                for (int i = 0; i < enemies_num; i++)
                {
                    if (lev[level_index].target[i].alive && lev[level_index].target[i].dead)
                    {
                        dead_enemies++;
                        lev[level_index].target[i].alive = false;
                    }
                }




                if (dead_enemies == enemies_num)
                {
                    stars_system(3, 2, 1, 0);
                    current_menu = won_panel;
                    drawLine = false;
                }

                else if (lev[level_index].num_of_bullets == 0 && level_complete && bullets.size() == 0)  ///32131563
                {
                    current_menu = lost_panel;
                }

            }

        }

        else if (current_menu == level_13)
        {
            drawLine = true;
            int enemies_num = 4;
            character_rotate_arm(lev[12].killer, sf::Mouse::getPosition());

            levels_eventloop(enemies_num);
            if (current_menu >= static_cast<menu_type>(0) && current_menu <= static_cast<menu_type>(4))
            {
                DrawingLevels(12, window);
                in_level = true;
                currentLvl = 13;

                for (int i = 0; i < bullets.size(); i++) {
                    HandlePhysics(lev[12], bullets[i]);
                }
                for (int i = 0; i < bullets.size(); i++) {
                    CollideEnemies(lev[12], bullets[i]);
                }


                for (int i = 0; i < enemies_num; i++)
                {
                    if (lev[level_index].target[i].alive && lev[level_index].target[i].dead)
                    {
                        dead_enemies++;
                        lev[level_index].target[i].alive = false;
                    }
                }




                if (dead_enemies == enemies_num)
                {
                    stars_system(3, 2, 1, 0);
                    current_menu = won_panel;
                    drawLine = false;
                }

                else if (lev[level_index].num_of_bullets == 0 && level_complete && bullets.size() == 0)  ///32131563
                {
                    current_menu = lost_panel;
                }

            }

        }

        else if (current_menu == level_14)
        {
            drawLine = true;
            int enemies_num = 1;
            character_rotate_arm(lev[13].killer, sf::Mouse::getPosition());

            levels_eventloop(enemies_num);
            if (current_menu >= static_cast<menu_type>(0) && current_menu <= static_cast<menu_type>(4))
            {
                DrawingLevels(13, window);
                in_level = true;
                currentLvl = 14;

                for (int i = 0; i < bullets.size(); i++) {
                    HandlePhysics(lev[13], bullets[i]);
                }
                for (int i = 0; i < bullets.size(); i++) {
                    CollideEnemies(lev[13], bullets[i]);
                }


                for (int i = 0; i < enemies_num; i++)
                {
                    if (lev[level_index].target[i].alive && lev[level_index].target[i].dead)
                    {
                        dead_enemies++;
                        lev[level_index].target[i].alive = false;
                    }
                }




                if (dead_enemies == enemies_num)
                {
                    stars_system(3, 2, 1, 0);
                    current_menu = won_panel;
                    drawLine = false;
                }

                else if (lev[level_index].num_of_bullets == 0 && level_complete && bullets.size() == 0)  ///32131563
                {
                    current_menu = lost_panel;
                }

            }

        }

        else if (current_menu == level_15)
        {
            drawLine = true;
            int enemies_num = 1;
            character_rotate_arm(lev[14].killer, sf::Mouse::getPosition());

            levels_eventloop(enemies_num);
            if (current_menu >= static_cast<menu_type>(0) && current_menu <= static_cast<menu_type>(14))
            {
                DrawingLevels(14, window);
                in_level = true;
                currentLvl = 15;

                for (int i = 0; i < bullets.size(); i++) {
                    HandlePhysics(lev[14], bullets[i]);
                }
                for (int i = 0; i < bullets.size(); i++) {
                    CollideEnemies(lev[14], bullets[i]);
                }


                for (int i = 0; i < enemies_num; i++)
                {
                    if (lev[level_index].target[i].alive && lev[level_index].target[i].dead)
                    {
                        dead_enemies++;
                        lev[level_index].target[i].alive = false;
                    }
                }




                if (dead_enemies == enemies_num)
                {
                    stars_system(3, 2, 1, 0);
                    current_menu = won_panel;
                    drawLine = false;
                }

                else if (lev[level_index].num_of_bullets == 0 && level_complete && bullets.size() == 0)  ///32131563
                {
                    current_menu = lost_panel;
                }

            }

        }


        else if (current_menu == Duels)
        {
            if (bullets.size() == 0) {
                Bullet newBullet;
                newBullet.bulletBody.setFillColor(sf::Color::Black);
                newBullet.bulletBody.setRadius(50.f);
                newBullet.bulletBody.setOrigin(newBullet.bulletBody.getLocalBounds().width / 2, newBullet.bulletBody.getLocalBounds().height / 2);
                newBullet.b.setRadius(10.f);
                newBullet.b.setOrigin(newBullet.b.getLocalBounds().width / 2, newBullet.b.getLocalBounds().height / 2);
                newBullet.b.setPosition(newBullet.bulletBody.getPosition());
                newBullet.b.setFillColor(Color::Black);
                bullets.push_back(newBullet);
            }
            //lev[level_index].num_of_bullets = 1;
            window.draw(Pause_menu_button);
            levels_background();
            if (playerOne.turn)
            {
                character_rotate_arm(playerOne, sf::Mouse::getPosition());
            }
            else {
                character_rotate_arm(playerTwo, sf::Mouse::getPosition());

            }
            for (int i = 0; i < bullets.size(); i++) {
                bullets[i].bulletBody.setPosition(bullets[i].bulletBody.getPosition() - bullets[i].bulletDirection * 25.f);
            }
            DrawingLevels(16, window);
            for (int i = 0; i < bullets.size(); i++) {
                HandlePhysics(lev[16], bullets[i]);
            }
            duels();
            healthBar(playerOne, playerTwo);
            Duels_eventLoop();
            if (playerOne.turn)
            {
                if (collided)
                {
                    collision(bullets[bullets.size() - 1], playerTwo);
                }
            }
            else
            {
                if (collided)
                {
                    collision(bullets[bullets.size() - 1], playerOne);
                }
            }
        }

        if (in_level) {
            //if (lev[level_index + 1].view.Level_evaluation < 0) {
            //    lev[level_index + 1].view.Level_evaluation = 0;
            //}
            character_rotate_arm(lev[level_index].killer, sf::Mouse::getPosition());
            levels_background();
            //if (drawLine)
                //window.draw(line);

        }

        if (current_menu >= static_cast<menu_type>(0) && current_menu <= static_cast<menu_type>(14) || current_menu == Duels)
        {
            for (int i = 0; i < bullets.size(); i++) {
                //window.draw(bullets[i].bulletBody);
                window.draw(bullets[i].b);
            }
        }
        window.display();
    }

	return 0;
}

/*
// Levels test
int main() {
    RenderWindow window(VideoMode(1920, 1080), "Levels");
    int levCounter = 1;

    // GAME loop
    while (window.isOpen())
    {
        Event ev;
        while (window.pollEvent(ev))
        {
            if (ev.type == Event::Closed)
                window.close();
            if (ev.type == Event::KeyPressed) {
                if (ev.key.code == Keyboard::Right) {
                    levCounter++;
                    if (levCounter > 4) {
                        levCounter = 1;
                    }
                }
            }
        }

        window.clear();
        DrawingLevels(levCounter, window);
        window.display();
    }
}
*/

/*
// Physics and Sprites test
int main()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "SFML works!");
    bullet.setPosition(200, 200);
    window.setFramerateLimit(60);
    sf::Color window_color(50, 50, 50);

    Character killer, target;

    character_init(killer, "assets/Characters/Killer/killer_head.png", "assets/Characters/Killer/hitman_body.png", false);
    character_set_scale(killer, 0.4);
    character_set_position(killer, sf::Vector2f(100, 700));
    character_init(target, "assets/Characters/gangster_head.png", "assets/Characters/black_suit_body.png", true);
    character_set_scale(target, 0.4);
    character_set_position(target, sf::Vector2f(1620, 700));
    sprites();
    while (window.isOpen())
    {
        // Moving the bullet
        Vector2i mousepos = Mouse::getPosition(window);
        bullet.setPosition(bullet.getPosition() - bulletDirection * 10.f);

        // Ricochet the bullet
        if (bullet.getGlobalBounds().intersects(wall1.getGlobalBounds())) {
            RicochetBullet(bullet, wall1);
        }
        if (bullet.getGlobalBounds().intersects(wall2.getGlobalBounds())) {
            RicochetBullet(bullet, wall2);
        }
        if (bullet.getGlobalBounds().intersects(wall3.getGlobalBounds())) {
            RicochetBullet(bullet, wall3);
        }
        if (bullet.getGlobalBounds().intersects(wall4.getGlobalBounds())) {
            RicochetBullet(bullet, wall4);
        }

        if (bullet.getGlobalBounds().intersects(box.getGlobalBounds())) {
            RicochetBullet(bullet, box);
        }
        if (bullet.getGlobalBounds().intersects(ring.getGlobalBounds())) {
            RicochetBullet(bullet, ring);
        }

        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.mouseButton.button == Mouse::Left) {
                cout << "yes";
                DirectBullet(bullet, event, mousepos);
            }

        }


        window.clear(window_color);
        window.draw(bullet);
        window.draw(wall1);
        window.draw(wall2);
        window.draw(wall3);
        window.draw(wall4);
        window.draw(box);
        window.draw(ring);
        character_draw(killer, window);
        character_draw(target, window);
        //window.draw(triangle);
        window.display();
    }
    return 0;
}
*/
