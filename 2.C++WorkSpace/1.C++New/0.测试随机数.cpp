#include <iostream>
#include <iomanip>
#define _USE_MATH_DEFINES
#include <math.h>
#include <ctime>
#include <random>
using namespace std;


void main() {
	default_random_engine e;
	uniform_int_distribution<int> u(-12, 20);
	uniform_real_distribution<double> u2(-10.5, 10.5);
	e.seed(time(0));
	for (int i = 0; i < 5; i++) {
		cout << u(e) << endl;
		cout << u2(e) << endl;
	}
}