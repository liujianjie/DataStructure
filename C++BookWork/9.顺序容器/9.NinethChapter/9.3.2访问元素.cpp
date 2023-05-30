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
	list<int> li1{ 1,2,3,4,5,6 };
	if (!li1.empty()) {
		li1.front() = 32;
		auto &v1 = li1.back();
		v1 = 1024;
		auto v2 = li1.back();// 
		v2 = 100;// 没有改变 不是引用
	}
	for (auto beg = li1.begin(), end = li1.end();
		beg != end; ++beg) {
		cout << *beg;
	}
	cout << endl;

	// 下标的操作和安全的随机访问
	vector<string> ve1;
	//cout << ve1[0];// 运行时错误
	//cout << ve1.at(0);// 抛出异常  可以捕捉

	// 练习
	// 9.23
	list<int> li2{2};
	if (!li2.empty()) {
		auto val1 = *li2.begin(), val2 = li2.front();
		auto last = li2.end();
		auto val3 = *(--last);
		auto val4 = li2.back();//forward_list不支持
		cout << val1 << val2 << val3 << val4;
	}
	string a1, a2;
	//a1 = ve1.front();//都不可
	//a2 = *ve1.begin();
	cout << a1 << "," << a2 << endl;
	cin >> a;
	return 0;
}