#include <iostream>
#include <fstream>
//#include <fstream>
//#include <string>
using namespace std;
#pragma warning(disable:4996)


class T1 {
public:
};
void fun() {
	//T1 t1;
}
int main()
{
	int a;

	cout << '\n';
	cout << '\12';
	cout << '\xA';
	cout << '\0';

	int *v1 = new int[3];
	delete v1;
	fun();

	cin >> a;
	return 0;
}