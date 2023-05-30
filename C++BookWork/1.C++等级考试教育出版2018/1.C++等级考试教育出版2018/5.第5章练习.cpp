#include <iostream>
using namespace std;

int fun(char *s)
{
	char *t = s;
	while (*t != '\0')
		t++;
	return (t - s);
}
void caozuo(char *s)
{
	//char *t = s;
	//t = 
}
int main()
{
	int a;

	a = fun("hello");
	cout << a << endl;

	char *ch1 = "asdf";
	//char *ch2 = "zxcv";
	char *c1 = ch1;
	//c1 = ch2;

	c1++;
	cout << "ch1:" << c1 << "ch2:" << ch1 << endl;

	cin >> a;
	return 0;
}