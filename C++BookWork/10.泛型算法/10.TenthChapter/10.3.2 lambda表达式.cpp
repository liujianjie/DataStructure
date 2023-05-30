#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <string>
#include <iterator>
#include <list>
#include "Sales_data.h"
using namespace std;
// 迭代器元素的值必须能转换为这里的参数
bool isShorter(const string &s1, const string &s2)
{
	return s1.size() < s2.size();
}
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
// 只能一个参数
bool isGreaterFive(const string& s1)
{
	return s1.length() >= 5;
}
bool isGreaterFivetwo(const string& s1, const vector<string>::size_type size)
{
	return s1.length() >= size;
}
// this chapter method
void biggies(vector<string> &words, vector<string>::size_type sz) {
	elimDups(words);
	stable_sort(words.begin(), words.end(), isShorter);
	auto firstit = find_if(words.begin(), words.end(), isGreaterFive);// 只能一个参数
	//auto firstit = find_if(words.begin(), words.end(), isGreaterFivetwo);// find_if只能一个参数
	cout << words.end() - firstit << endl;
	for (auto beg = firstit; beg != words.end(); ++beg) {
		cout << (*beg) << " ";
	}
	cout << endl;
}
void biggieslambda(vector<string> &words, vector<string>::size_type sz) {
	elimDups(words);
	stable_sort(words.begin(), words.end(), [](const string& s1, const string &s2) {return s1.size() < s2.size(); });
	auto firstit = find_if(words.begin(), words.end(),
		[sz](const string &s1) {return s1.size() >= sz; });
	cout << words.end() - firstit << endl;
	for (auto beg = firstit; beg != words.end(); ++beg) {
		cout << (*beg) << " ";
	}
	cout << endl;
	// for - each
	for_each(firstit, words.end(),
		[](const string &s) {cout << s << " "; });
	cout << endl;
}
// 题目10.18
void biggiespartition(vector<string> &words, vector<string>::size_type sz) {
	elimDups(words);
	stable_sort(words.begin(), words.end(), [](const string& s1, const string &s2) {return s1.size() < s2.size(); });
	auto parit = partition(words.begin(), words.end(),
		[sz](const string &s1) {return s1.size() >= sz; });//返回最后一个true之后的位置
	cout << parit - words.begin() << endl;
	cout << endl;
	// for - each
	for_each(words.begin(), parit,
		[](const string &s) {cout << s << " "; });
	cout << endl;
}
// 题目10.10
void biggiesstable_partition(vector<string> &words, vector<string>::size_type sz) {
	elimDups(words);
	stable_sort(words.begin(), words.end(), [](const string& s1, const string &s2) {return s1.size() < s2.size(); });
	auto parit = stable_partition(words.begin(), words.end(),
		[sz](const string &s1) {return s1.size() >= sz; });//返回最后一个true之后的位置，并且不会弄乱排好的相对顺序
	for_each(words.begin(), words.end(),
		[](const string &s) {cout << s << " "; });
	cout << endl;
	cout << parit - words.begin() << endl;
	cout << endl;
	// for - each
	for_each(words.begin(), parit,
		[](const string &s) {cout << s << " "; });
	cout << endl;
}
int main()
{
	int a;
	vector<string> v1{ "the","quick", "red", "fox", "jumps", "over", "the", "slow", "red" ,"turtle" };
	biggies(v1, 5);
	vector<string> v2{ "the","quick", "red", "fox", "jumps", "over", "the", "slow", "red" ,"turtle" };
	biggieslambda(v2, 5);
	// 介绍lambda
	auto f = [] {return 42; };
	cout << f() << endl;// 是调用对象，即使空的参数列表 也不能少()
	// 二

	// 练习
	//int a1, b1;
	//cin >> a1;
	//cin >> b1;
	//auto one = [](int a1, int b1) {return a1 + b1; };
	//cout << one(a1, b1) << endl;

	//int a2 = 23;
	//cin >> b1;
	//auto two = [a2](int b) {return a2 + b; };
	//cout << two(b1) << endl;

	vector<Sales_data> v3{ Sales_data("123"),Sales_data("8756") ,Sales_data("8") ,Sales_data("789") };
	sort(v3.begin(), v3.end(), 
		[](const Sales_data &s1, const Sales_data &s2) {return s1.isbn().size() < s2.isbn().size(); });
	for (auto beg = v3.begin(); beg != v3.end(); ++beg) {
		cout << (*beg).isbn() << " ";
	}
	cout << endl;

	vector<string> v4{ "the","quick", "red", "fox", "jumps", "over", "the", "slow", "red" ,"turtle" };
	biggiespartition(v4, 5);

	// 10.19
	vector<string> v5{ "the","quick", "red", "fox", "jumps", "over", "the", "slow", "red" ,"turtle" };
	biggiesstable_partition(v5,5);

	cin >> a;
	string ts1 = "adfgzvc";
	cout << ts1.length() << endl;
	cout << ts1.size() << endl;
	return 0;
}