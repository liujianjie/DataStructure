#include <iostream>
#include <stdio.h>

#include <iomanip>
#include <cstring>
#include <string>
#include <fstream>
using namespace std;


#define N 4

void fun(int a[][N], int b[])
{
	int i;
	for (i = 0; i < N; i++)
		b[i] = a[i][i];
}
int main()
{
	int a;
	//FILE *pf;
	//char *s1 = "china", *s2 = "Beijing";
	//pf = fopen("abc.txt","wb+");
	//fwrite(s2, 7, 1, pf);
	//rewind(pf);
	//fwrite(s1, 5, 1, pf);
	//fclose(pf);

	//24
	//char s[15] = "1234567\t\t\0111";
	//cout << strlen(s) << endl;

	// 13
//	const  char c = 'cd';
//	const  char c1 = '\a';
//	const  char c2 = '\011';
//const  const  int aa = 0.1e+6;

	// 19
	//int b; int c;
	//scanf("%d,%d,%d",&a,&b,&c);
	//cout << a << b << c << endl;

	// 35สýื้
	int x[][N] = { {1,2,3},{4},{5,6,7,8},{9,10} };
	int y[N], i;
	fun(x, y);
	for (i = 0; i < N; i++)
		printf("%d", y[i]);
	
	for ( i = 0; i < N;i++) {
		for (int j = 0; j < N; j++) {
			cout << x[i][j] << " " ;
		}
		cout << endl;
	}
	int ashuzu[7];
	cout << ashuzu[2] << endl;

	decltype(ashuzu) a3 = {1};

	cout << a3[0] << endl;
	int va1 = 23;
	decltype(ashuzu[1]) a4 = va1;

	int a5
		= 3;
	if
		(1)
	{
		cout <<
			"asdfs" <<
			endl;
	}
	cout << a5 << endl;

	//string s1 = "2/t2";
	char s1[10] = "12345\0\0";
	cout << strlen(s1) << endl;

	const char c2 = 'acdb';
	cout << c2 << endl;

	//const double a8 = 0.1e + 6;
	char c3 = '\011';
	char c4 = '\115';
	cout << c4 << endl;
	cin >> a;
	return 0;
}

