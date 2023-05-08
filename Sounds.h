#ifndef SOUNDS
#define SOUNDS

extern sf::SoundBuffer shootSound;
extern sf::SoundBuffer screamSound1;
extern sf::SoundBuffer screamSound2;
extern sf::SoundBuffer screamSound3;
extern sf::SoundBuffer screamSound4;
extern sf::SoundBuffer gameOverSound;
extern sf::SoundBuffer ricochetSound;

extern sf::Sound scream;
//extern sf::Sound shoot;
extern sf::Sound gameOver;
extern sf::Sound ricochet;

int BufferSounds();
void SetSounds();
#endif