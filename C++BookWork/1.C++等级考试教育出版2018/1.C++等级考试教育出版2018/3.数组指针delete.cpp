#include <iostream>
using namespace std;

class A :public A {};

int main()
{
	int a;
	int *ar = new int[2];
	delete []ar;

	cin >> a;
	return 0;
}