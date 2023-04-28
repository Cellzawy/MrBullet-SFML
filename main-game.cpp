#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "Sprites.h"
#include "Physics.h"
#include "Levels.h"
#include "Menus.h"
#include "win-lose-logic.h"


sf::RenderWindow window(sf::VideoMode(1920, 1080), "Mr bullet", sf::Style::Fullscreen);

// Menus test
int main() {
    window.setFramerateLimit(30);

    Texture_loading();

    SFX_click.setBuffer(SFX_click_soundbuffer);

    mainmenu_music.openFromFile("assets/sounds/main_music.ogg");
    mainmenu_music.play();
    mainmenu_music.setLoop(true);
    constructlev1(window);

    while(window.isOpen())
    {
        // drawing

        window.clear();

        if (current_menu == main_menu)
        {
            Main_menu();
        }

        else if (current_menu == play_menu)
        {
            Play_menu();
        }


        else if (current_menu == options_menu)
        {
            Options_menu();
        }


        else if (current_menu == classic_Mode)
        {
            Classic_menu();
        }

        else if (current_menu == achievements_menu)
        {
            Achievements_menu();
        }

        else if (current_menu == level_1)
        {
            //window.draw(lev1.bg);
            //window.draw(lev1.ground);
            //character_draw(lev1.killer, window);
            //character_draw(lev1.target[0], window);
            Win_panel();
        }

        else if (current_menu == level_2)
        {
            window.close();
        }

        else if (current_menu == level_3)
        {

        }

        else if (current_menu == level_4)
        {

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



//Cellz

/*
Vector2f startPosition;
Vector2f endPosition;


int main()
{
    RenderWindow window(VideoMode(1920, 1080), "SFML works!", Style::Fullscreen);
    bullet.setPosition(200, 200);
    window.setFramerateLimit(144);
    Clock clock;
    bool bulletFired = false;
    bool bulletExists = false;
    sf::Music music;

    sf::Sound SFX_click;

    sf::SoundBuffer SFX_click_soundbuffer;

    while (window.isOpen())
    {
        sprites();

        // Moving the bullet
        for (int i = 0; i < bullets.size(); i++) {
            bullets[i].bulletBody.setPosition(bullets[i].bulletBody.getPosition() - bullets[i].bulletDirection * 12.f);
        }

        if (bullets.size() != 0)
        {
            for (int i = 0; i < bullets.size(); i++)
            {
                Time elapsed = bullets[i].clock.getElapsedTime();
                if (elapsed >= seconds(5.f))
                {
                    cout << "erased" << endl;
                    bulletExists = false;
                    bullets.erase(bullets.begin() + i);
                    clock.restart();
                }
            }
        }

        Event event;

        while (window.pollEvent(event))
        {
            switch (event.type) {
            case Event::Closed:
                window.close();
                break;
            case Event::MouseButtonReleased:
                if (event.mouseButton.button == Mouse::Left && !Mouse::isButtonPressed(Mouse::Right)) {
                    cout << "yes";
                    Vector2i mousepos = Mouse::getPosition(window);
                    Bullet newBullet;
                    newBullet.bulletBody = bullet;
                    bullets.push_back(newBullet);
                    DirectBullet(bullets[bullets.size() - 1], event, mousepos);
                    bulletFired = true;
                    bulletExists = true;
                }
                break;
            default:
                break;
            }
        }


        window.clear();
        for (int i = 0; i < bullets.size(); i++) {
            window.draw(bullets[i].bulletBody);
        }
        //window.draw(triangle);
        window.display();
    }
    return 0;
}
*/
