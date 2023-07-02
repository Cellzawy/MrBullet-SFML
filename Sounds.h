#ifndef SOUNDS
#define SOUNDS

extern sf::SoundBuffer shootSound;
extern sf::SoundBuffer screamSounds[10];
extern sf::SoundBuffer gameOverSound;
extern sf::SoundBuffer ricochetSound;
extern sf::SoundBuffer three_strars_buffer;


extern sf::Sound screams[10];
//extern sf::Sound shoot;
extern sf::Sound gameOver;
extern sf::Sound ricochet;
extern sf::Sound three_strars;

int BufferSounds();
void SetSounds();
#endif