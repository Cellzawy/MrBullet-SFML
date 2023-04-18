#include <SFML/Graphics.hpp>
#include <iostream>
#include "Sprites.h"
#include "Physics.h"
#include "Levels.h"


// Levels test
int main() {
	RenderWindow window(VideoMode(1920, 1080), "Levels");

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
                }
            }
		}
        
		window.clear();

		if (levCounter == 1) // ==> constructing level 1
		{
			constructlev1(window);
		}


		else if (levCounter == 2) // ==> constructing level 2
		{
			constructlev2(window);
		}


		else if (levCounter == 3) // ==> constructing level 3
		{
            constructlev3(window);
		}
       

        else if (levCounter == 4)   // ==> constructing level 4
        {
            constructlev4(window);
            
        } else {
            levCounter = 1;
        }
		window.display();
	}
}


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