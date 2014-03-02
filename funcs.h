#ifndef FUNCS_H
#define FUNCS_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "player.h"
#include "exit.h"
#include "mapdef.h"
#include "level.h"
#include <vector>

using namespace std;

void drawPlayer(sf::Texture& tilemap, sf::Sprite& sprite, sf::RenderWindow& window, Player& player);
void drawExit(sf::Texture& tilemap, sf::Sprite& sprite, sf::RenderWindow& window, Exit& exit);
void drawMap(sf::Texture& tilemap, sf::Sprite& sprite, sf::RenderWindow& window, Level level);
int playerOnExit(Player player, Exit exit);
void push(Player player, Level level, vector< vector<int>>& varray);
void move(int cmd, Player& player, Level level, vector< vector<int>>& varray);

void exit();

#endif // FUNCS_H
