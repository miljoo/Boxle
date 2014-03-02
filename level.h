#ifndef LEVEL_H
#define LEVEL_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include "exit.h"
#include "player.h"
#include "loadlevel.h"

using namespace std;

class Level{
public:

	Level(int width, int height, string name);
	string getName();
	int getWidth();
	int getHeight();

	void setName(string input);
    void setWidth(int value);
	void setHeight(int value);

	void loadLevel(ifstream& file, Level& level, Player& player, Exit& exit);
	void saveMap(ofstream& file, Level level, Player player, Exit exit);

    vector< vector<int> > y;
    vector <int> x;
    vector<int> levelData;


	private:
	int levelWidth, levelHeight;
	string levelName;
};

#endif
