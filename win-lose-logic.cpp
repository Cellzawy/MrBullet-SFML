#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <string>
#include <iostream>
#include "win-lose-logic.h"
#include "Events.h"
#include "Menus.h"

void Win_panel();
void Winning_level_results(int);
void Zero_stars();
void One_star();
void Two_stars();
void Three_stars();
void DissolveEffect_three_stars(sf::Sprite&, sf::Sprite&, sf::Sprite&, float dissolveTime);
void DissolveEffect_won_options(sf::Sprite&, sf::Sprite&, sf::Sprite&, float dissolveTime);
void DissolveEffect_won_Quit(sf::Sprite&, float);

void Lose_panel();
void DissolveEffect_first_Text(sf::Text, float);
void DissolveEffect_second_Text(sf::Text, float);
void DissolveEffect_lost_options(sf::Sprite&, sf::Sprite&, sf::Sprite&, float dissolveTime);
void DissolveEffect_lost_Quit(sf::Sprite&, float);

void Moving_down_animation(sf::Sprite&);



sf::Texture win_panel_texture, lose_panel_texture;
sf::Texture star_texture, empty_star_texture, forward_texture, backward_texture, reset_texture;
sf::Texture quit_to_main_menu_texture;


sf::Sprite Forward, backward, first_star, second_star, third_star, reset;
sf::Sprite win_panel, lose_panel;
sf::Sprite quit_to_main_menu;
sf::Text result_text;

bool animation = true;

void Win_panel()
{
    int x = 0;

    Forward.setTexture(forward_texture);
    backward.setTexture(backward_texture);
    reset.setTexture(reset_texture);


    win_panel.setTexture(win_panel_texture);



    if (animation)
    {
        win_panel.setOrigin(win_panel.getLocalBounds().width / 2, win_panel.getLocalBounds().height / 2);
        win_panel.setPosition(window.getSize().x / 2, window.getSize().y / -0.624);

        first_star.setTexture(empty_star_texture);
        second_star.setTexture(empty_star_texture);
        third_star.setTexture(empty_star_texture);
    }

    first_star.setOrigin(first_star.getLocalBounds().width / 2, first_star.getLocalBounds().height / 2);
    first_star.setPosition(window.getSize().x / 2.6, window.getSize().y / 2.466);

    second_star.setOrigin(second_star.getLocalBounds().width / 2, second_star.getLocalBounds().height / 2);
    second_star.setPosition(window.getSize().x / 1.625, window.getSize().y / 2.466);

    third_star.setOrigin(third_star.getLocalBounds().width / 2, third_star.getLocalBounds().height / 2);
    third_star.setPosition(window.getSize().x / 2, window.getSize().y / 2.799);

    result_text.setCharacterSize(50);
    result_text.setFont(game_font);
    result_text.setOrigin(result_text.getGlobalBounds().width / 2, result_text.getGlobalBounds().height / 2);
    result_text.setPosition(window.getSize().x / 2, window.getSize().y / 2.1);

    Forward.setOrigin(Forward.getLocalBounds().width / 2, Forward.getLocalBounds().height / 2);
    Forward.setPosition(window.getSize().x / 1.579, window.getSize().y / 1.239);

    backward.setOrigin(backward.getLocalBounds().width /2, backward.getLocalBounds().height / 2);
    backward.setPosition(window.getSize().x / 2.727, window.getSize().y / 1.239);

    reset.setOrigin(reset.getLocalBounds().width / 2, reset.getLocalBounds().height / 2);
    reset.setPosition(window.getSize().x / 2, window.getSize().y / 1.388);

    quit_to_main_menu.setTexture(quit_to_main_menu_texture);
    quit_to_main_menu.setOrigin(quit_to_main_menu.getLocalBounds().width / 2, quit_to_main_menu.getLocalBounds().height / 2);
    quit_to_main_menu.setPosition(window.getSize().x / 6.061, window.getSize().y / 1.099);


    if(animation)
    {
        Moving_down_animation(win_panel);

        float dissolveTime = 1.0f;

        DissolveEffect_three_stars(first_star, second_star, third_star, dissolveTime);
        Winning_level_results(x);
        DissolveEffect_won_options(Forward, backward, reset, dissolveTime);
        DissolveEffect_won_Quit(quit_to_main_menu, dissolveTime);
    }

    animation = false;


    sf::Event event;
    while(window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            window.close();
        }

        else if (event.type == sf::Event::KeyPressed)
        {
            if (event.key.code == sf::Keyboard::Escape)
            {
                window.close();
            }
        }
    }


    window.draw(win_panel);
    window.draw(first_star);
    window.draw(second_star);
    window.draw(third_star);
    window.draw(result_text);
    window.draw(Forward);
    window.draw(backward);
    window.draw(reset);
    window.draw(quit_to_main_menu);
}

void DissolveEffect_three_stars(sf::Sprite& sprite1, sf::Sprite& sprite2, sf::Sprite& sprite3, float dissolveTime)
{
    normal_eventloop();

    sprite1.setColor(sf::Color(255, 255, 255, 0));
    sprite2.setColor(sf::Color(255, 255, 255, 0));
    sprite3.setColor(sf::Color(255, 255, 255, 0));

    sf::Clock dissolveClock;

    while(sprite1.getColor().a != 225 && sprite2.getColor().a != 255 && sprite3.getColor().a != 255)
    {

        float dissolvePercent = dissolveClock.getElapsedTime().asSeconds() / dissolveTime;

        sprite1.setColor(sf::Color(255, 255, 255, static_cast<sf::Uint8>(dissolvePercent * 255)));
        sprite2.setColor(sf::Color(255, 255, 255, static_cast<sf::Uint8>(dissolvePercent * 255)));
        sprite3.setColor(sf::Color(255, 255, 255, static_cast<sf::Uint8>(dissolvePercent * 255)));

        if (dissolvePercent >= 1.0f)
        {
            sprite1.setColor(sf::Color(255, 255, 255, 255));
            sprite2.setColor(sf::Color(255, 255, 255, 255));
            sprite3.setColor(sf::Color(255, 255, 255, 255));
        }

        window.clear();
        window.draw(win_panel);
        window.draw(sprite1);
        window.draw(sprite2);
        window.draw(sprite3);
        window.display();
    }
}

void Winning_level_results(int result)
{
    window.clear();
    window.draw(win_panel);
    window.draw(first_star);
    window.draw(second_star);
    window.draw(third_star);
    window.display();

    if (result == 0)
    {
        Zero_stars();
    }

    else if (result == 1)
    {
        One_star();
    }

    else if (result == 2)
    {
        Two_stars();
    }

    else if (result == 3)
    {
        Three_stars();
    }
}

void Zero_stars()
{
    result_text.setString("Good");

    window.clear();
    window.draw(win_panel);
    window.draw(first_star);
    window.draw(second_star);
    window.draw(third_star);
    window.display();
}

void One_star()
{
    result_text.setString("Great");

    sf::Clock delay;
    while(delay.getElapsedTime().asMilliseconds() < 800)
    {
        if (delay.getElapsedTime().asMilliseconds() > 500)
        {
            first_star.setTexture(star_texture);
        }
    }

    window.clear();
    window.draw(win_panel);
    window.draw(first_star);
    window.draw(second_star);
    window.draw(third_star);
    window.display();
}

void Two_stars()
{
    result_text.setString("AWESOME");

    sf::Clock delay;

    while (delay.getElapsedTime().asMilliseconds() < 1000)
    {
        if (delay.getElapsedTime().asMilliseconds() > 400)
        {
            first_star.setTexture(star_texture);

            window.clear();
            window.draw(win_panel);
            window.draw(first_star);
            window.draw(second_star);
            window.draw(third_star);
            window.display();

            if (delay.getElapsedTime().asMilliseconds() > 800)
            {
                second_star.setTexture(star_texture);

                window.clear();
                window.draw(win_panel);
                window.draw(first_star);
                window.draw(second_star);
                window.draw(third_star);
                window.display();
            }
        }
    }
}

void Three_stars()
{
    result_text.setString("EXCELLENT");

    sf::Clock delay;
    while(delay.getElapsedTime().asMilliseconds() < 1400)
    {
        if(delay.getElapsedTime().asMilliseconds() > 400)
        {
            first_star.setTexture(star_texture);

            window.clear();
            window.draw(win_panel);
            window.draw(first_star);
            window.draw(second_star);
            window.draw(third_star);
            window.display();

            if(delay.getElapsedTime().asMilliseconds() > 800)
            {
                second_star.setTexture(star_texture);

                window.clear();
                window.draw(win_panel);
                window.draw(first_star);
                window.draw(second_star);
                window.draw(third_star);
                window.display();

                if(delay.getElapsedTime().asMilliseconds() > 1200)
                {
                    third_star.setTexture(star_texture);

                    window.clear();
                    window.draw(win_panel);
                    window.draw(first_star);
                    window.draw(second_star);
                    window.draw(third_star);
                    window.display();
                }
            }
        }
    }
}

void DissolveEffect_won_options(sf::Sprite& sprite1, sf::Sprite& sprite2, sf::Sprite& sprite3, float dissolveTime)
{
    normal_eventloop();
    sprite1.setColor(sf::Color(255, 255, 255, 0));
    sprite2.setColor(sf::Color(255, 255, 255, 0));
    sprite3.setColor(sf::Color(255, 255, 255, 0));

    sf::Clock dissolveClock;

    while(sprite1.getColor().a != 225 && sprite2.getColor().a != 255 && sprite3.getColor().a != 255)
    {

        float dissolvePercent = dissolveClock.getElapsedTime().asSeconds() / dissolveTime;

        sprite1.setColor(sf::Color(255, 255, 255, dissolvePercent * 255));
        sprite2.setColor(sf::Color(255, 255, 255, dissolvePercent * 255));
        sprite3.setColor(sf::Color(255, 255, 255, dissolvePercent * 255));

        if (dissolvePercent >= 1.0f)
        {
            sprite1.setColor(sf::Color(255, 255, 255, 255));
            sprite2.setColor(sf::Color(255, 255, 255, 255));
            sprite3.setColor(sf::Color(255, 255, 255, 255));
        }

    window.clear();
    window.draw(win_panel);
    window.draw(first_star);
    window.draw(second_star);
    window.draw(third_star);
    window.draw(sprite1);
    window.draw(sprite2);
    window.draw(sprite3);
    window.display();
    }
}

void DissolveEffect_won_Quit(sf::Sprite& quit_button, float dissolveTime)
{
    quit_button.setColor(sf::Color(255, 255, 255, 0));

    sf::Clock dissolveClock;
    while(quit_button.getColor().a != 225)
    {
        float dissolvePercent = dissolveClock.getElapsedTime().asSeconds() / dissolveTime;

        quit_button.setColor(sf::Color(255, 255, 255, static_cast<sf::Uint8>(dissolvePercent * 255)));

        if (dissolvePercent >= 1.0f)
        {
            quit_button.setColor(sf::Color(255, 255, 255, 255));
        }

        window.clear();
        window.draw(win_panel);
        window.draw(first_star);
        window.draw(second_star);
        window.draw(third_star);
        window.draw(Forward);
        window.draw(backward);
        window.draw(reset);
        window.draw(quit_button);
        window.display();
    }
}


sf::Text out_of_bullets("YOU'RE OUT OF \n     BULLETS", game_font, 55), Try_again("TRY AGAIN?", game_font, 55);


void Lose_panel()
{
    lose_panel.setTexture(lose_panel_texture);

    Forward.setTexture(forward_texture);
    backward.setTexture(backward_texture);
    reset.setTexture(reset_texture);

    if (animation)
    {
        lose_panel.setOrigin(lose_panel.getLocalBounds().width / 2, lose_panel.getLocalBounds().height / 2);
        lose_panel.setPosition(window.getSize().x / 2, window.getSize().y / -0.625);
    }

    out_of_bullets.setFillColor(sf::Color(147, 22, 22, 255));
    out_of_bullets.setOrigin(out_of_bullets.getLocalBounds().width / 2, out_of_bullets.getLocalBounds().height / 2);
    out_of_bullets.setPosition(window.getSize().x / 2, window.getSize().y / 2.988);

    Try_again.setFillColor(sf::Color(147, 22, 22, 255));
    Try_again.setOrigin(Try_again.getLocalBounds().width / 2, Try_again.getLocalBounds().height / 2);
    Try_again.setPosition(window.getSize().x / 2, window.getSize().y / 1.825);

    Forward.setOrigin(Forward.getLocalBounds().width / 2, Forward.getLocalBounds().height / 2);
    Forward.setPosition(window.getSize().x / 1.579, window.getSize().y / 1.239);

    backward.setOrigin(backward.getLocalBounds().width /2, backward.getLocalBounds().height / 2);
    backward.setPosition(window.getSize().x / 2.727, window.getSize().y / 1.239);

    reset.setOrigin(reset.getLocalBounds().width / 2, reset.getLocalBounds().height / 2);
    reset.setPosition(window.getSize().x / 2, window.getSize().y / 1.388);

    quit_to_main_menu.setTexture(quit_to_main_menu_texture);
    quit_to_main_menu.setOrigin(quit_to_main_menu.getLocalBounds().width / 2, quit_to_main_menu.getLocalBounds().height / 2);
    quit_to_main_menu.setPosition(window.getSize().x / 6.061, window.getSize().y / 1.099);

    if (animation)
    {
        Moving_down_animation(lose_panel);

        float dissolveTime = 1.0f;

        DissolveEffect_first_Text(out_of_bullets, dissolveTime);
        DissolveEffect_second_Text(Try_again, dissolveTime);
        DissolveEffect_lost_options(Forward, backward, reset, dissolveTime);
        DissolveEffect_lost_Quit(quit_to_main_menu, dissolveTime);
    }

    animation = false;

    sf::Event event;
    while(window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            window.close();
        }

        else if (event.type == sf::Event::KeyPressed)
        {
            if (event.key.code == sf::Keyboard::Escape)
            {
                window.close();
            }
        }
    }

    window.draw(lose_panel);
    window.draw(out_of_bullets);
    window.draw(Try_again);
    window.draw(Forward);
    window.draw(backward);
    window.draw(reset);
    window.draw(quit_to_main_menu);
}

void DissolveEffect_first_Text(sf::Text text, float dissolveTime)
{
    normal_eventloop();

    text.setColor(sf::Color(147, 22, 22, 0));

    sf::Clock dissolveClock;
    while(text.getColor().a != 225)
    {
        float dissolvePercent = dissolveClock.getElapsedTime().asSeconds() / dissolveTime;

        text.setColor(sf::Color(147, 22, 22, static_cast<sf::Uint8>(dissolvePercent * 255)));

        if (dissolvePercent >= 1.0f)
        {
            text.setColor(sf::Color(147, 22, 22, 255));
        }

        window.clear();
        window.draw(lose_panel);
        window.draw(text);
        window.display();
    }
}

void DissolveEffect_second_Text(sf::Text text, float dissolveTime)
{
    normal_eventloop();

    text.setColor(sf::Color(147, 22, 22, 0));

    sf::Clock dissolveClock;
    while(text.getColor().a != 225)
    {
        float dissolvePercent = dissolveClock.getElapsedTime().asSeconds() / dissolveTime;

        text.setColor(sf::Color(147, 22, 22, static_cast<sf::Uint8>(dissolvePercent * 255)));

        if (dissolvePercent >= 1.0f)
        {
            text.setColor(sf::Color(147, 22, 22, 255));
        }

        window.clear();
        window.draw(lose_panel);
        window.draw(out_of_bullets);
        window.draw(text);
        window.display();
    }
}

void DissolveEffect_lost_options(sf::Sprite& sprite1, sf::Sprite& sprite2, sf::Sprite& sprite3, float dissolveTime)
{
    normal_eventloop();
    sprite1.setColor(sf::Color(255, 255, 255, 0));
    sprite2.setColor(sf::Color(255, 255, 255, 0));
    sprite3.setColor(sf::Color(255, 255, 255, 0));

    sf::Clock dissolveClock;

    while(sprite1.getColor().a != 225 && sprite2.getColor().a != 255 && sprite3.getColor().a != 255)
    {

        float dissolvePercent = dissolveClock.getElapsedTime().asSeconds() / dissolveTime;

        sprite1.setColor(sf::Color(255, 255, 255, dissolvePercent * 255));
        sprite2.setColor(sf::Color(255, 255, 255, dissolvePercent * 255));
        sprite3.setColor(sf::Color(255, 255, 255, dissolvePercent * 255));

        if (dissolvePercent >= 1.0f)
        {
            sprite1.setColor(sf::Color(255, 255, 255, 255));
            sprite2.setColor(sf::Color(255, 255, 255, 255));
            sprite3.setColor(sf::Color(255, 255, 255, 255));
        }

        window.clear();
        window.draw(lose_panel);
        window.draw(out_of_bullets);
        window.draw(Try_again);
        window.draw(sprite1);
        window.draw(sprite2);
        window.draw(sprite3);
        window.display();
    }

}

void DissolveEffect_lost_Quit(sf::Sprite& quit_button, float dissolveTime)
{
    quit_button.setColor(sf::Color(255, 255, 255, 0));

    sf::Clock dissolveClock;
    while(quit_button.getColor().a != 225)
    {
        float dissolvePercent = dissolveClock.getElapsedTime().asSeconds() / dissolveTime;

        quit_button.setColor(sf::Color(255, 255, 255, static_cast<sf::Uint8>(dissolvePercent * 255)));

        if (dissolvePercent >= 1.0f)
        {
            quit_button.setColor(sf::Color(255, 255, 255, 255));
        }

        window.clear();
        window.draw(lose_panel);
        window.draw(out_of_bullets);
        window.draw(Try_again);
        window.draw(Forward);
        window.draw(backward);
        window.draw(reset);
        window.draw(quit_button);
        window.display();
    }
}




void Moving_down_animation(sf::Sprite& panel)
{
    sf::Clock delay;

    while (panel.getPosition().y < window.getSize().y / 2)
    {
        normal_eventloop();
        window.clear();
        if (delay.getElapsedTime().asSeconds() > 1)
        {
            panel.move(0, window.getSize().y / 550);
            window.draw(panel);
        }
        window.display();
    }

}


