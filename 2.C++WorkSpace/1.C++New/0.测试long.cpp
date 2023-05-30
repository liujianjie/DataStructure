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
	int it = 2 << 30;
	long long lo = 1298307964911120440;
	long long lo2 = 2 << 32;
	double db = 129830790;
	cout << it << endl;;
	cout << lo2 << endl;;
	cout << lo << endl;;
	cout << sizeof(lo) << endl;
	cout << sizeof(it) << endl;
}