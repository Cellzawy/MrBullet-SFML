#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <string>
#include <iostream>
#include "win-lose-logic.h"
#include "Events.h"
#include "Menus.h"
#include "Sounds.h"

void Win_panel(int score);
void Winning_level_results(int score);
void Zero_stars();
void One_star();
void Two_stars();
void Three_stars();
void DissolveEffect_three_stars(float dissolveTime);
void DissolveEffect_won_options(float dissolveTime);
void DissolveEffect_won_Quit(float);

void Lose_panel(int lvl);
void DissolveEffect_first_Text(sf::Text, float);
void DissolveEffect_second_Text(sf::Text, float);
void DissolveEffect_lost_options(float dissolveTime);
void DissolveEffect_lost_Quit(float);

void Moving_down_animation(sf::Sprite&);
void Reset();



sf::Texture win_panel_texture, lose_panel_texture;
sf::Texture star_texture, empty_star_texture, forward_texture, backward_texture, reset_texture;
sf::Texture quit_to_main_menu_texture;
sf::Texture blur_effect_texture;


sf::Sprite Forward, backward, first_star, second_star, third_star, reset;
sf::Sprite win_panel, lose_panel;
sf::Sprite quit_to_main_menu;
sf::Sprite blur_effect;
sf::Text result_text;

bool animation = true;



void Win_panel(int score)
{
    if (lev[level_index + 1].view.highest_score == -1)
    {
        lev[level_index + 1].view.highest_score = 0;
    }

    DrawingLevels(level_index, window);
    Forward.setTexture(forward_texture);
    backward.setTexture(backward_texture);
    reset.setTexture(reset_texture);
    win_panel.setTexture(win_panel_texture);

    blur_effect.setTexture(blur_effect_texture);

    if (animation)
    {
        win_panel.setOrigin(win_panel.getLocalBounds().width / 2, win_panel.getLocalBounds().height / 2);
        win_panel.setPosition(window.getSize().x / 2, window.getSize().x / -0.577);

        first_star.setTexture(empty_star_texture);
        second_star.setTexture(empty_star_texture);
        third_star.setTexture(empty_star_texture);
    }

    first_star.setOrigin(first_star.getLocalBounds().width / 2, first_star.getLocalBounds().height / 2);
    first_star.setPosition(window.getSize().x / 2.4, window.getSize().y / 2.466);

    second_star.setOrigin(second_star.getLocalBounds().width / 2, second_star.getLocalBounds().height / 2);
    second_star.setPosition(window.getSize().x / 1.714, window.getSize().y / 2.466);

    third_star.setOrigin(third_star.getLocalBounds().width / 2, third_star.getLocalBounds().height / 2);
    third_star.setPosition(window.getSize().x / 2, window.getSize().y / 2.799);

    Forward.setOrigin(Forward.getLocalBounds().width / 2, Forward.getLocalBounds().height / 2);
    Forward.setPosition(window.getSize().x / 1.701, window.getSize().y / 1.339);

    backward.setOrigin(backward.getLocalBounds().width / 2, backward.getLocalBounds().height / 2);
    backward.setPosition(window.getSize().x / 2.427, window.getSize().y / 1.339);

    reset.setOrigin(reset.getLocalBounds().width / 2, reset.getLocalBounds().height / 2);
    reset.setPosition(window.getSize().x / 2, window.getSize().y / 1.388);

    quit_to_main_menu.setTexture(quit_to_main_menu_texture);
    quit_to_main_menu.setOrigin(quit_to_main_menu.getLocalBounds().width / 2, quit_to_main_menu.getLocalBounds().height / 2);
    quit_to_main_menu.setPosition(window.getSize().x / 6.061, window.getSize().y / 1.099);
    quit_to_main_menu.setScale(1.0f, 1.0f);


    if (animation)
    {
        float dissolveTime = 1.0f;
        Blur_effect(dissolveTime);
        Moving_down_animation(win_panel);

        DissolveEffect_three_stars(dissolveTime);
        Winning_level_results(score);
        DissolveEffect_won_options(dissolveTime);
        DissolveEffect_won_Quit(dissolveTime);
    }

    animation = false;

    win_lose_panels_eventloop();

    hoverEffect(quit_to_main_menu);

    window.draw(blur_effect);
    window.draw(win_panel);
    window.draw(first_star);
    window.draw(second_star);
    window.draw(third_star);
    window.draw(result_text);

    if (level_index != 14)
    {
        window.draw(Forward);
    }

    if (level_index != 0)
    {
        window.draw(backward);
    }

    window.draw(reset);
    window.draw(quit_to_main_menu);
}

void DissolveEffect_three_stars(float dissolveTime)
{
    normal_eventloop();

    first_star.setColor(sf::Color(255, 255, 255, 0));
    second_star.setColor(sf::Color(255, 255, 255, 0));
    third_star.setColor(sf::Color(255, 255, 255, 0));

    sf::Clock dissolveClock;

    while (first_star.getColor().a != 255 && second_star.getColor().a != 255 && third_star.getColor().a != 255)
    {

        float dissolvePercent = dissolveClock.getElapsedTime().asSeconds() / dissolveTime;

        first_star.setColor(sf::Color(255, 255, 255, static_cast<sf::Uint8>(dissolvePercent * 255)));
        second_star.setColor(sf::Color(255, 255, 255, static_cast<sf::Uint8>(dissolvePercent * 255)));
        third_star.setColor(sf::Color(255, 255, 255, static_cast<sf::Uint8>(dissolvePercent * 255)));

        if (dissolvePercent >= 1.0f)
        {
            first_star.setColor(sf::Color(255, 255, 255, 255));
            second_star.setColor(sf::Color(255, 255, 255, 255));
            third_star.setColor(sf::Color(255, 255, 255, 255));
        }

        window.clear();
        DrawingLevels(level_index, window);
        window.draw(blur_effect);
        window.draw(win_panel);
        window.draw(first_star);
        window.draw(second_star);
        window.draw(third_star);
        window.display();
    }
}

void Winning_level_results(int result)
{
    window.clear();
    DrawingLevels(level_index, window);
    window.draw(blur_effect);
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
    result_text.setCharacterSize(50);
    result_text.setFont(game_font);
    result_text.setOrigin(result_text.getLocalBounds().width / 2, result_text.getLocalBounds().height / 2);
    result_text.setPosition(window.getSize().x / 2, window.getSize().y / 2);

    sf::Clock delay;

    window.clear();
    DrawingLevels(level_index, window);
    window.draw(blur_effect);
    window.draw(win_panel);
    window.draw(first_star);
    window.draw(second_star);
    window.draw(third_star);
    window.display();
}

void One_star()
{
    result_text.setString("Great");
    result_text.setCharacterSize(50);
    result_text.setFont(game_font);
    result_text.setOrigin(result_text.getLocalBounds().width / 2, result_text.getLocalBounds().height / 2);
    result_text.setPosition(window.getSize().x / 2, window.getSize().y / 2);

    three_strars.setVolume(volume_value[1]);
    three_strars.play();
    sf::Clock delay;
    while (delay.getElapsedTime().asMilliseconds() < 800)
    {
        if (delay.getElapsedTime().asMilliseconds() > 400)
        {
            first_star.setTexture(star_texture);
        }
    }

    window.clear();
    DrawingLevels(level_index, window);
    window.draw(blur_effect);
    window.draw(win_panel);
    window.draw(first_star);
    window.draw(second_star);
    window.draw(third_star);
    window.display();
}

void Two_stars()
{
    result_text.setString("AWESOME");
    result_text.setCharacterSize(50);
    result_text.setFont(game_font);
    result_text.setOrigin(result_text.getLocalBounds().width / 2, result_text.getLocalBounds().height / 2);
    result_text.setPosition(window.getSize().x / 2, window.getSize().y / 2);

    sf::Clock delay;

    while (delay.getElapsedTime().asMilliseconds() < 1000)
    {
        if (delay.getElapsedTime().asMilliseconds() > 400)
        {
            first_star.setTexture(star_texture);

            window.clear();
            DrawingLevels(level_index, window);
            window.draw(blur_effect);
            window.draw(win_panel);
            window.draw(first_star);
            window.draw(second_star);
            window.draw(third_star);
            window.display();

            if (delay.getElapsedTime().asMilliseconds() > 800)
            {
                second_star.setTexture(star_texture);

                window.clear();
                DrawingLevels(level_index, window);
                window.draw(blur_effect);
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
    result_text.setCharacterSize(50);
    result_text.setFont(game_font);
    result_text.setOrigin(result_text.getLocalBounds().width / 2, result_text.getLocalBounds().height / 2);
    result_text.setPosition(window.getSize().x / 2, window.getSize().y / 2);


    sf::Clock delay;
    while (delay.getElapsedTime().asMilliseconds() < 1400)
    {
        if (delay.getElapsedTime().asMilliseconds() > 400)
        {
            first_star.setTexture(star_texture);

            window.clear();
            DrawingLevels(level_index, window);
            window.draw(blur_effect);
            window.draw(win_panel);
            window.draw(first_star);
            window.draw(second_star);
            window.draw(third_star);
            window.display();

            if (delay.getElapsedTime().asMilliseconds() > 800)
            {
                second_star.setTexture(star_texture);

                window.clear();
                DrawingLevels(level_index, window);
                window.draw(blur_effect);
                window.draw(win_panel);
                window.draw(first_star);
                window.draw(second_star);
                window.draw(third_star);
                window.display();

                if (delay.getElapsedTime().asMilliseconds() > 1200)
                {
                    third_star.setTexture(star_texture);

                    window.clear();
                    DrawingLevels(level_index, window);
                    window.draw(blur_effect);
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

void DissolveEffect_won_options(float dissolveTime)
{
    normal_eventloop();
    Forward.setColor(sf::Color(255, 255, 255, 0));
    backward.setColor(sf::Color(255, 255, 255, 0));
    reset.setColor(sf::Color(255, 255, 255, 0));

    sf::Clock dissolveClock;

    while (Forward.getColor().a != 255 && backward.getColor().a != 255 && reset.getColor().a != 255)
    {

        float dissolvePercent = dissolveClock.getElapsedTime().asSeconds() / dissolveTime;

        Forward.setColor(sf::Color(255, 255, 255, dissolvePercent * 255));
        backward.setColor(sf::Color(255, 255, 255, dissolvePercent * 255));
        reset.setColor(sf::Color(255, 255, 255, dissolvePercent * 255));

        if (dissolvePercent >= 1.0f)
        {
            Forward.setColor(sf::Color(255, 255, 255, 255));
            backward.setColor(sf::Color(255, 255, 255, 255));
            reset.setColor(sf::Color(255, 255, 255, 255));
        }

        window.clear();
        DrawingLevels(level_index, window);
        window.draw(blur_effect);
        window.draw(win_panel);
        window.draw(first_star);
        window.draw(second_star);
        window.draw(third_star);

        if (level_index != 14)
        {
            window.draw(Forward);
        }

        if (level_index != 0)
        {
            window.draw(backward);
        }

        window.draw(reset);
        window.display();
    }
}

void DissolveEffect_won_Quit(float dissolveTime)
{
    quit_to_main_menu.setColor(sf::Color(255, 255, 255, 0));

    sf::Clock dissolveClock;
    while (quit_to_main_menu.getColor().a != 255)
    {
        float dissolvePercent = dissolveClock.getElapsedTime().asSeconds() / dissolveTime;

        quit_to_main_menu.setColor(sf::Color(255, 255, 255, static_cast<sf::Uint8>(dissolvePercent * 255)));

        if (dissolvePercent >= 1.0f)
        {
            quit_to_main_menu.setColor(sf::Color(255, 255, 255, 255));
        }

        window.clear();
        DrawingLevels(level_index, window);
        window.draw(blur_effect);
        window.draw(win_panel);
        window.draw(first_star);
        window.draw(second_star);
        window.draw(third_star);

        if (level_index != 14)
        {
            window.draw(Forward);
        }

        if (level_index != 0)
        {
            window.draw(backward);
        }

        window.draw(reset);
        window.draw(quit_to_main_menu);
        window.display();
    }
}


sf::Text out_of_bullets("YOU'RE OUT OF \n     BULLETS", game_font, 55), Try_again("TRY AGAIN?", game_font, 55);


void Lose_panel(int lvl)
{
    DrawingLevels(lvl, window);
    lose_panel.setTexture(lose_panel_texture);

    Forward.setTexture(forward_texture);
    backward.setTexture(backward_texture);
    reset.setTexture(reset_texture);

    blur_effect.setTexture(blur_effect_texture);

    if (animation)
    {
        lose_panel.setOrigin(lose_panel.getLocalBounds().width / 2, lose_panel.getLocalBounds().height / 2);
        lose_panel.setPosition(window.getSize().x / 2, window.getSize().y / -0.625);
    }

    out_of_bullets.setFillColor(sf::Color(147, 22, 22, 255));
    out_of_bullets.setOrigin(out_of_bullets.getLocalBounds().width / 2, out_of_bullets.getLocalBounds().height / 2);
    out_of_bullets.setPosition(window.getSize().x / 2, window.getSize().y / 2.788);

    Try_again.setFillColor(sf::Color(147, 22, 22, 255));
    Try_again.setOrigin(Try_again.getLocalBounds().width / 2, Try_again.getLocalBounds().height / 2);
    Try_again.setPosition(window.getSize().x / 2, window.getSize().y / 1.825);

    Forward.setOrigin(Forward.getLocalBounds().width / 2, Forward.getLocalBounds().height / 2);
    Forward.setPosition(window.getSize().x / 1.701, window.getSize().y / 1.339);

    backward.setOrigin(backward.getLocalBounds().width / 2, backward.getLocalBounds().height / 2);
    backward.setPosition(window.getSize().x / 2.427, window.getSize().y / 1.339);

    reset.setOrigin(reset.getLocalBounds().width / 2, reset.getLocalBounds().height / 2);
    reset.setPosition(window.getSize().x / 2, window.getSize().y / 1.388);

    quit_to_main_menu.setTexture(quit_to_main_menu_texture);
    quit_to_main_menu.setOrigin(quit_to_main_menu.getLocalBounds().width / 2, quit_to_main_menu.getLocalBounds().height / 2);
    quit_to_main_menu.setPosition(window.getSize().x / 6.061, window.getSize().y / 1.099);
    quit_to_main_menu.setScale(1.0f, 1.0f);

    if (animation)
    {
        float dissolveTime = 1.0f;
        Blur_effect(dissolveTime);
        Moving_down_animation(lose_panel);

        DissolveEffect_first_Text(out_of_bullets, dissolveTime);
        DissolveEffect_second_Text(Try_again, dissolveTime);
        DissolveEffect_lost_options(dissolveTime);
        DissolveEffect_lost_Quit(dissolveTime);
    }

    animation = false;

    win_lose_panels_eventloop();

    hoverEffect(quit_to_main_menu);

    window.draw(blur_effect);
    window.draw(lose_panel);
    window.draw(out_of_bullets);
    window.draw(Try_again);

    if (level_index != 14)
    {
        window.draw(Forward);
    }

    if (level_index != 0)
    {
        window.draw(backward);
    }

    window.draw(reset);
    window.draw(quit_to_main_menu);
}

void DissolveEffect_first_Text(sf::Text text, float dissolveTime)
{
    normal_eventloop();

    text.setFillColor(sf::Color(147, 22, 22, 0));

    sf::Clock dissolveClock;
    while (text.getFillColor().a != 255)
    {
        float dissolvePercent = dissolveClock.getElapsedTime().asSeconds() / dissolveTime;

        text.setFillColor(sf::Color(147, 22, 22, (dissolvePercent * 255)));

        if (dissolvePercent >= 1.0f)
        {
            text.setFillColor(sf::Color(147, 22, 22, 255));
        }

        window.clear();
        DrawingLevels(level_index, window);
        window.draw(blur_effect);
        window.draw(lose_panel);
        window.draw(text);
        window.display();
    }
}

void DissolveEffect_second_Text(sf::Text text, float dissolveTime)
{
    normal_eventloop();

    text.setFillColor(sf::Color(147, 22, 22, 0));

    sf::Clock dissolveClock;
    while (text.getFillColor().a != 255)
    {
        float dissolvePercent = dissolveClock.getElapsedTime().asSeconds() / dissolveTime;

        text.setFillColor(sf::Color(147, 22, 22, static_cast<sf::Uint8>(dissolvePercent * 255)));

        if (dissolvePercent >= 1.0f)
        {
            text.setFillColor(sf::Color(147, 22, 22, 255));
        }

        window.clear();
        DrawingLevels(level_index, window);
        window.draw(blur_effect);
        window.draw(lose_panel);
        window.draw(out_of_bullets);
        window.draw(text);
        window.display();
    }
}

void DissolveEffect_lost_options(float dissolveTime)
{
    normal_eventloop();
    Forward.setColor(sf::Color(255, 255, 255, 0));
    backward.setColor(sf::Color(255, 255, 255, 0));
    reset.setColor(sf::Color(255, 255, 255, 0));

    sf::Clock dissolveClock;

    while (Forward.getColor().a != 255 && backward.getColor().a != 255 && reset.getColor().a != 255)
    {

        float dissolvePercent = dissolveClock.getElapsedTime().asSeconds() / dissolveTime;

        Forward.setColor(sf::Color(255, 255, 255, dissolvePercent * 255));
        backward.setColor(sf::Color(255, 255, 255, dissolvePercent * 255));
        reset.setColor(sf::Color(255, 255, 255, dissolvePercent * 255));

        if (dissolvePercent >= 1.0f)
        {
            Forward.setColor(sf::Color(255, 255, 255, 255));
            backward.setColor(sf::Color(255, 255, 255, 255));
            reset.setColor(sf::Color(255, 255, 255, 255));
        }

        window.clear();
        DrawingLevels(level_index, window);
        window.draw(blur_effect);
        window.draw(lose_panel);
        window.draw(out_of_bullets);
        window.draw(Try_again);

        if (level_index != 14)
        {
            window.draw(Forward);
        }

        if (level_index != 0)
        {
            window.draw(backward);
        }

        window.draw(reset);
        window.display();
    }

}

void DissolveEffect_lost_Quit(float dissolveTime)
{
    quit_to_main_menu.setColor(sf::Color(255, 255, 255, 0));

    sf::Clock dissolveClock;
    while (quit_to_main_menu.getColor().a != 255)
    {
        float dissolvePercent = dissolveClock.getElapsedTime().asSeconds() / dissolveTime;

        quit_to_main_menu.setColor(sf::Color(255, 255, 255, static_cast<sf::Uint8>(dissolvePercent * 255)));

        if (dissolvePercent >= 1.0f)
        {
            quit_to_main_menu.setColor(sf::Color(255, 255, 255, 255));
        }

        window.clear();
        DrawingLevels(level_index, window);
        window.draw(blur_effect);
        window.draw(lose_panel);
        window.draw(out_of_bullets);
        window.draw(Try_again);

        if (level_index != 14)
        {
            window.draw(Forward);
        }


        if (level_index != 0)
        {
            window.draw(backward);
        }

        window.draw(reset);
        window.draw(quit_to_main_menu);
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
        DrawingLevels(level_index, window);
        window.draw(blur_effect);
        if (delay.getElapsedTime().asSeconds() > 0.25)
        {
            panel.move(0, window.getSize().y / 50);
            window.draw(panel);
        }
        window.display();
    }

}

void Blur_effect(float dissolveTime)
{
    normal_eventloop();

    blur_effect.setColor(sf::Color(255, 255, 255, 0));

    sf::Clock dissolveClock;

    while(blur_effect.getColor().a != 255)
    {
        float dissolvePercent = dissolveClock.getElapsedTime().asSeconds() / dissolveTime;

        blur_effect.setColor(sf::Color(255, 255, 255, dissolvePercent * 255));

        if (dissolvePercent >= 1.0f)
        {
            blur_effect.setColor(sf::Color(255, 255, 255, 255));
        }

        window.clear();
        DrawingLevels(level_index, window);
        window.draw(blur_effect);
        window.display();
    }
}

void Reset()
{
    dead_enemies = 0;
    lev[level_index].num_of_bullets = lev[level_index].Return_num;
    for (int i = 0; i < 100; i++)
    {
        lev[level_index].target[i].alive = true;
        lev[level_index].target[i].dead = false;
        character_show(lev[level_index].target[i]);
    }
    cout << lev[level_index].num_of_bullets << endl;

    if (level_index == 0)
        constructlev1(window);
    else if (level_index == 1)
        constructlev2(window);
    else if (level_index == 2)
        constructlev3(window);
    else if (level_index == 3)
        constructlev4(window);
    else if (level_index == 4)
        constructlev5(window);
    cout << lev[level_index].num_of_bullets << endl;
    for (int i = bullets.size() - 1; i >= 0; i--)
    {
        bullets[i].clock.restart();
        bullets.erase(bullets.begin() + i);
        std::cout << "erased";
    }
}

void stars_system(int three_stars, int two_stars, int one_star, int zero_stars)
{

    if (lev[level_index].num_of_bullets >= three_stars)
    {
        lev[level_index].view.Level_evaluation = 3;
    }

    else if (lev[level_index].num_of_bullets >= two_stars)
    {
        lev[level_index].view.Level_evaluation = 2;
    }

    else if (lev[level_index].num_of_bullets >= one_star)
    {
        lev[level_index].view.Level_evaluation = 1;
    }

    else if (lev[level_index].num_of_bullets >= zero_stars)
    {
        lev[level_index].view.Level_evaluation = 0;
    }

    if (lev[level_index].view.Level_evaluation > lev[level_index].view.highest_score)
    {
        lev[level_index].view.highest_score = lev[level_index].view.Level_evaluation;
    }

}



