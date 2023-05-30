#include <iostream>
#include <vector>
#include <memory>
#include <list>
#include "Sales_data.h"
#include "StrBlob.h"
#include "StrBloPtr.h"
#include <sstream>
#include <string>
#include <fstream>

//#include <>
using namespace std;
/*
1.不控制所指向对象生成期的智能指针，指向shared_ptr管理的对象
2.伴随指针，安全性更高吧。
*/
int main()
{
	int a;
	auto p1 = make_shared<int>(42);
	weak_ptr<int> wp1(p1);// wp弱共享p，p引用计数未改变
	if (shared_ptr<int> p2 = wp1.lock())
	{
		// 在if块中，p2与p1共享对象
		cout << "if 块" << p2.use_count() << endl;
	}
	StrBlob sb1;
	ifstream ifs("练习12.20.txt");
	string line;
	while (getline(ifs, line)) {
		sb1.push_back(line);
	}
	// sb1.begin() end 就是获取strbloptr;
	for (auto beg = sb1.begin(); nteq(beg, sb1.end()) ; beg.incr()) {
		cout << beg.deref() << endl;
	}

	// 自己写的，不准确，是将私有成员放出来
	//StrBloPtr sbp1(sb1);
	//while (sbp1.curr < sb1.data->size()) {
	//	cout << sbp1.deref() << endl;
	//	sbp1.incr();
	//}

	// return (*check(curr, "dereference"))[curr]; 可读性低

	// 12.22 StrBloPtr(StrBlob &a, size_t sz = 0):就这里要改完事

	cin >> a;
	return 0;
}
