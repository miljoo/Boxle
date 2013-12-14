#include "level.h"

void Level::loadLevel(ifstream& file, Level& level, Player player, Exit exit){
    string page, line, pxyz, exyz, h, w, lvl;

    int tint;

    while (getline (file, line)){
        page.append(line);
        line.erase();
    }
    level.setName(find_field(page, "Name"));
    h = find_field(page, "Height");
    level.setHeight(atoi(h.c_str()));
    w = find_field(page, "Width");
    level.setWidth(atoi(w.c_str()));
    pxyz = find_field(page, "Player");
    exyz = find_field(page, "Exit");

    lvl = find_field(page, "Map");

    stringstream ss(lvl);

    player.set_x(pxyz[0]);
    player.set_x(pxyz[2]);
    player.set_x(pxyz[4]);

    exit.set_x(exyz[0]);
    exit.set_x(exyz[2]);
    exit.set_x(exyz[4]);


    for(int j = 0; j < level.getHeight(); j++){
        for(int i = 0 ; i < level.getWidth(); i++){

                if(i != ' '){
                    ss >> tint;
                    level.x.push_back(tint);
                }
                else{
                    i++;
                }


        }
        level.y.push_back(level.x);
        level.x.clear();
    }
 }

void Level::saveMap(ofstream& file, Level level ,Player player, Exit exit){
    vector<int>::iterator it_x;
    vector< vector<int> >::iterator it_y;

    file << "<Name>" << level.getName() << "</Name>" << endl;
    file << "<Height>" << getHeight() << "</Height>" << endl;
    file << "<Width>" << getWidth() << "</Width>" << endl;
    file << "<Player>" << player.get_x() << " " << player.get_y() << " " << player.get_z() << "</Player>" << endl;
    file << "<Exit>" << exit.get_x() << " " << exit.get_y() << " " << exit.get_z() << "</Exit>" << endl;
    file << "<Map>";

    for (it_y = y.begin(); it_y != y.end(); it_y++) {
        for (it_x = it_y->begin(); it_x != it_y->end(); it_x++) {
            file << *it_x << " " ;
        }
    }
    file << "</Map>" << endl;;
}

Level::Level(int width, int height, string name){
	for(int j = 0 ; j < height; j++){
        for(int i = 0; i < width ; i++){
            x.push_back(0);
        }
        y.push_back(x);
        x.clear();
	}
	levelName = name;
	levelHeight = height;
	levelWidth = width;
}

string Level::getName(){
    return levelName;
}

void Level::setName(string input){
    levelName = input;
}

void Level::setWidth(int value){
    levelWidth = value;
}

void Level::setHeight(int value){
    levelHeight = value;
}

int Level::getHeight(){
    return levelHeight;
}

int Level::getWidth(){
    return levelWidth;
}
