#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <string>
#include <iterator>
#include <list>
#include <functional>
#include <iterator>
#include "Sales_data.h"
using namespace std;
using namespace std::placeholders;// 占位符空间


void prints(vector<int> con) 
{
	for_each(con.begin(), con.end(),
		[](const int &s) {cout << s << " "; });
	cout << endl;
}
void prints(list<int> con)
{
	for_each(con.begin(), con.end(),
		[](const int &s) {cout << s << " "; });
	cout << endl;
}
// inserter 接受两个参数，一个容器，一个是要插入的位置
int main()
{

	int a;
	// 
	vector<int> v1;
	auto it = inserter(v1, v1.begin());
	it = 1;
	*it = 2;
	it++ = 3;
	++it = 4;

	prints(v1);

	list<int> lst = { 1,2,3,4 };
	list<int> lst2, lst3;// 空list
	copy(lst.cbegin(), lst.cend(), front_inserter(lst2));
	copy(lst.cbegin(), lst.cend(), inserter(lst3, lst3.begin()));
	prints(lst2);
	prints(lst3);

	list<int> lst4;
	auto it2 = back_inserter(lst4);
	it2 = 2;
	it2 = 3;
	it2 = 6;
	prints(lst4);

	// 练习
	vector<int> v2{1,1,1,2,2,2,2,4,5,6,6,6,6,7,7,7,7,8,8,8,8,9,9,9,9};
	list<int> lst5(v2.size());
	auto iter1 = unique_copy(v2.begin(),v2.end(), lst5.begin() );
	lst5.erase(iter1, lst5.end());
	prints(lst5);
	cout << lst5.size() << endl;

	list<int> lst6;
	unique_copy(v2.begin(), v2.end(), back_inserter(lst6));
	prints(lst6);
	// 
	vector<int> v3{ 1,2,3,4,5,6,7,8,9 };
	list<int> v6, v7, v8;
	copy(v3.begin(), v3.end(), front_inserter(v6));
	copy(v3.begin(), v3.end(), back_inserter(v7));
	copy(v3.begin(), v3.end(), inserter(v8, v8.begin()));
	prints(v6);
	prints(v7);
	prints(v8);


	cin >> a;
	return 0;
}

