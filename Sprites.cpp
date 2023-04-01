#include "Sprites.h"
#include <SFML/Graphics.hpp>

//  Shapes & sprites declaration:
CircleShape bullet(5.f);
CircleShape ring(150.f);
RectangleShape wall1(Vector2f(1920.f, 10.f));
RectangleShape wall2(Vector2f(10.f, 1080.f));
RectangleShape wall3(Vector2f(1920.f, 10.f));
RectangleShape wall4(Vector2f(10.f, 1080.f));
RectangleShape box(Vector2f(300.f, 300.f));
RectangleShape walls[] = {wall1, wall2, wall3, wall4};
//CircleShape triangle(10, 3);


void sprites() {
	bullet.setFillColor(sf::Color::Red);
	bullet.setOrigin(2.5, 2.5);
	//triangle.setOrigin(5, 5);

	wall3.setPosition(0.f, 1080);
	wall4.setPosition(1910, 0);
	box.setPosition(1920 / 2 - 500, 1080 / 2 - 150);
	ring.setPosition(1920/2 + 150, 1080/2 - 150);
	//triangle.setPosition(box.getPosition());
	//triangle.setFillColor(Color::Blue);
	//triangle.setRotation(45);

	wall1.setFillColor(Color::Cyan);
	wall2.setFillColor(Color::Cyan);
	wall3.setFillColor(Color::Cyan);
	wall4.setFillColor(Color::Cyan);
	box.setFillColor(Color::Cyan);
	ring.setFillColor(Color::Cyan);
	
	wall1.setRotation(0);
	wall2.setRotation(0);
	wall3.setRotation(0);
	wall4.setRotation(0);


}
