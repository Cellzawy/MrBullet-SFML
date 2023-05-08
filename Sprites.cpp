#include "Sprites.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cmath>
#include "Menus.h"

//  Shapes & sprites declaration:
CircleShape bullet(5.f);
CircleShape ring(150.f);
RectangleShape wall1(Vector2f(1920.f, 10.f));
RectangleShape wall2(Vector2f(10.f, 1080.f));
RectangleShape wall3(Vector2f(1920.f, 10.f));
RectangleShape wall4(Vector2f(10.f, 1080.f));
RectangleShape box(Vector2f(300.f, 300.f));
RectangleShape walls[] = {wall1, wall2, wall3, wall4};
vector<Bullet> bullets;
//CircleShape triangle(10, 3);


void sprites() {
	bullet.setFillColor(sf::Color::Red);
	bullet.setOrigin(2.5, 2.5);
	//triangle.setOrigin(5, 5);

	wall3.setPosition(0.f, 1080);
	wall4.setPosition(1910, 0);
	box.setPosition(1920 / 2 - 500, 1080 / 2 - 150);
	ring.setPosition(1920/2 + 150, 1080/2 - 150);
	//triangle.setPosition(box.getPosition());
	//triangle.setFillColor(Color::Blue);
	//triangle.setRotation(45);

	wall1.setFillColor(Color::Cyan);
	wall2.setFillColor(Color::Cyan);
	wall3.setFillColor(Color::Cyan);
	wall4.setFillColor(Color::Cyan);
	box.setFillColor(Color::Cyan);
	ring.setFillColor(Color::Cyan);

	wall1.setRotation(0);
	wall2.setRotation(0);
	wall3.setRotation(0);
	wall4.setRotation(0);
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
    }
}
void character_set_scale(Character &character, float scale) {
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
}

void character_rotate_arm(Character &character, sf::Vector2i mouse_position) {
    double x = sf::Mouse::getPosition().x - window.getPosition().x - character.left_arm1.getGlobalBounds().left;
    double y = sf::Mouse::getPosition().y - window.getPosition().y - character.left_arm1.getGlobalBounds().top - character.head.getGlobalBounds().height;
    const double PI = 3.14159265;
    double degree = 0;
    degree = atan(y / x) * 180 / PI;
    if (x < 0) {
        degree = degree + 180;
    }
    character.left_arm1.setRotation(degree - 90);
    character.left_arm2.setRotation(degree - 90);
    character.gun.setRotation(degree - 90);
}
