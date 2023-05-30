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

void print_vec(list<int>::iterator &beg, list<int>::iterator &end)
{
	for (; beg != end; ++beg)
	{
		cout << *beg;
	}
	cout << endl;
}

int main()
{
	int a;

	list<int> l1{ 1,2,3,4 };
	list<int> l2{ 1,2,3 };
	l2 = l1;
	print_vec(l1.begin(), l1.end());
	print_vec(l2.begin(), l2.end());
	l2 = { 1,2,3,4,5,6 };
	print_vec(l2.begin(), l2.end());

	array<int, 10> a1 = { 0,1,2,3,4 };
	array<int, 10> a2 = { 0 };
	auto beg = a1.begin();
	auto end = a1.end();
	for (; beg != end; ++beg)
	{
		cout << *beg;
	}
	cout << endl;
	a1 = a2;
	for (beg = a1.begin(), end = a1.end(); beg != end; ++beg)
	{
		cout << *beg;
	}
	cout << endl;
	a1 = { 0,2,3,4 };// 不支持一个花括号列表赋值 新标准允许吧
	for (beg = a1.begin(), end = a1.end(); beg != end; ++beg)
	{
		cout << *beg;
	}
	cout << endl;

	// 
	deque<int> tli1 = { 2,3,4,5,6,7 };
	deque<int> tli2 = { 8,9,10,11,12 };
	auto val1 = tli1.begin();
	auto val2 = tli2.begin();
	cout << "val1 :" << *val1 << endl;
	cout << "val2 :" << *val2 << endl;
	//tli1 = tli2;
	tli1.swap(tli2);// 不失效，但是也不会指向新的位置
	cout << "val1 :" << *val1 << "," << *tli1.begin() << endl;// list不会失效，但指向新值
	cout << "val2 :" << *val2 << endl;

	// 使用assign
	list<string> tlist1;
	list<string> tlist2{ "1","2" };
	tlist1.assign({ "3","6" });
	tlist1.assign(4, "6");

	list<string> names{"2","3","4","6"};
	//names.assign(4, "6");
	vector<const char*> oldstyle{ "2","4","6" };
	//names = oldstyle;//error;
	names.assign(oldstyle.cbegin(), oldstyle.cend());
	//names.assign(names.cbegin(), names.cend());// 可是可以但是为空了

	for (auto beg2 = names.begin(),  end2 = names.end(); beg2 != end2; ++beg2)
	{
		cout << *beg2;
	}
	cout << endl;
	list<string> slist1(1);
	slist1.assign(10, "Hiya!");
	for (auto beg2 = slist1.begin(), end2 = slist1.end(); beg2 != end2; ++beg2)
	{
		cout << *beg2;
	}
	cout << endl;

	// 三。使用swap
	vector<string> svec1={ "3" ,"4" ,"5" ,"6" ,"7" };
	vector<string> svec2={ "8" ,"9" ,"10" ,"11" ,"12" };
	auto svec1it = svec1.begin();
	auto sveclit2 = svec1it + 2;
	cout << "sveclit2:" << *sveclit2 << endl;// 指向svec1的位置
	for (auto beg2 = svec1.begin(), end2 = svec1.end(); beg2 != end2; ++beg2)
	{
		cout << *beg2;
	}
	cout << endl;
	swap(svec1, svec2);
	for (auto beg2 = svec1.begin(), end2 = svec1.end(); beg2 != end2; ++beg2)
	{
		cout << *beg2;
	}
	cout << endl;// 指向svec2的位置
	cout << "sveclit2:" << *sveclit2 << endl;

	string str1 = "1234567";
	string str2 = "989123";
	auto str1it = str1.begin() + 2;
	cout << *str1it << endl;
	//swap(str1, str2);//string 会失效
	cout << *str1it << endl;

	// 练习9.2.5 1
	list<const char*> pli1{"12321421"};
	vector<string> pv1;
	pv1.assign(pli1.begin(), pli1.end());
	for (auto beg2 = pv1.begin(), end2 = pv1.end(); beg2 != end2; ++beg2)
	{
		cout << *beg2;
	}
	cin >> a;
	return 0;
}