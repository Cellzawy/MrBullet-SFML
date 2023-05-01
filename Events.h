#ifndef EVENTS
#define EVENTS
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

void EventListener();
sf::Event normal_eventloop();
sf::Event main_menu_eventloop();
sf::Event play_menu_eventloop();
sf::Event classic_menu_eventloop();
sf::Event achievements_menu_eventloop();
sf::Event options_menu_eventloop();
sf::Event levels_eventloop();
sf::Event win_lose_panels_eventloop();

extern int currentLvl;

#endif
