#include <iostream>
#include <iomanip>
#include <cstring>
//#include <string>
using namespace std;

int val2;
decltype(val2) testway1(int a) {
	return 1;
}

int arr[] = { 1,2,3 };
decltype(arr[0]) testway1() {
	int a;
	return a;
}
int main()
{
	int a;
	
	int x[] = { 0 };
	
	cout << x[1] << endl;
	int x1[] = { 0,0,0 };
	cout << x1[1] << endl;

	//decltype(val);
	cin >> a;
	return 0;
}