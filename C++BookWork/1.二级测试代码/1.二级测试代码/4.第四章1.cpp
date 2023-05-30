#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <cstring>
#include <string>
#include <fstream>
using namespace std;


int main()
{
	int a;


	char s3[10];
	//gets(&s0);
	//gets(s3);

	//scanf("%s", s3 + 1);
	//scanf("%s", s3[1]);//´íÎó
	//char c1 = '2';
	//scanf("%s", c1);// ·ÅµØÖ·
	//int &b;
	//int -00;

	// 14
	//int(15.8 % 5);
	a = int(5);
	cout << a << endl;
	//float b = 15 % 2.0;

	int x=2, y=1,z=0;
	x = y + z + 5, ++y;
	//int xx = yy = 3;

	int val = 2;

	switch (val)
	{
	case 1:
	case 2:
		cout << "2" << endl;
	case 3:
		cout << "2" << endl;
	default:
		break;
	}
	//int xx1[][3];
	int x1[][3] = { 1,2,3,4,5 };
	//int x2[4][] = { {1,2,3,4},{1,2,3,4},{ 1,2,3,4 },{ 1,2,3,4 } };
	cout << x1[0][0] << endl;
	cout << x1[0][1] << endl;
	cout << x1[0][2] << endl;
	cout << x1[0][3] << endl;
	cout << x1[0][4] << endl;

	char s1[20] = "Beigjing", *p;
	p = s1;
	cout << *p << endl;

	int a2[2][3] = { {1,2,3},{ 4,5,6 } };
	int v1 = a2[1 > 2][!1];
	cout << !1 << endl;
	cout << (1 > 2) << endl;
	cout << a2[0][7] << endl;

	//float val = (float)(5 % 2.4);
	cin >> a;
	return 0;
}

