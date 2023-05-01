#include "Physics.h"
#include "Sprites.h"
#include "Levels.h"
#include <cmath>

using namespace sf;
//using namespace std;

//Vector2f bulletDirection;

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


void DirectBullet(Bullet& b, Event e, Vector2i mousep, int lvlNum) //  Takes bullet and event from pollEvent as parameters
{
    if (lvlNum == -1)
        return;
    for (int i = 0; i < bullets.size(); i++)
    {
        b.bulletBody.setPosition(lev[lvlNum].killer.body.getPosition());                        /*- helmy -*/
        b.bulletDirection = b.bulletBody.getPosition() - Vector2f(mousep);
        b.bulletDirection = NormalizeVector(b.bulletDirection);
    }
}

void HandlePhysics(Lev& l, Bullet& b) {
    if (b.bulletBody.getGlobalBounds().intersects(l.ground.getGlobalBounds()))
        RicochetBullet(b, l.ground);
    for (int i = 0; i < 10; i++) {
        if (b.bulletBody.getGlobalBounds().intersects(l.shape[i].getGlobalBounds()))
            RicochetBullet(b, l.shape[i]);
    }
    for (int i = 0; i < 10; i++) {
        if (b.bulletBody.getGlobalBounds().intersects(l.block[i].getGlobalBounds()))
            RicochetBullet(b, l.block[i]);
    }
}

void CollideEnemies(Lev& l, Bullet& b) {
    for (int i = 0; i < 10; i++) {
        if (b.bulletBody.getGlobalBounds().intersects(l.target[i].body.getGlobalBounds())) {
            l.target[i].dead = true;
            //Death Animation                                                   /* helmy */
        }
        if (b.bulletBody.getGlobalBounds().intersects(l.target[i].head.getGlobalBounds())) {
            l.target[i].dead = true;
            //Death Animation                                                   /* helmy */
        }
        if (b.bulletBody.getGlobalBounds().intersects(l.target[i].left_arm1.getGlobalBounds())) {
            l.target[i].dead = true;
            //Death Animation                                                   /* helmy */
        }
        if (b.bulletBody.getGlobalBounds().intersects(l.target[i].left_arm2.getGlobalBounds())) {
            l.target[i].dead = true;
            //Death Animation                                                   /* helmy */
        }
        if (b.bulletBody.getGlobalBounds().intersects(l.target[i].right_arm1.getGlobalBounds())) {
            l.target[i].dead = true;
            //Death Animation                                                   /* helmy */
        }
        if (b.bulletBody.getGlobalBounds().intersects(l.target[i].right_arm2.getGlobalBounds())) {
            l.target[i].dead = true;
            //Death Animation                                                   /* helmy */
        }
        if (b.bulletBody.getGlobalBounds().intersects(l.target[i].left_leg1.getGlobalBounds())) {
            l.target[i].dead = true;
            //Death Animation                                                   /* helmy */
        }
        if (b.bulletBody.getGlobalBounds().intersects(l.target[i].left_leg2.getGlobalBounds())) {
            l.target[i].dead = true;
            //Death Animation                                                   /* helmy */
        }
        if (b.bulletBody.getGlobalBounds().intersects(l.target[i].right_leg1.getGlobalBounds())) {
            l.target[i].dead = true;
            //Death Animation                                                   /* helmy */
        }
        if (b.bulletBody.getGlobalBounds().intersects(l.target[i].right_leg2.getGlobalBounds())) {
            l.target[i].dead = true;
            //Death Animation                                                   /* helmy */
        }
    }
}

void RicochetBullet(Bullet& b, RectangleShape w)
{
    // Check if the bullet is colliding with the wall
    if (b.bulletBody.getGlobalBounds().intersects(w.getGlobalBounds()))
    {
        FloatRect bBounds = b.bulletBody.getGlobalBounds();
        FloatRect wBounds = w.getGlobalBounds();

        // Determine which side the bullet is colliding with
        if (bBounds.top < wBounds.top) // colliding with top side
        {
            b.bulletDirection.y = abs(b.bulletDirection.y); // flip y component to go down
        }
        else if (bBounds.top + bBounds.height > wBounds.top + wBounds.height) // colliding with bottom side
        {
            b.bulletDirection.y = -abs(b.bulletDirection.y); // flip y component to go up
        }

        if (bBounds.left < wBounds.left) // colliding with left side
        {
            b.bulletDirection.x = abs(b.bulletDirection.x); // flip x component to go right
        }
        else if (bBounds.left + bBounds.width > wBounds.left + wBounds.width) // colliding with right side
        {
            b.bulletDirection.x = -abs(b.bulletDirection.x); // flip x component to go left
        }
    }
}




void RicochetBullet(Bullet& b, CircleShape w) // Takes bullet and wall as parameters
{
    bool hitCircle = false;

    // Get the center and radius of the circle shape
    Vector2f wallCenter = w.getPosition() + Vector2f(w.getRadius(), w.getRadius());
    float wallRadius = w.getRadius();

    // Check if the bullet intersects the circle shape
    FloatRect bulletBounds = b.bulletBody.getGlobalBounds();
    Vector2f bulletCenter = b.bulletBody.getPosition() + Vector2f(b.bulletBody.getRadius(), b.bulletBody.getRadius());
    Vector2f distance = bulletCenter - wallCenter;
    float distanceMagnitude = sqrt(distance.x * distance.x + distance.y * distance.y);
    if (distanceMagnitude <= (wallRadius + b.bulletBody.getRadius())) {
        hitCircle = true;
    }

    if (hitCircle) {
        // Calculate the normal vector of the collision
        Vector2f normal = NormalizeVector(distance);

        // Calculate the new direction of the bullet
        b.bulletDirection = b.bulletDirection - 2 * dot(b.bulletDirection, normal) * normal;

        // Move the bullet outside of the circle shape
        Vector2f newPosition = wallCenter + (wallRadius + b.bulletBody.getRadius()) * NormalizeVector(distance);
        b.bulletBody.setPosition(newPosition);
    }
}
