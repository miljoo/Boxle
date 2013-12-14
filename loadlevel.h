#ifndef LOADLEVEL_H
#define LOADLEVEL_H

#include <string>
#include <cstring>
#include <iostream>

using namespace std;

class String
{
friend ostream& operator<<(ostream &out, const String &tulostus);

private:
	char *c_string;
public:

	String(char *input="");
	String(const String &a);
	~String();
	void list();
	String operator+(const String &strinki);
	const String& operator=(const String &sijoitus);
	String& operator++();
	String operator++(int);
};

string find_field(string from, string search);


#endif
