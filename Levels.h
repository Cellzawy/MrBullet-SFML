#ifndef LEVELS
#define LEVELS
#include <SFML/Graphics.hpp>
#include "Sprites.h"
#include "Menus.h"
//#include "Physics.h"

using namespace sf;




void constructlev1(RenderWindow& window);
void constructlev2(RenderWindow& window);
void constructlev3(RenderWindow& window);
void constructlev4(RenderWindow& window);
void DrawingLevels(int num, RenderWindow& window);

#endif
