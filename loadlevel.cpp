#include "loadlevel.h"

using namespace std;

String::String(char *input)
{
	c_string = new char [strlen(input)+1];
	strcpy(c_string, input);
}

String::String(const String &a)
{
	c_string = new char [strlen(a.c_string)+1];
	strcpy(c_string, a.c_string);
}

void String::list()
{
	cout << c_string << endl;
}

String::~String()
{
	delete c_string;
}

String String::operator+(const String &strinki)
{
	char* uus = new char [strlen(c_string)+strlen(strinki.c_string)+1];
	strcpy(uus, c_string);
	strcat(uus, strinki.c_string);
	String aux(uus);
	delete uus;
	return aux;
}

const String& String::operator=(const String &sijoitus)
{
	if(this != &sijoitus)
	{
		delete c_string;
		c_string = new char [strlen(sijoitus.c_string)+1];
		strcpy(c_string, sijoitus.c_string);
	}

	return *this;
}

ostream& operator<<(ostream &out, const String &tulostus)
{
	out << tulostus.c_string;
	return out;
}

String& String::operator++()
{
	String x("x");
	*this = *this + x;
	return *this;
}

String String::operator++(int)
{
	String x("x");
	*this = *this + x;
	return *this;
}

string find_field(string from, string search)
{
	string str = from;
	string str2 = "<" + search + ">";
	string str3 = "</" + search + ">";
	size_t pos;
	size_t pos2;
	string result;

	pos=str.find(str2) + str2.length();
	pos2=str.rfind(str3);

	result = str.substr (pos,pos2 - pos);

    return result;
}
