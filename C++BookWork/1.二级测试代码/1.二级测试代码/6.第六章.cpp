#include <iostream>
#include <stdio.h>

#define PI 3.5

using namespace std;

//void fun(int * a, int * b)
//{
//	int val = 2;
//	int *c = &val;
//	*c = *a;
//	*a = *b;
//	*b = *c;
//}
void fun(int * a, int * b)
{
	int *c;
	c = a;
	a = b;
	b = c;
}
void fun2(int *p, int *q)
{
	*p = *p + 1;
	*q = *q + 1;
	cout << "p" << *p << endl;
}
struct ord
{
	int x, y;
}dt[2] = { 1,2,3,4 };
int main()
{
	int a;
	int x = 3, y = 5, *p = &x, *q = &y;
	fun(p, q);
	cout << *p << *q << endl;
	fun(&x, &y);
	cout << *p << *q << endl;

	int val1 = 10, val2 = 20;
	int *ref1 = &val1, *ref2 = &val2;
	int *ref4 = ref1, *ref5 = ref2;
	int *ref3;
	ref3 = ref4;
	ref4 = ref5;
	ref5 = ref3;
	cout << *ref1 << *ref2 << endl;
	cout << *ref4 << *ref5 << endl;

	// 27
	int m = 1, n = 2, *r1 = &m;
	//int *nr1 = r1;
	//*nr1 = *nr1 + 1;
	//cout << m << endl;
	//cout << *nr1 << endl;

	fun2(r1, &n);
	cout << m << n;

	cout << endl;
	// 16
	double x1, y1, *px1, *py1;
	px1 = &x1;
	py1 = &y1;

	//scanf("%lf%lf", px1, py1);
	//scanf("%lf%le",&x1,&y1);
	cout << *px1 <<" "<< *py1 << endl;

	// 37
	struct ord *p1 = dt + 1;
	cout << (++p1->x) << (++p1->y) << endl;

	// 40
	FILE * f;
	f = fopen("filea.txt","w");
	fprintf(f, "abc");
	fclose(f);

	// 32
	//char s[10];
	//s = "BOOK";
	char *s2;
	s2 = { "12312" };
	cout << s2 << endl;
	//char s3[10];
	//s3 = "12312";

	char *s4;
	s4 = "BOKK";

	cout << s4 << endl;
	cin >> a;
	return 0;
}


