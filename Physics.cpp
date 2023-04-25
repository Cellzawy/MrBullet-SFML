#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cmath>
#include "Sprites.h"

using namespace sf;
using namespace std;

Vector2f bulletDirection;

float dot(sf::Vector2f v1, sf::Vector2f v2)
{
    return v1.x * v2.x + v1.y * v2.y;
}

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

void RicochetBullet(CircleShape b, RectangleShape w) // Takes bullet and wall as parameters
{
    bool hitHorizontalSide = false;
    bool hitVerticalSide = false;

    if (b.getGlobalBounds().intersects(w.getGlobalBounds()) || b.getRadius() < w.getSize().x) {

        if (b.getGlobalBounds().top < w.getGlobalBounds().top) {
            bulletDirection = Vector2f(bulletDirection.x, -1 * bulletDirection.y);
            hitHorizontalSide = true;
        }
        else if (b.getGlobalBounds().top + b.getGlobalBounds().height > w.getGlobalBounds().top + w.getGlobalBounds().height) {
            bulletDirection = Vector2f(bulletDirection.x, -1 * bulletDirection.y);
            hitHorizontalSide = true;
        }

        if (b.getGlobalBounds().left < w.getGlobalBounds().left) {
            bulletDirection = Vector2f(-1 * bulletDirection.x, bulletDirection.y);
            hitVerticalSide = true;
        }
        else if (b.getGlobalBounds().left + b.getGlobalBounds().width > w.getGlobalBounds().left + w.getGlobalBounds().width) {
            bulletDirection = Vector2f(-1 * bulletDirection.x, bulletDirection.y);
            hitVerticalSide = true;
        }

        // handle corner collision
        if (hitHorizontalSide && hitVerticalSide) {
            FloatRect bulletBounds = b.getGlobalBounds();
            FloatRect wallBounds = w.getGlobalBounds();
            Vector2f bulletPosition = b.getPosition();
            Vector2f overlap;

            if (bulletPosition.x < wallBounds.left) {
                // bullet hits left side of wall
                if (bulletPosition.y < wallBounds.top) {
                    // bullet hits top side of wall
                    overlap.x = bulletBounds.left + bulletBounds.width - wallBounds.left;
                    overlap.y = bulletBounds.top + bulletBounds.height - wallBounds.top;

                    // determine which side the bullet should be moved to
                    if (overlap.x < overlap.y) {
                        bulletPosition.x -= overlap.x;
                        bulletDirection.x *= -1;
                    }
                    else {
                        bulletPosition.y -= overlap.y;
                        bulletDirection.y *= -1;
                    }
                }
                else if (bulletPosition.y > wallBounds.top + wallBounds.height) {
                    // bullet hits bottom side of wall
                    overlap.x = bulletBounds.left + bulletBounds.width - wallBounds.left;
                    overlap.y = wallBounds.top + wallBounds.height - bulletBounds.top;

                    // determine which side the bullet should be moved to
                    if (overlap.x < overlap.y) {
                        bulletPosition.x -= overlap.x;
                        bulletDirection.x *= -1;
                    }
                    else {
                        bulletPosition.y += overlap.y;
                        bulletDirection.y *= -1;
                    }
                }
            }
            else if (bulletPosition.x > wallBounds.left + wallBounds.width) {
                // bullet hits right side of wall
                if (bulletPosition.y < wallBounds.top) {
                    // bullet hits top side of wall
                    overlap.x = wallBounds.left + wallBounds.width - bulletBounds.left;
                    overlap.y = bulletBounds.top + bulletBounds.height - wallBounds.top;

                    // determine which side the bullet should be moved to
                    if (overlap.x < overlap.y) {
                        bulletPosition.x += overlap.x;
                        bulletDirection.x *= -1;
                    }
                    else {
                        bulletPosition.y -= overlap.y;
                        bulletDirection.y *= -1;
                    }
                }
                else if (bulletPosition.y > wallBounds.top + wallBounds.height) {
                    // bullet hits bottom side of wall
                    overlap.x = wallBounds.left + wallBounds.width - bulletBounds.left;
                    overlap.y = wallBounds.top + wallBounds.height - bulletBounds.top;

                    // determine which side the bullet should be moved to
                    if (overlap.x < overlap.y) {
                        bulletPosition.x += overlap.x;
                        bulletDirection.x *= -1;
                    }
                    else {
                        bulletPosition.y += overlap.y;
                        bulletDirection.y *= -1;
                    }
                }
            }

            b.setPosition(bulletPosition);
        }
    }
}

void RicochetBullet(CircleShape b, CircleShape w) // Takes bullet and wall as parameters
{
    bool hitCircle = false;

    // Get the center and radius of the circle shape
    Vector2f wallCenter = w.getPosition() + Vector2f(w.getRadius(), w.getRadius());
    float wallRadius = w.getRadius();

    // Check if the bullet intersects the circle shape
    FloatRect bulletBounds = b.getGlobalBounds();
    Vector2f bulletCenter = b.getPosition() + Vector2f(b.getRadius(), b.getRadius());
    Vector2f distance = bulletCenter - wallCenter;
    float distanceMagnitude = sqrt(distance.x * distance.x + distance.y * distance.y);
    if (distanceMagnitude <= (wallRadius + b.getRadius())) {
        hitCircle = true;
    }

    if (hitCircle) {
        // Calculate the normal vector of the collision
        Vector2f normal = NormalizeVector(distance);

        // Calculate the new direction of the bullet
        bulletDirection = bulletDirection - 2 * dot(bulletDirection, normal) * normal;

        // Move the bullet outside of the circle shape
        Vector2f newPosition = wallCenter + (wallRadius + b.getRadius()) * NormalizeVector(distance);
        b.setPosition(newPosition);
    }
}
