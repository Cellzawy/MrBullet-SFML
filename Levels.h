#ifndef LEVELS
#define LEVELS
#include <SFML/Graphics.hpp>
#include "Sprites.h"

using namespace sf;

struct level {
    Texture BG;

    Texture GROUND[10];

    Texture BLOCK[10];

    Texture SHAPES[10];

    Sprite bg;

    RectangleShape ground, shape[10];

    RectangleShape block[10];

    Character killer, target[100];

};

extern level lev[10];

void constructlev1(RenderWindow& window);
void constructlev2(RenderWindow& window);
void constructlev3(RenderWindow& window);
void constructlev4(RenderWindow& window);
void DrawingLevels(int num, RenderWindow& window);

#endif
