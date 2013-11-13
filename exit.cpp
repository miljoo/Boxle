#include "exit.h"

Exit::Exit(int px, int py){
	x = px;
	y = py;
	z = 0;
}

int Exit::get_x(){
	return x;
}

int Exit::get_y(){
	return y;
}

int Exit::get_z(){
	return z;
}

void Exit::set_z(int x, int y, int array[WIDTH][HEIGHT]){
	z = array[x][y];
}

void Exit::set_x(int value){
	x = value;
}

void Exit::set_y(int value){
	y = value;
}

void Exit::set_z(int value){
	z = value;
}
