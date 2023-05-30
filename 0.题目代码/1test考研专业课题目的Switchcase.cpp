#include <iostream>
//#include <cmath>
using namespace std;

int main() {
	cout << sqrt(12) << endl;
	int a = 1;
	switch (a)
	{
	case 1: {
		cout << a++ << endl;
		cout << "hh" << endl;
	}
		  break;
	case 3:
		cout << a++ << endl;
	case 4:
		cout << a++ << endl;
		cout << "hh" << endl;
	case 5:
		cout << a++ << endl;
		break;
	default:
		cout << "2" << endl;
		break;
	}
	cout << a << endl;
	return 0;
}