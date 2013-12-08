#ifndef FUNCS_H
#define FUNCS_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "player.h"
#include "exit.h"
#include "mapdef.h"

void drawPlayer(sf::Texture& tilemap, sf::Sprite& sprite, sf::RenderWindow& window, Player& player);
void drawExit(sf::Texture& tilemap, sf::Sprite& sprite, sf::RenderWindow& window, Exit& exit);
void drawMap(sf::Texture& tilemap, sf::Sprite& sprite, sf::RenderWindow& window, int array[WIDTH][HEIGHT]);
int playerOnExit(Player player, Exit exit);
void push(Player player, int array[WIDTH][HEIGHT]);
void move(int cmd, Player& player, int array[WIDTH][HEIGHT]);

void exit();

#endif // FUNCS_H
