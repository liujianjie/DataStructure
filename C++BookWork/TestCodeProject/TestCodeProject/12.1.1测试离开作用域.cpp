#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <functional>
#include <memory>
#include "Foo136.h"
using namespace std;


int main()
{
	int a;
	vector < string> v1;
	{
		vector<string> v2 = { "a" };
		v1 = v2;
		cout << v1[0] << endl;
	}
	cout << v1[0] << endl;

	shared_ptr<string> s1;
	{
		shared_ptr<string> s2 = make_shared<string>("123");
		s1 = s2;
		cout << *s1 << endl;
	}
	cout << *s1 << endl;


	std::cin >> a;
	return 0;
}
