#include <iostream>
#include "T1.h"

using namespace std;

int main() 
{
	int a;
	//int **x, *y, z = 10;
	//y = &z;
	//x = &y;
	//cout << **x + 1 << endl;

	int x[6] = { 1,3,5,7,9,11 }, *k, **s;
	k = &x[0];
	s = &k;
	cout << *(k++) << "," << **s << endl;

	int val1 = 1, val2 = 2;
	int &rv1 = val1;
	int &rv2 = val1;
	//rv1 = val2;

	cout << rv1 << " " << rv2 << endl;
	//rv1 = 40;
	//cout << rv1 << " " << rv2 << endl;

	cin >> a;
	return 0;
}