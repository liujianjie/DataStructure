#include <iostream>
#include <fstream>
//#include <fstream>
//#include <string>
using namespace std;
#pragma warning(disable:4996)

class T1 {
public:
	

};
int operator+(int a, T1 t2) {
	return 1;
}

int xx[3] = { 0,0 };
static int x[3] = { 0 };

void f(int a, int b){}
void f(int a, int b, int c = 0){}
int main()
{
	int a;

	T1 t1, t2;
	//t1 + t2;
	//t1 + 4;
	4 + t1;

	//T1 &rt = new T1;
	T1 t3, &rt2 = t3;
	//f(1,2);

	ofstream ofile;
	char ch;
	//ofile.open("abc.txt",'W');
	do {

		cin >> ch;
		ofile.put(ch);
	} while (ch != '#');
	ofile.close();
	
	cin >> a;
	return 0;
}