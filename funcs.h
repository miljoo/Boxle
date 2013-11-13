#ifndef FUNCS_H
#define FUNCS_H

#include "player.h"
#include "exit.h"
#include "mapdef.h"

void printArray(int array[WIDTH][HEIGHT]);
int playerOnExit(Player player, Exit exit);
void charray(int i[WIDTH][HEIGHT], char a[WIDTH][HEIGHT]);
void addPE(Player player, Exit exit, char a[WIDTH][HEIGHT]);
void printMap(char a[WIDTH][HEIGHT]);
void push(Player player, int array[WIDTH][HEIGHT]);
void move(int cmd, Player& player, int array[WIDTH][HEIGHT]);
void clearScreen();
void exit();

#endif // FUNCS_H
