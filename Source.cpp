#include <SFML/Graphics.hpp>
#include <iostream>
#include "Sprites.h"
#include "Physics.h"


int main()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "SFML works!");
    bullet.setPosition(1920 / 2, 1080 / 2);
    window.setFramerateLimit(144);

    while (window.isOpen())
    {
        sprites();

        // Moving the bullet
        Vector2i mousepos = Mouse::getPosition(window);
        bullet.setPosition(bullet.getPosition() - bulletDirection * 10.f);

        // Ricochet the bullet
        if (bullet.getGlobalBounds().intersects(wall1.getGlobalBounds())) {
            cout << "yes";
            RicochetBullet(bullet, wall1);
        }
        if (bullet.getGlobalBounds().intersects(wall2.getGlobalBounds())) {
            cout << "yes";
            RicochetBullet(bullet, wall2);
        }
        if (bullet.getGlobalBounds().intersects(wall3.getGlobalBounds())) {
            cout << "yes";
            RicochetBullet(bullet, wall3);
        }
        if (bullet.getGlobalBounds().intersects(wall4.getGlobalBounds())) {
            cout << "yes";
            RicochetBullet(bullet, wall4);
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


        window.clear();
        window.draw(bullet);
        window.draw(wall1);
        window.draw(wall2);
        window.draw(wall3);
        window.draw(wall4);
        window.display();
    }
    return 0;
}
