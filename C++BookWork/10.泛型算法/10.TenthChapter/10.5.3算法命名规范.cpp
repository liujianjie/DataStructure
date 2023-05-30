#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <string>
#include <iterator>
#include <list>
#include <functional>
#include <iterator>
#include <fstream>
#include <forward_list>
#include "Sales_item.h"
#include "Sales_data.h"
using namespace std;
using namespace std::placeholders;// 占位符空间


void prints(vector<int> con)
{
	for_each(con.begin(), con.end(),
		[](const int &s) {cout << s << " "; });
	cout << endl;
}
void prints(vector<string> con)
{
	for_each(con.begin(), con.end(),
		[](const string &s) {cout << s << " "; });
	cout << endl;
}
void prints(list<int> con)
{
	for_each(con.begin(), con.end(),
		[](const int &s) {cout << s << " "; });
	cout << endl;
}
bool pred1(int &vl) 
{
	return vl == 5;
}
/*


*/
int main()
{

	int a;
	vector<int> v1{ 1,2,3,4,6,5,8,23 };
	auto it1 = find_if(v1.begin(), v1.end(), pred1);
	for (auto beg = v1.begin(); beg != it1; ++beg) {
		cout << *beg << " ";
	}
	cout << endl;
	vector<int> v2{ 1,2,3,4,6,5,8,23 };
	// 并不会真正的删除
	auto it2 = remove_if(v2.begin(), v2.end(),
		[](int i) {return i % 2; });
	for (auto beg = v2.begin(); beg != it2; ++beg) {
		cout << *beg << " ";
	}
	cout << endl;

	vector<int> v4{ 1,2,3,4,6,5,8,23 }, v3;
	remove_copy_if(v4.begin(), v4.end(),back_inserter(v3),
		[](int i) {return i % 2; });
	for (auto beg = v3.begin(); beg != v3.end(); ++beg) {
		cout << *beg << " ";
	}
	cout << endl;
	cin >> a;
	return 0;
}

