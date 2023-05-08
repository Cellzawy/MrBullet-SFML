#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Sounds.h"



sf::SoundBuffer shootSound;
sf::SoundBuffer screamSound1;
sf::SoundBuffer screamSound2;
sf::SoundBuffer screamSound3;
sf::SoundBuffer screamSound4;
sf::SoundBuffer gameOverSound;
sf::SoundBuffer ricochetSound;

sf::Sound scream;
//sf::Sound shoot;
sf::Sound gameOver;
sf::Sound ricochet;

int BufferSounds() {
	//if (!shootSound.loadFromFile("assets/sounds/shoot.ogg"))
	//	return -1;
	if (!screamSound1.loadFromFile("assets/sounds/Screams/scream-04.ogg"))
		return -1;
	if (!screamSound2.loadFromFile("assets/sounds/Screams/scream-06.ogg"))
		return -1;
	if (!screamSound3.loadFromFile("assets/sounds/Screams/scream-25.ogg"))
		return -1;
	if (!screamSound4.loadFromFile("assets/sounds/Screams/scream-24.ogg"))
		return -1;
	if (!gameOverSound.loadFromFile("assets/sounds/mrjump-gameover.ogg"))
		return -1;
	if (!ricochetSound.loadFromFile("assets/sounds/ricochet.ogg"))
		return -1;
}

void SetSounds() {
	scream.setBuffer(screamSound4);
	//shoot.setBuffer(shootSound);
	gameOver.setBuffer(gameOverSound);
	ricochet.setBuffer(ricochetSound);
}