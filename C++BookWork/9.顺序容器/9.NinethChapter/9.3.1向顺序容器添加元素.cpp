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
	list<string> listrcontainer;
	//array<string,10> strcontainer;//不行
	//forward_list<string> strcontainer;// 也不行
	string word;
	//while ((cin >> word) && word != "n"){
	//	listrcontainer.push_back(word);
	//}
	//for (auto beg = listrcontainer.begin(), end = listrcontainer.end();
	//	beg != end; ++beg) {
	//	cout << *beg;
	//}
	//cout << endl;
	string strcontainer;
	int count = 1;
	while (count++ < 10) {
		strcontainer.push_back('s');
	}
	cout << strcontainer << endl;

	// 二，使用push_front
	list<int> tli1;
	//vector<int> tli1;// 不行
	//string tli1;// 不行
	//array<int,4> tli1;// 不行
	// 将元素添加到tli开头
	for (size_t ix = 0; ix != 4; ++ix) {
		tli1.push_front(ix);
	}
	for (auto beg = tli1.begin(), end = tli1.end();
		beg != end; ++beg) {
		cout << *beg;
	}
	cout << endl;
	// 三。在容器中的特定位置添加元素 array 不行，forward_list自己的操作
	string thstr1 = "asdfljksadfa";
	auto thstr1iter = thstr1.begin() + 3;
	thstr1.insert(thstr1iter, { '3','4','s' });
	cout << thstr1 << endl;
	// 不用考虑容器是否支持push_front
	
	list<string> thsli1;
	thsli1.insert(thsli1.begin(), "Hello!");
	vector<string> thsvec1;
	thsvec1.insert(thsvec1.begin(), "Hello!");// 等价使用push_front 但是会很慢

	cout << *thsli1.begin() << endl;
	cout << *thsvec1.begin() << endl;
	// insert可以接受更多参数
	thsvec1.insert(thsvec1.end(), 10, "Anna");

	vector<string> thsvec2;
	thsli1.insert(thsli1.end(), { "three","words","will","go" });
	thsvec2.insert(thsvec2.begin(), thsvec1.begin(), thsvec1.begin() + 3);
	thsvec2.insert(thsvec2.end(), thsli1.begin(), ++++++thsli1.begin());
	for (auto beg = thsvec2.begin(), end = thsvec2.end();
		beg != end; ++beg) {
		cout << *beg;
	}
	cout << "-------"<<endl;
	// 不会报错了 会赋值过去
	thsli1.insert(thsli1.begin(), thsli1.begin(), thsli1.end());
	for (auto beg = thsli1.begin(), end = thsli1.end();
		beg != end; ++beg) {
		cout << *beg;
	}
	cout << endl;

	// 四。使用insert返回值
	list<string> fourli1;
	//auto fouriter = fourli1.begin();
	//while ((cin >> word) && word != "n")
	//	fouriter = fourli1.insert(fouriter, word);
	//for (auto beg = fourli1.begin(), end = fourli1.end();
	//	beg != end; ++beg) {
	//	cout << *beg;
	//}

	// 五使用emplace操作，在容器内存空间中直接构造元素，而insert是将这些对象拷贝到容器中
	list<Sales_data> fiveli1;
	fiveli1.emplace_back("9999", 25, 12.9);
	fiveli1.emplace_back("9998");
	//fiveli1.push_back("9999", 25, 12.9);// error
	fiveli1.push_back(Sales_data("9999", 25, 12.9));//true

	fiveli1.emplace_back();
	fiveli1.emplace(fiveli1.begin(), "9999");
	fiveli1.emplace_front("9090", 25, 12.9);

	// 练习
	//// 9.18
	//deque<string> pde1;
	//while (cin>>word && word != "n") {
	//	pde1.push_back(word);
	//}
	//for (auto beg = pde1.begin(), end = pde1.end();
	//	beg != end; ++beg) {
	//	cout << *beg;
	//}
	// 9.19 不用什么改变呀
	/*list<string> pde1;
	while (cin >> word && word != "n") {
		pde1.push_back(word);
	}
	for (auto beg = pde1.begin(), end = pde1.end();
		beg != end; ++beg) {
		cout << *beg;
	}*/
	cout << endl;
	// 9.20
	list<int> pli2{1,2,3,4,5,6,7,8};
	deque<int> pde2;
	deque<int> pde3;
	for (auto beg = pli2.begin(), end = pli2.end();
		beg != end; ++beg) {
		if ((*beg) % 2 == 0) {
			pde2.push_back(*beg);
		}
		else {
			pde3.push_back(*beg);
		}
	}
	for (auto beg = pde2.begin(), end = pde2.end();
		beg != end; ++beg) {
		cout << *beg;
	}
	cout << endl;
	// 9.21
	//vector<string> pve1;
	//auto iter = pve1.begin();
	//while (cin >> word && word != "n")
	//{
	//	iter = pve1.insert(iter, word);
	//}
	//for (auto beg = pve1.begin(), end = pve1.end();
	//	beg != end; ++beg) {
	//	cout << *beg;
	//}
	//cout << endl;
	// 9.22
	vector<int> iv{1,2,3,4,5,6};
	vector<int>::iterator iter = iv.begin(), mid = iv.begin() + iv.size() / 2;
	while (iter != mid) {
		if (*iter == 2)
		{
			iv.insert(iter, 2 * 2);
			break;
		}
		iter++;
	}
	for (auto beg = iv.begin(), end = iv.end();
		beg != end; ++beg) {
		cout << *beg;
	}
	cout << endl;
	

	cin >> a;
	return 0;
}