#include <iostream>
#include <map>
#include <string>
#include <set>
#include <vector>

using namespace std;

void prints(map<string, int> maps)
{
	for (auto &words : maps)
	{
		cout << words.first << " occurs " << words.second << "times" << endl;;
	}
}
int main()
{

	int a;
	// 可以值初始化，可以列表初始化
	map<string, size_t> map1;
	set<string> set1 = { "the","but","an" };
	map<string, string> authors = { {"1","11"},
	{ "2","22" },
	{ "3","33" },
	{ "4","44" }, };

	// 二 初始化multimap 或 multiset
	vector<int> ivec;
	for (vector<int>::size_type i = 0; i != 20; ++i) {
		ivec.push_back(i);
		ivec.push_back(i);
	}
	set<int> set2(ivec.begin(), ivec.end());// 20个元素
	multiset<int> set3(ivec.begin(), ivec.end());// 40个元素
	cout << set2.size() << endl;
	cout << set3.size() << endl;

	// 练习
	/*
	1.当没有关键字映射元素就使用set简单便捷，但当有关键字且元素重复，但是关键字不同来区分用map
	2.list可以重复，set不可以重复，list是有序的，访问慢，删改快，
	3.
	4.显而易见？？还是set好查找？find（）？
	*/
	vector<string> ve3(20);


	cin >> a;
	return 0;
}