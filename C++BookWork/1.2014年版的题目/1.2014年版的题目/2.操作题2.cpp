#include <iostream>
#include <fstream>
//#include <fstream>
//#include <string>
using namespace std;
#pragma warning(disable:4996)


class T1 {
	virtual void fun() = 0;
};
class T2 : public T1 {

	virtual void fun() { cout << "year" << endl; }
};

int main()
{
	int a;
	T2 t2;
	//t2.fun();

	cin >> a;
	return 0;
}