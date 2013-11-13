#ifndef EXIT_H
#define EXIT_H

#include "mapdef.h"

class Exit{
public:
	Exit(int px, int py);
	int get_x();
	int get_y();
	int get_z();

	void set_z(int x, int y, int array[WIDTH][HEIGHT]);

	void set_x(int value);
	void set_y(int value);
	void set_z(int value);

private:
	int x, y, z;
};

#endif // EXIT_H
