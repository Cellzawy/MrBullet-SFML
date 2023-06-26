
#include <SFML/Graphics.hpp>
#include <iostream>
#include <SFML/Audio.hpp>
#include "Levels.h"
#include "Events.h"
#include "Menus.h"
#include "Sprites.h"
//#include "main-game.cpp"
#include "Physics.h"
#include "win-lose-logic.h"
#include "1v1.h"

using namespace sf;
sf::VertexArray line(sf::Lines, 2);
Texture tx;
//bool shot = false;


void EventListener() {
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "SFML works!");
    sf::Event event;
}

sf::Event normal_eventloop()
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            WriteFile();
            window.close();
        }
    }

    return event;
}

sf::Event main_menu_eventloop()
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            SFX_click.play();
            WriteFile();
            window.close();
        }

        else if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
        {

            // a variable to store the mouse position on the screen
            sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

            if (quit_button.sprite.getGlobalBounds().contains(mousePosition.x, mousePosition.y))
            {
                SFX_click.play();
                quit_button.sprite.setTexture(quit_button.Pressed_texture);
                WriteFile();
                window.close();

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

    return event;
}

sf::Event play_menu_eventloop()
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            SFX_click.play();
            WriteFile();
            window.close();
        }

        else if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
        {
            sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

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
            else if (duels_menu.sprite.getGlobalBounds().contains(mousePosition.x, mousePosition.y))
            {
                SFX_click.play();
                current_menu = Duels;
            }
        }
    }

    return event;
}

sf::Event options_menu_eventloop()
{
    Event event;
    while (window.pollEvent(event))
    {

        //Mouse Events
        if (event.type == Event::MouseButtonPressed)
        {
            if (Mouse::isButtonPressed(Mouse::Left))
            {

                Vector2i mousePosition = Mouse::getPosition(window);

                //Music
                volume_manage(volume_presentage[0], Volume_increase[0], Volume_decrease[0], volume_value[0]);
                mainmenu_music.setVolume(volume_value[0]);
                //SFX
                volume_manage(volume_presentage[1], Volume_increase[1], Volume_decrease[1], volume_value[1]);
                SFX_click.setVolume(volume_value[1]);


                volume_presentage[0].setOrigin(volume_presentage[0].getLocalBounds().width / 2, volume_presentage[0].getLocalBounds().height / 2);
                volume_presentage[1].setOrigin(volume_presentage[1].getLocalBounds().width / 2, volume_presentage[0].getLocalBounds().height / 2);



                if (back_button.sprite.getGlobalBounds().contains(sf::Vector2f(mousePosition)))
                {
                    back_button.sprite.setTexture(back_button.Pressed_texture);
                    SFX_click.play();
                    current_menu = main_menu;
                }

                if (check_box_close.getGlobalBounds().contains(sf::Vector2f(mousePosition)) && fullscreen_close == true)
                {
                    SFX_click.play();
                    fullscreen_close = false;
                    window.setFramerateLimit(60);
                    window.create(VideoMode(1920, 1080), "window", Style::Fullscreen); //FUllscreen_mode
                }

                else if (check_box_open.getGlobalBounds().contains(sf::Vector2f(mousePosition)))
                {
                    SFX_click.play();
                    fullscreen_close = true;
                    window.setFramerateLimit(60);
                    window.create(VideoMode(1920, 1080), "window", Style::Default); //Default_mode
                }
            }
        }

        if (event.type == Event::Closed)
        {
            SFX_click.play();
            WriteFile();
            window.close();
        }

    }
    return event;
}

sf::Event options_menu_pause_eventloop()
{
    Event event;
    while (window.pollEvent(event))
    {

        //Mouse Events
        if (event.type == Event::MouseButtonPressed)
        {
            if (Mouse::isButtonPressed(Mouse::Left))
            {

                Vector2i mousePosition = Mouse::getPosition(window);

                //Music
                volume_manage(volume_presentage[0], Volume_increase[0], Volume_decrease[0], volume_value[0]);
                mainmenu_music.setVolume(volume_value[0]);
                //SFX
                volume_manage(volume_presentage[1], Volume_increase[1], Volume_decrease[1], volume_value[1]);
                SFX_click.setVolume(volume_value[1]);


                volume_presentage[0].setOrigin(volume_presentage[0].getLocalBounds().width / 2, volume_presentage[0].getLocalBounds().height / 2);
                volume_presentage[1].setOrigin(volume_presentage[1].getLocalBounds().width / 2, volume_presentage[0].getLocalBounds().height / 2);



                if (back_button.sprite.getGlobalBounds().contains(sf::Vector2f(mousePosition)))
                {
                    back_button.sprite.setTexture(back_button.Pressed_texture);
                    SFX_click.play();
                    current_menu = pause_MENU;
                }

                if (check_box_close.getGlobalBounds().contains(sf::Vector2f(mousePosition)) && fullscreen_close == true)
                {
                    SFX_click.play();
                    fullscreen_close = false;
                    window.create(VideoMode(1920, 1080), "window", Style::Fullscreen); //FUllscreen_mode
                }

                else if (check_box_open.getGlobalBounds().contains(sf::Vector2f(mousePosition)))
                {
                    SFX_click.play();
                    fullscreen_close = true;
                    window.create(VideoMode(1920, 1080), "window", Style::Default); //Default_mode
                }
            }
        }

        if (event.type == Event::Closed)
        {
            SFX_click.play();
            WriteFile();
            window.close();
        }

    }
    return event;
}

sf::Event pause_eventloop()
{
    Event event;
    while (window.pollEvent(event))
    {
        if (event.type == Event::MouseButtonPressed)
        {
            if (Mouse::isButtonPressed(Mouse::Left))
            {
                Vector2i mousePosition = Mouse::getPosition(window);
                if (Resume.sprite.getGlobalBounds().contains(sf::Vector2f(mousePosition)))
                {
                    Resume.sprite.setTexture(Resume.Pressed_texture);
                    SFX_click.play();
                    current_menu = static_cast<menu_type>(level_index);

                }
                if (optionts.sprite.getGlobalBounds().contains(sf::Vector2f(mousePosition)))
                {
                    optionts.sprite.setTexture(optionts.Pressed_texture);
                    current_menu = OPTIONS_MENU_PAUSE;
                    SFX_click.play();
                }
                if (QUIT.sprite.getGlobalBounds().contains(sf::Vector2f(mousePosition)))
                {
                    QUIT.sprite.setTexture(QUIT.Pressed_texture);
                    current_menu = classic_Mode;
                    //Reset();
                    SFX_click.play();
                    lev[level_index].num_of_bullets = 1;

                }
            }
        }

        if (event.type == Event::Closed) {
            WriteFile();
            window.close();
        }
    }
    return event;
}

sf::Event classic_menu_eventloop()
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            SFX_click.play();
            WriteFile();
            window.close();

        }

        else if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
        {
            sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

            if (back_button.sprite.getGlobalBounds().contains(mousePosition.x, mousePosition.y))
            {
                SFX_click.play();
                back_button.sprite.setTexture(back_button.Pressed_texture);
                current_menu = play_menu;
            }
            else
            {
                /*
                */
                for (int i = 0; i < 15; i++)
                {
                    if (lev[i].view.Level_selection.getGlobalBounds().contains(mousePosition.x, mousePosition.y) && lev[i].view.highest_score != -1)
                    {
                        current_menu = menu_type(i);
                        if (i == 4)
                            level_index = 10;
                        else if (i == 5)
                            level_index = 12;
                        else
                            level_index = i;
                            std::cout << level_index << endl;
                            Reset();
                        //}

                    }

                }
            }
        }
    }

    return event;
}

sf::Event achievements_menu_eventloop()
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            WriteFile();
            window.close();
        }

        else if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
        {
            sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

            if (back_button.sprite.getGlobalBounds().contains(mousePosition.x, mousePosition.y))
            {
                SFX_click.play();
                back_button.sprite.setTexture(back_button.Pressed_texture);
                current_menu = main_menu;
            }
        }
    }

    return event;
}


sf::Event levels_eventloop(int enemies_num)
{
    // event loop
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            WriteFile();
            window.close();
        }

        //Mouse Events
        if (event.type == Event::MouseButtonPressed)
        {
            cout << Mouse::getPosition().x << "\t" << Mouse::getPosition().y << endl;
            if (Mouse::isButtonPressed(Mouse::Left))
            {

                Vector2i mousePosition = Mouse::getPosition(window);


                if (Replay.getGlobalBounds().contains(sf::Vector2f(mousePosition)))
                {
                    Reset();
                    Restart_sound.setVolume(volume_value[1]);
                    Restart_sound.play();
                }

                else if (Pause_menu_button.getGlobalBounds().contains(sf::Vector2f(mousePosition)))
                {
                    current_menu = pause_MENU;
                }
                else if (lev[level_index].num_of_bullets > 0)
                {
                    shoot.setVolume(volume_value[1]);
                    shoot.play();
                    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
                    Vector2i mousepos = Mouse::getPosition(window);
                    //CircleShape newBullet(10.f);
                    std::cout << "yes";
                    Bullet newBullet;
                    newBullet.bulletBody.setFillColor(sf::Color::Black);
                    newBullet.bulletBody.setRadius(50.f);
                    newBullet.bulletBody.setOrigin(newBullet.bulletBody.getLocalBounds().width / 2, newBullet.bulletBody.getLocalBounds().height / 2);
                    newBullet.b.setRadius(10.f);
                    newBullet.b.setOrigin(newBullet.b.getLocalBounds().width / 2, newBullet.b.getLocalBounds().height / 2);
                    newBullet.b.setPosition(newBullet.bulletBody.getPosition());
                    newBullet.b.setFillColor(Color::Black);
                    bullets.push_back(newBullet);
                    //for (int i = 0; i < bullets.size(); i++) {
                    //    DirectBullet(bullets[i], event, mousepos);
                    //}
                    DirectBullet(bullets[bullets.size() - 1], event, mousepos, level_index, lev[level_index].killer.bullet_pos, lev[level_index].killer);
                    lev[level_index].num_of_bullets--;

                    // win-lose logic

                    for (int i = 0; i < enemies_num; i++)
                    {
                        if (newBullet.bulletBody.getGlobalBounds().intersects(lev[level_index].target[i].body.getGlobalBounds()))
                        {
                            lev[level_index].target[i].dead = true;
                        }


                    }
                }

            }
        }

    }
    return event;
}


sf::Event win_lose_panels_eventloop()
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        line[0].position = sf::Vector2f(0, 0);
        line[1].position = sf::Vector2f(0, 0);
        if (event.type == sf::Event::Closed)
        {
            WriteFile();
            window.close();
        }

        else if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
        {
            sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

            if (quit_to_main_menu.getGlobalBounds().contains(mousePosition.x, mousePosition.y))
            {
                animation = true;
                current_menu = main_menu;
                //Reset();
                lev[level_index].num_of_bullets = 2;
            }

            else if (Forward.getGlobalBounds().contains(mousePosition.x, mousePosition.y) && level_index != 9)
            {
                Reset();
                animation = true;
                level_index++;
                current_menu = static_cast<menu_type>(level_index);
                lev[level_index].view.Level_evaluation = 0;
                Reset();

            }

            else if (backward.getGlobalBounds().contains(mousePosition.x, mousePosition.y) && level_index != 0)
            {
                Reset();
                animation = true;
                level_index--;
                current_menu = static_cast<menu_type>(level_index);
                Reset();
            }

            else if (reset.getGlobalBounds().contains(mousePosition.x, mousePosition.y))
            {
                current_menu = static_cast<menu_type>(level_index);

                Reset();
                animation = true;
                Reset();
            }
        }
    }

    return event;
}

sf::Event Duels_eventLoop()
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            WriteFile();
            window.close();
        }
        if (playerOne.dead == false && playerTwo.dead == false) {
            lev[level_index].num_of_bullets = 1;
            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left && lev[level_index].num_of_bullets > 0 && shot == false)
            {
                

                shot = true;
                sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
                Vector2i mousepos = Mouse::getPosition(window);
                std::cout << "yes";
                Bullet newBullet;
                newBullet.bulletBody.setFillColor(sf::Color::Black);
                newBullet.bulletBody.setRadius(50.f);
                newBullet.bulletBody.setOrigin(newBullet.bulletBody.getLocalBounds().width / 2, newBullet.bulletBody.getLocalBounds().height / 2);
                newBullet.b.setRadius(10.f);
                newBullet.b.setOrigin(newBullet.b.getLocalBounds().width / 2, newBullet.b.getLocalBounds().height / 2);
                newBullet.b.setPosition(newBullet.bulletBody.getPosition());
                newBullet.b.setFillColor(Color::Black);
                bullets.push_back(newBullet);

                lev[level_index].num_of_bullets--;
                cout << 1 << endl;
                
                if (playerOne.turn)
                {
                    DirectBullet(bullets[bullets.size() - 1], event, mousepos, level_index, playerOne.bullet_pos, playerOne);
                    character_rotate_arm(playerOne, sf::Mouse::getPosition());

                }
                else
                {
                    DirectBullet(bullets[bullets.size() - 1], event, mousepos, level_index, playerTwo.bullet_pos, playerTwo);
                    character_rotate_arm(playerTwo, sf::Mouse::getPosition());

                }
                
            }
        }

        switch (event.type)
        {
        case sf::Event::MouseButtonPressed:
            if (event.mouseButton.button == sf::Mouse::Left)
            {
                sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
                if (restart.getGlobalBounds().contains(mousePos))
                {
                    if (playerOne.dead == true || playerTwo.dead == true)
                    {
                        resetDuels();
                    }
                }
                if (back.getGlobalBounds().contains(mousePos))
                {
                    if (playerOne.dead == true || playerTwo.dead == true)
                    {
                        current_menu = main_menu;
                        resetDuels();
                    }
                }
            }
            break;
        }
    }
    return event;
}
