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
	cout << words.size() << endl;
	// 真正删除
	words.erase(thewei, words.end());
	cout << words.size() << endl;
}

bool compareIsbn(Sales_data &s1, Sales_data &s2) 
{
	return s1.isbn().length() < s2.isbn().length();
}

bool tenonthree(const string& s1) {
	return s1.length() < 5;
}
int main()
{
	int a;
	vector<string> v1{ "the","quick", "red", "fox", "jumps", "over", "the", "slow", "red" ,"turtle" };
	//sort(v1.begin(), v1.end(), isShorter);
	elimDups(v1);
	for (auto beg = v1.begin(); beg != v1.end(); ++beg) {
		cout << *beg << " ";
	}
	cout << endl;
	stable_sort(v1.begin(), v1.end(), isShorter);// 保持同等大小的相对字典序
	for (auto beg = v1.begin(); beg != v1.end(); ++beg) {
		cout << *beg << " ";
	}
	cout << endl;

	// 练习
	vector<Sales_data> v2{Sales_data("123"),Sales_data("8756") ,Sales_data("8") ,Sales_data("789") };
	sort(v2.begin(), v2.end(), compareIsbn);
	for (auto beg = v2.begin(); beg != v2.end(); ++beg) {
		cout << (*beg).isbn() << " ";
	}
	cout << endl;

	vector<string> v3{ "the","quick", "red", "fox", "jumps", "overdfsdf", "the", "slow", "red" ,"turtle" };
	auto trueiter = partition(v3.begin(), v3.end(), tenonthree);
	for (auto beg = v3.begin(); beg != v3.end(); ++beg) {
		cout << (*beg) << " ";
	}
	cout << endl;
	cout << v3.end() - trueiter << endl;
	cin >> a;
	return 0;
}