#ifndef PLAYER_H
#define PLAYER_H

#include "mapdef.h"
#include <vector>

using namespace std;


class Player{
public:
	Player(int px, int py);
	int get_x();
	int get_y();
	int get_z();
	int get_tx();
	int get_ty();
	int get_tz();
	int get_dir();

	void set_z(int x, int y, vector< vector<int>> varray);

	void set_dir(int value);
	void set_x(int value);
	void set_y(int value);
	void set_z(int value);
	void set_tx(int value);
	void set_ty(int value);
	void set_tz(int value);

private:
	int x, y, z, tx, ty, tz, dir;
};

#endif // PLAYER_H
