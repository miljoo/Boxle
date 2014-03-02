#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include "player.h"
#include "exit.h"
#include "funcs.h"
#include "level.h"

#define WIN_X 800
#define WIN_Y 640

using namespace std;

int main(){

    Level level(9,10, "default");
    Player player(1,1);
    player.set_dir(8);
    player.set_z(player.get_x(),player.get_y(),level.y);
    Exit exit(2,1);

    ifstream ifile;

    sf::RenderWindow window;

    window.create(sf::VideoMode(WIN_X,WIN_Y), "Boxle a0.5");
    window.setKeyRepeatEnabled(false);
    window.setFramerateLimit(30);

    sf::Texture tilemap;
    sf::Sprite tiles;
    if(!tilemap.loadFromFile("invisgblue2.png")){
        cout << "Error loading tileset" << endl;
    }

    sf::Texture instruction_picture;
    sf::Sprite instruction_pic;
    if(!instruction_picture.loadFromFile("instructions.png")){
        cout << "Error loading instruction pic" << endl;
    }

    sf::Font font;
    if(!font.loadFromFile("tahomabd.ttf")){
        cout << "error loading font" << endl;
    }

    sf::Text tplay;
    sf::Text tinst;
    sf::Text texit;
    tplay.setFont(font);
    tplay.setCharacterSize(36);
    tplay.setColor(sf::Color(255,255,255));
    tinst.setFont(font);
    tinst.setCharacterSize(36);
    tinst.setColor(sf::Color(255,255,255));
    texit.setFont(font);
    texit.setCharacterSize(36);
    texit.setColor(sf::Color(255,255,255));
    string play = "1. Play";
    string instructions = "2. Instructions";
    string strexit = "3. Exit";
    tplay.setString(play);
    tinst.setString(instructions);
    texit.setString(strexit);
    //set text positions.
    tplay.setPosition(WIN_X/3, WIN_Y/3);
    tinst.setPosition(WIN_X/3, WIN_Y/3 + 40);
    texit.setPosition(WIN_X/3, WIN_Y/3 + 80);

    int infoloop = 1;
    int escInGame = 1;
    int gameloop = 1;
    int selection = 0;

    while(window.isOpen()){
        sf::Event event;
        while(gameloop){
            while(window.pollEvent(event)){
                window.clear();

                window.draw(tplay);
                window.draw(tinst);
                window.draw(texit);

                window.display();

                if(event.type == sf::Event::KeyPressed){
                    if(event.key.code == sf::Keyboard::Num1){
                        selection = 1;
                    }
                    else if(event.key.code == sf::Keyboard::Num2){
                        selection = 2;
                    }
                    else if(event.key.code == sf::Keyboard::Num3){
                        selection = 3;
                    }
                }
            }

            switch(selection){
                case 1:
                    cout << "P:" << player.get_x() << "," << player.get_y() << endl;
                    cout << "E:" << exit.get_x() << "," << exit.get_y() << endl;

                    ifile.open("default.lvl");
                    if(ifile.is_open()){
                        level.loadLevel(ifile, level, player,exit);
                        ifile.close();
                    }
                    else{
                        cout << "default.lvl not opened" << endl;
                    }

                    cout << "P:" << player.get_x() << "," << player.get_y() << endl;
                    cout << "E:" << exit.get_x() << "," << exit.get_y() << endl;
                    escInGame = 1;

                    while(!playerOnExit(player, exit) && escInGame == 1){

                        sf::sleep(sf::Time(sf::seconds(0.1f)));

                        while(window.pollEvent(event)){

                            if(event.type == sf::Event::Closed){
                                window.close();
                            }
                            window.clear();

                            if(event.type == sf::Event::KeyPressed){
                                if(event.key.code == sf::Keyboard::Space){
                                    push(player, level, level.y);
                                }
                                if(event.key.code == sf::Keyboard::Escape){
                                    selection = 0;
                                    escInGame = 0;
                                }
                                if(event.key.code == sf::Keyboard::Up){
                                    move(8, player, level, level.y);
                                }
                                if(event.key.code == sf::Keyboard::Down){
                                    move(2, player, level, level.y);
                                }
                                if(event.key.code == sf::Keyboard::Left){
                                    move(4, player, level, level.y);
                                }
                                if(event.key.code == sf::Keyboard::Right){
                                    move(6, player, level, level.y);
                                }
                            }
                            exit.set_z(exit.get_x(),exit.get_y(),level.y);
                            //draw map
                            drawMap(tilemap, tiles, window ,level);
                            //draw exit
                            drawExit(tilemap, tiles, window, exit);
                            //draw player
                            drawPlayer(tilemap, tiles, window, player);
                            window.display();
                        }
                    }
                    selection = 0;
                break;

                case 2:
                    infoloop = 1;
                    while(infoloop){
                        while(window.pollEvent(event)){
                            window.clear();
                            instruction_pic.setTextureRect(sf::IntRect(0,0,800, 640));
                            instruction_pic.setTexture(instruction_picture);
                            window.draw(instruction_pic);
                            selection = 0;
                            window.display();

                            if(event.type == sf::Event::KeyPressed){
                                if(event.key.code == sf::Keyboard::Return){
                                    infoloop = 0;
                                }
                                else if(event.key.code == sf::Keyboard::Escape){
                                    infoloop = 0;
                                }
                                else if(event.key.code == sf::Keyboard::Space){
                                    infoloop = 0;
                                }
                            }
                        }
                    }
                break;

                case 3:
                    window.close();
                    gameloop = 0;
                break;
            }
       }
    }
    return 0;
}




