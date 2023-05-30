#include <iostream>
#include <list>
#include <deque>
#include <vector>
#include <forward_list>
#include <array>
#include "Sales_data.h"
#include "noDefault.h"
#include <string>
using namespace std;

int main()
{
	// 等于为0，大于为1，小于为-1
	int a;
	const char c1[] = "1231232";
	string s1("123");
	string s2("123");
	auto v1 = s1.compare(s2);
	cout << v1 << endl;
	cout << s1.compare(2, 2, s2) << endl;
	cout << s1.compare(2, 2, s2, 2, 2) << endl;
	cout << s1.compare(c1) << endl;
	cout << s1.compare(0, 2, c1) << endl;
	cout << s1.compare(0, 2, c1, 2) << endl;

	cin >> a;
	return 0;
}