#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;


void main() {
	float fl = 3.12312312312;
	cout << setiosflags(ios::fixed) << setprecision(2) << fl << endl;
}