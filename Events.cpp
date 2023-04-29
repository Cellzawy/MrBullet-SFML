
#include <SFML/Graphics.hpp>
#include <iostream>
#include <SFML/Audio.hpp>
#include "Events.h"
#include "Menus.h"
#include "Sprites.h"
#include "Physics.h"
#include "win-lose-logic.h"

using namespace sf;

void EventListener() {
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "SFML works!");
    sf::Event event;
}

sf::Event normal_eventloop()
{
    sf::Event event;
    while(window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            window.close();
        }
    }

    return event;
}

sf::Event main_menu_eventloop()
{
    sf::Event event;
    while(window.pollEvent(event))
    {
        if(event.type == sf::Event::Closed)
        {
            SFX_click.play();
            window.close();
        }

        else if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
        {

            // a variable to store the mouse position on the screen
            sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

            if(quit_button.sprite.getGlobalBounds().contains(mousePosition.x, mousePosition.y))
            {
                SFX_click.play();
                quit_button.sprite.setTexture(quit_button.Pressed_texture);
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
    while(window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            SFX_click.play();
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
            window.close();
        }

    }
    return event;
}

sf::Event classic_menu_eventloop()
{
    sf::Event event;
    while(window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            SFX_click.play();
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
                for (int i = 0; i < 10;i++)
                {
                    if (level[i].view.Level_selection.getGlobalBounds().contains(mousePosition.x, mousePosition.y) && level[i].view.Level_evaluation != -1)
                        current_menu = menu_type(i);
                }
            }
        }
    }

    return event;
}

sf::Event achievements_menu_eventloop()
{
    sf::Event event;
    while(window.pollEvent(event))
    {
        if(event.type == sf::Event::Closed)
        {
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


sf::Event levels_eventloop()
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            window.close();
        }

        else if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
        {
            sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
            Vector2i mousepos = Mouse::getPosition(window);
            //CircleShape newBullet(10.f);
            std::cout << "yes";
            Bullet newBullet;
            newBullet.bulletBody.setFillColor(sf::Color::Black);
            newBullet.bulletBody.setRadius(8.f);
            bullets.push_back(newBullet);
            //for (int i = 0; i < bullets.size(); i++) {
            //    DirectBullet(bullets[i], event, mousepos);
            //}
            DirectBullet(bullets[bullets.size() - 1], event, mousepos);

        }
    }

    return event;
}
