#include "Physics.h"
#include "Sprites.h"
#include <cmath>
#include <SFML/Graphics.hpp>

using namespace sf;

Vector2f bulletDirection;

Vector2f NormalizeVector(Vector2f vector) //  Gets the vector required to move the bullets
{
	float m = sqrt(vector.x * vector.x + vector.y * vector.y);
	Vector2f normalizedVector;
	normalizedVector.x = vector.x / m;
	normalizedVector.y = vector.y / m;

	return normalizedVector;
}

void DirectBullet(CircleShape b, Event e, Vector2i mousep) //  Takes bullet and event from pollEvent as parameters
{
	bulletDirection = bullet.getPosition() - Vector2f(mousep);
	bulletDirection = NormalizeVector(bulletDirection);
}

void RicochetBullet(CircleShape b, RectangleShape w) //  Takes bullet and wall as parameters
{
	if (w.getRotation() == 0) {
		bulletDirection = Vector2f(bulletDirection.x, -1 * bulletDirection.y);
	}
	else if (w.getRotation() == 90) {
		bulletDirection = Vector2f(-1 * bulletDirection.x, bulletDirection.y);
	}
}
