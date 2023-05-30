#include <iostream>
#include <cstring>
#include <string>
#pragma warning(disable:4996)
using namespace std;

void sus(char * s1) {
	
	cout << s1 << endl;
	delete s1;
}
void reverse(char *s)
{

	char *p, *q, temp;
	p = s;
	q = s + strlen(s) - 1;
	while (p < q) {
		temp = *p;
		*p = *q;
		*q = temp;
		p++;
		q--;
	}
	cout << *q << endl;
}
int main()
{
	int a;
	char s1[90], s2[100];
	strcpy(s1, "C++");
	//strcpy(s1, "add");
	cout << s1 << endl;

	string st1 = "12321";
	cout << st1.size() << endl;

	int x = 1;
	int *px = new int(2);
	*px = x;
	cout << *px << endl;

	//  Ðü¹ÒÖ¸Õë
	char *ch1 = "AVCSDFSDF";
	cout << ch1 << endl;
	//sus(ch1);

	cout << ch1 << endl;

	//reverse(ch1);

	// Á·Ï°
	int val3 = 20,val4 = 40;
	int &val1 = val3;
	val1 = val4;
	cout << val4 << endl;

	cin >> a;
	return 0;
}