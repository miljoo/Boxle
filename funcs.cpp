#include "funcs.h"
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

void drawPlayer(sf::Texture& tilemap, sf::Sprite& tiles, sf::RenderWindow& window, Player& player){
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
    tiles.setPosition(player.get_x()*TILESIZE, player.get_y()*TILESIZE);
    window.draw(tiles);
}

void drawExit(sf::Texture& tilemap, sf::Sprite& tiles, sf::RenderWindow& window, Exit& exit){
    tiles.setTextureRect(sf::IntRect(5*TILESIZE, TILESIZE*exit.get_z(), TILESIZE, TILESIZE));
    tiles.setTexture(tilemap);
    tiles.setPosition(exit.get_x()*TILESIZE, exit.get_y()*TILESIZE);
    window.draw(tiles);

}

void drawMap(sf::Texture& tilemap, sf::Sprite& tiles, sf::RenderWindow& window, int array[WIDTH][HEIGHT]){
 int i , j;
    for(j = 1 ; j < HEIGHT - 1 ; j++){
        for(i = 1; i < WIDTH - 1 ; i++){
            tiles.setTextureRect(sf::IntRect(0, (TILESIZE*array[i][j]), TILESIZE, TILESIZE));
            tiles.setTexture(tilemap);
            tiles.setPosition(i*TILESIZE, j*TILESIZE);
            window.draw(tiles);
        }
    }
}

void move(int cmd, Player& player, int array[WIDTH][HEIGHT]){

	if(cmd != player.get_dir()){
        //cout << player.get_dir();
		player.set_dir(cmd);
        //cout << player.get_dir();
	}

	else{
		if(cmd == 8){
			player.set_ty( player.get_y() - 1 );

			if(player.get_z() >= array[player.get_x()][player.get_ty()]){
				player.set_z(array[player.get_x()][player.get_ty()]);
				player.set_y(player.get_ty());
			}
			else{
				if(player.get_z() >= array[player.get_x()][player.get_ty() - 1]){
					player.set_y(player.get_ty());
					int temp = array[player.get_x()][player.get_y()] - player.get_z();
					array[player.get_x()][player.get_y()] = player.get_z();
					array[player.get_x()][player.get_y() - 1] += temp;
				}
				else if(player.get_z() + 1 == array[player.get_x()][player.get_ty()]){
					player.set_z(player.get_z() + 1);
					player.set_y(player.get_ty());
				}
			}
		}

		else if(cmd == 2){//valittu 2 suunta alas
			player.set_ty( player.get_y() + 1 );

			if(player.get_z() >= array[player.get_x()][player.get_ty()]){
				player.set_z(array[player.get_x()][player.get_ty()]);
				player.set_y(player.get_ty());
			}
			else{
				if(player.get_z() >= array[player.get_x()][player.get_ty() + 1]){
					player.set_y(player.get_ty());
					int temp = array[player.get_x()][player.get_y()] - player.get_z();
					array[player.get_x()][player.get_y()] = player.get_z();
					array[player.get_x()][player.get_y() + 1] += temp;
				}
				else if(player.get_z() + 1 == array[player.get_x()][player.get_ty()]){
					player.set_z(player.get_z() + 1);
					player.set_y(player.get_ty());
				}
			}
		}
		else if(cmd == 6){//valittu 6 suunta oikealle
			player.set_tx( player.get_x() + 1 );

			if(player.get_z() >= array[player.get_tx()][player.get_y()]){
				player.set_z(array[player.get_tx()][player.get_y()]);
				player.set_x(player.get_tx());
			}
			else{
				if(player.get_z() >= array[player.get_tx() + 1][player.get_y()]){
					player.set_x(player.get_tx());
					int temp = array[player.get_x()][player.get_y()] - player.get_z();
					array[player.get_x()][player.get_y()] = player.get_z();
					array[player.get_x() + 1][player.get_y()] += temp;
				}
				else if(player.get_z() + 1 == array[player.get_tx()][player.get_y()]){
					player.set_z(player.get_z() + 1);
					player.set_x(player.get_tx());
				}
			}
		}
		else if(cmd == 4){//valittu 4 suunta vasemmalle
			player.set_tx( player.get_x() - 1 );

			if(player.get_z() >= array[player.get_tx()][player.get_y()]){
				player.set_z(array[player.get_tx()][player.get_y()]);
				player.set_x(player.get_tx());
			}
			else{
				if(player.get_z() >= array[player.get_tx() - 1][player.get_y()]){
					player.set_x(player.get_tx());
					int temp = array[player.get_x()][player.get_y()] - player.get_z();
					array[player.get_x()][player.get_y()] = player.get_z();
					array[player.get_x() - 1][player.get_y()] += temp;
				}
				else if(player.get_z() + 1 == array[player.get_tx()][player.get_y()]){
					player.set_z(player.get_z() + 1);
					player.set_x(player.get_tx());
				}
			}
		}
	}
}

void push(Player player, int array[WIDTH][HEIGHT]){
	if(player.get_dir() == 8){
		if((array[player.get_x()][player.get_y()] >= array[player.get_x()][player.get_y() - 2]) && (array[player.get_x()][player.get_y()] < array[player.get_x()][player.get_y() - 1])){
			array[player.get_x()][player.get_y() - 2] += 1;
			array[player.get_x()][player.get_y() - 1] -= 1;
		}
	}

    else if(player.get_dir() == 2){
		if((array[player.get_x()][player.get_y()] >= array[player.get_x()][player.get_y() + 2]) && (array[player.get_x()][player.get_y()] < array[player.get_x()][player.get_y() + 1])){
			array[player.get_x()][player.get_y() + 2] += 1;
			array[player.get_x()][player.get_y() + 1] -= 1;
		}
	}

	else if(player.get_dir() == 6){
		if( (array[player.get_x()][player.get_y()] >= array[player.get_x() + 2][player.get_y()]) && (array[player.get_x()][player.get_y()] < array[player.get_x() + 1][player.get_y()]) ){
			array[player.get_x() + 2][player.get_y()] += 1;
			array[player.get_x() + 1][player.get_y()] -= 1;
		}
	}

	else if(player.get_dir() == 4){
		if( (array[player.get_x()][player.get_y()] >= array[player.get_x() - 2][player.get_y()]) && (array[player.get_x()][player.get_y()] < array[player.get_x() - 1][player.get_y()]) ){
			array[player.get_x() - 2][player.get_y()] += 1;
			array[player.get_x() - 1][player.get_y()] -= 1;
		}
	}
}

int playerOnExit(Player player, Exit exit){

	if(player.get_x() == exit.get_x() && player.get_y() == exit.get_y()){
		return 1;
	}
	else return 0;
}

void exit(){
   exit(EXIT_SUCCESS);
}
