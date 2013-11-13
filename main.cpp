#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include "player.h"
#include "exit.h"
#include "funcs.h"

#define TILESIZE 64

using namespace std;

int main(){

    char c[WIDTH][HEIGHT];
    int a[WIDTH][HEIGHT] = {{9,9,9,9,9,9,9,9,9,9},
                            {9,9,9,9,9,9,9,9,9,9},
                            {9,9,0,1,1,0,0,7,9,9},
                            {9,9,2,1,0,0,1,6,9,9},
                            {9,9,2,0,0,2,0,5,9,9},
                            {9,9,0,3,0,0,0,0,9,9},
                            {9,9,0,6,0,0,0,3,9,9},
                            {9,9,7,4,3,0,0,2,9,9},
                            {9,9,9,9,9,9,9,9,9,9},
                            {9,9,9,9,9,9,9,9,9,9}};

    Player player(2,2);
    Exit exit(2,7);

    player.set_z(player.get_x(),player.get_y(),a);
    player.set_dir(8);

    charray(a,c);
    addPE(player, exit, c);

    sf::RenderWindow window;
    window.create(sf::VideoMode(700,700), "Boxle a0.1");
    window.setKeyRepeatEnabled(false);

    sf::Texture tilemap;
    sf::Sprite tiles;
    if(!tilemap.loadFromFile("gblue.png"))
        std::cout << "Error loading tileset" << std::endl;


    sf::Font font;
    if(!font.loadFromFile("tahomabd.ttf"))
        std::cout << "error loading font" << std::endl;
    sf::Text text;
    text.setFont(font);
    text.setCharacterSize(36);




    while(window.isOpen()){
       sf::Event event;
       while(!playerOnExit(player, exit)){
            while(window.pollEvent(event)){

                if(event.type == sf::Event::Closed){
                    window.close();
                }
                window.display();
                window.clear();

                if(event.type == sf::Event::KeyPressed){
                    if(event.key.code == sf::Keyboard::Space){
                        push(player, a);
                    }
                    if(event.key.code == sf::Keyboard::Escape){
                        return 0;
                    }
                    if(event.key.code == sf::Keyboard::Up){
                        move(8,player, a);
                    }
                    if(event.key.code == sf::Keyboard::Down){
                        move(2,player, a);
                    }
                    if(event.key.code == sf::Keyboard::Left){
                        move(4,player, a);
                    }
                    if(event.key.code == sf::Keyboard::Right){
                        move(6,player, a);
                    }
                }

                exit.set_z(exit.get_x(),exit.get_y(),a); //mabby somedya clean up not so tired derp :P
                charray(a,c);
                addPE(player, exit,c);

                for(int j = 1 ; j < HEIGHT - 1 ; j++){
                    for(int i = 1; i < WIDTH - 1 ; i++){
                        if(c[i][j] != 'P' && c[i][j] != 'E' && c[i][j] != '9'){
                            tiles.setTextureRect(sf::IntRect(0, (TILESIZE*a[i][j]), TILESIZE, TILESIZE));
                            tiles.setTexture(tilemap);
                            tiles.setPosition(i*TILESIZE, j*TILESIZE);
                            window.draw(tiles);
                        }
                        else if(c[i][j] == 'P'){
                            int pdir;
                            if(player.get_dir() == 8){
                                pdir = 1;
                            }else if(player.get_dir() == 4){
                                pdir = 2;
                            }else if(player.get_dir() == 2){
                                pdir = 3;
                            }else if(player.get_dir() == 6){
                                pdir = 4;
                            }
                            tiles.setTextureRect(sf::IntRect(pdir*TILESIZE, TILESIZE*player.get_z(), TILESIZE, TILESIZE));
                            tiles.setTexture(tilemap);
                            tiles.setPosition(i*TILESIZE, j*TILESIZE);
                            window.draw(tiles);
                        }else if(c[i][j] == 'E'){
                            tiles.setTextureRect(sf::IntRect(5*TILESIZE, TILESIZE*exit.get_z(), TILESIZE, TILESIZE));
                            tiles.setTexture(tilemap);
                            tiles.setPosition(i*TILESIZE, j*TILESIZE);
                            window.draw(tiles);
                        }else if(c[i][j] == '9'){
                            tiles.setTextureRect(sf::IntRect(6*TILESIZE, 0, TILESIZE, TILESIZE));
                            tiles.setTexture(tilemap);
                            tiles.setPosition(i*TILESIZE, j*TILESIZE);
                            window.draw(tiles);
                        }
                    }
                }

                text.setColor(sf::Color(255,255,255));
                std::string tmp;
                std::string tmp2;
                tmp = ("P =");
                tmp += (char)player.get_z() + 48;
                tmp2 = (" E =");
                tmp2 += (char)exit.get_z() + 48;
                text.setString(tmp += tmp2);
                window.draw(text);
                playerOnExit(player, exit);
            }
        }
        window.close();
    }
    return 0;
}



