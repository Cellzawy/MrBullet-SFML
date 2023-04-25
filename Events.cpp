
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Events.h"
#include "Menus.h"
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
                for (int i = 0; i < levels.size();i++)
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
