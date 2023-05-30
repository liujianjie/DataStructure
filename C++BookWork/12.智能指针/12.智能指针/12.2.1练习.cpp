
#include <iostream>
#include <cstring>
using std::cout;
using std::endl;
using std::string;

int main(int argc, char *argv[])
{
	const char *c1 = "Hello";
	const char *c2 = "World";

	char *r = new char[strlen(c1) + strlen(c2) + 1];
	strcpy(r, c1);
	strcat(r, c2);
	cout << r << endl;
	string s1 = "hello";
	string s2 = "world";
	strcpy(r, (s1 + s2).c_str());
	cout << r << endl;
	delete[] r;
	return 0;
}