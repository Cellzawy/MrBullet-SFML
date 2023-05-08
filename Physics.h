#ifndef PHYSICS
#define PHYSICS
#include "Sprites.h"
#include "Levels.h"


#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

extern Vector2f gunPos;

float dot(sf::Vector2f v1, sf::Vector2f v2); // Gets the dot product of two vectors

Vector2f NormalizeVector(Vector2f vector); //  Gets the vector required to move the bullets


void DirectBullet(Bullet& b, Event e, Vector2i mousep, int lvlNum, Vector2f gunPos); //  Takes bullet and event from pollEvent as parameters

void HandlePhysics(Lev& l, Bullet& b);

void RicochetBullet(Bullet& b, RectangleShape w); //  Takes bullet and wall as parameters

void RicochetBullet(Bullet& b, CircleShape w); // Takes bullet and wall as parameters

void CollideEnemies(Lev& l, Bullet& b);

#endif
