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
	// 删除首 不适合vector 与string
	//vector<int> ve1 = {1,2,3,4,5}; // 不行
	//string ve1 = { 1,2,3,4,5 };
	list<int> ve1 = { 1,2,3,4,5 };
	ve1.pop_front();
	ve1.pop_back();
	for (auto beg = ve1.begin(), end = ve1.end();
		beg != end; ++beg) {
		cout << *beg;
	}
	cout << endl;
	// 删除一个元素
	list<int> li1 = { 0,1,2,3,4,5,6,7,8,9,10 };
	auto it1 = li1.begin();
	while (it1 != li1.end()) {
		if (*it1 % 2)
			it1 = li1.erase(it1);
		else
			++it1;
	}
	for (auto beg = li1.begin(), end = li1.end();
		beg != end; ++beg) {
		cout << *beg;
	}
	cout << endl;
	// 删除多个元素
	vector<int> ve2 = { 0,1,2,3,4,5,6,7,8,9,10 };
	auto elem1 = ve2.begin();
	auto elem2 = ve2.begin() + 3;
	ve2.erase(elem1,elem2);
	for (auto beg = ve2.begin(), end = ve2.end();
		beg != end; ++beg) {
		cout << *beg;
	}
	cout << endl;
	// 删除所有
	ve2.clear();
	ve2.erase(ve2.begin(), ve2.end());

	// 练习
	// 9.25
	vector<int> ve3 = { 0,1,2,3,4,5,6,7,8,9,10 };
	 elem1 = ve3.end();
	 elem2 = ve3.end();
	/*ve3.erase(elem1, elem1);
	for (auto beg = ve3.begin(), end = ve3.end();
		beg != end; ++beg) {
		cout << *beg;
	}
	cout << endl;*/
	ve3.erase(elem1, elem2);
	for (auto beg = ve3.begin(), end = ve3.end();
		beg != end; ++beg) {
		cout << *beg;
	}
	cout << endl;

	// 9.26
	
	int ia[] = { 0,1,1,2,3,5,8,13,21,55,89 };
	vector<int> ve4(begin(ia),end(ia));
	list<int> li3(begin(ia), end(ia));
	auto be1 = begin(ia),end1 = end(ia);
	int count = 0;
	int lidel = 0;
	int vedel = 0;
	while (be1 != end1) {
		if (*be1 % 2) {
			auto it3 = li3.begin();
			// count - lidel 不能先加后减，因为加的时候就会越界再减来不及了
			for (int i = 0; i < count - lidel; ++i) {
				it3++;
			}
			li3.erase(it3);
			lidel++;
		}
		else {
			ve4.erase((ve4.begin() + count - vedel));
			vedel++;
		}
		be1++;
		count++;
	}
	cout << endl;
	for (auto beg = ve4.begin(), end = ve4.end();
		beg != end; ++beg) {
		cout << *beg;
	}
	cout << endl;
	for (auto beg = li3.begin(), end = li3.end();
		beg != end; ++beg) {
		cout << *beg;
	}
	cout << endl;
	cin >> a;
	return 0;
}