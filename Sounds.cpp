#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Sounds.h"



sf::SoundBuffer shootSound;

sf::SoundBuffer screamSounds[10];
sf::SoundBuffer gameOverSound;
sf::SoundBuffer ricochetSound;
sf::SoundBuffer three_strars_buffer;

sf::Sound screams[10];
//sf::Sound shoot;
sf::Sound gameOver;
sf::Sound ricochet;
sf::Sound three_strars;

int BufferSounds() {
	//if (!shootSound.loadFromFile("assets/sounds/shoot.ogg"))
	//	return -1;
	if (!screamSounds[0].loadFromFile("assets/sounds/Screams/scream-04.ogg"))
		return -1;
	if (!screamSounds[1].loadFromFile("assets/sounds/Screams/scream-06.ogg"))
		return -1;
	if (!screamSounds[2].loadFromFile("assets/sounds/Screams/scream-25.ogg"))
		return -1;
	if (!screamSounds[3].loadFromFile("assets/sounds/Screams/scream-24.ogg"))
		return -1;
	if (!screamSounds[4].loadFromFile("assets/sounds/Screams/scream-22.ogg"))
		return -1;
	if (!screamSounds[5].loadFromFile("assets/sounds/Screams/scream-17.ogg"))
		return -1;
	if (!screamSounds[6].loadFromFile("assets/sounds/Screams/scream-13.ogg"))
		return -1;
	if (!screamSounds[7].loadFromFile("assets/sounds/Screams/scream-01.ogg"))
		return -1;
	if (!screamSounds[8].loadFromFile("assets/sounds/Screams/scream-16.ogg"))
		return -1;
	if (!screamSounds[9].loadFromFile("assets/sounds/Screams/scream-10.ogg"))
		return -1;
	if (!gameOverSound.loadFromFile("assets/sounds/mrjump-gameover.ogg"))
		return -1;
	if (!ricochetSound.loadFromFile("assets/sounds/ricochet.ogg"))
		return -1;
	if (!three_strars_buffer.loadFromFile("assets/sounds/win-star.ogg"));
		return -1;

}



void SetSounds() {
	for (int i = 0; i < 10; i++) {
		screams[i].setBuffer(screamSounds[i]);
	}
	//shoot.setBuffer(shootSound);
	gameOver.setBuffer(gameOverSound);
	ricochet.setBuffer(ricochetSound);
	three_strars.setBuffer(three_strars_buffer);

}