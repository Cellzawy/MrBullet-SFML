#include "Levels.h" ===>> header file in (Sprites.h) "Ahmed Siam's code"
#include <SFML/Graphics.hpp>
// {{ Ahmed siam code }} SPRITES


//  Shapes & sprites declaration:
CircleShape bullet(5.f);
CircleShape ring(150.f);
RectangleShape wall1(Vector2f(1920.f, 10.f));
RectangleShape wall2(Vector2f(10.f, 1080.f));
RectangleShape wall3(Vector2f(1920.f, 10.f));
RectangleShape wall4(Vector2f(10.f, 1080.f));
RectangleShape box(Vector2f(300.f, 300.f));
RectangleShape walls[] = { wall1, wall2, wall3, wall4 };
//CircleShape triangle(10, 3);


void sprites() {
    bullet.setFillColor(sf::Color::Red);
    bullet.setOrigin(2.5, 2.5);
    //triangle.setOrigin(5, 5);

    wall3.setPosition(0.f, 1080);
    wall4.setPosition(1910, 0);
    box.setPosition(1920 / 2 - 500, 1080 / 2 - 150);
    ring.setPosition(1920 / 2 + 150, 1080 / 2 - 150);
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

void character_set_position(Character& character, sf::Vector2f pos) {
    float scale = character.body.getScale().x;
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

        character.left_leg2.setScale(sf::Vector2f(-scale, scale));
        character.right_leg1.setOrigin(sf::Vector2f(character.right_leg1.getLocalBounds().width, 0));
        character.right_leg1.setScale(sf::Vector2f(-scale, scale));
        character.right_leg2.setOrigin(sf::Vector2f(character.right_leg2.getLocalBounds().width, 0));
        character.right_leg2.setScale(sf::Vector2f(-scale, scale));

        character.head.setPosition(pos + sf::Vector2f(character.body.getGlobalBounds().width / 2 - character.head.getGlobalBounds().width / 2 - 4 * character.head.getScale().y, 0));
        character.body.setPosition(pos + sf::Vector2f(0, character.head.getGlobalBounds().height));

        // flip left and right arm
        character.right_arm1.setPosition(pos + sf::Vector2f(+25 * character.head.getScale().x, character.head.getGlobalBounds().height - 10 * character.head.getScale().x));  // flip signs
        character.right_arm2.setPosition(character.right_arm1.getPosition() + sf::Vector2f(0, 95 * character.head.getScale().y));

        character.left_arm1.setPosition(character.right_arm1.getPosition() + sf::Vector2f(character.body.getGlobalBounds().width - 5 * character.head.getScale().y, 0));
        character.left_arm2.setPosition(character.left_arm1.getPosition() + sf::Vector2f(0, 95 * character.head.getScale().y));

        character.right_leg1.setPosition(character.body.getPosition() + sf::Vector2f(37 * character.head.getScale().y, character.body.getGlobalBounds().height - 30 * character.head.getScale().y));
        character.right_leg2.setPosition(character.right_leg1.getPosition() + sf::Vector2f(-27 * character.head.getScale().y, character.left_leg1.getGlobalBounds().height - 45 * character.head.getScale().y));

        character.left_leg1.setPosition(character.right_leg1.getPosition() + sf::Vector2f(83 * character.head.getScale().y, 0));
        character.left_leg2.setPosition(character.left_leg1.getPosition() + sf::Vector2f(-27 * character.head.getScale().y, character.right_leg1.getGlobalBounds().height - 45 * character.head.getScale().y));
    }
    else {
        character.head.setPosition(pos + sf::Vector2f(character.body.getGlobalBounds().width / 2 - character.head.getGlobalBounds().width / 2 + 4 * character.head.getScale().x, 0));
        character.body.setPosition(pos + sf::Vector2f(0, character.head.getGlobalBounds().height));
        character.left_arm1.setPosition(pos + sf::Vector2f(-25 * character.head.getScale().x, character.head.getGlobalBounds().height + 10 * character.head.getScale().x));
        character.left_arm2.setPosition(character.left_arm1.getPosition() + sf::Vector2f(0, 95 * character.head.getScale().y));
        character.right_arm1.setPosition(character.left_arm1.getPosition() + sf::Vector2f(character.body.getGlobalBounds().width - 5 * character.head.getScale().y, 0));
        character.right_arm2.setPosition(character.right_arm1.getPosition() + sf::Vector2f(0, 95 * character.head.getScale().y));
        character.left_leg1.setPosition(character.body.getPosition() + sf::Vector2f(37 * character.head.getScale().x, character.body.getGlobalBounds().height - 30 * character.head.getScale().x));
        character.left_leg2.setPosition(character.left_leg1.getPosition() + sf::Vector2f(0, character.left_leg1.getGlobalBounds().height - 45 * character.head.getScale().x));
        character.right_leg1.setPosition(character.left_leg1.getPosition() + sf::Vector2f(83 * character.head.getScale().x, 0));
        character.right_leg2.setPosition(character.right_leg1.getPosition() + sf::Vector2f(0, character.left_leg1.getGlobalBounds().height - 45 * character.head.getScale().x));
    }
}
void character_set_scale(Character& character, float scale) {
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
}
void character_init(Character& character, std::string head_path, std::string body_path, bool flip) {
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

    character_set_scale(character, 1);
    character.flip = flip;
    character_set_position(character, sf::Vector2f(0, 0));
}

void character_draw(Character& character, sf::RenderWindow& window) {
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
}

// {{ My_Code }} CONSTRUCTING LEVELS

int levCounter = 1;
struct level
{
	Texture BG;
	Texture ENEMY1[100];
	Texture FLOOR[10];
	Texture BLOCK[10];
    Texture SHAPES[10];
    Sprite bg;
}lev1, lev2, lev3, lev4, lev5;



void constructlev1(Sprite& a, Character& killer ,Character& target , RectangleShape& R, RenderWindow& w)
{
	// background
	lev1.BG.loadFromFile("background_city.png");
	a.setTexture(lev1.BG);
	a.setScale(4, 1.2);

	// Rectangular ground
	lev1.FLOOR[0].loadFromFile("ground.png");
	R.setTexture(&lev1.FLOOR[0]);
	R.setSize(Vector2f(w.getSize().x, w.getSize().y / 4));
	R.setOrigin(R.getLocalBounds().width / 2, R.getLocalBounds().height / 2);
	R.setPosition(w.getSize().x /2.0, w.getSize().y);

	// Charachters
    
    //killer
    character_init(killer, "killer_head.png", "blue_suit_body.png", false);
    character_set_scale(killer, 0.4);
    character_set_position(killer, Vector2f(200, R.getPosition().y - (R.getLocalBounds().height)*1.41));
    //enemy
    character_init(target, "gangster_head.png", "punk_body.png", true);
    character_set_scale(target, 0.4);
    character_set_position(target, Vector2f(1720, R.getPosition().y - (R.getLocalBounds().height) * 1.4));

}

void constructlev2(Sprite& a2, Character& killer, Character targets[8], RectangleShape R2[10], RenderWindow& w2)
{
    // background
    lev2.BG.loadFromFile("background_city.png");
    a2.setTexture(lev2.BG);
    a2.setScale(4, 1.2);

    // Blocks
    for (int i = 0; i < 9; i++)
    {
        lev2.BLOCK[i].loadFromFile("block.png");
        R2[i].setTexture(&lev2.BLOCK[i]);
        if (i == 0)
        {
            R2[i].setSize(Vector2f(130, 130));
        }
        else
        {
            R2[i].setSize(Vector2f(100, 100));
        }
        R2[i].setOrigin(R2[i].getLocalBounds().width / 2, R2[i].getLocalBounds().height / 2);
    }

    // set positions for BLlocks
    R2[0].setPosition(w2.getSize().x / static_cast<float>(2), w2.getSize().y / static_cast<float>(2) + 150);
    R2[1].setPosition(R2[0].getPosition().x + 400, R2[0].getPosition().y + 250);
    R2[2].setPosition(R2[1].getPosition().x + 150, R2[1].getPosition().y + 100);
    R2[3].setPosition(R2[0].getPosition().x - 400, R2[0].getPosition().y + 250);
    R2[4].setPosition(R2[3].getPosition().x - 150, R2[3].getPosition().y + 100);
    R2[5].setPosition(R2[0].getPosition().x - 400, R2[0].getPosition().y - 250);
    R2[6].setPosition(R2[5].getPosition().x - 150, R2[5].getPosition().y - 100);
    R2[7].setPosition(R2[0].getPosition().x + 400, R2[0].getPosition().y - 250);
    R2[8].setPosition(R2[7].getPosition().x + 150, R2[7].getPosition().y - 100);

    //Characters

    //killer
    character_init(killer, "killer_head.png", "blue_suit_body.png", false);
    character_set_scale(killer, 0.4);
    character_set_position(killer, Vector2f(R2[0].getPosition().x - 50, R2[0].getPosition().y - 300));
    //Targets
    for (int i = 0; i < 8; i++)
    {
        character_init(targets[i], "gangster_head.png", "punk_body.png", false);
        character_set_scale(targets[i], 0.4);
        character_set_position(targets[i], Vector2f(R2[i + 1].getPosition().x - 50, R2[i + 1].getPosition().y - 300));
    }

}

void constructlev3(Sprite& a3, Character& killer3, Character& target3, RectangleShape& ground, RectangleShape& sh1, RectangleShape& sh2, RenderWindow& w3)
{
    //backround
    lev3.BG.loadFromFile("background_city.png");
    a3.setTexture(lev3.BG);
    a3.setScale(4, 1.2);

    //ground
    lev3.FLOOR[0].loadFromFile("ground.png");
    ground.setTexture(&lev3.FLOOR[0]);
    ground.setSize(Vector2f(w3.getSize().x, w3.getSize().y / 4));
    ground.setOrigin(ground.getLocalBounds().width / 2, ground.getLocalBounds().height / 2);
    ground.setPosition(w3.getSize().x / 2.0, w3.getSize().y);

    //shape1
    lev3.SHAPES[0].loadFromFile("rectangle1.png");
    sh1.setTexture(&lev3.SHAPES[0]);
    sh1.setSize(Vector2f(450,80));
    sh1.setOrigin(sh1.getLocalBounds().width / 2, sh1.getLocalBounds().height / 2);
    sh1.setPosition(w3.getSize().x - sh1.getSize().x/2, 350);

    //shape2
    lev3.SHAPES[1].loadFromFile("rectangle2.png");
    sh2.setTexture(&lev3.SHAPES[1]);
    sh2.setSize(Vector2f(200, 400));
    //sh2.setOrigin(sh2.getLocalBounds().width / 2, sh2.getLocalBounds().height / 2);
    sh2.setPosition(0, 400);

    //killer
    character_init(killer3, "killer_head.png", "blue_suit_body.png", true);
    character_set_scale(killer3, 0.34);
    character_set_position(killer3, Vector2f(w3.getSize().x-200, ground.getPosition().y - (ground.getLocalBounds().height) * 1.3));
    //enemy
    character_init(target3, "gangster_head.png", "punk_body.png", true);
    character_set_scale(target3, 0.34);
    character_set_position(target3, Vector2f(sh1.getPosition().x - (sh1.getSize().x / 2), sh1.getPosition().y-235));

}



int main() {
	RenderWindow window(VideoMode(1920, 1080), "EL_Aostaz bullet");

	// Setting Textures
    Character killer, target[100];
    Sprite bg;
	RectangleShape ground , shape1, shape2;
	RectangleShape blocksLev2[10];
	

	// GAME loop
	while (window.isOpen())
	{
		Event ev;
		while (window.pollEvent(ev))
		{
			if (ev.type == Event::Closed)
				window.close();
		}
        if (Keyboard::isKeyPressed(Keyboard::A))
            levCounter++;

		window.clear();

		if (levCounter == 1) // ==> constructing level 1
		{
            
			constructlev1(bg, killer, target[0], ground, window);
			window.draw(bg);
			window.draw(ground);
            character_draw(killer, window);
            character_draw(target[0], window);
           

		}

		else if (levCounter == 2) // ==> constructing level 2
		{
			constructlev2(bg, killer ,target, blocksLev2, window);
			window.draw(bg);
			for (int i = 0; i < 10; i++)
			{
				window.draw(blocksLev2[i]);
			}
            character_draw(killer, window);
            for (int i = 0; i < 8; i++)
            {
                character_draw(target[i], window);
            }

		}
		else if (levCounter == 3) // ==> constructing level 3
		{
            constructlev3(bg, killer, target[0], ground, shape1, shape2, window);
            window.draw(bg);
            window.draw(ground);
            window.draw(shape1);
            window.draw(shape2);
            character_draw(killer, window);
            character_draw(target[0], window);
		}
       

		window.display();

	}
}
