#include <iostream>
#include <cmath>

#include <string>

int a1 = 5;
extern int a1;
extern int a1;

using namespace std;
int main() 
{
	int a;
	extern int a1;
	extern int a1;

	//extern int a2;
	//int a2;

	const double eps = 1e-6;
	//cout << oct << eps << endl;
	int sign = 1;
	double pi = 0.0;
	double item = 1.0;
	double d = 1.0;
	while (fabs(item) >= eps) {
		pi += item;
		d += 2.0;
		sign = -sign;
		item = sign *(1 / d);
	}
	pi *= 4;
	cout << "PI = " << pi << endl;


	int i = 1, sum = 0;
Loop:
	sum += i;
	i++;
	if (i <= 100)
		goto Loop;
	cout << sum << endl;

	do {
		cout << "111" << endl;
		goto end;
	} while (1);
end:cout << "end" << endl;

	for (int i = 0; i < 10; i++) {
		break;
		break;
	}
	int v1 = 2, v2 = 3;
	//if (v1 < v2) {
	//	break;
	//}

	int s1 = 1;
	switch (s1)
	{
	case 1:
		cout << "case 1" << endl;
		break;
	default:
		cout << "#" << endl;
		break;
	}

	char c1[8] = "1234";
	cout << strlen(c1) << endl;
	char c2[7] = {'1','2','3','4','\0'};
	cout << strlen(c2) << endl;
	cout << c2 << endl;

	string s1 = "123213";
	//cout << s1.size() << endl;
	cin >> a;
	return 0;
}