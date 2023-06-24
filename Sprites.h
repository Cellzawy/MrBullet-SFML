#ifndef SPRITES
#define SPRITES
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

//  Shapes & sprites declaration:
extern CircleShape bullet;
extern CircleShape ring;
extern RectangleShape wall1;
extern RectangleShape wall2;
extern RectangleShape wall3;
extern RectangleShape wall4;
extern RectangleShape box;
extern Sprite crosshair;
extern Texture crosshairTx;
extern RectangleShape walls[];

struct Bullet {
    CircleShape bulletBody;
    CircleShape b;
    Vector2f bulletDirection;
    Clock clock;
};

extern vector<Bullet>bullets;

void sprites();




struct Character {
    bool flip;
    sf::Texture head_texture;
    sf::Texture body_texture;

    sf::Sprite head;
    sf::Sprite body;
    sf::Sprite left_arm1;
    sf::Sprite left_arm2;
    sf::Sprite right_arm1;
    sf::Sprite right_arm2;
    sf::Sprite left_leg1;
    sf::Sprite left_leg2;
    sf::Sprite right_leg1;
    sf::Sprite right_leg2;
    sf::RectangleShape gun;

    bool dead = false;
    bool alive = true;
    bool has_gun = false;
    sf::Vector2f bullet_pos;
    float arm_scale;
    int health = 100;
    bool turn = true;
    sf::Texture steam_texture;
    sf::Sprite steam;
    sf::Clock clock;
    double framex = 0, framey = 0;

    sf::Texture player_arrow_texture;
    sf::Sprite player_arrow;
    bool show_player_arrow = false;
    bool player_arrow_exist = false;
};

void character_set_position(Character &character, sf::Vector2f pos);
void character_set_scale(Character &character, float scale);
void character_init(Character &character, std::string head_path, std::string body_path, bool flip);
void character_draw(Character &character, sf::RenderWindow &window);
void character_rotate_arm(Character &character, sf::Vector2i mouse_position);
void character_dead(Character& character);
void character_show(Character& character);
void character_set_player_arrow(Character& character, std::string player_arrow_path);
void character_show_player_arrow(Character& character, bool show_player_arrow);
#endif
