#pragma once


void duels();
void collision (Bullet& b, Character& shotPlayer);
void resetDuels();
void healthBar(Character playerOneHealth, Character playerTwoHealth);
void duelsPauseMenu();
void duelsOptionMenu();


extern RectangleShape back;
extern RectangleShape victory_menu;
extern RectangleShape victory_menu_2;
extern RectangleShape restart;
extern RectangleShape hundred_health;
extern RectangleShape seventy_health;
extern RectangleShape forty_health;
extern RectangleShape ten_health;
extern RectangleShape zero_health;
extern RectangleShape hundred_health_2;
extern RectangleShape seventy_health_2;
extern RectangleShape forty_health_2;
extern RectangleShape ten_health_2;
extern RectangleShape zero_health_2;

extern bool collided;



extern Texture victory_texture;
extern Texture victory_texture_2;
extern Texture restart_texture;
extern Texture back_texture;
extern Texture hundred_health_texture;
extern Texture seventy_health_texture;
extern Texture forty_health_texture;
extern Texture ten_health_texture;
extern Texture zero_health_texture;
extern Texture hundred_health_texture_2;
extern Texture seventy_health_texture_2;
extern Texture forty_health_texture_2;
extern Texture ten_health_texture_2;
extern Texture zero_health_texture_2;

extern Character playerOne;
extern Character playerTwo;


//#endif
