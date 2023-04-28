#ifndef PHYSICS
#define PHYSICS

#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

//extern Vector2f bulletDirection;

float dot(sf::Vector2f v1, sf::Vector2f v2); // Gets the dot product of two vectors

Vector2f NormalizeVector(Vector2f vector); //  Gets the vector required to move the bullets


void DirectBullet(CircleShape b, Event e, Vector2i mousep); //  Takes bullet and event from pollEvent as parameters


void RicochetBullet(CircleShape b, RectangleShape w); //  Takes bullet and wall as parameters

void RicochetBullet(CircleShape b, CircleShape w); // Takes bullet and wall as parameters

#endif
