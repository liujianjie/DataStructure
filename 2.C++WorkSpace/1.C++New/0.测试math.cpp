#include <iostream>
#include <iomanip>
#define _USE_MATH_DEFINES
#include <math.h>
using namespace std;

inline int _pow(int a, int b) {
	cout << "±¾µØpow" << endl;
	int x = 1;
	for (; b > 0; b--) {
		x = x * a;
	}
	return x;
}

void main() {
	float fl = 3.12312312312;
	cout << setiosflags(ios::fixed) << setprecision(2) << fl << endl;
	double pi = M_PI;
	cout << setprecision(30) << pi << endl;;

	double pi2 = acos(-1);
	cout << pi2 << endl;

	double db3 = _pow(3, 4);
	cout << db3 << endl;
	double db4 = pow(3, 4);
	cout << db4 << endl;
}