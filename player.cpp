#include "player.h"

Player::Player(int px, int py){
	x = px;
	y = py;
	z = 0;
	tx = px;
	ty = py;
	tz = 0; //ehkä turha
	dir = 8;
}

int Player::get_x(){
	return x;
}

int Player::get_y(){
	return y;
}

int Player::get_z(){
	return z;
}

int Player::get_tx(){
	return tx;
}

int Player::get_ty(){
	return ty;
}

int Player::get_tz(){
	return tz;
}

int Player::get_dir(){
	return dir;
}

void Player::set_z(int x, int y, int array[WIDTH][HEIGHT]){
	z = array[x][y];
}

void Player::set_dir(int value){
	dir = value;
}

void Player::set_x(int value){
	x = value;
}

void Player::set_y(int value){
	y = value;
}

void Player::set_z(int value){
	z = value;
}

void Player::set_tx(int value){
	tx = value;
}

void Player::set_ty(int value){
	ty = value;
}

void Player::set_tz(int value){
    tz = value;
}
