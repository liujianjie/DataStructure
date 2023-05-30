#include <iostream>
#include <math.h>

int a2;
extern int a2;
extern int a2;

using namespace std;
int main()
{
	//char c1 = '\a';
	//cout << c1 << endl;
	//const char c2 = '\4f';
	//cout << c2 << endl;

	double x = 2.5, y = 4.7;
	int a = 7;
	cout << (x + a % 3 * (int)(x + y) % 2 / 4) << endl;

	// 编程题
	int o1;
	unsigned int o2;
	long o3;
	unsigned o4;
	cout << sizeof(o1) << endl;
	cout << sizeof(o2) << endl;
	cout << sizeof(o3) << endl;
	cout << sizeof(o4) << endl;
	cout << sizeof(long int) << endl;

	// 
	cout << "\n" << endl;
	cout << sizeof(char) << endl;
	cout << sizeof(unsigned char) << endl;
	cout << sizeof(signed char) << endl;
	cout << sizeof(float) << endl;
	cout << sizeof(double) << endl;
	cout << sizeof(long double) << endl;
	//cout << sizeof(void) << endl;

	// 3
	int a1, b1, c1;
	cout << "输入三角形边长" << endl;
	cin >> a1 >> b1 >> c1;
	if (a1 + b1 > c1 && a1+ c1 > b1 && b1 + c1 > a1) {
		double s = (a1 + b1 + c1) / 2;
		double area = sqrt(s*(s-a1)*(s-b1)*(s-c1));
		cout << "三角形的面积为:" << area << endl;
	}


	cin >> a;
	return 0;
}