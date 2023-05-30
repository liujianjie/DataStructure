#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <fstream>
#include <list>
#include <string> 
#include <memory>
#include <type_traits>
#include <climits>
#include "Blob.h"
#include "DebugDelete.h"
#include "NoDefault.h"
using namespace std;

/*

*/
template <typename T>
int compare(const T &a, const T &b)
{
	cout << "a" << a << endl;
	return 0;
}

void fcn(int(*)(const string&,const string &))
{
	cout << "void fcn(int(*)(const string*,const string *))" << endl;
}
void fcn(int(*)(const int&, const int &))
{
	cout << "void fcn(int(*)(const int*,const int *))" << endl;
}

int main()
{
	int a;
	int(*pf1)(const int &, const int&) = compare;
	auto a1 = pf1(3,4);

	fcn(compare<string>);
	/*
	*/

	cin >> a;
	return 0;
}


