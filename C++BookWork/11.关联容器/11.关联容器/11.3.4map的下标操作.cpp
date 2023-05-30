#include <iostream>
#include <map>
#include <string>
#include <set>
#include <vector>
#include "Sales_data.h"
#include <fstream>
#include <list>
#include <iterator>


using namespace std;

void prints(map<string, int> maps)
{
	for (auto &words : maps)
	{
		cout << words.first << " occurs " << words.second << "times" << endl;;
	}
}
bool compareIsbn(const Sales_data &lhs, const Sales_data &rhs)
{
	return lhs.isbn() < rhs.isbn();
}
/*

map的下标 有下标运算和对应的at
mult的不能下标，因为有可能有多个值与一个关键相关联
set没有下标

不同的是，如果关键字不在map中会进行添加插入map中，并且关联值进行值初始化

只适合用非const的map和unordered_map
*/
int main()
{

	int a;
	map<int, int> map1{ { 1,1 },{ 2,2 },{ 3,3 },{ 4,4 },{ 5,5 } };
	int a1 = map1.at(2);
	cout << a1 << endl;

	// map的下标运算(mapped_type)与解引用一个迭代器返回的类型不同（value_type）
	// mapped_type 可读可写
	cout << map1[1];
	++map1[1];
	cout << map1[1];

	vector<int> v1;
	//v1[0] = 1;//error

	// 练习
	/*
	map的关键字类型,或者可以转换map的关键字类型 key_type,
	返回的是mapped_typed
	*/

	cin >> a;
	return 0;
}