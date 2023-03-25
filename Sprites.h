#pragma once
using namespace std;
using namespace sf;

//  Shapes & sprites declaration:
CircleShape bullet(10.f);
RectangleShape wall1(Vector2f(1920.f, 10.f));
RectangleShape wall2(Vector2f(1920.f, 10.f));
RectangleShape wall3(Vector2f(1920.f, 10.f));
RectangleShape wall4(Vector2f(1920.f, 10.f));
RectangleShape walls[] = {wall1, wall2, wall3, wall4};


void sprites() {
	bullet.setFillColor(sf::Color::Red);
	bullet.setOrigin(5, 5);
	wall2.setPosition(10, 0);
	wall3.setPosition(0.f, 1070);
	wall4.setPosition(1920, 0);
	wall1.setFillColor(Color::Cyan);
	wall2.setFillColor(Color::Cyan);
	wall3.setFillColor(Color::Cyan);
	wall4.setFillColor(Color::Cyan);
	
	wall1.setRotation(0);
	wall2.setRotation(90);
	wall3.setRotation(0);
	wall4.setRotation(90);
}
