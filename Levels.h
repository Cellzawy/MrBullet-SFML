#ifndef LEVELS
#define LEVELS
#include <SFML/Graphics.hpp>
#include "Sprites.h"
#include "Menus.h"
//#include "Physics.h"

using namespace sf;

extern int dead_enemies;
extern int level_index;
extern sf::VertexArray line;

void constructlev1(RenderWindow& window);
void constructlev2(RenderWindow& window);
void constructlev3(RenderWindow& window);
void constructlev4(RenderWindow& window);
void constructlev5(RenderWindow& window);
void constructlev6(RenderWindow& window);
void constructlev7(RenderWindow& window);
void constructlev8(RenderWindow& window);
void constructlev9(RenderWindow& window);
void constructlev10(RenderWindow& window);
void constructlev11(RenderWindow& window);
void constructlev12(RenderWindow& window);
void constructlev13(RenderWindow& window);
void constructlev14(RenderWindow& window);
void constructlev15(RenderWindow& window);
void constructOneVSone(RenderWindow& window);

void DrawingLevels(int num, RenderWindow& window);

#endif
