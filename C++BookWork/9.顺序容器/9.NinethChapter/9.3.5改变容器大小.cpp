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
	int a;

	//
	list<int> ilist(10, 42);// 10个int：每个值都是42
	ilist.resize(15);// 多加5个0
	for (auto beg = ilist.begin(), end = ilist.end();
		beg != end; ++beg) {
		cout << *beg;
	}
	cout << endl;
	ilist.resize(25, -1);// 多加10个值再后面
	for (auto beg = ilist.begin(), end = ilist.end();
		beg != end; ++beg) {
		cout << *beg;
	}
	cout << endl;
	ilist.resize(5);// 删除20个元素
	for (auto beg = ilist.begin(), end = ilist.end();
		beg != end; ++beg) {
		cout << *beg;
	}
	cout << endl;

	// array不支持
	//array<int, 10> arr1;
	//arr1.resize(15);

	deque<int> li1(10, 42);// 10个int：每个值都是42
	auto it1 = li1.begin() + 7;
	cout << *it1 << endl;
	li1.resize(5);
	//cout << *it1 << endl;// 会失效

	// 练习
	// 9.29
	vector<int> ve2(25);
	for (auto beg = ve2.begin(), end = ve2.end();
		beg != end; ++beg) {
		cout << *beg;
	}
	cout << endl;
	ve2.resize(100);
	for (auto beg = ve2.begin(), end = ve2.end();
		beg != end; ++beg) {
		cout << *beg;
	}
	cout << endl;
	cout << ve2.size() << endl;
	ve2.resize(10);
	for (auto beg = ve2.begin(), end = ve2.end();
		beg != end; ++beg) {
		cout << *beg;
	}
	cout << endl;

	// 练习9.30 
	cin >> a;
	return 0;
}