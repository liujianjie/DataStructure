#include <iostream>
#include <list>
#include <deque>
#include <vector>
#include "Sales_data.h"
#include "noDefault.h"

using namespace std;

int main()
{
	int a;
	// ≥…‘±
	vector<int>::size_type v1 = 1;
	cout << v1 << endl;
	vector<int>::iterator v2;
	//cout << v2 << endl;
	vector<int>::const_iterator v3;
	//cout << v3 << endl;
	vector<int>::difference_type v4 = 3;
	cout << v4 << endl;
	vector<int>::value_type v5 = 5;
	cout << v5 << endl;
	vector<int>::difference_type v6 = 6;
	cout << v6 << endl;

	cin >> a;
	return 0;
}