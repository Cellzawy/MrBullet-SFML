#include "Sprites.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cmath>
#include "Menus.h"

//  Shapes & sprites declaration:
Bullet duelsbullet;
CircleShape bullet(5.f);
CircleShape ring(150.f);
RectangleShape wall1(Vector2f(1920.f, 10.f));
RectangleShape wall2(Vector2f(10.f, 1080.f));
RectangleShape wall3(Vector2f(1920.f, 10.f));
RectangleShape wall4(Vector2f(10.f, 1080.f));
RectangleShape box(Vector2f(300.f, 300.f));
RectangleShape walls[] = {wall1, wall2, wall3, wall4};
vector<Bullet> bullets = { duelsbullet };
Texture crosshairTx;
Sprite crosshair;
//CircleShape triangle(10, 3);


void sprites() {
	//bullet.setFillColor(sf::Color::Red);
	//bullet.setOrigin(2.5, 2.5);
	////triangle.setOrigin(5, 5);

	//wall3.setPosition(0.f, 1080);
	//wall4.setPosition(1910, 0);
	//box.setPosition(1920 / 2 - 500, 1080 / 2 - 150);
	//ring.setPosition(1920/2 + 150, 1080/2 - 150);
	////triangle.setPosition(box.getPosition());
	////triangle.setFillColor(Color::Blue);
	////triangle.setRotation(45);

	//wall1.setFillColor(Color::Cyan);
	//wall2.setFillColor(Color::Cyan);
	//wall3.setFillColor(Color::Cyan);
	//wall4.setFillColor(Color::Cyan);
	//box.setFillColor(Color::Cyan);
	//ring.setFillColor(Color::Cyan);

	//wall1.setRotation(0);
	//wall2.setRotation(0);
	//wall3.setRotation(0);
	//wall4.setRotation(0);
}

void character_set_position(Character &character, sf::Vector2f pos) {
    float scale = character.body.getScale().x;
    character.left_arm1.setOrigin(sf::Vector2f(27, 27));
    character.left_arm2.setOrigin(sf::Vector2f(27, -67));
    character.gun.setOrigin(sf::Vector2f(-27, -165));
    character.right_arm1.setOrigin(sf::Vector2f(27, 27));
    character.right_arm2.setOrigin(sf::Vector2f(27, 27));
    if (character.flip) {
        character.body.setOrigin(sf::Vector2f(character.body.getLocalBounds().width, 0));
        character.body.setScale(sf::Vector2f(-scale, scale));
        character.head.setOrigin(sf::Vector2f(character.head.getLocalBounds().width, 0));
        character.head.setScale(sf::Vector2f(-scale, scale));
        character.left_arm1.setOrigin(sf::Vector2f(character.left_arm1.getLocalBounds().width, 0));
        character.left_arm1.setScale(sf::Vector2f(-scale, scale));
        character.left_arm2.setOrigin(sf::Vector2f(character.left_arm2.getLocalBounds().width, 0));
        character.left_arm2.setScale(sf::Vector2f(-scale, scale));
        character.right_arm1.setOrigin(sf::Vector2f(character.right_arm1.getLocalBounds().width, 0));
        character.right_arm1.setScale(sf::Vector2f(-scale, scale));
        character.right_arm2.setOrigin(sf::Vector2f(character.right_arm2.getLocalBounds().width, 0));
        character.right_arm2.setScale(sf::Vector2f(-scale, scale));
        character.left_leg1.setOrigin(sf::Vector2f(character.left_leg1.getLocalBounds().width, 0));
        character.left_leg1.setScale(sf::Vector2f(-scale, scale));
        character.left_leg2.setOrigin(sf::Vector2f(character.left_leg2.getLocalBounds().width, 0));

        character.left_arm1.setOrigin(sf::Vector2f(27, 27));
        character.left_arm2.setOrigin(sf::Vector2f(27, -67));
        character.gun.setOrigin(sf::Vector2f(57, -165));
        character.right_arm1.setOrigin(sf::Vector2f(27, 27));
        character.right_arm2.setOrigin(sf::Vector2f(27, 27));

        character.left_leg2.setScale(sf::Vector2f(-scale, scale));
        character.right_leg1.setOrigin(sf::Vector2f(character.right_leg1.getLocalBounds().width, 0));
        character.right_leg1.setScale(sf::Vector2f(-scale, scale));
        character.right_leg2.setOrigin(sf::Vector2f(character.right_leg2.getLocalBounds().width, 0));
        character.right_leg2.setScale(sf::Vector2f(-scale, scale));

        character.head.setPosition(pos + sf::Vector2f(character.body.getGlobalBounds().width / 2 - character.head.getGlobalBounds().width / 2 - 4 * character.head.getScale().y, 0));
        character.body.setPosition(pos + sf::Vector2f(0, character.head.getGlobalBounds().height));

        // flip left and right arm
        character.right_arm1.setPosition(pos + sf::Vector2f(-2 * character.head.getScale().x, character.head.getGlobalBounds().height - 37 * character.head.getScale().x));  // flip signs
        character.right_arm2.setPosition(character.right_arm1.getPosition() + sf::Vector2f(0, 95 * character.head.getScale().y));

        character.left_arm1.setPosition(character.right_arm1.getPosition() + sf::Vector2f(character.body.getGlobalBounds().width - 5 * character.head.getScale().y, 0));
        character.left_arm2.setPosition(character.left_arm1.getPosition());
        character.gun.setPosition(character.left_arm1.getPosition());

        character.right_leg1.setPosition(character.body.getPosition() + sf::Vector2f(37 * character.head.getScale().y, character.body.getGlobalBounds().height - 30 * character.head.getScale().y));
        character.right_leg2.setPosition(character.right_leg1.getPosition() + sf::Vector2f(-27 * character.head.getScale().y, character.left_leg1.getGlobalBounds().height - 45 * character.head.getScale().y));

        character.left_leg1.setPosition(character.right_leg1.getPosition() + sf::Vector2f(83 * character.head.getScale().y, 0));
        character.left_leg2.setPosition(character.left_leg1.getPosition() + sf::Vector2f(-27 * character.head.getScale().y, character.right_leg1.getGlobalBounds().height - 45 * character.head.getScale().y));
        character.player_arrow.setPosition(character.head.getPosition() + sf::Vector2f(10 * character.head.getScale().y, -character.player_arrow.getGlobalBounds().height - 30 * character.head.getScale().y));
    } else {
        character.head.setPosition(pos + sf::Vector2f(character.body.getGlobalBounds().width / 2 - character.head.getGlobalBounds().width / 2 + 4 * character.head.getScale().x, 0));
        character.body.setPosition(pos + sf::Vector2f(0, character.head.getGlobalBounds().height));
        character.left_arm1.setPosition(pos + sf::Vector2f(2 * character.head.getScale().x, character.head.getGlobalBounds().height + 37 * character.head.getScale().x));
        character.left_arm2.setPosition(character.left_arm1.getPosition());
        character.gun.setPosition(character.left_arm1.getPosition());
        character.right_arm1.setPosition(character.left_arm1.getPosition() + sf::Vector2f(character.body.getGlobalBounds().width - 5 * character.head.getScale().y, 0));
        character.right_arm2.setPosition(character.right_arm1.getPosition() + sf::Vector2f(0, 95 * character.head.getScale().y));
        character.left_leg1.setPosition(character.body.getPosition() + sf::Vector2f(37 * character.head.getScale().x, character.body.getGlobalBounds().height - 30 * character.head.getScale().x));
        character.left_leg2.setPosition(character.left_leg1.getPosition() + sf::Vector2f(0, character.left_leg1.getGlobalBounds().height - 45 * character.head.getScale().x));
        character.right_leg1.setPosition(character.left_leg1.getPosition() + sf::Vector2f(83 * character.head.getScale().x, 0));
        character.right_leg2.setPosition(character.right_leg1.getPosition() + sf::Vector2f(0, character.left_leg1.getGlobalBounds().height - 45 * character.head.getScale().x));
        character.player_arrow.setPosition(character.head.getPosition() + sf::Vector2f(10 * character.head.getScale().y, -character.player_arrow.getGlobalBounds().height - 30 * character.head.getScale().y));
    }
}
void character_set_scale(Character &character, float scale) {
    character.arm_scale = scale;
    character.head.setScale(sf::Vector2f(scale, scale));
    character.body.setScale(sf::Vector2f(scale, scale));
    character.left_arm1.setScale(sf::Vector2f(scale, scale));
    character.left_arm2.setScale(sf::Vector2f(scale, scale));
    character.right_arm1.setScale(sf::Vector2f(scale, scale));
    character.right_arm2.setScale(sf::Vector2f(scale, scale));
    character.left_leg1.setScale(sf::Vector2f(scale, scale));
    character.left_leg2.setScale(sf::Vector2f(scale, scale));
    character.right_leg1.setScale(sf::Vector2f(scale, scale));
    character.right_leg2.setScale(sf::Vector2f(scale, scale));
    character.gun.setScale(sf::Vector2f(scale, scale));
    if (character.player_arrow_exist) {
        character.player_arrow.setScale(sf::Vector2f(scale, scale));
    }
}
void character_init(Character &character, std::string head_path, std::string body_path, bool flip) {
    character.head_texture.loadFromFile(head_path);
    character.body_texture.loadFromFile(body_path);

    character.head.setTexture(character.head_texture);
    character.body.setTexture(character.body_texture);
    character.left_arm1.setTexture(character.body_texture);
    character.left_arm2.setTexture(character.body_texture);
    character.right_arm1.setTexture(character.body_texture);
    character.right_arm2.setTexture(character.body_texture);
    character.left_leg1.setTexture(character.body_texture);
    character.left_leg2.setTexture(character.body_texture);
    character.right_leg1.setTexture(character.body_texture);
    character.right_leg2.setTexture(character.body_texture);

    character_show(character);

    character.head.setTextureRect(sf::IntRect(34, 45, 179, 163));
    character.body.setTextureRect(sf::IntRect(203, 51, 216, 235));
    character.left_arm1.setTextureRect(sf::IntRect(50, 50, 54, 145));
    character.left_arm2.setTextureRect(sf::IntRect(50, 242, 54, 148));
    character.right_arm1.setTextureRect(sf::IntRect(520, 50, 54, 148));
    character.right_arm2.setTextureRect(sf::IntRect(520, 242, 54, 149));
    character.left_leg1.setTextureRect(sf::IntRect(203, 360, 55, 157));
    character.left_leg2.setTextureRect(sf::IntRect(203, 563, 82, 131));
    character.right_leg1.setTextureRect(sf::IntRect(365, 360, 55, 157));
    character.right_leg2.setTextureRect(sf::IntRect(365, 563, 82, 131));

    character.gun.setFillColor(sf::Color::Black);
    character.gun.setSize(sf::Vector2f(30, 90));

    character_set_scale(character, 1);
    character.flip = flip;
    character_set_position(character, sf::Vector2f(0, 0));
    character.steam_texture.loadFromFile("assets/steam.png");
    character.steam.setTexture(character.steam_texture);
}

void character_draw(Character &character, sf::RenderWindow &window) {
    window.draw(character.head);
    window.draw(character.right_arm1);
    window.draw(character.right_arm2);
    window.draw(character.left_leg1);
    window.draw(character.left_leg2);
    window.draw(character.right_leg1);
    window.draw(character.right_leg2);
    window.draw(character.body);
    window.draw(character.left_arm1);
    window.draw(character.left_arm2);
    if (character.has_gun) {
        window.draw(character.gun);
    }
    if (character.framex != 0 || character.framey != 0) {
        window.draw(character.steam);
    }
    if (character.show_player_arrow) {
        window.draw(character.player_arrow);
    }
}

void character_set_player_arrow(Character& character, std::string player_arrow_path) {
    character.player_arrow_texture.loadFromFile(player_arrow_path);
    character.player_arrow.setTexture(character.player_arrow_texture);
    character.player_arrow_exist = true;
}
void character_show_player_arrow(Character& character, bool show_player_arrow) {
    character.show_player_arrow = show_player_arrow;
}

void character_rotate_arm(Character &character, sf::Vector2i mouse_position) {
    double x = sf::Mouse::getPosition().x - window.getPosition().x - character.gun.getPosition().x;
    double y = sf::Mouse::getPosition().y - window.getPosition().y - character.gun.getPosition().y;
    const double PI = 3.14159265;
    double degree = 0;
    degree = atan(y / x) * 180 / PI;
    if (x < 0) {
        degree = degree + 180;
    }
    character.left_arm1.setRotation(degree - 90);
    character.left_arm2.setRotation(degree - 90);
    character.gun.setRotation(degree - 90);

    double bx = 250 * character.arm_scale;
    double by = -45 * character.arm_scale;
    if (character.flip) {
        by += 90 * character.arm_scale;
    }
    double blen = sqrt(pow(bx, 2) + pow(by, 2));
    double bdeg = atan(by / bx) + atan(y / x);
    if (x < 0) {
        bdeg = bdeg + PI;
    }
    bx = blen * cos(bdeg);
    by = blen * sin(bdeg);
    character.bullet_pos = character.gun.getPosition() + sf::Vector2f(bx, by);
}

void character_dead(Character& character) {
    /*character.framex += 0.1;
    while (character.framex != 0 || character.framey != 0) {
    float time = character.clock.getElapsedTime().asMicroseconds();
    character.clock.restart();
    time /= 650;
    if (time > 20) {
        time = 20;
    }

    character.framex += 0.040 * time;
    if (character.framex >= 8) {
        character.framey++;
        character.framex = 0;
    }
    if (character.framey == 8) {
        character.framex = 0;
        character.framey = 0;
    }
    character.steam.setTextureRect(sf::IntRect(
        128 * int(character.framex), 146 * int(character.framey), 128, 146));
        window.draw(character.steam);
        window.display();
    }*/
    character.head.setColor(sf::Color(0, 0, 0, 0));
    character.body.setColor(sf::Color(0, 0, 0, 0));
    character.left_arm1.setColor(sf::Color(0, 0, 0, 0));
    character.left_arm2.setColor(sf::Color(0, 0, 0, 0));
    character.right_arm1.setColor(sf::Color(0, 0, 0, 0));
    character.right_arm2.setColor(sf::Color(0, 0, 0, 0));
    character.left_leg1.setColor(sf::Color(0, 0, 0, 0));
    character.left_leg2.setColor(sf::Color(0, 0, 0, 0));
    character.right_leg1.setColor(sf::Color(0, 0, 0, 0));
    character.right_leg2.setColor(sf::Color(0, 0, 0, 0));
    character.gun.setFillColor(sf::Color(0, 0, 0, 0));
}

void character_show(Character& character) {
    character.head.setColor(sf::Color(255, 255, 255, 255));
    character.body.setColor(sf::Color(255, 255, 255, 255));
    character.left_arm1.setColor(sf::Color(255, 255, 255, 255));
    character.left_arm2.setColor(sf::Color(255, 255, 255, 255));
    character.right_arm1.setColor(sf::Color(255, 255, 255, 255));
    character.right_arm2.setColor(sf::Color(255, 255, 255, 255));
    character.left_leg1.setColor(sf::Color(255, 255, 255, 255));
    character.left_leg2.setColor(sf::Color(255, 255, 255, 255));
    character.right_leg1.setColor(sf::Color(255, 255, 255, 255));
    character.right_leg2.setColor(sf::Color(255, 255, 255, 255));
    character.gun.setFillColor(sf::Color(0, 0, 0, 255));
}
