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
	// 添加元素
	// 之前之后的迭代器失效会报错，而引用和指针则是未定义的值
	vector<int> v1{0,1,2,3,4,5,6};
	auto itprev1 = v1.begin() + 0;
	auto itafter1 = v1.begin() + 3;

	int* pprev1 = &v1.at(0);// 1之前位置的指针
	int* pafter1 = &v1.at(3);// 1之后的位置指针
	auto &rprev1 = v1.at(0);// 引用
	auto &rafter1 = v1.at(3);// 引用
	
	cout << *itprev1 << endl;
	cout << *itafter1 << endl;
	cout << *pprev1 << endl;
	cout << *pafter1 << endl;
	cout << rprev1 << endl;
	cout << rafter1 << endl;

	v1.insert(v1.begin()+2, 2);

	cout << "----------------" << endl;
	//cout << *itprev1 << endl;
	//cout << *itafter1 << endl;
	cout << *pprev1 << endl;
	cout << *pafter1 << endl;
	cout << rprev1 << endl;
	cout << rafter1 << endl;
	cout << "----------------" << endl;
	// deque,首尾之外迭代器会失效，指向元素的引用和指针不会失效只是指的值不一样了，若是在首尾则指的值不会变
	deque<int> de1{ 0,1,2,3,4,5,6,7,8,9 };
	auto itprev2 = de1.begin() + 0;
	auto itafter2 = de1.begin() + 3;
	int* pprev2 = &de1.at(0);// 1之前位置的指针
	int* pafter2 = &de1.at(3);// 1之后的位置指针
	auto &rprev2 = de1.at(0);// 引用
	auto &rafter2 = de1.at(3);// 引用

	cout << *itprev2 << endl;
	cout << *itafter2 << endl;
	cout << *pprev2 << endl;
	cout << *pafter2 << endl;
	cout << rprev2 << endl;
	cout << rafter2 << endl;

	de1.insert(de1.begin() + 2, 9);

	cout << "----------------" << endl;
	//cout << *itprev2 << endl;
	//cout << *itafter2 << endl;
	cout << *pprev2 << endl;
	cout << *pafter2 << endl;
	cout << rprev2 << endl;
	cout << rafter2 << endl;

	cout << "-------list和forward_list-------" << endl;
	// 迭代器都不会失效
	list<int> li1{ 0,1,2,3,4,5,6,7,8,9 };
	auto itprev3 = li1.begin();
	auto itafter3 = ++++++li1.begin();

	cout << *itprev3 << endl;
	cout << *itafter3 << endl;

	li1.insert(++++li1.begin(), 9);

	cout << "----------------" << endl;
	cout << *itprev3 << endl;
	cout << *itafter3 << endl;

	// 删除元素
	cout << "--- 删除元素---------" << endl;
	cout << "-----vector--------" << endl;
	// 只有删除之前的迭代器会失效，之后和之前的引用和指针都有效，之后的指针会指向下一个值。。
	vector<int> v2{ 0,1,2,3,4,5,6,7,8,9 };
	itprev1 = v2.begin() + 0;
	itafter1 = v2.begin() + 3;

	pprev1 = &v2.at(0);// 1之前位置的指针
	pafter1 = &v2.at(3);// 1之后的位置指针
	rprev1 = v2.at(0);// 引用
	rafter1 = v2.at(3);// 引用

	cout << *itprev1 << endl;
	cout << *itafter1 << endl;
	cout << *pprev1 << endl;
	cout << *pafter1 << endl;
	cout << rprev1 << endl;
	cout << rafter1 << endl;

	v2.erase(v2.begin() + 2);

	cout << "----------------" << endl;
	cout << *itprev1 << endl;
	//cout << *itafter1 << endl;
	cout << *pprev1 << endl;
	cout << *pafter1 << endl;
	cout << rprev1 << endl;
	cout << rafter1 << endl;

	cout << "------de2--------" << endl;
	// 任意位置，迭代器失效，指向元素的引用和指针不会失效只是指的值不一样了
	// 尾的位置不影响
	// 首位置，迭代器失效，指向元素的引用和指针不影响
	deque<int> de2{ 0,1,2,3,4,5,6,7,8,9 };
	itprev2 = de2.begin() + 0;
	itafter2 = de2.begin() + 3;
	pprev2 = &de2.at(0);// 1之前位置的指针
	pafter2 = &de2.at(3);// 1之后的位置指针
	rprev2 = de2.at(0);// 引用
	rafter2 = de2.at(3);// 引用

	cout << *itprev2 << endl;
	cout << *itafter2 << endl;
	cout << *pprev2 << endl;
	cout << *pafter2 << endl;
	cout << rprev2 << endl;
	cout << rafter2 << endl;

	de2.erase(de2.begin());

	cout << "----------------" << endl;
	//cout << *itprev2 << endl;
	//cout << *itafter2 << endl;
	cout << *pprev2 << endl;
	cout << *pafter2 << endl;
	cout << rprev2 << endl;
	cout << rafter2 << endl;

	cout << "------list--------" << endl;
	// 不会失效
	list<int> li2{ 0,1,2,3,4,5,6,7,8,9 };
	 itprev3 = li2.begin();
	 itafter3 = ++++++li2.begin();

	cout << *itprev3 << endl;
	cout << *itafter3 << endl;

	li2.erase(++li2.begin());

	cout << "----------------" << endl;
	cout << *itprev3 << endl;
	cout << *itafter3 << endl;

	cout << "----------------" << endl;
	// 编写改变容器的循环程序
	vector<int> vi3 = { 0,1,2,3,4,5,6,7,8,9 };
	auto iter3 = vi3.begin();
	while (iter3 != vi3.end()) {
		if (*iter3 % 2) {
			iter3 = vi3.insert(iter3, *iter3);// insert指向被添加之前的元素
			iter3 += 2;// 向前跳动2个
		}
		else {
			iter3 = vi3.erase(iter3);// erase指向被删除之后的元素
		}
	}
	for (auto beg = vi3.begin(), end = vi3.end();
		beg != end; ++beg) {
		cout << *beg;
	}
	cout << endl;

	// 不要保存end返回的迭代器
	// end返回的迭代器在vector和string中删除/添加元素，deque首之外添加/删除，end总会失效
	vector<int> vi4 = { 0,1,2,3,4,5,6,7,8,9 };
	auto begin = vi4.begin();
	auto end = vi4.end();
	// end迭代器会失效
	//while (begin != end) {
	//	++begin;// 想在当前元素之后添加
	//	begin = vi4.insert(begin, 42);
	//	++begin;
	//}
	while (begin != vi4.end()) {
		++begin;// 想在当前元素之后添加
		begin = vi4.insert(begin, 42);
		++begin;
	}
	for (auto beg = vi4.begin(), end = vi4.end();
		beg != end; ++beg) {
		cout << *beg;
	}
	cout << endl;
	// 练习
	cout << "练习" << endl;
	// 9.31
	list<int> li4 = { 0,1,2,3,4,5,6,7,8,9 };
	auto iter4 = li4.begin();
	while (iter4 != li4.end()) {
		if (*iter4 % 2) {
			iter4 = li4.insert(iter4, *iter4);// insert指向被添加之前的元素
			++++iter4;// 向前跳动2个
		}
		else {
			iter4 = li4.erase(iter4);// erase指向被删除之后的元素
		}
	}
	cout << "out while" << endl;
	for (auto beg = li4.begin(), end = li4.end();
		beg != end; ++beg) {
		cout << *beg;
	}
	cout << endl;
	// 9.32
	vector<int> vi5 = { 0,1,2,3,4,5,6,7,8,9 };
	auto iter5 = vi5.begin();
	while (iter5 != vi5.end()) {
		if (*iter5 % 2) {
			iter5 = vi5.insert(iter5, *iter5++);// insert指向被添加之前的元素
			iter5++;// 向前跳动2个
		}
		else {
			iter5 = vi5.erase(iter5);// erase指向被删除之后的元素
		}
	}
	for (auto beg = vi5.begin(), end = vi5.end();
		beg != end; ++beg) {
		cout << *beg;
	}
	cout << endl;
	// 9.33 会失效。vi6添加后，因为这个迭代器在之后吗？所以会失效。
	vector<int> vi6 = { 0,1,2,3,4,5,6,7,8,9 };
	auto begin2 = vi6.begin();
	//while (begin2 != (vi6.end() - 2)) {
	//	++begin2;// 像在当前元素之后添加会让迭代器失效 若没重新定义
	//	vi6.insert(begin2, 42);
	//}
	for (auto beg = vi6.begin(), end = vi6.end();
		beg != end; ++beg) {
		cout << *beg;
	}
	cout << endl;
	// 9.34 无限循环
	cout << "9.34"<<endl;
	vector<int> vi7 = { 0,1,2,3,4,5,6,7,8,9 };
	auto begin3 = vi7.begin();
	while (begin3 != (vi7.end())) {
		if (*begin3 % 2)
			begin3 = vi7.insert(begin3, *begin3);
		++begin3;
	}
	for (auto beg = vi7.begin(), end = vi7.end();
		beg != end; ++beg) {
		cout << *beg;
	}
	cout << endl;
	//int val1 = 4;
	//int	*p2 = &val1;
	//int &r2 = val1;
	//cout << val1 << endl;
	//*p2 = 5;
	//cout << val1 << endl;
	//r2 = 6;
	//cout << val1 << endl;
	cin >> a;
	return 0;
}