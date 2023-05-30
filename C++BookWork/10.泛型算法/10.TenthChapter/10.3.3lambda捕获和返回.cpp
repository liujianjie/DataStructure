#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <string>
#include <iterator>
#include <list>
#include "Sales_data.h"
using namespace std;

void fcn1()
{
	size_t v1 = 42;
	auto f = [v1] {return v1; };
	v1 = 0;
	auto j = f();
	cout << j << endl;
}
// 
void fcn2() 
{
	size_t v1 = 42;
	auto f = [&v1] {return v1; };
	v1 = 0;
	auto j = f();
	cout << j << endl;
}

// this chapter method
void elimDups(vector<string> &words)
{
	// 因为算法是对迭代器而不是容器操作，所以算法不能直接添加或删除元素
	// 按字典序排序words
	sort(words.begin(), words.end());
	// 消除重复的
	auto thewei = unique(words.begin(), words.end());
	// 真正删除
	words.erase(thewei, words.end());
}
void biggies(vector<string> &words, vector<string>::size_type sz, 
		ostream &os = cout, char c = ' ') {
	elimDups(words);
	
	for_each(words.begin(), words.end(),
		[&os, c](const string &s) {os << s << c; });
	cout << endl;
}
void biggieslambda(vector<string> &words, vector<string>::size_type sz) {
	elimDups(words);
	stable_sort(words.begin(), words.end(), [](const string& s1, const string &s2) {return s1.size() < s2.size(); });
	auto firstit = find_if(words.begin(), words.end(),
		[=](const string &s1) {return s1.size() >= sz; });
	// for - each
	for_each(firstit, words.end(),
		[](const string &s) {cout << s << " "; });
	cout << endl;
}

// 值捕获不能改变值，除非加上可变的
int fcn3() 
{
	size_t v1 = 42;
	auto f = [v1]()mutable {return ++v1; };
	v1 = 0;
	auto j = f();
	return j;
}
int fcn4()
{
	size_t v1 = 42;
	auto f = [&v1]() {return ++v1; };
	v1 = 0;
	auto j = f();// 为1
	return j;
}
void biggieslambda2(vector<string> &words, vector<string>::size_type sz,
	ostream &os = cout, char c = ' ') {
	elimDups(words);

	// 不知道为什么 隐式捕获必须在第一个捕获位置，必须的，
	// 并且当第一个隐式为&第二个不能为&，第一个为=，第二个不能为=需加&，就是得不同的
	// 隐式捕获和值捕获都可以是多个
	for_each(words.begin(), words.end(),
		[&, c](const string &s) {os << s << c; });
	cout << endl;
	for_each(words.begin(), words.end(),
		[=, &os](const string &s) {os << s << c; });
	cout << endl;
}
// 隐式捕获写一个=可以隐式捕获所有在函数体内用到的局部变量，引用则需要一个个指定
// 第一个写&一样的，反过来的意思
int main()
{
	int a;
	// 值捕获
	fcn1();
	// 引用捕获
	fcn2();
	vector<string> v1{ "the","quick", "red", "fox", "jumps", "over", "the", "slow", "red" ,"turtle" };
	biggies(v1, 5);

	// 隐式捕获
	biggieslambda(v1,5);
	// 混用隐式和显式
	biggieslambda2(v1,5);

	cout << fcn3() << endl;
	cout << fcn4() << endl;

	// 指定返回类型
	vector<int> v2{ -1,-5,5,-6,-8,-5 };
	transform(v2.begin(), v2.end(), v2.begin(),
		[](int i) {return i < 0 ? -i : i; });
	ostream &os = cout;
	char c = ' ';
	for_each(v2.begin(), v2.end(),
		[=, &os](const int &s) {os << s << c; });

	// 错误的写法 但14不会了
	vector<int> v3{ -1,-5,5,-6,-8,-5 };
	transform(v3.begin(), v3.end(), v3.begin(),
		[](int i) { if (i < 0)  return -i;  else return i; });
	for_each(v3.begin(), v3.end(),
		[=, &os](const int &s) {os << s << c; });

	vector<int> v4{ -1,-5,5,-6,-8,-5 };
	transform(v4.begin(), v4.end(), v4.begin(),
		[](int i)->int 
		{ if (i < 0)  return -i;  else return i; });
	for_each(v4.begin(), v4.end(),
		[=, &os](const int &s) {os << s << c; });

	// 练习
	cout << endl;
	int size = 4;
	int as = 0;
	vector<string> v5{ "the","quick", "red", "fox", "jumps", "over", "the", "slow", "red" ,"turtle" };
	int counts = count_if(v5.begin(), v5.end(),
		[=](const string& s1) {return s1.length() >= size 
		&& s1.length() > as; });
	cout << counts << endl;

	// 需两个都返回
	int val2 = 10;
	auto f1 = [&val2]()->bool {if (val2 != 0) { val2--; return false; } else { return true; }};
	while (!f1()) {
	
	}
	cout << "结束" <<val2<< endl;

	int val4 = 4;
	int val5 = 6;
	auto f2 = [&]() {return val4 + val5; };
	cout << f2() << endl;
	cin >> a;
	return 0;
}

