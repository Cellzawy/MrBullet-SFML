#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <math.h>
//#include "Struct.cpp"

using namespace std;
using namespace sf;


struct Platform {
	RectangleShape surface;
	char type;
};

Vector2f NormalizeVector(Vector2f vector) {
	float m = sqrt(vector.x * vector.x + vector.y * vector.y);
	Vector2f normalizedVector;
	normalizedVector.x = vector.x / m;
	normalizedVector.y = vector.y / m;

	return normalizedVector;
}

bool Reset(int l) {
	//
	return false;
}


int main() {
	RenderWindow window(VideoMode(1453, 1115), "Zombies Down", sf::Style::Titlebar | sf::Style::Close);
	Sprite bullet;
	CircleShape crosshair(5), scroll1(20), scroll2(20);
	bullet.setPosition(0, 600);
	bullet.setOrigin(613 / 2, 171 / 2);
	bool hit = false;
	float dir = 10.0f;
	Vector2f bulletDirection;

	RectangleShape pausedBlur(Vector2f(1453, 1115));
	pausedBlur.setFillColor(Color::Color(0, 0, 0, 130));
	pausedBlur.setPosition(0, 0);
	RectangleShape pausedBox(Vector2f(1453 / 2, 1115 / 2));
	pausedBox.setFillColor(Color::Color(0, 0, 0, 200));
	pausedBox.setPosition(1453 / 2, 1115 / 2);
	pausedBox.setOrigin(pausedBox.getLocalBounds().width / 2, pausedBox.getLocalBounds().height / 2);
	Font roboto;
	roboto.loadFromFile("Roboto-Regular.ttf");
	Text resume;
	resume.setFont(roboto);
	resume.setScale(1.2, 1.2);
	resume.setString("Resume");
	resume.setOrigin(resume.getLocalBounds().width / 2, resume.getLocalBounds().height / 2);
	resume.setPosition(1453 / 2, 450);
	Text mainMenu;
	mainMenu.setFont(roboto);
	mainMenu.setScale(1.2, 1.2);
	mainMenu.setString("Back to main menu");
	mainMenu.setOrigin(mainMenu.getLocalBounds().width / 2, mainMenu.getLocalBounds().height / 2);
	mainMenu.setPosition(1453 / 2, 600);


	// audio
	Music music;
	music.openFromFile("sample.OGG");
	music.play();
	RectangleShape audio_bar(Vector2f(493.1, 38)), FX(Vector2f(493.1, 38));
	audio_bar.setPosition(268, 434);
	FX.setPosition(268, 614);
	scroll1.setPosition(735, 433); // for music
	scroll1.setFillColor(Color{ 55, 55, 55, 255 });
	scroll2.setPosition(735, 613); // for FX
	scroll2.setFillColor(Color{ 55, 55, 55, 255 });


	Platform platform;
	Platform platform2;
	Platform platform3;
	Platform platform4;
	platform.surface.setPosition(0, 700);
	platform.surface.setSize(Vector2f(1453, 800));
	platform2.surface.setPosition(1400, 0);
	platform2.surface.setSize(Vector2f(1453, 1115));
	platform3.surface.setPosition(1200, 1000);
	platform3.surface.setSize(Vector2f(200, 115));
	platform4.surface.setPosition(1200, 700);
	platform4.surface.setSize(Vector2f(0.0001, 800));
	platform.type = 'X';
	platform2.type = 'Y';
	platform3.type = 'X';
	platform4.type = 'Y';

	Platform Platforms[20] = { platform, platform2, platform3, platform4 };



	Texture menu1, menu2, menuaudio, menulevels, backTexture, shopTexture, inventoryTexture, backgroundTexture, dirt, arrow, reset, pause, bow_animation, player, zombie;
	menu1.loadFromFile("main menu.png");
	menu2.loadFromFile("options.png");
	menuaudio.loadFromFile("Audio.png");
	menulevels.loadFromFile("levels.png");
	backTexture.loadFromFile("back.png");
	shopTexture.loadFromFile("shop.png");
	inventoryTexture.loadFromFile("inventory.png");
	backgroundTexture.loadFromFile("Background.png");
	dirt.loadFromFile("dirt.png");
	arrow.loadFromFile("arrow.png");
	reset.loadFromFile("reset.png");
	pause.loadFromFile("pause.png");
	bow_animation.loadFromFile("bow_animation.png");
	player.loadFromFile("player.png");
	zombie.loadFromFile("wild zombie.png");

	platform.surface.setTexture(&dirt);
	platform2.surface.setTexture(&dirt);
	platform3.surface.setTexture(&dirt);
	platform4.surface.setTexture(&dirt);

	Sprite mainmenu, options, audio, levels, back, shop, inventory, resetIcon, pauseIcon, bow, archer, wildzombie;
	wildzombie.setTexture(zombie);
	wildzombie.setTextureRect(IntRect(0, 0, 96, 96));
	bow.setTexture(bow_animation);
	bow.setTextureRect(IntRect(0, 0, (367.0 / 6.0), 69));
	archer.setTexture(player);
	mainmenu.setTexture(menu1);
	options.setTexture(menu2);
	audio.setTexture(menuaudio);
	levels.setTexture(menulevels);
	back.setTexture(backTexture);
	shop.setTexture(shopTexture);
	resetIcon.setTexture(reset);
	pauseIcon.setTexture(pause);
	resetIcon.setPosition(100, 40);
	pauseIcon.setPosition(10, 40);
	resetIcon.setScale(0.15, 0.15);
	pauseIcon.setScale(0.15, 0.15);
	//Platform.Platform.
	inventory.setTexture(inventoryTexture);
	back.setPosition(30, 30);
	back.setScale(2, 2);
	bullet.setTexture(arrow);
	bullet.setScale(0.15, 0.15);





	RectangleShape background(Vector2f(1453, 1115));
	background.setTexture(&backgroundTexture);

	int menucounter = 0;
	int level = 0;
	float ani1 = 0, delay1 = 0, ani2 = 0, delay2 = 0, ani3 = 0, delay3 = 0;
	const float PI = 3.14159265;
	bool deadgamed = false;
	bool levelPassed = false;
	bool paused = false;
	bool attack = false;
	window.setFramerateLimit(30);
	while (window.isOpen()) {
		Platform Platforms[20] = { platform, platform2, platform3, platform4 };
		bool dead = wildzombie.getGlobalBounds().intersects(bullet.getGlobalBounds());
		if (Mouse::isButtonPressed(Mouse::Left))
			attack = true;
		if (level == 1) {
			platform.surface.setPosition(0, 700);
			platform.surface.setSize(Vector2f(1453, 800));
			platform2.surface.setSize(Vector2f(0, 0));
			platform3.surface.setSize(Vector2f(0, 0));
			platform4.surface.setSize(Vector2f(0, 0));
			window.draw(platform.surface);
			window.draw(crosshair);
			window.draw(bullet);
			window.draw(resetIcon);
			window.draw(pauseIcon);
		}
		else if (level == 2) {
			platform.surface.setPosition(0, 700);
			platform.surface.setSize(Vector2f(1100, 800));
			platform2.surface.setPosition(1400, 0);
			platform2.surface.setSize(Vector2f(1453, 1115));
			platform3.surface.setPosition(1100, 1000);
			platform3.surface.setSize(Vector2f(1453, 115));
			platform4.surface.setPosition(1100, 700);
			platform4.surface.setSize(Vector2f(0.0001, 800));
		}
		else if (level == 3) {
			platform.surface.setPosition(0, 700);
			platform.surface.setSize(Vector2f(1453, 800));
			platform4.surface.setPosition(300, 300);
			platform4.surface.setSize(Vector2f(0.0001, 200));
			platform3.surface.setPosition(300, 300);
			platform3.surface.setSize(Vector2f(1453, 200));
			platform2.surface.setPosition(-1400, 0);
			platform2.surface.setSize(Vector2f(1453, 1000));
		}
		crosshair.setPosition(Mouse::getPosition(window).x, Mouse::getPosition(window).y);
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			Vector2i mousepos = Mouse::getPosition(window);
			cout << mousepos.x << " " << mousepos.y << endl;
			if (menucounter == 6) {
				if (pauseIcon.getGlobalBounds().contains(Vector2f(mousepos))) {
					paused = true;
				}
				if (resume.getGlobalBounds().contains(Vector2f(mousepos)) && paused) {
					paused = false;
					sleep(seconds(0.15f));

				}
				if (mainMenu.getGlobalBounds().contains(Vector2f(mousepos)) && paused) {
					menucounter = 0;
					paused = false;
					sleep(seconds(0.15f));
				}
			}
		}
		if (dead)
			deadgamed = true;
		if (deadgamed == false) {
			wildzombie.setTextureRect(IntRect(ani2 * 96, 0, 96, 96));
			delay2++;
			if (delay2 >= 5) {
				ani2++;
				delay2 = 0;
			}
			if (ani2 >= 7)
			{
				ani2 = 0;
				delay2 = 0;
			}
		}
		else if (deadgamed)
		{
			dead = true;
			wildzombie.setTextureRect(IntRect(ani3 * 96, 96, 96, 96));
			delay3++;
			if (delay3 >= 5) {
				ani3++;
				delay3 = 0;
			}
			if (ani3 >= 5)
			{
				ani3 = 0;
				delay3 = 0;
				wildzombie.setScale(0, 0);
			}
		}
		if (attack)
		{
			bow.setTextureRect(IntRect(ani1 * (367.0 / 6.0), 0, (367.0 / 6.0), 69));
			delay1++;
			if (delay1 >= 5) {
				ani1++;
				delay1 = 0;
			}
			if (ani1 >= 6)
			{
				ani1 = 0;
				delay1 = 0;
				attack = false;
			}
		}
		else if (!attack)
			bow.setTextureRect(IntRect(0, 0, (367.0 / 6.0), 69));
		// rotaion of the bow
		Vector2f curpos = bow.getPosition(); // bow_position
		Vector2i mouse = Mouse::getPosition(window); //mouse_position
		float dx = curpos.x - mouse.x;
		float dy = curpos.y - mouse.y;
		crosshair.setPosition(Mouse::getPosition(window).x, Mouse::getPosition(window).y);
		float rotaion = atan2(dy, dx) * 180 / PI;    // angle,  const float PI =  3.14159265;
		bow.setRotation(rotaion + 180);
		bow.setOrigin(bow.getLocalBounds().width / 2, bow.getLocalBounds().height / 2);
		bow.setPosition(296, 664);
		if (!paused) {
			bullet.setPosition(bullet.getPosition() + bulletDirection * 10.0f);

			if (Mouse::isButtonPressed(Mouse::Left))
			{
				Vector2i mousePosition = Mouse::getPosition(window);
				bulletDirection = /*Vector2f(mousePosition.x, mousePosition.y)*/Vector2f(mousePosition) - bullet.getPosition();
				bulletDirection = NormalizeVector(bulletDirection * 4.0f);

			}

		}
		if (bulletDirection.x > 0 && !paused)
			bullet.setRotation(atan(bulletDirection.y / bulletDirection.x) / 3.14159 * 180);
		else if (bulletDirection.x < 0 && !paused)
			bullet.setRotation(atan(bulletDirection.y / bulletDirection.x) / 3.14159 * 180 - 180);

		if (menucounter == 6 && paused == false) {
			for (int i = 0; i < 10; i++) {
				if (bullet.getGlobalBounds().intersects(Platforms[i].surface.getGlobalBounds())) {
					if (Platforms[i].type == 'X')
						bulletDirection = Vector2f(bulletDirection.x, -1 * bulletDirection.y);
					else if (Platforms[i].type == 'Y')
						if (level == 1 || level == 2) {
							if (bulletDirection.x > 0) {
								bulletDirection = Vector2f(-1 * bulletDirection.x, bulletDirection.y);
								//break;
							}
							else {
								bulletDirection = Vector2f(-1 * bulletDirection.x, -1 * bulletDirection.y);
								//break;
							}
						}
						else if (level == 3) {
							if (bulletDirection.x > 0) {
								bulletDirection = Vector2f(-1 * bulletDirection.x, -1 * bulletDirection.y);
								//break;
							}
							else {
								bulletDirection = Vector2f(-1 * bulletDirection.x, bulletDirection.y);
								//break;
							}
						}

				}
			}
		}



		if (audio_bar.getGlobalBounds().contains(mouse.x, mouse.y) && Mouse::isButtonPressed(Mouse::Left)) {
			scroll1.setPosition(mouse.x, 433);
			music.setVolume(((mouse.x - 268) * 100) / 493.1);
		}
		if (FX.getGlobalBounds().contains(mouse.x, mouse.y) && Mouse::isButtonPressed(Mouse::Left)) {
			scroll2.setPosition(mouse.x, 613);
		}
		// audioooooooo UP

		//if (bullet.getGlobalBounds().intersects(Platform.Platform.getGlobalBounds())) {
		//	cout << bulletDirection.x << " " << bulletDirection.y << endl;
		//	if (Platform.type == 'X')
		//		bulletDirection = Vector2f(bulletDirection.x, -1 * bulletDirection.y);
		//	else
		//		bulletDirection = Vector2f(-1 * bulletDirection.x, bulletDirection.y);
		//}
		//if (bullet.getGlobalBounds().intersects(platform2.Platform.getGlobalBounds())) {
		//	cout << bulletDirection.x << " " << bulletDirection.y << endl;
		//	if (platform2.type == 'X')
		//		bulletDirection = Vector2f(bulletDirection.x, -1 * bulletDirection.y);
		//	else
		//		bulletDirection = Vector2f(-1 * bulletDirection.x, bulletDirection.y);
		//}
		//if (bullet.getGlobalBounds().intersects(platform3.Platform.getGlobalBounds())) {
		//	cout << bulletDirection.x << " " << bulletDirection.y << endl;
		//	if (platform3.type == 'X')
		//		bulletDirection = Vector2f(bulletDirection.x, -1 * bulletDirection.y);
		//	else
		//		bulletDirection = Vector2f(-1 * bulletDirection.x, bulletDirection.y);
		//}
		//if (bullet.getGlobalBounds().intersects(platform4.Platform.getGlobalBounds())) {
		//	cout << bulletDirection.x << " " << bulletDirection.y << endl;
		//	if (platform4.type == 'X')
		//		bulletDirection = Vector2f(bulletDirection.x, -1 * bulletDirection.y);
		//	else
		//		bulletDirection = Vector2f(-1 * bulletDirection.x, -1 * bulletDirection.y);
		//}

		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		if (Mouse::isButtonPressed(Mouse::Left)) {
			sleep(seconds(0.15f));
			Vector2i mousepos = Mouse::getPosition(window);

			if (menucounter == 0 && mousepos.x > 206.2 && mousepos.x < 662 && mousepos.y < 465 && mousepos.y > 327) {
				//levels
				menucounter = 1;
			}
			else if (menucounter == 0 && mousepos.x > 206.2 && mousepos.x < 662 && mousepos.y < 648 && mousepos.y > 514) {
				//options

				menucounter = 2;
			}
			else if (menucounter == 0 && mousepos.x > 206.2 && mousepos.x < 662 && mousepos.y < 830 && mousepos.y > 688) {
				//exit
				window.close();
			}

			else if (menucounter == 2 && mousepos.x > 501 && mousepos.x < 952 && mousepos.y < 463 && mousepos.y > 333) {
				//audio
				menucounter = 3;
			}
			else if (menucounter == 2 && mousepos.x > 501 && mousepos.x < 952 && mousepos.y < 646 && mousepos.y > 510) {
				//inventory
				menucounter = 4;
			}
			else if (menucounter == 2 && mousepos.x > 501 && mousepos.x < 952 && mousepos.y < 827 && mousepos.y > 693) {
				//shop
				menucounter = 5;
			}
			else if (menucounter != 0 && menucounter != 6 && back.getGlobalBounds().contains(Vector2f(mousepos))) {
				if (menucounter == 5 || menucounter == 4 || menucounter == 3)
					menucounter = 2;
				else {
					menucounter = 0;
				}
			}
			else if (menucounter == 1 && mousepos.x > 194 && mousepos.x < 481 && mousepos.y < 665 && mousepos.y > 373) {
				level = 1;
				menucounter = 6;
			}
			else if (menucounter == 1 && mousepos.x > 583 && mousepos.x < 870 && mousepos.y < 665 && mousepos.y > 373) {
				level = 2;
				menucounter = 6;
			}
			else if (menucounter == 1 && mousepos.x > 969 && mousepos.x < 1259 && mousepos.y < 665 && mousepos.y > 373) {
				level = 3;
				menucounter = 6;
			}
		}
		window.clear();
		window.draw(background);
		if (menucounter == 0) {
			window.draw(mainmenu);
		}
		else if (menucounter == 1) {
			window.draw(levels);
			window.draw(back);
		}
		else if (menucounter == 2) {
			window.draw(options);
			window.draw(back);
		}
		else if (menucounter == 3) {
			window.draw(audio);
			window.draw(back);
			window.draw(scroll1);
			window.draw(scroll2);
		}
		else if (menucounter == 4) {
			window.draw(inventory);
			window.draw(back);
		}
		else if (menucounter == 5) {
			window.draw(shop);
			window.draw(back);
		}
		else if (level == 1) {
			window.draw(platform.surface);
			window.draw(crosshair);
			window.draw(bullet);
			window.draw(resetIcon);
			window.draw(pauseIcon);
			window.draw(archer);
			window.draw(bow);
			window.draw(wildzombie);
		}
		else if (level == 2) {
			window.draw(platform.surface);
			window.draw(platform2.surface);
			window.draw(platform3.surface);
			window.draw(platform4.surface);
			window.draw(crosshair);
			window.draw(bullet);
			window.draw(resetIcon);
			window.draw(pauseIcon);
		}
		else if (level == 3) {
			window.draw(platform.surface);
			window.draw(platform2.surface);
			window.draw(platform3.surface);
			window.draw(platform4.surface);
			window.draw(crosshair);
			window.draw(bullet);
			window.draw(resetIcon);
			window.draw(pauseIcon);
		}
		if (paused) {
			window.draw(pausedBlur);
			window.draw(pausedBox);
			window.draw(resume);
			window.draw(mainMenu);
		}

		window.display();

	}
	return 0;
}