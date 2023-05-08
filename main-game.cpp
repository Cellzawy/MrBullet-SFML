#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "Sprites.h"
#include "Physics.h"
#include "Levels.h"
#include "Menus.h"
#include "Events.h"
//#include "Levels.cpp"
#include "win-lose-logic.h"

sf::RenderWindow window(sf::VideoMode(1920, 1080), "Mr bullet", sf::Style::Fullscreen);
bool in_level;
int currentLvl = 0;



// Menus test
int main() {
    window.setFramerateLimit(60);

    Texture_loading();

    SFX_click.setBuffer(SFX_click_soundbuffer);

    mainmenu_music.openFromFile("assets/sounds/main_music.ogg");
    mainmenu_music.setVolume(volume_value[0]);
    mainmenu_music.play();
    mainmenu_music.setLoop(true);
    constructlev1(window);
    constructlev2(window);
    constructlev3(window);
    constructlev4(window);
    bool level_complete = false;
    int currentLvl;

    while (window.isOpen())
    {
        if (current_menu >= static_cast<menu_type>(0) && current_menu <= static_cast<menu_type>(9))
        {
            if (bullets.size() != 0)
            {
                for (int i = bullets.size() - 1; i >= 0; i--)
                {
                    Time elapsed = bullets[i].clock.getElapsedTime();
                    level_complete = false;
                    if (elapsed >= seconds(5.f))
                    {
                        bullets[i].clock.restart();
                        bullets.erase(bullets.begin() + i);
                        std::cout << "erased";
                        level_complete = true;
                    }
                }
            }

            //for (int i = 0; i < bullets.size(); i++) {
            //    bullets[i].bulletBody.setPosition(bullets[i].bulletBody.getPosition() - bullets[i].bulletDirection * 20.f);
            //}
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
            Win_panel(lev[level_index].view.Level_evaluation);
        }

        else if (current_menu == lost_panel)
        {
            Lose_panel(currentLvl);
        }


        else if (current_menu == level_1)
        {
            character_rotate_arm(lev[0].killer, sf::Mouse::getPosition());
            int enemies_num = 1;
            levels_eventloop(enemies_num);
            if (current_menu >= static_cast<menu_type>(0) && current_menu <= static_cast<menu_type>(9))
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
                    stars_system(3, 2, 1, 0);
                    current_menu = won_panel;
                }

                else if (lev[level_index].num_of_bullets == 0 && level_complete && bullets.size() == 0)  ///32131563
                {
                    current_menu = lost_panel;
                }

            }
        }

        else if (current_menu == level_2)
        {
            int enemies_num = 8;
            levels_eventloop(enemies_num);
            if (current_menu >= static_cast<menu_type>(0) && current_menu <= static_cast<menu_type>(9))
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
                }

                else if (lev[level_index].num_of_bullets == 0 && level_complete && bullets.size() == 0)  ///32131563
                {
                    current_menu = lost_panel;
                }

            }
        }
        else if (current_menu == level_3)
        {
            int enemies_num = 1;
            levels_eventloop(enemies_num);
            if (current_menu >= static_cast<menu_type>(0) && current_menu <= static_cast<menu_type>(9))
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
                }

                else if (lev[level_index].num_of_bullets == 0 && level_complete && bullets.size() == 0)  ///32131563
                {
                    current_menu = lost_panel;
                }

            }
        }
        else if (current_menu == level_4)
        {
            int enemies_num = 3;
            levels_eventloop(enemies_num);
            if (current_menu >= static_cast<menu_type>(0) && current_menu <= static_cast<menu_type>(9))
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
                }

                else if (lev[level_index].num_of_bullets == 0 && level_complete && bullets.size() == 0)  ///32131563
                {
                    current_menu = lost_panel;
                }

            }
        }

        if (in_level) {
            levels_background();
        }

        if (current_menu >= static_cast<menu_type>(0) && current_menu <= static_cast<menu_type>(9))
        {
            for (int i = 0; i < bullets.size(); i++) {
                window.draw(bullets[i].bulletBody);
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
