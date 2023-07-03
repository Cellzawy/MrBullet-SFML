#ifndef EVENTS
#define EVENTS
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

extern bool shot;

void EventListener();
sf::Event normal_eventloop();
sf::Event main_menu_eventloop();
sf::Event play_menu_eventloop();
sf::Event classic_menu_eventloop();
sf::Event achievements_menu_eventloop();
sf::Event options_menu_eventloop();
sf::Event pause_eventloop();
sf::Event levels_eventloop(int num_of_enemies);
sf::Event player_one_menu_eventloop();
sf::Event player_two_menu_eventloop();
sf::Event MAPS_1v1_eventloop();
sf::Event duelsPauseMenu_eventLoop();
sf::Event duelsOptionMenu_eventLoop();
sf::Event win_lose_panels_eventloop();
sf::Event options_menu_pause_eventloop();
sf::Event Duels_eventLoop();

#endif
