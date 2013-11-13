#include "funcs.h"
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

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

void addPE(Player player, Exit exit, char a[WIDTH][HEIGHT]){ //lisää pelaajan ja exitin kartalle
	//add exit
	a[exit.get_x()][exit.get_y()] = 'E';

	//add player
	a[player.get_x()][player.get_y()] = 'P';
	/*
	if(player.get_dir() == 8){
		a[player.get_x()][player.get_y()] = 'A';
	}
	else if (player.get_dir() == 6){
		a[player.get_x()][player.get_y()] = '>';
	}
	else if (player.get_dir() == 2){
		a[player.get_x()][player.get_y()] = 'V';
	}
	else{
		a[player.get_x()][player.get_y()] = '<';
	}
	*/
}

void charray(int i[WIDTH][HEIGHT], char a[WIDTH][HEIGHT]){ //lisää 48 int mappiin
	int x;
	int y;
	for(y = 0 ; y < HEIGHT ; y++){
		for(x = 0 ; x < WIDTH ; x++){
			a[x][y] = (char) i[x][y] + 48;
		}
	}
}

void printMap(char a[WIDTH][HEIGHT]){ //tulostaa kartan
	int x;
	int y;

	for(y = 0; y < HEIGHT; y++){
		for(x = 0; x < WIDTH; x++){
			if( x < WIDTH - 1){
				cout << a[x][y];
			}
			else{
				cout << a[x][y] << endl;
			}
		}
	}
}

int playerOnExit(Player player, Exit exit){

	if(player.get_x() == exit.get_x() && player.get_y() == exit.get_y()){
		return 1;
	}
	else return 0;
}

void printArray(int array[WIDTH][HEIGHT]){
    int i,j;
    for(j = 0 ; j < HEIGHT ; j++){
        for(i = 0 ; i < WIDTH ; i++){
            if(i == WIDTH - 1){
                cout << array[i][j] << endl;
            }
            else{
                cout << array[i][j] << ' ';
            }
        }
    }

}

void clearScreen()
{
    cout << string( 100, '\n' );
}

void exit(){
   exit(EXIT_SUCCESS);
}
